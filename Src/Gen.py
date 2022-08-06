import random as rd
import sys

def Gen(N):
    for num in range(N):
        with open("In/Inpts" + str(num + 1) + ".in", "w+") as In:
            In.write("1\n10\n")
            for i in range(10):
                j = rd.randint(0, 9999999999)
                In.write(str(j) + '\n')

Gen(int(sys.argv[1]))
