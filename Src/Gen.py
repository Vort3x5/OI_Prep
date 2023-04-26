import random as rd
import sys

def Gen(N):
    for i in range(N):
        with open("In/Inputs" + str(i + 1) + ".in", "w+") as In:
            n = rd.randint(8, 20)
            m = rd.randint(1, n)
            In.write(str(n) + ' ' + str(m) + '\n')
            for j in range(m):
                l = rd.randint(0, 1)
                num = rd.randint(1, n)
                if l:
                    In.write("D " + str(num) + '\n')
                    n -= 1
                else:
                    In.write("L " + str(num) + '\n')

Gen(int(sys.argv[1]))
