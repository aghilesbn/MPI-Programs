# MPI Send / Receive (Blocking)

This example demonstrates basic point-to-point communication using `MPI_Send` and `MPI_Recv`.

The communication is blocking:  
- `MPI_Recv` blocks until the message is received.  
- `MPI_Send` may block depending on the message size and the MPI implementation.

This example illustrates how simple blocking communication works and why improper ordering can lead to deadlocks.

## Compile

mpicc send_recv.c -o send_recv

## Run

mpirun -np 2 ./send_recv
