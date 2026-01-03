#include <stdio.h>   // For printf
#include <mpi.h>     // MPI library

int main(int argc, char **argv) {

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int rank;
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int value;  // Variable that will be sent/received

    // If this is process 0, it sends the value
    if (rank == 0) {
        value = 42;  // Value to send
        printf("Process 0 sending value %d\n", value);

        // Send the value to process 1
        // &value : address of the data to send
        // 1      : number of elements
        // MPI_INT: data type
        // 1      : destination rank
        // 0      : message tag
        // MPI_COMM_WORLD : global communicator
        MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } 
    // If this is process 1, it receives the value
    else if (rank == 1) {

        // Receive the value from process 0
        MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Process 1 received value %d\n", value);
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
