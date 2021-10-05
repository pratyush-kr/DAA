#include<iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

struct Array
{
    int *array;
    int size;
    Array(int n)
    {
        size = n;
        array = new int[n];
    }
    int* begin(){return &array[0];}
    int *end(){return &array[size-1];}
    friend istream& operator >> (istream &in, Array arr);
    friend ostream& operator << (ostream &out, Array arr);
    void heapify(int);
    void buildHeap();
    void sort();
};

int main()
{
    int n;
    cout<<"n: ";
    cin>>n;
    Array arr(n);
    cout<<"Array: ";
    cin>>arr;
    cout<<arr;
    arr.buildHeap();
    cout<<arr;
    return 0;
}

istream& operator >> (istream &in, Array arr)
{
    for(int i=0; i<arr.size; i++)
        in>>arr.array[i];
    return in;
}

ostream& operator << (ostream &out, Array arr)
{
    out<<"{"<<arr.array[0];
    for(int i=1; i<arr.size; i++)
        out<<", "<<arr.array[i];
    out<<"}\n";
    return out;
}

void Array::heapify(int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(array[i] < array[l] || array[i] < array[r])
    {
        largest = (array[l] > array[r])? l : r;
        swap(array[i], array[largest]);
        heapify(largest);
    }
}

void Array::buildHeap()
{
    int startIdx = size/2 - 1;
    for(int i=startIdx; i>=0; i--)
        heapify(i);
}

void Array::sort()
{
    buildHeap();
    for(int i=size-1; i>=0; i--)
    {
        swap(array[0], array[i]);
        heapify(0);
    }
}