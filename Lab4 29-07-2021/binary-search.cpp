#include<iostream>
#include<random>
#include<ctime>
#include<vector>
#include<algorithm>
#include<map>
#include<fstream>

int func_call = 0;

int randomNumber()
{
    return rand() % 100 + 1;
}

int binary_search(std::vector<int> arr, int l, int r, int key)
{
    int mid;
    while(l<=r)
    {
        func_call++;
        mid = (l+r)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return binary_search(arr, l, mid-1, key);
        else if(arr[mid] < key)
            return binary_search(arr, mid+1, r, key);
    }
    return -1;
}

int main()
{
    int testcases, n, num;
    std::cout<<"TestCases: ";
    std::cin>>testcases;
    std::vector<std::vector<int>> arrays;
    std::vector<int> *arr;
    std::map<int, bool> *mp;
    srand(time(0));
    for(int i=0; i<testcases; i++)
    {
        arr = new std::vector<int>;
        mp = new std::map<int, bool>;
        n = randomNumber();
        for(int i=0; i<n; i++)
        {
            num = randomNumber();
            if((*mp)[num]++ != true)
                arr->push_back(num);
        }
        std::sort(arr->begin(), arr->end());
        arrays.push_back(*arr);
        delete mp;
    }
    int key, time_taken;
    std::ofstream file("Bs_data.csv");
    file<<"n,timetaken\n";
    for(int i=0; i<arrays.size(); i++)
    {
        key = randomNumber();
        binary_search(arrays[i], 0, (int)arrays[i].size(), key);
        time_taken = func_call;
        func_call = 0;
        file<<arrays[i].size()<<','<<time_taken<<'\n';
    }
    return 0;
}