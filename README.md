# CS375-Final-Project
Implement a hash table with the three different open addressing methods we discussed in class, to investigate how they affect the runtime of the insert, search and delete functions, and the number of collisions each function encounters. We will write our code from scratch to implement a hash table data structure, insert(), search(), and delete() functions for the different open addressing methods (linear probing, quadratic probing and double hashing). We will conduct tests for our different functions using various input sizes, prime table sizes(11, 29, 101), and load factors(40%, 60%, 80%) to ensure our sample size is sufficient. We will time all of our experiments and record the number of collisions to see which of the open addressing methods prove most effective. Specifically, we would like to find out (a) how large of an input size is needed to see a difference in runtime and number of collisions, and (b) how table size effects runtime and number of collisions.


For more information refer to our presentation: Open Addressing Methods for Hash Tables


---
# Running
make
Before running, data.csv should be 2 lines only. First line untouch and 2nd line newline character. This will create a excel representation of cell by cell data after run
single run "./test" after compiling
50 test run -> "make target"


---
# Files
1.Hash.h/Hash.cpp - Implementation of open addressing methohds, insert(), search(), delete()
2.Driver.cpp - Generates test cases and data.cvs with results
3.dataExcel.xlsx - Generate graphs from data.cvs


---
