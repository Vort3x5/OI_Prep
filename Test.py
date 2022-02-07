import subprocess as proc
import sys

N = int(sys.argv[1])

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

def MakeCases():
    proc.run(["python3", "clear_tests.py"])
    proc.run(["python3", "Gen.py", str(N)])
    for i in range (N):
        with open("In/Inpts" + str(i) + ".in") as In:
        
            with open("Given_Out/G_Res" + str(i) + ".out", "w+") as Out:
                proc.run(["./bin/main", '<', In.name, '>', Out.name])
            
            with open("Expected_Out/E_Res" + str(i) + ".out", "w+") as Out:
                proc.run(["./bin/brut", '<', In.name, '>', Out.name])

def CmpRes():
    for i in range(N):
        main_res = ""
        with open("Given_Out/G_Res" + str(i) + ".out") as f:
            main_res = f.read()
        brut_res = ""
        with open("Expected_Out/E_Res" + str(i) + ".out") as f:
            brut_res = f.read()
        
        if main_res.strip() == brut_res.strip():
            print("Git\n")
        else:
            print("Niet\n")
        print ("poprawny:\t" + brut_res + '\n')
        print ("Czewiasty:\t" + main_res + '\n')

Compile()
MakeCases()
CmpRes()
