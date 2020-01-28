# ex4 - Problem Solver

# Description

In this program, we deal with provding a solution for a problem given to us. We are given a problem as input, and we return the solution for the problem.

# Input/Output

As input, we need to be provided with a problem, which in our case is a Matrix, where each cell represents a certain value. Each line in the matrix will be seperated by a /n. In addition to the matrix, there needs to be 2 additional lines, which tell us the start point and the finish point of the matrix.


 
 # How To Compile
 
In order for the code to compile, the program needs to be provided with a text file that list all of the commands of the flight simulator. This file should be provided as a program argument. 

To compile from the command line use: 
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread 

 # How To Run the Program
 
In order for the program to run and work correctly, after compiling and running the program  
run the FlightGear application, in order to make a connection with the program. Once a successful connection is obtained, after a few moments, the plane should start to move, and soon thereafter, takeoff and fly. 

 # How The Program Works
 
 We first read the text file that is given to us and interpret the commands so we can use them. We are also going to have 3 threads running at the same time. One is the main, which runs the program, the second is a thread that maintains a connection with the server(which is the FlighGear program which we run after compiling our code) which sends commands to the server, in order to update the values in the server,  and the third is also in connection with the server, where the server updates our values. The constant communication with these threads enables a sharing of information between our program and the FlightGear, that enables the plane to fly. 
 
  # Link To Github
  
  https://github.com/fe1493/PleaseWork
