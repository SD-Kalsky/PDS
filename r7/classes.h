#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

using std::time;
using std::rand;
using std::srand;

long long toBinary(long long n){
    long long a=0;
    long long i=1, j=1;
    while(n>0){
        a+=((n%2)*j);
        j *= 10;
        n /= 2;
    }
    return a;
}

long long randINT(long long a){
    setlocale(0, "");
    srand(static_cast<unsigned int>(time(NULL)));
    return rand() % a;
}

bool isSimple(long long a){
    bool b=true;
    long long i=2;
    while(i<a){
        if ( a % i == 0 ) {b=false; break;}  
        i++;
    }
    return b;
}

long long toSimple(long long a){
    long long i=0;
    while(i<a){
        if ( isSimple( a += i )) break; 
        i++;
    }
    return a;
}

long long naivMod(long long x, long long a, long long p){
    long long y=1, i=0;
    while(i<x){
        y *= a;
        i++;
    }
    y = y % p;
    return y;
}

long long fastMod(long long x, long long g, long long p){
    long long y=1;
    while(x>0){
        y*=( x % 2 > 0 ?  g : 1 );
        g *= g;
        x /= 2;
    }
    y = y % p;
    return y;
}

long long reModBruteForce(long long y, long long g, long long p){
    long long x=0;
    bool b=false;
    while( x < p ){
        if(  y == fastMod( x, g, p ) ) {b=true; break;}
        x++;
    }
    return x *= b;
}

long long reModBabyGiantStep(int m, int k, long long y, long long g, long long p){
    long long a;
    bool b=true;
    vector<long long> ay;
    int i, j, x=0;

    i = 0; 
    a = 1;
    while( i < m ){
        ay.push_back( y * a );
        a *= g;
        i++;
    }
    j = 1;
    while( j <= k && b ){
        i = 0;
        while( i < m ){
            // cout << "a^" << j+m << " => " << a << " (mod " << p << ") = " << a % p << "; ya^" << i << " => " << ay[i] << " (mod " << p << ")= " << ay[i] % p << endl;
            if(a % p == ay[i] % p){
                x = m * j  - i  ;
                b = false;
                break;
            }
            i++;
        }
        a *= g;
        j++;
    }
    return x;
}

vector<long long> makeKeys(long long g, long long p){
    p = toSimple(p);
    g = toSimple(g);
    long long q;
    q = ( p - 1 )/ 2;
    if( 1 == fastMod(q, g, p) || g <= 1 || p - 1 <= g ){
        g = 2;
        while( 1 == fastMod(q, g, p) ){
            g++;
            g = toSimple(g);
        }
    }
    vector<long long> keys{g,p};
    return keys;
}

long long DiffieHellman(long long xa, long long xb, long long g, long long p){
    long long s, ya, yb;   
    ya=fastMod(xa, g, p);
    yb=fastMod(xb, g, p);
    return fastMod(xb, ya, p)*(ya*yb);
}

long long DiffieHellman(long long xa, long long yb, long long p){   
    return fastMod(xa, yb, p);
}