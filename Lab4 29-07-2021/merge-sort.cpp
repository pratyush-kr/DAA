#include<iostream>
#include<random>
#include<ctime>
#include<vector>
#include<algorithm>
#include<fstream>
#include<map>

int func_call = 0;

int randomNumber()
{
    return rand() % 10000 + 1;
}

void merge(std::vector<int> &arr, const int l, const int m , const int r)
{
    std::vector<int> array;
    int i=l, j=m+1;
    while(i <= m && j <= r)
    {
        func_call++;
        if(arr[i] <= arr[j])
        {
            array.push_back(arr[i]);
            i++;
        }
        else
        {
            array.push_back(arr[j]);
            j++;
        }
    }
    while(i <= m)
    {
        array.push_back(arr[i]);
        i++;
    }
    while(j <= r)
    {
        array.push_back(arr[j]);
        j++;
    }
    for(int i=l; i<=r; i++)
        arr[i] = array[i - l];
}

void merge_sort(std::vector<int> &arr, const int l, const int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
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
    int time_taken;
    std::ofstream file("MS_data.csv");
    file<<"n,timetaken\n";
    for(int i=0; i<arrays.size(); i++)
    {
        func_call = 0;
        merge_sort(arrays[i], 0, arrays[i].size()-1);
        time_taken = func_call;
        file<<arrays[i].size()<<','<<time_taken<<'\n';
    }
    return 0;
}