#include <iostream>
#include "classes.h"
#include<time.h>
using namespace std;

int main()
{
    Stack a;

    int i=0;

    while (i<10)
    {
        a.push(rand()%100);
        i++;
    }
    i=0; bool b;
    while (i<30)
    {
        b=rand()%2;
        if (b) a.push(rand()%100);
        else a.pop();
        
        i++;
    }
    


    a.print();


    return 0;
}