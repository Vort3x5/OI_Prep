import subprocess as proc
import sys

def Compile():
    try:
        proc.run(["g++", "K0.cpp", "-o", "bin/main"], check=True)
    except proc.CalledProcessError:
        print("Compilation of main failed")
        exit(1)
    
    try:
        proc.run(["g++", "Brut.cpp", "-o", "bin/brut"], check=True)
    except proc.CalledProcessError:
        print("Compilation of brut failed")
        exit(1)

def MakeCases(N):
    proc.run(["python3", "clear_tests.py"])
    proc.run(["python3", "Gen.py", str(N)])
    for i in range (N):
        with open("In/Inpts" + str(i) + ".in") as f:
            ins = f.read()
            ins = ins.strip()
        
        with open("Given_Out/G_Res" + str(i) + ".out") as f:
            proc.run(["cmd >>", f.name])
       
        proc.run("./bin/main")
        proc.run(["echo", ins])
        proc.run("./bin/brut")
        proc.run(["echo", ins])

def CmpRes():
    pass

Compile()
MakeCases(sys.argv[1])
CmpRes()
