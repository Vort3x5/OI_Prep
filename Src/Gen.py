import random as rd
import sys

def Gen(N):
    for i in range(N):
        with open("In/Inpts" + str(i + 1) + ".in", "w+") as In:
            n = rd.randint(1, 20)
            In.write(str(n) + '\n')
            for x in range(2):
                for j in range(n):
                    l = rd.randint(1, 2)
                    if l == 1:
                        In.write('a')
                    elif l == 2:
                        In.write('b')
                In.write('\n')
            q = rd.randint(1, 10)
            In.write(str(q) + '\n')
            for j in range(q):
                fst = rd.randint(0, n - 1)
                sec = rd.randint(0, n - 1)
                In.write(str(fst) + ' ' + str(sec) + '\n')

Gen(int(sys.argv[1]))
