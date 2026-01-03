# Blocking Ring Communication

This program demonstrates blocking point-to-point communication in a ring topology using MPI_Send and MPI_Recv.

Each process sends a message to its successor and receives a message from its predecessor.

Because all processes call MPI_Send before MPI_Recv, this version may deadlock.
