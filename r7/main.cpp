#include <iostream>
#include "classes.h"

using namespace std;

int main()
{
    int n=5, a=5, m=3, c;
    int i=5;
    c=naivMod(n, a, m);
    cout << c << endl;
    c=fastMod(n, a, m);
    cout << c << endl;

    return 0;
}