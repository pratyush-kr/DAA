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