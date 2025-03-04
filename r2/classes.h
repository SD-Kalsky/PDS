#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;


int readClock(int* a, int n, int f);
int readClockBinary(int* a, int n, int f);
void charTable();
void bubbleSort(int* a, int n);
int clockBubbleSort(int* a, int n);
void ShellSort(int *a, int n);
int ClockShellSort(int *a, int n);

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
  int c=0, i=0, min=0, max=n, mid;
  bool b=false;

  while (min<=max) 
  {
    mid=(min+max)/2;
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
  int i=0, f=100, size=1000;
  int* a=new int[size], *b;
  randomize(a, size);
  a[size-1]=f;
  b=a;
  int n=ClockShellSort(b,  size);
  
  i=0;
  cout<<"| K  |   the Number Clocks of the simple search  |  the Number Clocks of the binary search |"<<endl;
  while (i<=50)
  {
    //f=i+1;
    cout<<"| "<<i+1<<" | "<<readClock(a, size, f)<<" | "<<readClockBinary(b, size, f)+n<<" |"<<endl;
    i++;
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


