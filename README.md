# OS-Project2

# Bankers Algorithm

Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?

 # What is the Banker's algorithm?

The bankers algorithm consists of multiple instances of which each process must claim a maximum use. When a process requests a resource it may need to wait until a different process returns its resources. There's some terms we need to cover. A resource can be available if there are enough resources to allocate to the different processes. Max is the maximum amount of resources the resource matrix can hold. Allocation is the matrix of resources which are distributed to complete the task. Lastly need is the matrix of the resources needed to complete the task. There are 2 subalgorithms within the bankers algorithm called the Safety algorithm and the resource request algorithm. 
Let's start with the Safety algorithm. It is used to determine the safety of the system. We first need to set work as available. Next we need to check the availability of resources as long as finish is false. When finish becomes true then the system is considered to be safe. 
The resource request algorithm is used to determine when to allocate resources according to the behavior of the system. If the need is greater than or equal to the request and if the resources available are greater or equal to the requested resources then the requested resource is available for use by the process that requested it. These two algorithms work together in order to solve the issues of resource allocation for different processes. 

 # How to run?
 Compile:
g++ -o main main.cpp
Run:
./main

# Data Table
This is the data table:

|Process	|Allocation	|Max	    |Available|
| ----------|---------- |-----------|-------- |
|P0	    |0 1 0	    |7 5 3	|3 3 2|
|P1	 |   2 0 0	 |   3 2 2	|
|P2	 |   3 0 2	 |   9 0 2	|
|P3	  |  2 1 1	  |  2 2 2	|
|P4	 |   0 0 2	   | 4 3 3	|
I converted the above table into a .txt file:
0 1 0 7 5 3 3 3 2
2 0 0 3 2 2
3 0 2 9 0 2
2 1 1 2 2 2
0 0 2 4 3 3
