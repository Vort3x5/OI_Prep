import random as rd
import sys

global tree
global to_push
global qs

tree = []
qs = []

def Are_Z0s(tree):
    for node in tree:
        if node == 0:
            return True
    return False

def Generate(tree, qs):
    global n
    global q
    
    n = rd.randint(1, 16)
    q = rd.randint(1, 16)

    tree.clear()
    qs.clear()

    to_push = []

    for i in range(n):
        tree.append(rd.randint(0, 10))

    for i in range(q):
        no_zero = True
        while no_zero:
            type = (rd.randint(1, 2))
            if type == 1:
                no_zero = False
            else:
                if (Are_Z0s(tree)):
                    no_zero = False
        
        to_push.append(type)
        if (type == 1):
            to_push.append(rd.randint(1, 16))
            to_push.append(rd.randint(0, 10))
        else:
            correct = False
            while not correct:
                a = rd.randint(1, n - 1)
                b = rd.randint(a, n - 1)
                rng = 0
                for j in range (a - 1, b):
                    if tree[j] == 0:
                        rng += 1
                if rng == 0:
                    continue
                else:
                    correct = True
                    to_push.append(a)
                    to_push.append(b)
                    to_push.append(rd.randint(1, rng))
    
        qs.append(tuple(to_push))
        to_push.clear()

def Write(tree, qs, N):
    i = 0
    while (i < N):
        Generate(tree, qs)
        if (Are_Z0s(tree)):
            with open("In/Inpts" + str(i) + ".in", "w+") as ins:
                ins.write(str(n) + ' ' + str(q) + '\n')
                for node in tree:
                    ins.write(str(node) + ' ')
                ins.write('\n')
                for qr in qs:
                    for a in qr:
                        ins.write(str(a) + ' ')
                    ins.write('\n')
            i += 1

Write(tree, qs, int(sys.argv[1]))
