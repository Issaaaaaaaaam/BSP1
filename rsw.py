#user 1 part creating the time lock puzzle 
from Crypto.Util import number
import time 
import random

# the rsw function takes as inputs the timebounds "t",  generator "g", and a composite modulus n 
def rsw(t,g,n) : 
        s = g 
        for i in range(t):
                s = s*s %n  
        return s

def test() : 
        with open("data_Python.txt","w") as datafile : 
                T = [14,15,16,17,18,19,20,21,22,23]
                z=0
                i=0
                modulus_size = 81
                while i<100 : 
                        datafile.write(str(modulus_size)+"\n")
                        p = number.getPrime(modulus_size) 
                        q = number.getPrime(modulus_size) 
                        n = p * q 
                        g = random.randint(1, n)
                        compt = 0
                        for z in range (0,10) :
                                t = 2**(T[compt])
                                start = time.time()
                                s = rsw (t, g, n) 
                                end = time.time()
                                datafile.write(str(end-start)+"\n")
                                compt += 1
                        datafile.flush()
                        modulus_size = modulus_size+81
                        i +=1


def main(): 
        test() 
        
if __name__ == '__main__':
        main()




