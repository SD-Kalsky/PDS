#include <iostream>
#include <ctime>
#include <cmath>
#include <chrono>

using namespace std;
// Реализуйте стек на основе массива со счетчиком (операции push(), pop(), last(), isEmpty() и вспомогательную функцию print()).

class Stack
{
private:
    int *array=new int [1];
    
    void init()
    {
        int num=0;
        array[0]=1;
    }
    void destroy()
    {
        delete[] array;
        array=nullptr;
    }

public:
    Stack()
    {
        init();
    }
    ~Stack()
    {
        destroy();
    }
    void push(int a)
    {
        int *newarray=new int[array[0]+1];
        int i=1;
        while (i<array[0])
        {
            newarray[i]=array[i];
            i++;
        }
        newarray[array[0]]=a;
        newarray[0]=array[0]+1;
        destroy();
        array=newarray;
    }

    void pop()
    {
        if(array[0]>1)
        {       
            int *newarray=new int[array[0]-1];
            int i=1;
            while (i<array[0]-1)
            {
                newarray[i]=array[i];
                i++;
            }
            newarray[0]=array[0]-1;
            destroy();
            array=newarray;
        }
    }

    void print()
    {
        int i=1;
        while(i<array[0])
        {
            cout<<array[i]<<' ';
            i++;
        }
    }
    bool isEmpty()
    {
        return array[0]==1;
    }
    int last()
    {
        int l=0;
        if (array[0]>1) l+=array[array[0]-1];
        return l;
    }
};
// Реализуйте очередь на основе массива со счетчиком и сдвигом при (операции enqueue(), dequeue(), first(), isEmpty() и вспомогательную функцию print()).
class Queue
{
private:
    int *array=new int [1];
    
    void init()
    {
        array[0]=1;
    }
    void destroy()
    {
        delete[] array;
        array=nullptr;
    }

public:
    Queue()
    {
        init();
    }
    int first()
    {
        int r=0;
        if(array[0]>1)
            r+=array[array[0]];
        else
            cout<<"Error"<<endl;
        return r;
    }
    void enqueue(int a)
    {
        int *newarray=new int[array[0]+1];
        int i=1;
        while (i<array[0])
        {
            newarray[i]=array[i];
            i++;
        }
        newarray[array[0]]=a;
        newarray[0]=array[0]+1;
        destroy();
        array=newarray;
    }

    void dequeue()
    {
        if(array[0]>1)
        {       
            int *newarray=new int[array[0]-1];
            int i=1;
            while (i<array[0]-1)
            {
                newarray[i]=array[i];
                i++;
            }
            newarray[0]=array[0]-1;
            destroy();
            array=newarray;
        }
    }
    bool isEmpty()
    {
        return array[0]==1;
    }
    void print()
    {
        int i=array[0]-1;
        while(i>1)
        {
            cout<<array[i]<<' ';
            i--;
        }
    }

};
// Реализуйте список на основе массива со сдвигом элементов при добавлении/удалении.

class Array
{
private:
    int *array=new int [1];
    void init()
    {
        array[0]=0;
    }
    void destroy()
    {
        delete[] array;
        array=nullptr;
    }

public:
    Array()
    {
        init();
    }
    void add(int a)
    {   
        array[0]++;
        int i=0;
        int *newarray= new int[array[0]];
        while(i<array[0])
        {
            newarray[i]=array[i];
            i++;
        }
        newarray[i]=a;

        destroy();
        array=newarray;

        // delete [] newarray;
        // newarray=nullptr;

    }

    void remove()
    {   
        if(array[0]>0)
        {
            array[0]--;
            int i=0;
            int *newarray= new int[array[0]];
            while(i<=array[0])
            {
                newarray[i]=array[i];
                i++;
            }

            destroy();
            array=newarray;

            // delete [] newarray;
            // newarray=nullptr;
        }
    }
    void remove(int n)
    {   
        if(array[0]>0)
        {
            int i=0;
            int j=0;
            int *newarray= new int[array[0]-1];
            while(i<=array[0])
            {
                if(i==n) i++;
                newarray[j]=array[i];
                i++;
                j++;
            }
            destroy();
            array=nullptr;
            array=newarray;
            array[0]--;

            // delete [] newarray;
            // newarray=nullptr;

        }
    }
    bool isEmpty()
    {
        return array[0]>0;
    }
    void print()
    {
        int i=1;
        while (i<=array[0])
        {
            cout<<array[i]<<' ';
            i++;
        }
        cout<<endl;
    }

};
// Реализуйте множество на основе массива с пометкой элементов. Использование обертки - по желанию.

