#include "view.h"
#include "classes.h"
// #include "r1/classes.h"
// #include "r2/classes.h"
// #include "r3/classes.h"
// #include "r4/classes.h"

using namespace std;

void lab2();
void lab3();
void lab4();
// void lab5();


void start()
{
    menu();
    char n;
    cin>>n;
    switch (n)
    {
    case '1':
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
            println();
            i=0;
            while(i<10)
            {
                if (rand()%2==0) a.push(rand()%100);
                else a.pop();
                i++;
            }
            a.print();
            break;
        }
        
    case '2':
        lab2();
        break;
    case '3':
        lab3();
        break;
    case '4':
        lab4();
        break;
    default:
        goto exit;
    }
    println();
    start();
    exit:
        end();
}


void lab1()
{

}




void lab2()
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
}


void lab3()
{
    print_lab();
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
    {
        print(" Open h-file");
        break;
    }
    case 2:
    {
        
        Second obj;
        int m;
        print("Input numbers ");
        cin>>m;
        cout<<"a: "<< measureTime(obj.a(m))<<endl;
        cout<<"b: "<< measureTime(obj.b(m))<<endl;
        cout<<"c: "<< measureTime(obj.c(m))<<endl;
        cout<<"d: "<< measureTime(obj.c(m))<<endl;
        break;
    }
    case 3:
    {
        Third obj;
        int m,n;
        print("Input numbers ");
        cin>>m>>n;
        cout<<"a: "<< measureTime(obj.a(m,n))<<endl;
        cout<<"b: "<< measureTime(obj.b(m,n))<<endl;
        cout<<"c: "<< measureTime(obj.c(m,n))<<endl;
        cout<<"d: "<< measureTime(obj.c(m,n))<<endl;
        break;
    }
    case 4:
    {
        Fourth obj;
        int m,n;
        print("Input numbers ");
        cin>>m>>n;
        cout<<"a: "<< measureTime(obj.a(m,n))<<endl;
        cout<<"b: "<< measureTime(obj.b(m,n))<<endl;
        cout<<"c: "<< measureTime(obj.c(m,n))<<endl;

        break;
    }
    case 5:
    {
        print("404");
    }
    default:
        break;
    }
    println();
}

void lab4()
{
    print_lab();
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
    {
        long n;
        println("Input a number ");
        cin>>n;
        print("A digit sum is ");        
        println(digit_sum(n));
        print("A factorial is ");
        println(factorial(n));
        print("A sum is ");
        println(sum(n));
        break;
    }
    case 2:
    {
        long n;
        println("Input a number ");
        cin>>n;
        print("A digit sum is "); 
        out_factorial(n);
        println();
        print("A factorial is ");
        out_sql2(n);
        println();
        print("A sum is ");
        out_even(n);
        println();
        break;
    }
    case 3:
    {
        long a,b;
        println("Input numbers ");
        cin>>a>>b;
        println(power(a,b));
        out_even(a,b);
        break;
    }
    case 4:
    {
        println("Input a number ");
        long n;
        Fibonacci f;
        cin>>n;
        println(fib(n));
        f.fib(n);
        f.print();
        println();
        println(r_fib_array(n));
        fib_prlong(n);
        println();

        break;
    }
    case 5:
    {
        long n;
        Fibonacci f;
        println("Input a number ");
        cin>>n;
        print("Without optimization - ");
        println(measureTime(fib(n)));
        print("With a cash memory - ");
        println(measureTime(f.r_fib(n)));
        print("With an array - ");
        println(measureTime(r_fib_array(n)));
        print("On th fly - ");
        println(measureTime(r_fib_prlong(n)));

        println();
        break;
    }
    default:
        break;
    }
    println();
}