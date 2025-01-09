#include <iostream>
// #include <cmath>
using namespace std;

int naivMod(int x, int a, int m){
    int y=1, i=0;
    while(i<x){
        y *= a;
        i++;
    }
    cout<<"y="<<y<<" ";
    y = y % m;
    return y;
}

int fastMod(int x, int a, int m){
    int y=1;
    int i=1, p=1;
    while(x>0){
        y*=( x % 2 > 0 ?  a : 1 );
        a *= a;
        x /= 2;
    }
    cout<<"y="<<y<<" ";
    y = y % m;
    return y;
}

int reModBruteForce(int y, int a, int m){
    int x=0;
    int i=1, p=1;
    while(x%m==y){
        y *= a;
    }
    return y;
}

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
class DaClass{

};