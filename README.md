# Problem Solver

# Description

In this program, we deal with provding a solution for a problem given to us. We are given a problem as input, and we return the solution for the problem.

# Input/Output

As input, we need to be provided with a problem, which in our case is a Matrix, where each cell represents a certain value(state). Each line in the matrix will be seperated by a /n. In addition to the matrix, there needs to be 3 additional lines, 2 which tell us the start point and the finish point of the matrix, and the last line has the word "end" which tells us to stop reading the file. The output, will be the fastest way to get from the start point to the goal point in the matrix (in essence we are solving a maze). 



 # How To Compile/Run
 
In order for the code to compile, the program needs to be provided with a socket to enable us to create a certain stream that will connect with our program and in that stream we will be sent a file that holds the matrix. 

To compile from the command line use: 

g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread  

 

 # How The Program Works
 
 We will have 10 clients connecting to our program, and each client(user) will send us a text file that has the information of the matrix that we need to solve. Our program will interpret the text file to a  matrix, where each cell holds a state. Each state we will have a cost, its place, and where it came from. After interpreting the matrix, we will run a the Astar algorithm, which we know is the best one out of all the rest(BFS,DFS,AStar,BestFirstSearch) in order to find the fastest path from the start to the finish. After we have the solution, we  will save it in a cache (the cache has a certain capacity) in order to get quick access to the solution.  Once the cache is full and we want to add to it, we will move one of the solutions into a file cache, where we will now save the sloution. For a problem given to us, we will search to see if we have the solution in the cache (faster to find), or in the file cache (takes longer to find), and if not, we will find a new solution for the problem. We will return the solution that we find.
 
  # Link To Github
  
https://github.com/4yonatan4/ex4
