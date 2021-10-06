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
    vector<int> array;
    friend ostream& operator << (ostream &out, const Array &arr);
    void maxHeapify(int, int);
    void buildMaxHeap();
    void maxSort();
    void minHeapify(int, int);
    void buildMinHeap();
    void minSort();
};

int main()
{
    Array *arr;
    string command;
    while(1)
    {
        cout<<"Command: ";
        cin>>command;
        if(command == "exit")
            break;
        else if(command == "new")
        {
            int n;
            cout<<"n: ";
            cin>>n;
            arr = new Array;
            cout<<"Array: ";
            int x;
            for(int i=0; i<n; i++)
            {
                cin>>x;
                arr->array.push_back(x);
            }
        }
        else if(command == "display")
            cout<<(*arr);
        else if(command == "Max-Heap-Sort")
            arr->maxSort();
        else if(command == "Min-Heap-Sort")
            arr->minSort();
    }
    return 0;
}

ostream& operator << (ostream &out, const Array &arr)
{
    out<<"{"<<arr.array[0];
    for(int i=1; i<arr.array.size(); i++)
        out<<", "<<arr.array[i];
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
    int size = array.size();
    int startIdx = size/2 - 1;
    for(int i=startIdx; i>=0; i--)
        maxHeapify(i, size);
}

void Array::maxSort()
{
    int size = array.size();
    buildMaxHeap();
    for(int i=size-1; i>=0; i--)
    {
        swap(array[0], array[i]);
        maxHeapify(0, i);
    }
}

void Array::minSort()
{
    int size = array.size();
    buildMinHeap();
    for(int i=size-1; i>0; i--)
    {
        swap(array[0], array[i]);
        minHeapify(0, i);
    }
}

void Array::buildMinHeap()
{
    int size = array.size();
    int startIdx = size/2 - 1;
    for(int i=startIdx; i>=0; i--)
        minHeapify(i, size);
}

void Array::minHeapify(int i, int n)
{
    int smallest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    smallest = (l<n && array[smallest] > array[l])? l:smallest;
    smallest = (r<n && array[smallest] > array[r])? r:smallest;
    if(smallest != i)
    {
        swap(array[smallest], array[i]);
        minHeapify(smallest, n);
    }
}