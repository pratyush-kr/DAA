#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct String;
struct HuffmanTree;
struct Node;

struct Node
{
    int frequecy;
    char symbol;
    Node *left;
    Node *right;
    Node()
    {
        frequecy = 1;
        symbol = '\0';
    }
    Node(int f, char s = '\0')
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

void buildTree(Node *root, vector<Node*> LeafNodes, int sum)
{
    int i=0;
    for(i=0; i<LeafNodes.size()-2; i++)
    {
        root->left = LeafNodes[i];
        sum = sum - LeafNodes[i]->frequecy;
        root->right = new Node(sum);
        root = root->right;
    }
    root->left = LeafNodes[i];
    root->right = LeafNodes[i+1];
}

int main()
{
    string str;
    getline(cin, str);
    cout<<str<<'\n';
    String msg(str);   
    vector<Node*> LeafNodes;
    int i=0;
    for(auto mp : msg.freq)
        LeafNodes.push_back(new Node(mp.second, mp.first));
    sort(LeafNodes.begin(), LeafNodes.end(), [](Node *a, Node *b){return (a->frequecy < b->frequecy)? 1:0;});
    int fsum=0;
    for(auto node : LeafNodes)
        fsum += node->frequecy;
    printf("total length = %d\nfrequecy sum = %d\n", msg.size, fsum);
    Node *root = new Node(fsum, '\0');
    buildTree(root, LeafNodes, fsum);
    return 0;
}