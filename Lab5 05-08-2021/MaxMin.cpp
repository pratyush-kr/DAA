#include<iostream>
#include<fstream>
#include<vector>

int complexity = 0;

int RandomNumber()
{
    return rand()%100 + 1;
}

int DAC_Max(const std::vector<int>&, const int, const int);
int DAC_Min(const std::vector<int>&, const int, const int);
int Max(const std::vector<int>&);
int Min(const std::vector<int>&);
int BruteMax(std::vector<int>);
int BruteMin(std::vector<int>);
void swap(int &a, int &b) {a^=b^=a^=b;}

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
    std::fstream outfile("Searching_Data.csv", std::ios::out);
    std::cout<<"File Created\n";
    outfile<<"DAC_MAX,Complexity,DAC_MIN,Complexity,"
            <<"MAX,Complexity,MIN,Complexity,"
            <<"Brute_MAX,Complexity,Brute_Min,Complexity\n";
    for(int i=0; i<testcases; i++)
    {
        complexity = 0;
        DAC_Max(vec[i], 0, vec[i].size());
        outfile<<std::to_string(vec[i].size())<<","<<std::to_string(complexity)<<",";
        complexity = 0;
        DAC_Min(vec[i], 0, vec[i].size());
        outfile<<std::to_string(vec[i].size())<<","<<std::to_string(complexity)<<",";
        complexity = 0;
        Max(vec[i]);
        outfile<<std::to_string(vec[i].size())<<","<<std::to_string(complexity)<<",";
        complexity = 0;
        Min(vec[i]);
        outfile<<std::to_string(vec[i].size())<<","<<std::to_string(complexity)<<",";
        complexity = 0;
        BruteMax(vec[i]);
        outfile<<std::to_string(vec[i].size())<<","<<std::to_string(complexity)<<",";
        complexity = 0;
        BruteMin(vec[i]);
        outfile<<std::to_string(vec[i].size())<<","<<std::to_string(complexity)<<'\n';
    }
    outfile.close();
    return 0;
}

int DAC_Max(const std::vector<int> &arr, const int index, const int l)
{
    complexity++;
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
    complexity++;
    int min;
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

int Max(const std::vector<int> &arr)
{
    int max = INT32_MIN;
    for(int i=0; i<arr.size(); i++)
    {
        complexity++;
        if(arr[i] > max)
        {
            max = arr[i];
            break;
        }
    }
    return max;
}

int Min(const std::vector<int> &arr)
{
    int min = INT32_MAX;
    for(int i=0; i<arr.size(); i++)
    {
        complexity++;
        if(arr[i] > min)
        {
            min = arr[i];
            break;
        }
    }
    return min;
}

int BruteMax(std::vector<int> arr)
{
    int n = arr.size();
    int comps = n-1;
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i=0; i<comps; i++)
        {
            complexity++;
            if(arr[i] > arr[i+1])
            {
                sorted = false;
                swap(arr[i], arr[i+1]);
            }
        }
        comps--;
    }
    return arr[arr.size() - 1];
}

int BruteMin(std::vector<int> arr)
{
    int n = arr.size();
    int comps = n-1;
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i=0; i<comps; i++)
        {
            complexity++;
            if(arr[i] > arr[i+1])
            {
                sorted = false;
                swap(arr[i], arr[i+1]);
            }
        }
        comps--;
    }
    return arr[0];
}