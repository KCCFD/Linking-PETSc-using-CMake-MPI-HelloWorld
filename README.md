# Linking-PETSc-using-CMake
This project shows how to link PETSc library using CMake. Following steps show how to build PETSc library as a non-root user and how to link the library to the project. 
Example code: HelloWorld.cpp

PETSc builind:
Step 1: Follow the steps as provided in the website:
https://petsc.org/release/install/download/

git clone -b release https://gitlab.com/petsc/petsc.git petsc

Step 2: Configure PETSc:
./configure --with-cc=gcc --with-cxx=g++ --with-fc=gfortran --download-f2cblaslapack --download-mpich





