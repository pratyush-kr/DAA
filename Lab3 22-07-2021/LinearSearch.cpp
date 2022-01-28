#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>

int randomNumber()
{
    return rand() % (100) + 1;
}

std::vector<double> compareTime(std::vector<std::vector<int>> arr)
{
    std::vector<double> times;
    double tim;
    int num;
    srand(time(0));
    for(int i=0; i<arr.size(); i++)
    {
        tim = arr[i].size();
        num = randomNumber();
        for(int j=1; j<arr[i].size(); j++)
            if(arr[i][j] == num)
            {
                tim = j;
                break;
            }
        
        times.push_back(tim);
    }
    return times;
}

int main()
{
    std::ofstream outfile("LS_Data.csv");
    std::vector<std::vector<int>> vec;
    int n, testcases, num;
    std::vector<int> *arr;
    std::cout<<"TestCases: ";
    std::cin>>testcases;
    srand(time(0));
    for(int i=0; i<testcases; i++)
    {
        n = randomNumber();
        arr = new std::vector<int>;
        for(int j=0; j<n; j++)
        {
            num = randomNumber();
            arr->push_back(num);
        }
        vec.push_back(*arr);
    }
    outfile<<"n,"<<"Looped\n";
    std::vector<double> times = compareTime(vec);
    for(int i=0; i<vec.size(); i++)
        outfile<<std::to_string(vec[i].size())<<","<<std::to_string(times[i])<<'\n';
    return 0;
}