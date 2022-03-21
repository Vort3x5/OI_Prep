import random as rd
import sys

global to_push

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
    global z_count
    
    n = rd.randint(1, 16)
    q = rd.randint(1, 16)

    tree.clear()
    qs.clear()

    to_push = []

    z_count = 0
    for i in range(n):
        tree.append(rd.randint(0, 10))
        if tree[i] == 0:
            z_count += 1
    if z_count == 0:
        for i in range(3):
            tree[rd.randint(0, n - 1)] = 0

    for i in range(q):
        type = (rd.randint(1, 2))
        
        to_push.append(type)
        if (type == 1):
            to_push.append(rd.randint(1, n - 1))
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
