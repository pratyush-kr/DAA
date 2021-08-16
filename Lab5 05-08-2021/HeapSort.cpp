#include<iostream>
#include<vector>
#include<ctime>

int randomNumber() {return rand() % 20 + 1;}
void swap(int &a, int &b) {a ^=b ^= a ^= b;}
void heapify(std::vector<int>&, int, int);
void heapSort(std::vector<int>&);
void print(std::vector<int>&);


int main()
{
    std::vector<std::vector<int>> arrays;
    std::vector<int> *arr;
    int test_cases, size;
    printf("Test Cases: ");
    std::cin>>test_cases;
    srand(time(0));
    for(int i=0; i<test_cases; i++)
    {
        size = randomNumber();
        arr = new std::vector<int>;
        for(int j=0; j<size; j++)
            arr->push_back(randomNumber());
        arrays.push_back(*arr);
    }
    for(int i=0; i<test_cases; i++)
        print(arrays[i]);
    for(int i=0; i<test_cases; i++)
        heapSort(arrays[i]);
    printf("After Sorting\n");
    for(int i=0; i<test_cases; i++)
        print(arrays[i]);
    return 0;
}

void heapify(std::vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
      largest = left;
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
}
  
void heapSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
}

void print(std::vector<int> &arr)
{
    printf("{%d", arr[0]);
    for(int i=1; i<arr.size(); i++)
        printf(", %d", arr[i]);
    std::cout<<"}\n";
}