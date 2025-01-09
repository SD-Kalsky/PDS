#include <iostream>
#include <vector>
// #include <cmath>
using namespace std;

int toBinary(int n){
    int a=0;
    int i=1, j=1;
    while(n>0){
        a+=((n%2)*j);
        j *= 10;
        n /= 2;
    }
    return a;
}

bool isSimple(int a){
    bool b=true;
    int i=2;
    while(i<a){
        if ( a % i == 0 ) {b=false; break;}  
        i++;
    }
    return b;
}

int toSimple(int a){
    int i=0;
    while(i<a){
        if ( isSimple( a += i )) break; 
        i++;
    }
    return a;
}

int naivMod(int x, int a, int p){
    int y=1, i=0;
    while(i<x){
        y *= a;
        i++;
    }
    cout<<"y="<<y<<" ";
    y = y % p;
    return y;
}

int fastMod(int x, int a, int p){
    int y=1;
    while(x>0){
        y*=( x % 2 > 0 ?  a : 1 );
        a *= a;
        x /= 2;
    }
    y = y % p;
    return y;
}

int reModBruteForce(int y, int a, int p){
    int x=0;
    bool b=false;
    while( x < p ){
        if(  y == fastMod( x, a, p ) ) {b=true; break;}
        x++;
    }
    return x *= b;
}

vector<int> makeKeys(int g, int p){
    p = toSimple(p);
    g = toSimple(g);
    int q;
    q = ( p - 1 )/ 2;
    if( 1 == fastMod(q, g, p) || g <= 1 || p - 1 <= g ){
        g = p - 2;
        g = toSimple(g);
        while( 1 == fastMod(q, g, p) ){
            g = toSimple(g);
        }
    }
    vector<int> keys{g,p};
    return keys;
}



class DaClass{

};