class ID_Array
{
private:
    int **array=new int *[2];
    
    int last_id;
    void init()
    {
        array[0]=new int [1];
        array[1]=new int [1];
        array[0][0]=0;
        array[1][0]=0;
        last_id=0;
    }
    void destroy()
    {
        delete[] array;
        array=nullptr;
    }

public:
    ID_Array()
    {
        init();
    }
    void add(int a)
    {   
        array[0][0]++;
        int i=0;
        int **newarray= new int *[2];
        newarray[0]=new int [array[0][0]];
        newarray[1]=new int [array[0][0]];
        while(i<array[0][0])
        {
            newarray[0][i]=array[0][i];
            newarray[1][i]=array[1][i];
            i++;
        }
        newarray[0][i]=a;
        newarray[1][i]=last_id;
        last_id++;
        destroy();
        array=newarray;

        // delete [] newarray;
        // newarray=nullptr;

    }

    void remove()
    {   
        if(array[0][0]>0)
        {
        int i=0;
        int **newarray= new int *[2];
        newarray[0]=new int [array[0][0]];
        newarray[1]=new int [array[0][0]];
        while(i<array[0][0])
        {
            newarray[0][i]=array[0][i];
            newarray[1][i]=array[1][i];
            i++;
        }
            destroy();
            array=newarray;
            array[0][0]--;


            // delete [] newarray;
            // newarray=nullptr;
        }
    }
    void remove(int n)
    {   
        if(array[0][0]>0)
        {
            int i=1;
            int j=1;
            int **newarray= new int*[2];
            newarray[0]=new int [array[0][0]];
            newarray[1]=new int [array[0][0]];
            while(i<=array[0][0])
            {
                if(i==n) i++;
                newarray[0][j]=array[0][i];
                newarray[1][j]=array[1][i];
                i++;
                j++;
            }
            destroy();
            array=nullptr;
            array=newarray;
            array[0]--;

            // delete [] newarray;
            // newarray=nullptr;

        }
    }
    bool isEmpty()
    {
        return array[0][0]>0;
    }
    void print()
    {
        int i=1;
        while (i<=array[0][0])
        {
            cout<<array[0][i]<<' ';
            i++;
        }
        cout<<endl;
    }
    void print_with_id()
    {
        int i=1;
        while (i<=array[0][0])
        {
            cout<<array[0][i]<<'-'<<array[1][i]<<' ';
            i++;
        }
        cout<<endl;
    }
};
//



//Наполнение массива случайными целыми числами от 0 до 99 включительно
void randomize(int* a, int n)
{
  int i=0;
  srand(time(0));
  while (i<n)
  {
      a[i]=rand()%100;
      i++;
  }
}
//Вывод массива
void print(int* a, int n)
{
  int i=0;
  while (i<n)
  {
      cout<<a[i]<<' ';
      i++;
  }
}

void println(int* a, int n)
{
  int i=0;
  while (i<n)
  {
      cout<<a[i]<<' ';
      i++;
  }
  cout<<endl;
}
// 1. Реализуйте последовательный поиск элемента в массиве с подсчетом
// фактического количества выполненных сравнений. Протестируйте работу
// программы при различных размерах массива и различных искомых
// элементах.

int readClock(int* a, int n, int f) //Функция вывода тактов поиска. Если искомого нет возвращает 0.
{
  int c=0, i=0;
  bool b=false;
  while (i<n)
  {
      if(f==a[i]) {b=true; break;}
      i++;
  }
  if (b) i++;
  else i=0;
  return i;
}

// 2. Реализуйте двоичный поиск элемента в отсортированном массиве с
// подсчетом фактического количества выполненных сравнений.
// Протестируйте работу программы при различных размерах массива и
// различных искомых элементах.

