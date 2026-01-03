# MPI Sendrecv (Deadlock-Free Exchange)

This example demonstrates bidirectional point-to-point communication using `MPI_Sendrecv`.

`MPI_Sendrecv` performs a send and a receive operation in a single call, which helps avoid deadlocks in pairwise exchanges.

This example shows how `MPI_Sendrecv` can be used to safely exchange data between two processes without requiring a strict send/receive ordering.

## Compile

mpicc sendrecv.c -o sendrecv

## Run

mpirun -np 2 ./sendrecv
