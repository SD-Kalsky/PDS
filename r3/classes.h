#include <iostream>
#include <chrono>
#include <math.h>


using namespace std;

// 1. Разработайте схему экспериментов, чтобы программа выводила
// наглядную таблицу, по которой можно видеть зависимость сложности от
// размера входных данных.

template <typename F> double measureTime(F  &&func) 
{
  auto start = std::chrono::high_resolution_clock::now();
  forward<F>(func);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> duration = end - start;
  return duration.count();
}

template <class C> void pTable(C obj, int m, int n)
{

    cout<<m<<' ' <<n<<' '<<endl;
    cout<<"a: "<< measureTime(obj.a(m,n))<<endl;
    cout<<"b: "<< measureTime(obj.b(m,n))<<endl;
    cout<<"c: "<< measureTime(obj.c(m,n))<<endl;
    cout<<"d: "<< measureTime(obj.d(m,n))<<endl;
}

template <class C> void pTable(C obj, int m)
{

    cout<<m<<' '<<' '<<endl;
    cout<<"a: "<< measureTime(obj.a(m))<<endl;
    cout<<"b: "<< measureTime(obj.b(m))<<endl;
    cout<<"c: "<< measureTime(obj.c(m))<<endl;
    cout<<"d: "<< measureTime(obj.d(m))<<endl;
}

// 2. Согласно разработанной схеме проведите экспериментальные замеры
// времени при различных входных данных для алгоритмов проверки числа
// на простоту:
// a. Перебор от 2 до N
// b. Перебор от 2 до N только четных чисел
// c. Перебор от 2 до sqrt(N)
// d. Перебор от 2 до sqrt(N) только четных чисел
class Second
{
    public:
    bool a(int n)
    {
        int t=0, i=2;
        bool b=true;
        while(i<n)
        {
            if(n%i==0) {b=false; break;}
            i++;
        }
        return b;
    }
    bool b(int n)
    {
        int t=0, i=2;
        bool b=true;
        while(i<n)
        {
            if(n%i==0) {b=false; break;}
            i+=2;
        }
        return b;
    }
    bool c(int n)
    {
        n=sqrt(n);
        int t=0, i=2;
        bool b=true;
        while(i<n)
        {
            if(n%i==0) {b=false; break;}
            i++;
        }
        return b;
    }
    bool d(int n)
    {
        n=sqrt(n);
        int t=0, i=2;
        bool b=true;
        while(i<n)
        {
            if(n%i==0) {b=false; break;}
            i+=2;
        }
        return b;
    }
};

//3. Согласно разработанной схеме проведите экспериментальные замеры
// времени при различных входных данных для алгоритмов вычисления
// НОД(M, N), в том числе перебором и алгоритмом Евклида:
// a. Формирование массива общих делителей M и N с последующим
// поиском максимума в нем.
// b. Перебор от 1 до min(M, N)
// c. Перебор от min(M, N) до 1
// d. Алгоритм Евклида

class Third
{
    public:
    int* array(int m, int n)
    {
        int *a=new int[2]{2,1}, i=2, c;
        c=(m>n ? n: m);
        n=(n>m ? n: m);
        m=c;
        c=2;
        while(i<n)
        {
            if((m%i==0)&&(n%i==0)) c++; 
            i++;
        }
        a[0]=2; a[1]=1;
        if(c>2)
            {
                i=2;
                delete [] a;
                a=nullptr;
                a=new int [c];
                a[0]=c; a[1]=1;
                c=1;
                while(i<n)
                {
                    if((m%i==0)&&(n%i==0)) {c++; a[c]=i; }
                    i++;
                }
            }
        return a;
    }

    int a(int m, int n)
    {
        // int i, max=1;
        // i=(m>n ? n: m);
        // n=(n>m ? n: m);
        // m=i;
        // i=1;
        // while(i<n)
        // {
        //     if((m%i==0)&&(n%i==0)&&(max<i)) max=i; 
        //     i++;
        // }
        int *a;
        a=array(m,n);
        int  max=a[1], i=2;

        while(i<a[0])
        {
            if(max<a[i]) max=a[i]; 
            i++;
        }

        return max;
    }

    int b(int m, int n)
    {
        int i, nod=1; 
        i=(m>n ? n: m);
        n=(n>m ? n: m);
        m=i;
        i=2; 
        while(i<=m)
        {
            if((m%i)==0 && (n%i)==0) {nod=i;break;}
            i++;
        }
        return nod;
    }
    int c(int m, int n)
    {
        int i, nod=1;
        i=(m>n ? n: m);
        n=(n>m ? n: m);
        m=i;
        i=m;
        while(i>0)
        {
            if(m%i==0 && n%i==0) {nod=i; break;}
            i--;
        }
        return nod;
    }
    int d(int m, int n)
    {
        int i=1;
        i=(m>n ? n: m);
        n=(n>m ? n: m);
        m=i;
        i=m;
        while(n!=0)
        {
            n-=m;
            if(n<0)
            {
                i=n+m;
                n=m; m=i;
            }
        }
        return m;
    }
};


// 4. Дополнительное задание. Согласно разработанной схеме проведите
// экспериментальные замеры времени при различных входных данных для
// алгоритмов вычисления НОК(M, N), в том числе перебором и алгоритмом
// Евклида:
// a. Формирование массива общих кратных M и N с последующим
// поиском минимума в нем.
// b. Перебор от max(M, N) до M*N
// c. Алгоритм Евклида и вычисление через НОД
class Fourth
{
    public:
    int* array(int m, int n)
    {
        int *a=new int[2]{2,1}, i, c;
        c=(m>n ? n: m);
        n=(n>m ? n: m);
        m=c;
        i=m*n-1;
        c=2;
        while(i>n)
        {
            if((i%m==0)&&(i%n==0)) c++;
            i--;
        }
        a[0]=2; a[1]=m*n;
        if(c>2)
            {
                delete [] a;
                a=nullptr;
                a=new int [c];
                a[0]=c; a[1]=m*n;
                c=1;
                i=m*n-1;
                while(i>n)
                {
                    if((i%m==0)&&(i%n==0)) {c++; a[c]=i; }
                    i--;
                }
            }
        return a;
    }

    int a(int m, int n)
    {
        int *a;
        a=array(m,n);
        int  min=a[1], i=2;

        while(i<a[0])
        {
            if(min>a[i]) min=a[i]; 
            i++;
        }

        return min;
    }

    int b(int m, int n)
    {
        int i, nok=m*n; 
        i=(n>m ? n: m); 
        while(i<m*n)
        {
            if((i%m)==0 && (i%n)==0) {nok=i;break;}
            i++;
        }
        return nok;
    }
    int c(int m, int n)
    {
        int i=1, p=m*n;
        i=(m>n ? n: m);
        n=(n>m ? n: m);
        m=i;
        i=m;
        while(n!=0)
        {
            n-=m;
            if(n<0)
            {
                i=n+m;
                n=m; m=i;
            }
        }

        return p/m;
    }
    int d(int m, int n)
    {
        int a=0;
        return a;
    }
};

// 5. Дополнительное задание. Во многих языках программирования есть
// встроенные функции сортировки. Засеките время и определите
// сложность сортировки. Скорее всего, будет O(N*Log_2(N)). Тем самым
// подтвердится, что используется быстрый алгоритм сортировки, а не
// квадратичный


