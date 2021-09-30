#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct String;
struct HuffmanTree;
struct Node;

struct Node
{
    int frequecy;
    char symbol;
    Node()
    {
        frequecy = 1;
        symbol = '\0';
    }
    Node(char s, int f)
    {
        frequecy = f;
        symbol = s;
    }
};

struct HuffmanTree
{
    void buildMinHeap();

};
struct String
{
    int size;
    string str;
    map<char, int> freq;
    String(const string &str)
    {
        size = str.size();
        this->str = str;
        for(auto i : str)
            freq[i]++;
    }
};

int main()
{
    map<char, int> freq;
    string str;
    getline(cin, str);
    cout<<str<<'\n';
    for(auto ch : str)
        freq[ch]++;
    vector<Node*> LeafNodes;
    int i=0;
    for(auto mp : freq)
        LeafNodes.push_back(new Node(mp.first, mp.second));
    sort(LeafNodes.begin(), LeafNodes.end(), [])
    return 0;
}