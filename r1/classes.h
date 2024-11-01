#include <iostream>

using namespace std;
// Реализуйте стек на основе массива со счетчиком (операции push(), pop(), last(), isEmpty() и вспомогательную функцию print()).
// Реализуйте очередь на основе массива со счетчиком и сдвигом при (операции enqueue(), dequeue(), first(), isEmpty() и вспомогательную функцию print()).
// Реализуйте список на основе массива со сдвигом элементов при добавлении/удалении.
// Реализуйте множество на основе массива с пометкой элементов. Использование обертки - по желанию.
// Требования и рекомендации. Для реализации рекомендуется использовать любой компилируемый язык программирования со статической типизацией (C/C++, Java, C#).Не рекомендуется использовать языки Python и JavaScript.

class Stack
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
    Stack()
    {
        init();
    }
    int last()
    {
        int r=0;
        if(array[0]>0)
            r+=array[array[0]];
        else
            cout<<"Error"<<endl;
        return r;
    }
    void push(int a)
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

    void pop()
    {   
        if(array[0]>0)
        {
            int i=0;
            int *newarray= new int[array[0]];
            while(i<array[0])
            {
                newarray[i]=array[i];
                i++;
            }
            destroy();
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
        
        int i=0;
        if(array[0]>0)
            while (i<array[0]+1)
                {
                    cout<<array[i]<<' ';
                    i++;
                }
        else 
        cout<<0<<' ';
    }

};

class Queue
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
    Queue()
    {
        init();
    }
    int first()
    {
        int r=0;
        if(array[0]>0)
            r+=array[array[0]];
        else
            cout<<"Error"<<endl;
        return r;
    }
    void enqueue(int a)
    {   
        int i=0;
        int *newarray= new int[array[0]];
        while(i<=array[0])
        {
            newarray[i]=array[i];
            i++;
        }
        newarray[i]=a;

        destroy();
        array=newarray;
        array[0]++;

        // delete [] newarray;
        // newarray=nullptr;

    }

    void dequeue()
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
    bool isEmpty()
    {
        return array[0]>0;
    }
    void print()
    {
        int i=array[0];
        while (i!=0)
        {
            cout<<array[i]<<' ';
            i--;
        }
        
    }

};

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