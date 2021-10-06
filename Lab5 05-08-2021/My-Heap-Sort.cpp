#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

struct Array
{
    vector<int> *array;
    Array()
    {
        array = new vector<int>;
    }
    friend istream& operator >> (istream &in, Array arr);
    friend ostream& operator << (ostream &out, Array arr);
    void maxHeapify(int, int);
    void buildMaxHeap();
    void sort();
};

int main()
{
    int n;
    cout<<"n: ";
    cin>>n;
    Array arr;
    cout<<"Array: ";
    cin>>arr;
    cout<<arr;
    arr.sort();
    cout<<"Sorted Array:\n"<<arr;
    return 0;
}

istream& operator >> (istream &in, Array arr)
{
    int element;
    in>>element;
    arr.array->push_back(element);
    return in;
}

ostream& operator << (ostream &out, Array arr)
{
    out<<"{"<<(*arr.array)[0];
    for(int i=1; i<arr.array->size(); i++)
        out<<", "<<(*arr.array)[i];
    out<<"}\n";
    return out;
}

void Array::maxHeapify(int i, int n)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    largest = (l < n && array[largest] < array[l])? l:largest;
    largest = (r < n && array[largest] < array[r])? r:largest;
    if(largest != i)
    {
        swap(array[i], array[largest]);
        maxHeapify(largest, n);
    }
}

void Array::buildMaxHeap()
{
    int size = array->size();
    int startIdx = size/2 - 1;
    for(int i=startIdx; i>=0; i--)
        maxHeapify(i, size);
}

void Array::sort()
{
    int size = array->size();
    buildMaxHeap();
    for(int i=size-1; i>=0; i--)
    {
        swap(array[0], array[i]);
        maxHeapify(0, i);
    }
}