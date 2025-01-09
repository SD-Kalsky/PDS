#include <iostream>
#include "classes.h"
#include "view.h"
using namespace std;

int main()
{
    print_lab();
    char a;
    cin>>a;
    switch (a)
    {
    case '1':
    {
        int n=10, s;
        int *a=new int[n];
        randomize(a,n);
        println(a,n);
        print("Input a searching number ");
        cin>>s;
        println(readClock(a,n,s));
        break;
    }
    case '2':
    {
        int n=10, s;
        int *a=new int[n];
        randomize(a,n);
        ShellSort(a,n);
        println(a,n);
        print("Input a searching number ");
        cin>>s;
        println(readClockBinary(a,n,s));
        break;
    }
    case '3':
        charTable();
        break;
    case '4':
        {
            int n=10, s;
            int *a=new int[n];
            randomize(a,n);
            println(a,n);
            int c=clockBubbleSort(a,n);
            println(a,n);
            print("The number of clocks is ");
            println(c);
        }
    case '5':
        {
            int n=10, s;
            int *a=new int[n];
            randomize(a,n);
            println(a,n);
            int c=ClockShellSort(a,n);
            println(a,n);
            print("The number of clocks is ");
            println(c);
        }
    default:
        break;
    }
    println();

  return 0;
}
