#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

struct Node
{
    char data;
    int frequency;
    Node* left;
    Node* right;
    Node(char data, int frequency)
    {
        this->data = data;
        this->frequency = frequency;
        left = right = NULL;
    }
    Node(int frequency)
    {
        data = '\0';
        this->frequency = frequency;
    }
    Node()
    {
        data = '\0';
        frequency = 0;
        left = right = NULL;
    }
};

struct Info
{
    char data;
    int frequency;
    Info(char data, int frequency)
    {
        this->data = data;
        this->frequency = frequency;
    }
};

std::vector<Info> count_frequency(const std::string &);
void heapify(Node* [], int);

int main()
{
    std::string str = "ABCACBACBABCABCBABCBABBACBBCAB";
    int size = str.size();
    //calculate frequency of each element
    std::vector<Info> info = count_frequency(str);
    //sort info as per frequencies
    std::sort(info.begin(), info.end(),
    [](const Info &a, const Info &b)
    {return a.frequency < b.frequency;} //comparator
    );
    //print info of str
    for(auto x : info)
        printf("%c %d\n", x.data, x.frequency);
    int distict_elements = info.size();
    Node* heap[distict_elements+1];
    heap[0] = NULL;
    int i=1;
    for(auto x : info)
        heap[i] = new Node(x.data, x.frequency);
    for(int i=2; i<=distict_elements; i++)
        heapify(heap, i);
    return 0;
}

std::vector<Info> count_frequency(const std::string &str)
{
    std::vector<Info> info;
    int size = str.size();
    std::map<char, int> mp;
    Info *ptr;
    for(int i=0; i<size; i++)
        mp[str[i]]++;
    for(auto i : mp)
    {
        ptr = new Info(i.first, i.second);
        info.push_back(*ptr);
    }
    return info;
}

void heapify(Node* arr[], int n)
{
    int i = n;
    Node *tmp = arr[i];
    while(i>1 && arr[i]->frequency > arr[i/2]->frequency)
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[n] = tmp;
}