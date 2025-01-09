#include <iostream>
#include "classes.h"
#include<time.h>
using namespace std;

int main()
{
    Stack a;
    srand(time(0));
    int i=0;
    while(i<10)
    {
        a.push(rand()%100);
        i++;
    }
    a.print();
    cout<<endl;
    i=0;
    while(i<10)
    {
        if (rand()%2==0) a.push(rand()%100);
        else a.pop();
        i++;
    }
    a.print();
    return 0;
}