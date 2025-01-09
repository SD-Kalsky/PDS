#include <iostream>

using namespace std;


template<typename T> void print(T a)
{
    cout<<a;
}
    
template<typename T> void println(T a)
{

    cout<<a<<endl;

}
void println()
{

    cout<<endl;

}
void menu()
{
    println("Input");
    println("1 to open the 1st lab work"); 
    println("2 to open the 2nd lab work");
    println("3 to open the 3rd lab work");
    println("4 to open the 4th lab work");
    println("");
    println("Another number to terminate");
}

void print_lab()
{
    println("Input");
    println("1 to show 1st ex"); 
    println("2 to show 2st ex");
    println("3 to show 3st ex");
    println("4 to show 4st ex");
    println("5 to show 5st ex");
    println();

    println("Another number to back to start");
}



void end()
{
    println("The program is terminated");
    println("***");
}