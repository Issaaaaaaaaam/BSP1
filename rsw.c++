#include <bits/stdc++.h>
#include <cmath>
#include <gmpxx.h>
#include <gmp.h> 
#include <iostream>
 
using namespace std;


unsigned long  getRandomInt(){ // this function gives us a random number
    std::random_device rd;
    return rd();
}


mpz_class fonctionarandom (mpz_class n) {
    gmp_randclass X(gmp_randinit_default) ; 
    X.seed(getRandomInt());
    mpz_class z = X.get_z_range(n-2);   
    if (z == 0 | z==1 );   {
        return 2 ; 
    }
    return z ; 
}
mpz_class fonctionrandom (int bits) {       // this function will give us a random number with the number of bits that will constitute it as a parameter 
    gmp_randclass X(gmp_randinit_default) ; 
    X.seed(getRandomInt());   
    mpz_class z = X.get_z_bits(bits); 
    return z ; 
}
mpz_class exp_one(mpz_class a, mpz_class b, mpz_class c){    // this function is to facilitate the exponential on gmp taking as parameter the base the exponential and the mod
  mpz_class r;
  mpz_powm(r.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t(), c.get_mpz_t());
  return r;
}
mpz_class exp_two(mpz_class a, mpz_class b){     // this function is to facilitate the power of 2 on gmp taking as parameter the base and the mod 
  mpz_class r, c;
  c = 2;
  mpz_powm(r.get_mpz_t(), a.get_mpz_t(), c.get_mpz_t(), b.get_mpz_t());
  return r;
}

bool millerTest ( mpz_class d, mpz_class  n){        // rabbin-miller test return true if it is probably a prime and false if it is composite                
    mpz_class  a = fonctionarandom(n) ; 
    mpz_class  x = exp_one(a,d,n) ;
    
    if (x == 1 || x == n-1){
        return true; 
    }
    while (d != n-1 ){
        x = (x*x) % n ;
        d *= 2 ; 
        if (x==1){
            return false ; 
        }
        if (x == n-1){
            return true ;
        }
    }
    return false; 
}

bool isPrime(mpz_class n, mpz_class k ){    // the main function of our prime test it will test the corner cases and do the rabbin-miller test k times for decurity purposes 
    if ( n<= 1 || n==4) return false ; 
    if ( n<= 3 ) return true ; 
    mpz_class d = n -1 ; 
    while (d %2 == 0 ) {
        d /= 2 ;
    }
    for ( mpz_class i = 0 ; i<k ; i++)
        if (!millerTest(d,n)){
            return false ; 
        }
    return true ; 
}


mpz_class generateprime(int u) {
    
    mpz_class k = 2 ; // we need 20 for it to be acceptable 
    mpz_class i ; 

    while (k != true) {
    i = fonctionrandom(u) ;
    if ( isPrime(i,k) == true  ){
        k = true ; 
        cout << "this is the prime number" << "  " << i << endl ; 
          
    }
  }
    return i ; 
}
mpz_class rsw(mpz_class t, mpz_class g , mpz_class n){
    mpz_class s = g ; 
    for ( mpz_class i =  0 ; i<t ; i++){
        s = (s*s) % n ; 
    }
    return s ; 
}

int main() {
    ofstream myfile;
    myfile.open("data_c++.txt") ; 
    int T []  = {14,15,16,17,18,19,20,21,22,23}; 
    int i = 0 ;
    int  modulus_size = 81 ; 
    while ( i <= 100 ) {
        myfile << modulus_size << endl ; 
        mpz_class p, q, n ; 
        p = generateprime(modulus_size) ;
        q = generateprime(modulus_size) ; 
        n = p*q ; 
        mpz_class g = fonctionarandom(n) ; 
        if (g == 0) {
            g = 1 ; 
        }
        for (int z = 0 ; z < 10 ; z++ ){
            mpz_class t = pow(2,T[z]) ;
            std::clock_t start;
            double duration;
            start = std::clock();
            mpz_class s = rsw(t,g,n) ; 
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
            myfile << duration << endl ; 
        }
        modulus_size += 81 ; 
        i++ ; 
        cout << "finished"<< endl ;
         
    }
    myfile.close() ; 
    return 0 ; 
}