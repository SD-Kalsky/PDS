#include <iostream>
#include <vector>
// #include <cmath>
using namespace std;

long toBinary(long n){
    long a=0;
    long i=1, j=1;
    while(n>0){
        a+=((n%2)*j);
        j *= 10;
        n /= 2;
    }
    return a;
}

bool isSimple(long a){
    bool b=true;
    long i=2;
    while(i<a){
        if ( a % i == 0 ) {b=false; break;}  
        i++;
    }
    return b;
}

long toSimple(long a){
    long i=0;
    while(i<a){
        if ( isSimple( a += i )) break; 
        i++;
    }
    return a;
}

long naivMod(long x, long a, long p){
    long y=1, i=0;
    while(i<x){
        y *= a;
        i++;
    }
    y = y % p;
    return y;
}

long fastMod(long x, long g, long p){
    long y=1;
    while(x>0){
        y*=( x % 2 > 0 ?  g : 1 );
        g *= g;
        x /= 2;
    }
    y = y % p;
    return y;
}

long reModBruteForce(long y, long g, long p){
    long x=0;
    bool b=false;
    while( x < p ){
        if(  y == fastMod( x, g, p ) ) {b=true; break;}
        x++;
    }
    return x *= b;
}

vector<long> makeKeys(long g, long p){
    p = toSimple(p);
    g = toSimple(g);
    long q;
    q = ( p - 1 )/ 2;
    if( 1 == fastMod(q, g, p) || g <= 1 || p - 1 <= g ){
        g = 2;
        while( 1 == fastMod(q, g, p) ){
            g++;
            g = toSimple(g);
        }
    }
    vector<long> keys{g,p};
    return keys;
}

long DiffieHellman(long xa, long xb, long g, long p){
    long s, ya, yb;   
    ya=fastMod(xa, g, p);
    yb=fastMod(xb, g, p);
    return fastMod(xb, ya, p);
}

long DiffieHellman(long xa, long yb, long p){   
    return fastMod(xa, yb, p);
}