The goal of this assignment is to investigate the performance of a computer's file system by running files of different sizes and analyzing the time for which they complete. The time will be given in three different forms; but for this lab, we will be focusing on the user (wall clock) time in order to determine the effectiveness of the CPU performance. The question we are attempting to answer could be described as: "How quickly can a file system handle requests from a user process?" This is rather vague, so specifically, you are expected to offer an answer for one question: "What is the impact of user workload on file system performance?" We will test the performance using files of sizes 1G, 2.5G, and 5G.

We will be approaching this question in two different ways. We will first create an algorithm that reads the data input sequentially, and another one that reads it randomly. We will name these files seqread.c and randread.c. But first, we must create the files for 1G, 2.5G, and 5G in the /local/weka directory. We do this by using the command "cat /dev/urandom|head-c filesize>local/weka/filesize". We can then use ls -l /local/weka to check that the files are created. Note that for the 2.5G file, we have to name the file as 2500M, because the file does not accept decimal inputs for the size. These files will be used to test the performance.

Looking at seqread.c, the algorithm in which we read each character bit by bit, we use the library stdio to allow us to get the files that we have to test. We do this by creating FILE * filename, and then use fopen to allow us to read in the characters in the file. We can then check to see if the file can open; if it doesn't, it will print a statement stating that the file cannot open. To read through the contents in the file, we make the condition so that while not end of file (meaning that there are still characters to be read), we still use fgetc to get the characters from the file reading each character one by one. When we reach the end of the file, we can close the input file.

For randread.c, we have to approach this differently. The file io is the same; we use fopen to open the file object that we create and initialize, and we can check to see whether the file can be opened or not. However, this time we have to store the data that is being read in a variable of type long long, since for the 5G file there are too many characters to be stored in type int or type long. We then read the content of the file and store it into the man variable. Now the man variable will hold the content of any file we would like to test, such as the 1G file, 2.5G file, or 5G file. So under the condition while the counter toorukun is less than the size of the man which holds the content of the file, we use a do while loop to randomize where we change the head so that we can read the file randomly. We must shift the bits left 32 bits so that it can cover the randomization of the whole 64 bits as represented by the long long size type. We then use the fseek() function to change the position to a new one. This ends when the fseek() function returns a non-zero number. Finally, when the counter (toorukun) is the same as man, that means every character in the input file has been read and that the file can be closed. In sum, This code should read all the contents of the given files.
 
The test results are listed below:
--------------------------------------------------------------------------------------------------------

seqread.c:

1G:
real: 0m6.034s
user: 0m5.777s
sys:  0m0.261s

real: 0m5.998s
user: 0m5.737s
sys:  0m0.261s

real: 0m6.114s
user: 0m5.873s
sys:  0m0.241s

AVERAGE TIME: 0m6.085s

2.5G:
real: 0m14.624s
user: 0m14.051s
sys:  0m0.570s

real: 0m14.674s
user: 0m14.147s
sys:  0m0.526s

real: 0m14.391s
user: 0m13.838s
sys:  0m0.552s


AVERAGE TIME: 0m14.563s

5G:
real: 0m30.760s 
user: 0m29.655s
sys:  0m1.092s

real: 0m29.612s
user: 0m28.485s
sys:  0m1.123s

real: 0m29.393s
user: 0m28.294s
sys:  0m1.098s


AVERAGE TIME: 0m29.922

-------------------------------------------------------------------------------------------------------

randread.c:

1G:
324.753 user 1621.524 system 0:32.25 elapsed 99%CPU
335.254 user 1634.428 system 0:32.48 elapsed 99%CPU
328.629 user 1625.812 system 0:32.31 elapsed 99%CPU


AVERAGE TIME: 0:32.35m

2.5G:
629.810 user 3141.643 system 1:02.56 elapsed 99%CPU
651.326 user 3224.064 system 1:04.35 elapsed 100%CPU
613.612 user 3037.379 system 1:00.51 elapsed 100%CPU


AVERAGE TIME: 1:02.28m

5G:
1348.294 user 6783.941 system 2:15.14 elapsed 99%CPU
1325.621 user 6764.842 system 2:14.51 elapsed 100%CPU
1355.890 user 6919.310 system 2:17.55 elapsed 99%CPU

AVERAGE TIME: 2:15.44m

-------------------------------------------------------------------------------------------------------

Relations Analysis:

Time difference between Sequential and Random reading algorithms:
The main answer that we must answer in this lab can be stated as "what is the impact of user workload on file system performance". Looking at the average time obtained for the 1G, 2.5G and 5G files for both the seqread.c and randread.c reveals major differences. It can be concluded that seqread.c has significantly less latency in job completion than randread.c, espcially when they are completing jobs with the same sizes. For example, the average time for the 1G file for the sequential analysis only took about 6 seconds, while the random read analysis took more than half an hour. The reason for the much longer performance time fo the random anaylsis could be because of the fact that for sequential read, since we are reading the characters into the files bit by bit, the program can easily continue the same function until it reaches the end of file. The program has a very linear function, and thus it is easy for the system call interface to proceed to the next request. However, for the random reading algorithm, for every character read there is a need to select a new random position to start reading the new characters, which creates an instant delay in time. The position must be adjusted before the next character can be read in the file. The cumulative time it takes to adjust the random position of the random read algorithm could be explained as the primary reason why the random reading algorithm is much slower in terms of performance than the sequential read anaylsis. Thus, the differences in request pattern has a significant impact on the performance of the system call interface in obtaining the user requests.

Time difference for both algorithms in terms of reading files of different sizes:
It can also be seen that between the 1G, 2.5G and 5G file, there were also major differences in the time needed for the system call interface to process the files. Looking at the sequential read times, for the 1G file, it took an average of 6 seconds to complete, while for the 2.5 G it took around 14 seconds, and for 5G it took about 29 seconds. Looking at the time, it can be said that the increase in file size made the sequential read program run roughly 2 times longer to complete the request. The same can be said about the random read algorithm. For 1G it took around 30 minutes, while for 2.5G it took around an hour for the process to complete, and for 5G it took roughtly 2 hours and 15 minutes, which also is around 2 times longer for the increase in file size.

