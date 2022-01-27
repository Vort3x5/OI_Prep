import subprocess, sys

def Compile():
    try:
        subprocess.run(["g++", "K0.cpp", "-o", "main"], check=True)
    except subprocess.CalledProcessError:
        print("Compilation of main failed")
        exit(1)
    
    try:
        subprocess.run(["g++", "Brut.cpp", "-o", "brut"], check=True)
    except subprocess.CalledProcessError:
        print("Compilation of brut failed")
        exit(1)

def MakeCases(N):
    subprocess.run(["python3", "Gen.py", str(N)])
    for i in range (N):
        pass

def CmpRes():
    pass

Compile()
# MakeCases(sys.argv[1])
