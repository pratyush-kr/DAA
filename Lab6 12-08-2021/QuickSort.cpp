#include<iostream>
#include<vector>
#include<fstream>

int RandomNumber()
{
    return rand() % 100 + 1;
}

int quickSort(std::vector<int> &, const int&, const int&); //returns complexity to sort an array

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
        int complexity = quickSort(arrays[i], 0, arrays[i].size()-1);
        outfile<<arrays[i++].size()<<","<<complexity;
    }
    outfile.close();
    return 0;
}

int quickSort(std::vector<int> &arr)
{
    int complexity = 0;
}