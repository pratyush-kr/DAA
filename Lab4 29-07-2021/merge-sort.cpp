#include<iostream>
#include<random>
#include<ctime>
#include<vector>
#include<algorithm>
#include<fstream>

int func_call = 0;

int randomNumber()
{
    return rand() % 100 + 1;
}

void merge(std::vector<int> &arr, int l, int m , int r)
{
    int n1, n2;
    n1 = m;
    n2 = r;
    std::vector<int> arr1, arr2, array;
    for(int i=l; i<n1; i++)
        arr1.push_back(arr[i]);
    for(int i=n1; i<n2; i++)
        arr2.push_back(arr[i]);
    int i=0, j=0, z=l;
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
            arr[z++] = arr1[i++];
        else
            arr[z++] = arr2[j++];
    }
    while(i<arr1.size())
        arr[z++] = arr1[i++];
    while(j<arr2.size())
        arr[z++] = arr2[j++];
}

void merge_sort(std::vector<int> &arr, int l, int r)
{
    func_call++;
    if(l < r)
    {
        int mid = (l+r)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int testcases, n, num;
    std::cout<<"TestCases: ";
    std::cin>>testcases;
    std::vector<std::vector<int>> arrays;
    std::vector<int> *arr;
    srand(time(0));
    for(int i=0; i<testcases; i++)
    {
        arr = new std::vector<int>;
        n = randomNumber();
        for(int i=0; i<n; i++)
        {
            num = randomNumber();
            arr->push_back(num);
        }
        arrays.push_back(*arr);
    }
    int key, time_taken;
    std::ofstream file("MS_data.csv");
    file<<"n,timetaken\n";
    for(int i=0; i<arrays.size(); i++)
    {
        key = randomNumber();
        merge_sort(arrays[i], 0, arrays[i].size());
        time_taken = func_call;
        func_call = 0;
        file<<arrays[i].size()<<','<<time_taken<<'\n';
    }
    return 0;
}