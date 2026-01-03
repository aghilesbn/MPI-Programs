#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int size, rank;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // This example is designed for exactly 2 processes
    if (size != 2) {
        if (rank == 0) {
            printf("This program must be run with exactly 2 processes.\n");
        }
        MPI_Finalize();
        return 0;
    }

    int sendbuf;   // value to send
    int recvbuf;   // value to receive
    int tag = 0;

    // Each process sends a different value
    sendbuf = 100 + rank;

    if (rank == 0) {
        // Process 0 sends to process 1 and receives from process 1
        MPI_Sendrecv(&sendbuf, 1, MPI_INT, 1, tag,
                     &recvbuf, 1, MPI_INT, 1, tag,
                     MPI_COMM_WORLD, &status);

    } else if (rank == 1) {
        // Process 1 sends to process 0 and receives from process 0
        MPI_Sendrecv(&sendbuf, 1, MPI_INT, 0, tag,
                     &recvbuf, 1, MPI_INT, 0, tag,
                     MPI_COMM_WORLD, &status);
    }

    // Print the result of the exchange
    printf("Process %d sent %d and received %d from process %d\n",
           rank, sendbuf, recvbuf, status.MPI_SOURCE);

    MPI_Finalize();
    return 0;
}
