# Frequently Asked Questions

- [Frequently Asked Questions](#frequently-asked-questions)
  - [I don't know from where to start?](#i-dont-know-from-where-to-start)
  - [I am getting into a lot of segmentation faults, what should I do?](#i-am-getting-into-a-lot-of-segmentation-faults-what-should-i-do)
  - [How to push the code to the repository?](#how-to-push-the-code-to-the-repository)
  - [I want to run the test cases locally](#i-want-to-run-the-test-cases-locally)

## I don't know from where to start?

Follow the following implementation order,

1. Constructor
2. Getter and Setter
3. Comparison operator
4. Addition and Subtraction operator
5. Multiplication operator

## I am getting into a lot of segmentation faults, what should I do?

This is most probably caused by the incorrect implementation of getter/setter. A word of advice would be to avoid using the `elements` vector directly instead use the getter and setter. This will help you in debugging the code.

## How to push the code to the repository?

First of all, make sure you are the root of the git repository. Then run the following commands,

```bash
git add .
git commit -m "Your message"
git push
```

## I want to run the test cases locally

The prerequisite for running the test cases locally is to have [CMake][CMake] and [`gtest`][gtest] installed on your machine.

1. **Windows**

   If you are using Windows then install [`gtest`][gtest] locally which is a tedious process. For this you can follow [Google Test Installation Guide for C++ in Windows (for Visual Studio Code)](https://medium.com/swlh/google-test-installation-guide-for-c-in-windows-for-visual-studio-code-2b2e66352456). Another much easier way is to use [WSL][WSL] and follow the Linux/WSL installation guide.

2. **Linux/WSL**

   Installing [`gtest`][gtest] on Linux is much easier. Run the following commands,

   ```bash
   sudo apt update
   sudo apt install libgtest-dev
   ```

3. **MacOS**

    A StackOverflow [answer](https://stackoverflow.com/a/76695155/26167473) for installing [`gtest`][gtest] on MacOS is as follows,

   ```bash
   brew install googletest
   ```

After installing the [`gtest`][gtest] library, you can run the test cases using the following commands,

```bash
cmake -Bbuild # to generate the build files
cmake --build build # to build the project
ctest --test-dir build -VV --progress --output-on-failure # to run the test cases
```

<details><summary>Output</summary>
<p>

```bash
(base) gradf@beepboop:/media/gradf/hw3$ cmake -Bbuild
-- The CXX compiler identification is GNU 12.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found GTest: /usr/lib/x86_64-linux-gnu/cmake/GTest/GTestConfig.cmake (found version "1.12.1")
-- Configuring done
-- Generating done
-- Build files have been written to: /media/gradf/hw3/build
(base) gradf@beepboop:/media/gradf/hw3$ cmake --build build
[ 10%] Building CXX object CMakeFiles/MatrixAlgebraSystem.dir/src/DiagonalMatrix.cpp.o
[ 20%] Building CXX object CMakeFiles/MatrixAlgebraSystem.dir/src/Matrix.cpp.o
[ 30%] Building CXX object CMakeFiles/MatrixAlgebraSystem.dir/src/SquareMatrix.cpp.o
[ 40%] Building CXX object CMakeFiles/MatrixAlgebraSystem.dir/src/LowerTriangularMatrix.cpp.o
[ 50%] Building CXX object CMakeFiles/MatrixAlgebraSystem.dir/src/UpperTriangularMatrix.cpp.o
[ 60%] Linking CXX static library libMatrixAlgebraSystem.a
[ 60%] Built target MatrixAlgebraSystem
[ 70%] Building CXX object tests/CMakeFiles/DefaultTests.dir/testDefaults.cpp.o
[ 80%] Linking CXX executable DefaultTests
[ 80%] Built target DefaultTests
[ 90%] Building CXX object tests/CMakeFiles/OperationsTests.dir/testOperations.cpp.o
[100%] Linking CXX executable OperationsTests
[100%] Built target OperationsTests
(base) gradf@beepboop:/media/gradf/hw3$ ctest --test-dir build -VV --progress --output-on-failure
Internal ctest changing into directory: /media/gradf/hw3/build
UpdateCTestConfiguration  from :/media/gradf/hw3/build/DartConfiguration.tcl
UpdateCTestConfiguration  from :/media/gradf/hw3/build/DartConfiguration.tcl
Test project /media/gradf/hw3/build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: DefaultTests

1: Test command: /media/gradf/hw3/build/tests/DefaultTests
1: Working Directory: /media/gradf/hw3/build/tests
1: Test timeout computed to be: 10000000
1: Running main() from ./googletest/src/gtest_main.cc
1: [==========] Running 105 tests from 1 test suite.
1: [----------] Global test environment set-up.
1: [----------] 105 tests from DefaultMatrix
1: [ RUN      ] DefaultMatrix.DiagonalMatrixConstructor/0
1: [       OK ] DefaultMatrix.DiagonalMatrixConstructor/0 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixConstructor/1
1: [       OK ] DefaultMatrix.DiagonalMatrixConstructor/1 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixConstructor/2
1: [       OK ] DefaultMatrix.DiagonalMatrixConstructor/2 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixConstructor/3
1: [       OK ] DefaultMatrix.DiagonalMatrixConstructor/3 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixConstructor/4
1: [       OK ] DefaultMatrix.DiagonalMatrixConstructor/4 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixConstructor/5
1: [       OK ] DefaultMatrix.DiagonalMatrixConstructor/5 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixConstructor/6
1: [       OK ] DefaultMatrix.DiagonalMatrixConstructor/6 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixConstructor/0
1: [       OK ] DefaultMatrix.LowerTriangularMatrixConstructor/0 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixConstructor/1
1: [       OK ] DefaultMatrix.LowerTriangularMatrixConstructor/1 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixConstructor/2
1: [       OK ] DefaultMatrix.LowerTriangularMatrixConstructor/2 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixConstructor/3
1: [       OK ] DefaultMatrix.LowerTriangularMatrixConstructor/3 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixConstructor/4
1: [       OK ] DefaultMatrix.LowerTriangularMatrixConstructor/4 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixConstructor/5
1: [       OK ] DefaultMatrix.LowerTriangularMatrixConstructor/5 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixConstructor/6
1: [       OK ] DefaultMatrix.LowerTriangularMatrixConstructor/6 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixConstructor/0
1: [       OK ] DefaultMatrix.MatrixConstructor/0 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixConstructor/1
1: [       OK ] DefaultMatrix.MatrixConstructor/1 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixConstructor/2
1: [       OK ] DefaultMatrix.MatrixConstructor/2 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixConstructor/3
1: [       OK ] DefaultMatrix.MatrixConstructor/3 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixConstructor/4
1: [       OK ] DefaultMatrix.MatrixConstructor/4 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixConstructor/5
1: [       OK ] DefaultMatrix.MatrixConstructor/5 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixConstructor/6
1: [       OK ] DefaultMatrix.MatrixConstructor/6 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixConstructor/0
1: [       OK ] DefaultMatrix.SquareMatrixConstructor/0 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixConstructor/1
1: [       OK ] DefaultMatrix.SquareMatrixConstructor/1 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixConstructor/2
1: [       OK ] DefaultMatrix.SquareMatrixConstructor/2 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixConstructor/3
1: [       OK ] DefaultMatrix.SquareMatrixConstructor/3 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixConstructor/4
1: [       OK ] DefaultMatrix.SquareMatrixConstructor/4 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixConstructor/5
1: [       OK ] DefaultMatrix.SquareMatrixConstructor/5 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixConstructor/6
1: [       OK ] DefaultMatrix.SquareMatrixConstructor/6 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixConstructor/0
1: [       OK ] DefaultMatrix.UpperTriangularMatrixConstructor/0 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixConstructor/1
1: [       OK ] DefaultMatrix.UpperTriangularMatrixConstructor/1 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixConstructor/2
1: [       OK ] DefaultMatrix.UpperTriangularMatrixConstructor/2 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixConstructor/3
1: [       OK ] DefaultMatrix.UpperTriangularMatrixConstructor/3 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixConstructor/4
1: [       OK ] DefaultMatrix.UpperTriangularMatrixConstructor/4 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixConstructor/5
1: [       OK ] DefaultMatrix.UpperTriangularMatrixConstructor/5 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixConstructor/6
1: [       OK ] DefaultMatrix.UpperTriangularMatrixConstructor/6 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixGetElement/0
1: [       OK ] DefaultMatrix.DiagonalMatrixGetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixGetElement/1
1: [       OK ] DefaultMatrix.DiagonalMatrixGetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixGetElement/2
1: [       OK ] DefaultMatrix.DiagonalMatrixGetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixGetElement/3
1: [       OK ] DefaultMatrix.DiagonalMatrixGetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixGetElement/4
1: [       OK ] DefaultMatrix.DiagonalMatrixGetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixGetElement/5
1: [       OK ] DefaultMatrix.DiagonalMatrixGetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixGetElement/6
1: [       OK ] DefaultMatrix.DiagonalMatrixGetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixGetElement/0
1: [       OK ] DefaultMatrix.LowerTriangularMatrixGetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixGetElement/1
1: [       OK ] DefaultMatrix.LowerTriangularMatrixGetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixGetElement/2
1: [       OK ] DefaultMatrix.LowerTriangularMatrixGetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixGetElement/3
1: [       OK ] DefaultMatrix.LowerTriangularMatrixGetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixGetElement/4
1: [       OK ] DefaultMatrix.LowerTriangularMatrixGetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixGetElement/5
1: [       OK ] DefaultMatrix.LowerTriangularMatrixGetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixGetElement/6
1: [       OK ] DefaultMatrix.LowerTriangularMatrixGetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixGetElement/0
1: [       OK ] DefaultMatrix.MatrixGetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixGetElement/1
1: [       OK ] DefaultMatrix.MatrixGetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixGetElement/2
1: [       OK ] DefaultMatrix.MatrixGetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixGetElement/3
1: [       OK ] DefaultMatrix.MatrixGetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixGetElement/4
1: [       OK ] DefaultMatrix.MatrixGetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixGetElement/5
1: [       OK ] DefaultMatrix.MatrixGetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixGetElement/6
1: [       OK ] DefaultMatrix.MatrixGetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixGetElement/0
1: [       OK ] DefaultMatrix.SquareMatrixGetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixGetElement/1
1: [       OK ] DefaultMatrix.SquareMatrixGetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixGetElement/2
1: [       OK ] DefaultMatrix.SquareMatrixGetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixGetElement/3
1: [       OK ] DefaultMatrix.SquareMatrixGetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixGetElement/4
1: [       OK ] DefaultMatrix.SquareMatrixGetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixGetElement/5
1: [       OK ] DefaultMatrix.SquareMatrixGetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixGetElement/6
1: [       OK ] DefaultMatrix.SquareMatrixGetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixGetElement/0
1: [       OK ] DefaultMatrix.UpperTriangularMatrixGetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixGetElement/1
1: [       OK ] DefaultMatrix.UpperTriangularMatrixGetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixGetElement/2
1: [       OK ] DefaultMatrix.UpperTriangularMatrixGetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixGetElement/3
1: [       OK ] DefaultMatrix.UpperTriangularMatrixGetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixGetElement/4
1: [       OK ] DefaultMatrix.UpperTriangularMatrixGetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixGetElement/5
1: [       OK ] DefaultMatrix.UpperTriangularMatrixGetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixGetElement/6
1: [       OK ] DefaultMatrix.UpperTriangularMatrixGetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixSetElement/0
1: [       OK ] DefaultMatrix.DiagonalMatrixSetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixSetElement/1
1: [       OK ] DefaultMatrix.DiagonalMatrixSetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixSetElement/2
1: [       OK ] DefaultMatrix.DiagonalMatrixSetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixSetElement/3
1: [       OK ] DefaultMatrix.DiagonalMatrixSetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixSetElement/4
1: [       OK ] DefaultMatrix.DiagonalMatrixSetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixSetElement/5
1: [       OK ] DefaultMatrix.DiagonalMatrixSetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.DiagonalMatrixSetElement/6
1: [       OK ] DefaultMatrix.DiagonalMatrixSetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixSetElement/0
1: [       OK ] DefaultMatrix.LowerTriangularMatrixSetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixSetElement/1
1: [       OK ] DefaultMatrix.LowerTriangularMatrixSetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixSetElement/2
1: [       OK ] DefaultMatrix.LowerTriangularMatrixSetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixSetElement/3
1: [       OK ] DefaultMatrix.LowerTriangularMatrixSetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixSetElement/4
1: [       OK ] DefaultMatrix.LowerTriangularMatrixSetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixSetElement/5
1: [       OK ] DefaultMatrix.LowerTriangularMatrixSetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.LowerTriangularMatrixSetElement/6
1: [       OK ] DefaultMatrix.LowerTriangularMatrixSetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixSetElement/0
1: [       OK ] DefaultMatrix.MatrixSetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixSetElement/1
1: [       OK ] DefaultMatrix.MatrixSetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixSetElement/2
1: [       OK ] DefaultMatrix.MatrixSetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixSetElement/3
1: [       OK ] DefaultMatrix.MatrixSetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixSetElement/4
1: [       OK ] DefaultMatrix.MatrixSetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixSetElement/5
1: [       OK ] DefaultMatrix.MatrixSetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.MatrixSetElement/6
1: [       OK ] DefaultMatrix.MatrixSetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixSetElement/0
1: [       OK ] DefaultMatrix.SquareMatrixSetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixSetElement/1
1: [       OK ] DefaultMatrix.SquareMatrixSetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixSetElement/2
1: [       OK ] DefaultMatrix.SquareMatrixSetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixSetElement/3
1: [       OK ] DefaultMatrix.SquareMatrixSetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixSetElement/4
1: [       OK ] DefaultMatrix.SquareMatrixSetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixSetElement/5
1: [       OK ] DefaultMatrix.SquareMatrixSetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.SquareMatrixSetElement/6
1: [       OK ] DefaultMatrix.SquareMatrixSetElement/6 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixSetElement/0
1: [       OK ] DefaultMatrix.UpperTriangularMatrixSetElement/0 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixSetElement/1
1: [       OK ] DefaultMatrix.UpperTriangularMatrixSetElement/1 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixSetElement/2
1: [       OK ] DefaultMatrix.UpperTriangularMatrixSetElement/2 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixSetElement/3
1: [       OK ] DefaultMatrix.UpperTriangularMatrixSetElement/3 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixSetElement/4
1: [       OK ] DefaultMatrix.UpperTriangularMatrixSetElement/4 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixSetElement/5
1: [       OK ] DefaultMatrix.UpperTriangularMatrixSetElement/5 (0 ms)
1: [ RUN      ] DefaultMatrix.UpperTriangularMatrixSetElement/6
1: [       OK ] DefaultMatrix.UpperTriangularMatrixSetElement/6 (0 ms)
1: [----------] 105 tests from DefaultMatrix (0 ms total)
1:
1: [----------] Global test environment tear-down
1: [==========] 105 tests from 1 test suite ran. (0 ms total)
1: [  PASSED  ] 105 tests.
1/2 Test #1: DefaultTests .....................   Passed    0.01 sec
test 2
    Start 2: OperationsTests

2: Test command: /media/gradf/hw3/build/tests/OperationsTests
2: Working Directory: /media/gradf/hw3/build/tests
2: Test timeout computed to be: 10000000
2: Running main() from ./googletest/src/gtest_main.cc
2: [==========] Running 336 tests from 1 test suite.
2: [----------] Global test environment set-up.
2: [----------] 336 tests from SameShapeOperations
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixAddDiagonalMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixAddLowerTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixAddSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixAddUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddLowerTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixAddUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixAddMatrix/0
2: [       OK ] SameShapeOperations.MatrixAddMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixAddMatrix/1
2: [       OK ] SameShapeOperations.MatrixAddMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixAddMatrix/2
2: [       OK ] SameShapeOperations.MatrixAddMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixAddMatrix/3
2: [       OK ] SameShapeOperations.MatrixAddMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixAddMatrix/4
2: [       OK ] SameShapeOperations.MatrixAddMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixAddMatrix/5
2: [       OK ] SameShapeOperations.MatrixAddMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixAddMatrix/6
2: [       OK ] SameShapeOperations.MatrixAddMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixAddDiagonalMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddSquareMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixAddSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddSquareMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixAddSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddSquareMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixAddSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddSquareMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixAddSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddSquareMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixAddSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddSquareMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixAddSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddSquareMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixAddSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixAddUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.UpperTriangularMatrixAddUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixSubDiagonalMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixSubLowerTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixSubSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixSubUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubLowerTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixSubUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixSubMatrix/0
2: [       OK ] SameShapeOperations.MatrixSubMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixSubMatrix/1
2: [       OK ] SameShapeOperations.MatrixSubMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixSubMatrix/2
2: [       OK ] SameShapeOperations.MatrixSubMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixSubMatrix/3
2: [       OK ] SameShapeOperations.MatrixSubMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixSubMatrix/4
2: [       OK ] SameShapeOperations.MatrixSubMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixSubMatrix/5
2: [       OK ] SameShapeOperations.MatrixSubMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixSubMatrix/6
2: [       OK ] SameShapeOperations.MatrixSubMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixSubDiagonalMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubSquareMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixSubSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubSquareMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixSubSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubSquareMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixSubSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubSquareMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixSubSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubSquareMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixSubSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubSquareMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixSubSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubSquareMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixSubSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixSubUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.UpperTriangularMatrixSubUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixMulDiagonalMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixMulLowerTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixMulSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixMulUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulLowerTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixMulUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixMulMatrix/0
2: [       OK ] SameShapeOperations.MatrixMulMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixMulMatrix/1
2: [       OK ] SameShapeOperations.MatrixMulMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixMulMatrix/2
2: [       OK ] SameShapeOperations.MatrixMulMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixMulMatrix/3
2: [       OK ] SameShapeOperations.MatrixMulMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixMulMatrix/4
2: [       OK ] SameShapeOperations.MatrixMulMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixMulMatrix/5
2: [       OK ] SameShapeOperations.MatrixMulMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixMulMatrix/6
2: [       OK ] SameShapeOperations.MatrixMulMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixMulDiagonalMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulSquareMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixMulSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulSquareMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixMulSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulSquareMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixMulSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulSquareMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixMulSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulSquareMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixMulSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulSquareMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixMulSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulSquareMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixMulSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixMulUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.UpperTriangularMatrixMulUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixEqDiagonalMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixEqLowerTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixEqSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.DiagonalMatrixEqUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqLowerTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.LowerTriangularMatrixEqUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixEqMatrix/0
2: [       OK ] SameShapeOperations.MatrixEqMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixEqMatrix/1
2: [       OK ] SameShapeOperations.MatrixEqMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixEqMatrix/2
2: [       OK ] SameShapeOperations.MatrixEqMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixEqMatrix/3
2: [       OK ] SameShapeOperations.MatrixEqMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixEqMatrix/4
2: [       OK ] SameShapeOperations.MatrixEqMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixEqMatrix/5
2: [       OK ] SameShapeOperations.MatrixEqMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.MatrixEqMatrix/6
2: [       OK ] SameShapeOperations.MatrixEqMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixEqDiagonalMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqSquareMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixEqSquareMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqSquareMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixEqSquareMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqSquareMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixEqSquareMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqSquareMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixEqSquareMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqSquareMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixEqSquareMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqSquareMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixEqSquareMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqSquareMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixEqSquareMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.SquareMatrixEqUpperTriangularMatrix/6 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/0
2: [       OK ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/0 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/1
2: [       OK ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/1 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/2
2: [       OK ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/2 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/3
2: [       OK ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/3 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/4
2: [       OK ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/4 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/5
2: [       OK ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/5 (0 ms)
2: [ RUN      ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/6
2: [       OK ] SameShapeOperations.UpperTriangularMatrixEqUpperTriangularMatrix/6 (0 ms)
2: [----------] 336 tests from SameShapeOperations (4 ms total)
2:
2: [----------] Global test environment tear-down
2: [==========] 336 tests from 1 test suite ran. (4 ms total)
2: [  PASSED  ] 336 tests.
2/2 Test #2: OperationsTests ..................   Passed    0.02 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.03 sec
```

</p>
</details>

[gtest]: https://github.com/google/googletest
[CMake]: https://cmake.org
[WSL]: https://learn.microsoft.com/en-us/windows/wsl
