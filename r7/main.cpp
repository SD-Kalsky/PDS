#include <iostream>
#include "classes.h"

using namespace std;

void transferAB(){
    long g=5, p=23, xa=6, xb=15, ya, yb, s;
    ya=fastMod(xa, g, p);
    yb=fastMod(xb, g, p);
    cout << "xa=" << xa << " ya=" << ya << endl;
    cout << "xb=" << xb << " yb=" << yb << endl;
    cout << fastMod(xa, yb, p) << endl;
    cout << fastMod(xb, ya, p) << endl;


}


int main()
{
    // long g = 3, p = 23;

    // vector<long> keys;
    
    // keys = makeKeys( g, p );

    // cout << keys[0] << " " << keys[1];

    // y=fastMod(x, a, p);
    // cout << "For x=" << x << " we got y=" <<y << endl;
    // x=reModBruteForce(y,a,p);
    // cout << "For y=" << y << " we got x=" <<x << endl;

    transferAB();

    return 0;
}