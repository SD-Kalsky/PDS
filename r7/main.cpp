#include <iostream>
#include "classes.h"

using namespace std;

void transferAB(){
    long g=5, p=23, xa=9, xb=15, ya, yb, s;
    int m =  sqrt(p) + 1 , k = sqrt(p) + 1 ; 
    ya=fastMod(xa, g, p);
    // yb=fastMod(xb, g, p);
    cout << "xa=" << xa << " ya=" << ya << endl;
    cout << "xa=" << reModBruteForce(ya, g, p) << endl;
    xa = reModBabyGiantStep(m, k, ya, g, p);
    cout << "xa=" << xa << endl;
}


int main()
{
    // long g = 3, p = 23;

    // vector<long> keys;
    
    // keys = makeKeys( g, p );

    // cout << keys[0] << " " << keys[17];

    // y=fastMod(x, a, p);
    // cout << "For x=" << x << " we got y=" <<y << endl;
    // x=reModBruteForce(y,a,p);
    // cout << "For y=" << y << " we got x=" <<x << endl;

    transferAB();

    return 0;
}