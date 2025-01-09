#include <iostream>
#include "classes.h"

using namespace std;

void transferAB(){
    int g, p, a, b;

}


int main()
{
    int x=1024, a=5, y;
    int i=5;

    int g = 3, p = 23;

    vector<int> keys;
    
    keys = makeKeys( g, p );

    cout << keys[0] << " " << keys[1];

    // y=fastMod(x, a, p);
    // cout << "For x=" << x << " we got y=" <<y << endl;
    // x=reModBruteForce(y,a,p);
    // cout << "For y=" << y << " we got x=" <<x << endl;
    return 0;
}