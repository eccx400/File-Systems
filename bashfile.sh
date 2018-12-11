#!/bin/bash
echo "first test"
(/bin/time ./randread /local/weka/1G.bat) 2> randread1Gtime.txt
(/bin/time ./randread /local/weka/1G.bat) 2>> randread1Gtime.txt
(/bin/time ./randread /local/weka/1G.bat) 2>> randread1Gtime.txt
echo "second test"
(/bin/time ./randread /local/weka/2500M.bat) 2> randread2.5Gtime.txt
(/bin/time ./randread /local/weka/2500M.bat) 2>> randread2.5Gtime.txt
(/bin/time ./randread /local/weka/2500M.bat) 2>> randread2.5Gtime.txt
echo "third test"
(/bin/time ./randread /local/weka/5G.bat) 2> randread5Gtime.txt
(/bin/time ./randread /local/weka/5G.bat) 2>> randread5Gtime.txt
(/bin/time ./randread /local/weka/5G.bat) 2>> randread5Gtime.txt
