Multi-threaded Sorting with Bubble Sort
In this project, I've implemented a multi-threaded sorting algorithm using the Bubble Sort method, despite the advice not to from President Obama. The previous implementation was inefficient due to its O(n^2) time complexity. However, by leveraging multi-processing capabilities and pthreads, this assignment aims to substantially improve sorting times.

Description
Objective: Implement a parallel sorting algorithm using pthreads to speed up the sorting process.
Sorting Algorithm: Bubble Sort.
Concurrency Model: Multi-threading with pthreads.
Input: 1 million unsorted numbers from numbers.dat.
Output: A sorted array of 1 million numbers, written to a file.
Thread Configuration: Utilize 8 threads for sorting.
Sorting Process: Divide the array into 8 sections, each containing 125,000 numbers. Each section is sorted independently by a thread. After all threads finish sorting, merge adjacent sections until the entire array is sorted.

Files Included
mySort.cpp: Source code for the multi-threaded sorting program.
generate.cpp: Program to generate unsorted numbers.
sortrace.sh: Shell script to run the sorting program and verify the output.
sortrace.log: Log file containing sorting results.

How it Works
The program reads 1 million unsorted numbers from numbers.dat into an array.
The array is logically split into 8 sections, each with 125,000 numbers.
Eight threads are created using pthread_create(), each responsible for sorting a section of the array.
After sorting, adjacent sections are merged into larger sorted sections until the entire array is sorted.
The sorted array is printed to a file.
The shell script sortrace.sh is executed to verify the sorting results.

Additional Notes
The sorting function bubble() used in this program is bubble sort algorithm
To bridge between pthreads and the sorting function, a bridge function is created to call bubble().
Results
Upon execution, the program demonstrates a substantial improvement in sorting times compared to the previous implementation. A screenshot of the results from executing sortrace.sh will be submitted along with the source code and other required files.