int readClockBinary(int* a, int n, int f) //Функция вывода тактов бинарного поиска. Если искомого нет возвращает 0.
{
  int c=0, i=0, min=0, max=n;
  bool b=false;

  while (min<=max) 
  {
    int mid=min+(max-min)/2;
    if (a[mid]==f) {b=true; break;}
    else
      if (a[mid]<f) min = mid + 1;
      else max = mid - 1;
    i++; 
  }

  if (!b) i=0;
  return i;
}

// 3. Напишите программу, которая демонстрирует зависимость практической
// сложности двоичного и последовательного поиска от размера массива.
// Необходимо в цикле увеличивать размер массива на фиксированную
// величину (например, на 20 элементов) и подсчитывать фактическое
// количество сравнений. В качестве искомого значения выбирать
// случайное из заданного диапазона. Результатом работы программы
// должен быть вывод следующей таблицы (сравните значения из таблицы
// с теоретическими расчетами):
    // Размер | Практическая сложность массива (N) последовательного поиска | Практическая сложность двоичного поиска
    // 20
    // 40
    // 60
    // 80
    // …
    // 500

void charTable()
{
  int i=20 , f=100;
  cout<<"| Size  |   the Number Clocks of the simple search  |  the Number Clocks of the binary search |"<<endl;
  while (i<=500)
  {
    int* a=new int[i];
    randomize(a, i);
    a[i-1]=f;
    cout<<"| "<<i<<" | "<<readClock(a, i, f)<<" | "<<readClockBinary(a, i, f)<<" |"<<endl;
    i+=20;
  }
}

// 4. Дополнительное задание 
//1. Реализуйте один из алгоритмов сортировки
// с квадратичной (O(N^2)) сложностью (пузырьковая, вставками, прямым
// выбором и пр.). Реализуйте определение фактического количества
// сравнений (перестановки можно не считать). Создайте цикл для
// моделирования нескольких запросов (обозначим это количество через
// K). Экспериментально определите, при каком значении K двоичный поиск
// становится эффективнее.

void bubbleSort(int* a, int n)
{
  int i, j=1, t;
  while(j<n+1)
  {
    i=0;
    while(i<n-j)
    {
      t=a[i];
      a[i]=(a[i]>a[i+1])*a[i+1]+(a[i]<=a[i+1])*a[i];
      a[i+1]=(t>a[i+1])*t+(t<=a[i+1])*a[i+1];
      i++;
    }
    j++;
  }
}
int clockBubbleSort(int* a, int n)
{
  int i, j=1, t, c=0;
  while(j<n+1)
  {
    i=0;
    while(i<n-j)
    {
      t=a[i];
      a[i]=(a[i]>a[i+1])*a[i+1]+(a[i]<=a[i+1])*a[i];
      a[i+1]=(t>a[i+1])*t+(t<=a[i+1])*a[i+1];
      c++;
      i++;
    }
    j++;
  }
  return c;
}



// 5. Дополнительное задание 
//2. Выполните дополнительное задание 1, но
// вместо квадратичного метода сортировки возьмите любой быстрый
// метод, дающий сложность O(N*Log_2(N)). Например, пирамидальная,
// быстрая или слиянием.

void ShellSort(int *a, int n)
  {
      int i, j, step=n/2;
      int temp;
      while(step > 0)
      {
        i = step;
        while (i < n)
        {
          temp = a[i];
          j = i; 
          while(j >= step)
          {
            if (temp<a[j-step]) a[j] = a[j - step];
            else break;
            j -= step;
          }
          a[j] = temp;
          i++;
        }
        step/= 2;
      }
  }
int ClockShellSort(int *a, int n)
  {
    int i, j, step=n/2, c=0;
    int temp;
    while(step > 0)
    {
      i = step;
      while (i < n)
      {
        temp = a[i];
        j = i; 
        while(j >= step)
        {
          if (temp<a[j-step]) a[j] = a[j - step];
          else break;
          c++;
          j -= step;
        }
        a[j] = temp;
        i++;
      }
      step/= 2;
    }
    return c;
  }



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


class Fifth
{
public:
double *func(int* a, int n)
{
    double *d=new double[2];
    
    return d;
}
};





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