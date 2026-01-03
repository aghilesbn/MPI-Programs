#include <stdio.h>   // For printf
#include <mpi.h>     // MPI library

int main(int argc, char **argv) {

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int rank, size;

    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Get the total number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Each process prints its own rank and the total number of processes
    printf("Hello from process %d out of %d processes\n", rank, size);

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
