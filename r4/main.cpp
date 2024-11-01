#include <iostream>
#include "classes.h"

using namespace std;

int main()
{
    int i=40;
    // long *a=fib_array(n);
    
    // int i=0;
    // while(i<=n)
    //     {cout<<a[i]<<' ';i++;}

    // charTable(n);
    Fibonacci f;
    cout<<"Without optimization - "<<measureTime(fib(i))<<endl;
    // cout<<"With a cash memory - "<<measureTime(f.r_fib(i))<<endl;
    // cout<<"With an array - " <<measureTime(r_fib_array(i))<<endl;
    // cout<<"On th fly - " <<measureTime(r_fib_prlong(i))<<endl;

    return 0;
}