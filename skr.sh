#!/bin/bash
g++ -std=c++11 ./wzor.cpp -o wzor
g++ -std=c++11 ./gen.cpp -o gen
g++ -std=c++11 ./brut.cpp -o brut
for((j=1;;j++))
do
for i in ./tests/*.txt;
  do
    echo $j
    ./wzor < $i > ./tests/wzor.out
    ./brut < $i > ./tests/brut.out
    if ! diff -bq ./tests/wzor.out ./tests/brut.out &>/dev/null; then
       >&2 echo "different"
      break
    fi
  done
done
#   time -p (./wzor < ./tests/test_$i.in > ./tests/wzor_$i.out) 2> ./.time_info
#   PROG_TIME=`cat .time_info | grep real | cut -d" " -f2`;
#   echo $PROG_TIME
#g++ -std=c++11 ./wzor.cpp -o wzor
#g++ -std=c++11 ./gen.cpp -o gen
#g++ -std=c++11 ./brut.cpp -o brut
##for((i=1;i<=$1;i++)) do
##  ./gen $i > ./tests2/test_$i.in
##done
#for i in ./tests2/*.in;
#do
#  echo $i
#  ./wzor < $i > ./wzor_out/wzor.out
#	./brut < $i > ./brut_out/brut.out
#	if ! diff -bq ./wzor_out/wzor.out ./brut_out/brut.out &>/dev/null; then
#     >&2 echo "different"
#	  break
#	fi
#done
