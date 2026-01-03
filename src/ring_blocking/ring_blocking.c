#include <stdio.h>
#include <mpi.h>

/*
 * ring_blocking.c
 * Demonstrates blocking point-to-point communication in a ring topology.
 * This version may deadlock because all processes call MPI_Send before MPI_Recv.
 */

int main(int argc, char **argv) {
    int rank, size;
    int sendbuf, recvbuf;
    int succ, pred;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    succ = (rank + 1) % size;
    pred = (rank - 1 + size) % size;

    sendbuf = rank;

    printf("Process %d sending %d to process %d\n", rank, sendbuf, succ);
    MPI_Send(&sendbuf, 1, MPI_INT, succ, 0, MPI_COMM_WORLD);

    MPI_Recv(&recvbuf, 1, MPI_INT, pred, 0, MPI_COMM_WORLD, &status);
    printf("Process %d received %d from process %d\n", rank, recvbuf, pred);

    MPI_Finalize();
    return 0;
}
