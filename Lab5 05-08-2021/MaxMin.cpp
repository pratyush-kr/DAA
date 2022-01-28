#include<iostream>
#include<vector>

int RandomNumber()
{
    return rand()%100 + 1;
}

int DAC_Max(const std::vector<int>&, const int, const int);
int DAC_Min(const std::vector<int>&, const int, const int);

int main()
{
    std::vector<std::vector<int>> vec;
    std::vector<int> *arr;
    int testcases, n;
    std::cout<<"TestCases: ";
    std::cin>>testcases;
    for(int i=0; i<testcases; i++)
    {
        n = RandomNumber();
        arr = new std::vector<int>;
        for(int j=0; j<n; j++)
            arr->push_back(RandomNumber());
        vec.push_back(*arr);
    }
    for(int i=0; i<testcases; i++)
    {
        printf("Max of Array %d = %d\n", i+1, DAC_Max(vec[i], 0, vec[i].size()));
        printf("Max of Array %d = %d\n\n", i+1, DAC_Min(vec[i], 0, vec[i].size()));
    }
    return 0;
}

int DAC_Max(const std::vector<int> &arr, const int index, const int l)
{
    int max = INT32_MIN;
    if(index >= l-2)
    {
        if(arr[index] > arr[index + 1])
            return arr[index];
        else
            return arr[index+1];
    }
    max = DAC_Max(arr, index+1, l);
    if(arr[index] > max)
        return arr[index];
    else
        return max;
}

int DAC_Min(const std::vector<int> &arr, const int index, const int l)
{
    int min = INT32_MAX;
    if(index >= l - 2)
    {
        if(arr[index] < arr[index + 1])
          return arr[index];
        else
          return arr[index + 1];
    }
     
    min = DAC_Min(arr, index + 1, l);  
    if(arr[index] < min)
       return arr[index];
    else
       return min;
}