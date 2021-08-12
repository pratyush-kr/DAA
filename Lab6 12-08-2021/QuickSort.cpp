#include<iostream>
#include<vector>
#include<fstream>

int RandomNumber()
{
    return rand() % 100 + 1;
}

void swap(int &a, int &b)
{
    a ^= b ^= a ^= b;
}

void quickSort(std::vector<int> &, const int&, const int&);
int partition(std::vector<int> &, const int&, const int&);

int complexity = 0;

int main()
{
    std::vector<std::vector<int>> arrays;
    std::vector<int> *arr;
    int test_cases, size, i=0, num;
    printf("Test Cases: ");
    std::cin>>test_cases;
    srand(time(0));
    while(i++ < test_cases)
    {
        arr = new std::vector<int>;
        size = RandomNumber();
        for(int j=0; i<size; j++)
        {
            num = RandomNumber();
            arr->push_back(num);
        }
        arrays.push_back(*arr);
    }
    i=0;
    std::fstream outfile("Data.csv");
    outfile<<"N, Complexity\n";
    while(i < test_cases-1)
    {
        complexity = 0; //var in global scope
        quickSort(arrays[i], 0, arrays[i].size()-1);
        outfile<<arrays[i++].size()<<","<<complexity;
    }
    outfile.close();
    return 0;
}

void quickSort(std::vector<int> &arr, const int &left, const int &right)
{
    int pivot;
    if(left < right)
    {
        pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}

int partition(std::vector<int> &arr, const int &left, const int &right)
{
    int pivot = arr[right]; // pivot 
    int i = (left - 1);
  
    for (int j=left; j<right; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[right]); 
    return i + 1; 
}