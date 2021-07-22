#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>

int randomNumber()
{
    return rand() % 10000 + 1;
}

int insertionSort(std::vector<int> &array)
{
    int time = 0;
    for(int step = 1; step < array.size(); step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
            time++;
        }
        array[j + 1] = key;
    }
    return time;
}

std::vector<double> compareTime(std::vector<std::vector<int>> arr)
{
    std::vector<double> times;
    clock_t start, end;
    double tim;
    int num;
    for(int i=0; i<arr.size(); i++)
    {
        num = randomNumber();
        tim = insertionSort(arr[i]);
        times.push_back(tim);
    }
    return times;
}

int main()
{
    std::ofstream outfile("iData.csv");
    std::vector<std::vector<int>> vec;
    int n, arr_size = 15, num;
    std::vector<int> *arr;
    std::cout<<"n: ";
    std::cin>>n;
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        arr_size = randomNumber();
        arr = new std::vector<int>;
        for(int j=0; j<arr_size; j++)
        {
            num = randomNumber();
            arr->push_back(num);
        }
        vec.push_back(*arr);
    }
    std::vector<double> times = compareTime(vec);
    for(int i=0; i<vec.size(); i++)
        outfile<<std::to_string(vec[i].size())<<","<<std::to_string(times[i])<<'\n';
    return 0;
}