import random as rd
import sys

def ZerCount(arr, a, b):
    res = 0
    for i in range(a - 1, b):
        res += not(arr[i])
    return res

def Gen(N):
    for i in range(N):
        with open("In/Inpts" + str(i + 1) + ".in", "w+") as In:
            n = rd.randint(1, 12)
            q = rd.randint(1, 10)
            arr = list()
            In.write(str(n) + ' ' + str(q) + '\n')
            for j in range(n):
                arr.append(rd.randint(0, 1))
                In.write(str(arr[j]) + ' ')
            In.write('\n')
            for j in range(q):
                qr = rd.randint(1, 2)
                a = rd.randint(1, n)
                if qr == 1:
                    x = rd.randint(0, 1)
                    arr[a - 1] = x
                    In.write(str(qr) + ' ' + str(a) + ' ' + str(x) + '\n')
                elif qr == 2:
                    b = 0
                    if a < n:
                        b = rd.randint(a, n)
                    else:
                        b = n
                    zer = ZerCount(arr, a, b)
                    if zer:
                        k = rd.randint(1, zer)
                        In.write(str(qr) + ' ' + str(a) + ' ' + str(b) + ' ' + str(k) + '\n')
                    else:
                        x = rd.randint(0, 1)
                        arr[a - 1] = x
                        In.write("1 " + str(a) + ' ' + str(x) + '\n')


Gen(int(sys.argv[1]))
