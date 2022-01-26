import subprocess, sys

def Compile():
    try:
        subprocess.run(["g++", "K0.cpp", "-o", "Given_out/main"], check=True)
    except subprocess.CalledProcessError:
        print("Compilation of main failed")
        exit(1)
    
    try:
        subprocess.run(["g++", "Brut.cpp", "-o", "Expected_out/brut"], check=True)
    except subprocess.CalledProcessError:
        print("Compilation of main failed")
        exit(1)

def Run():
    pass

Compile()
