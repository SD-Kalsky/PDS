#include <iostream>
#include <math.h>
#include <chrono>
using namespace std;

// Создайте несколько рекурсивных функций (не менее 3), решающих разные задачи. Например, сумма цифр числа, цифровой корень числа, факториал, сумма числа от 1 до N и т.д.
long digit_sum(long n)
{
    n=(n<0)*(-1)*n+(n>0)*n;
    if (n>=11) n=digit_sum(n/10)+n%10;
    return n;
}
long factorial(long n)
{
    if(n==0)
        n=1;
    else
        n=n*factorial(n-1);
    return n;
}
long sum(long n)
{
    if(n==1)
        n=1;
    else
        n=n+sum(n-1);
    return n;   
}
//
// Создайте несколько рекурсивных процедур (не менее 3), выводящих на экран различные последовательности. Например, от 1 до N, от N до 1, от от –N до N, от N до -N, четные числа, нечетные числа и т.д. 
void out_factorial(long n)
{
    if(n==0)
        n=1;
    else
        {out_factorial(n-1); cout<<'*';}
        cout<<n;
}
void out_sql2(long n)
{
if(n==0)
    {cout<<1;}
else
    { cout<<pow(2,n)<<' '; out_sql2(n-1); }
}
void out_even(long b)
{
    if(1!=b) out_even(b-1);
    if(b%2==0) cout<<b<<' ';
}
//
// Создайте одну рекурсивную функцию или процедуру, не менее чем от 2 аргументов. Например, возведение в степень, алгоритм Евклида. 
long power(long a, long b)
{
    if(b==0) a=1;
    else if(b>0) a=power(a, b-1)*a;
    else a=power(a, b+1)/a;
    return a;
}
void out_even(long a, long b)
{
    if(a!=b) out_even(a, b-1);
    if(b%2==0) cout<<b<<' ';
}
//
// Создайте четыре реализации функции, вычисляющей числа Фибоначчи:
// рекурсивную без оптимизации;
long fib(long n)
{
    long f, m=(n<0)*(-1)*n+(n>0)*n;
    switch (m)
    {
    case 0:
        f=0;
        break;
    case 1:
        f=1;
        break;
    default:
        f=fib(m-1)+fib(m-2);
        break;
    }
    f=(n<0)*(-1)*f+(n>0)*f;
    return f;
}
//
// рекурсивную с кеш-памятью;
class Fibonacci
{
private:
long *a=new long[1]{0}, number=0, c=1;
void init()
{
    delete [] a;
    a=nullptr;
    a=new long[number+1];
}
void infib(long n)
{
    switch(n)
    {
        case 0:
        {
            a[n]=0;
            break;
        }
        case 1:
        {
            a[n]=c;
            break;
        }
        default:
        {

            this->infib(n-1);
            this->infib(n-2);
            a[n]=a[n-1]+a[n-2];
        }
    }
}
public:
Fibonacci()
{
    init();
}
Fibonacci(long n)
{
    if(n!=0)
    {       
        long m=(n<0)*(-1)*n+(n>0)*n;
        c=(n<0)*(-1)+(n>=0);
        this->number=m;
        this->init();
        this->infib(n);
    }
}
~Fibonacci()
{
    delete [] a;
    a=nullptr;
}
void fib(int n)
{
    if(n!=0)
    {       
        long m=(n<0)*(-1)*n+(n>0)*n;
        c=(n<0)*(-1)+(n>=0);
        this->number=m;
        this->init();
        this->infib(n);
    }
}

long r_fib(int n)
{
    long m=(n<0)*(-1)*n+(n>0)*n;
    if(n!=0)
    {       
        c=(n<0)*(-1)+(n>=0);
        this->number=m;
        this->init();
        this->infib(n);
    }
    return a[m];
}
void print()
{
    long i=0;
    while (i<=number)
    {
        cout<<a[i]<<' ';
        i++;
    }
}
};
//
// итеративную с временным массивом;
long *fib_array(long n)
{
    long m=(n<0)*(-1)*n+(n>0)*n;
    long *a=new long[m+1];
    long i=2;
    a[0]=0;
    a[1]=(n<0)*(-1)+(n>=0);
    while(i<=m)
    {
        a[i]=a[i-1]+a[i-2];
        i++;
    }
    return a;
}
long r_fib_array(long n)
{
    long m=(n<0)*(-1)*n+(n>0)*n;
    long *a;
    a=fib_array(n);
    return a[m];
}
// итеративную с вычислением “на лету”.
void fib_prlong(long n)
{
    long m=(n<0)*(-1)*n+(n>0)*n;
    long i=2;
    long f1=0;
    long f2=(n<0)*(-1)+(n>=0);
    while(i<=m)
    {
        n=f2;
        f2=f1+f2;
        f1=n;
        cout<<f2<<' ';
        i++;
    }
}
long r_fib_prlong(long n)
{
    long m=(n<0)*(-1)*n+(n>0)*n;
    long i=2;
    long f1=0;
    long f2=(n<0)*(-1)+(n>=0);
    while(i<=m)
    {
        n=f2;
        f2=f1+f2;
        f1=n;
        i++;
    }
    return f2;
}
//
// Проведите эксперименты с заданием 4:
// До какого максимального числа можно вычислить за приемлемое время? Убедитесь, что рекурсия без оптимизации позволяет вычислять не более 30-40 значений.
// Засеките время выполнения программы через встроенную функцию наподобие time().
// template <typename F> double measureTime(F  &&func) 
// {
//     auto start = std::chrono::high_resolution_clock::now();
//     forward<F>(func);
//     auto end = chrono::high_resolution_clock::now();
//     chrono::duration<double, milli> duration = end - start;
//     return duration.count();
// }

// void charTable(int i)
// {
//     Fibonacci f;
//     cout<<"| Size  |  Time |"<<endl;
//     cout<<"Without optimization - "<<measureTime(fib(i))<<endl;
//     cout<<"With a cash memory - "<<measureTime(f.r_fib(i))<<endl;
//     cout<<"With an array - " <<measureTime(r_fib_array(i))<<endl;
//     cout<<"On th fly - " <<measureTime(r_fib_prlong(i))<<endl;
// }
// Засеките расход памяти через диспетчер задач (для этого эксперимента необходимо запустить программу на компьютере или ноутбуке, а не в онлайн-компиляторе)
