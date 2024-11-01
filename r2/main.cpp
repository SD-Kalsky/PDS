#include <iostream>
#include "classes.h"
using namespace std;

int main()
{
  int n=10, m=10;
  int *a=new int[n];
  randomize(a,n);
  // a[n-1]=m;
  println(a,n);
  cout<<ClockShellSort(a, n)<<endl;
  println(a,n);
  // cout<<endl;
  // cout<<readClockBinary(a, n, m);

  return 0;
}