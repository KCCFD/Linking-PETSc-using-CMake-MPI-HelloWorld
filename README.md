# Linking-PETSc-using-CMake
This project shows how to link PETSc library using CMake. Following steps show how to build PETSc library as a non-root user and how to link the library to the project. 
Example code: HelloWorld.cpp

PETSc install in $HOME:
Step 1: Follow the steps as provided in the website:
```
https://petsc.org/release/install/download/
```

Download through terminal:
```
git clone -b release https://gitlab.com/petsc/petsc.git petsc
```

Step 2: Configure PETSc:
```
./configure --with-cc=gcc --with-cxx=g++ --with-fc=gfortran --download-f2cblaslapack --download-mpich
```

-> follow the instructions in the terminal and make + makeinstall PETSc
-> edit the .bashrc file by exporting the path to directories $PETSC_DIR and $PETSC_ARCH (if necessary)
```
export PETSC_DIR=/<home>/<user>/petsc
export PETSC_ARCH=arch-linux-c-debug
```

Step 3: Search for the shared object file (.so) "libpetsc.so". In my case it was in:
"${PETSC_DIR}/${PETSC_ARCH}/lib/libpetsc.so"

Step 4: Goto the build folder of the project and copy-paste the following:
```
cmake \
-DCMAKE_C_COMPILER=${PETSC_DIR}/${PETSC_ARCH}/bin/mpicc \
-DCMAKE_CXX_COMPILER=${PETSC_DIR}/${PETSC_ARCH}/bin/mpicxx \
-DPETSCINC=${PETSC_DIR}/include \
-DPETSCLIB=${PETSC_DIR}/${PETSC_ARCH}/lib/libpetsc.so \
../src
```

Step 5:
```
make
```
 Compilation done if successful. Thanks!!!
 
Step 6: 
Run:
```
$PETSC_DIR/$PETSC_ARCH/bin/mpirun -n <nprocs> ./HelloWorld
```






