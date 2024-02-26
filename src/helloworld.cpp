/* This is the main function to call helloworld by MPI uing PETSc */

#include<bits/stdc++.h>
#include <petsc.h>

int main( int argc,char **argv )
{

PetscErrorCode ierr;
PetscMPIInt rank;

PetscInitialize(&argc,&argv,PETSC_NULLPTR,PETSC_NULLPTR);

ierr = MPI_Comm_rank(PETSC_COMM_WORLD, &rank);CHKERRQ(ierr);

PetscCallMPI(MPI_Comm_rank(PETSC_COMM_WORLD, &rank));


PetscPrintf(PETSC_COMM_SELF,"Hello World from : \t %d\n",rank);
return PetscFinalize();
}

