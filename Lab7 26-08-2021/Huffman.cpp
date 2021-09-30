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

struct HuffmanTree
{
    Node *root;
    string bstEncoder(Node *root, char ch, string str);
    string encode(string str, Node *root);
    string decode(string str, Node *root);
    void buildTree(Node *root, vector<Node*> LeafNodes, int sum);
};

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
    printf("sorted: ");
    for(auto ptr : LeafNodes)
        printf("%c", ptr->symbol);
    cout<<'\n';
    int fsum=0;
    for(auto node : LeafNodes)
        fsum += node->frequecy;
    printf("total length = %d\nfrequecy sum = %d\n", msg.size, fsum);
    HuffmanTree tree;
    tree.root = new Node(fsum, '\0');
    tree.buildTree(tree.root, LeafNodes, fsum);
    string e, d;
    e = tree.encode(str, tree.root);
    cout<<e<<'\n';
    d = tree.decode(e, tree.root);
    cout<<d<<'\n';
    return 0;
}

string HuffmanTree::bstEncoder(Node *root, char ch, string str = "")
{
    if(root->left->symbol == ch)
    {
        str += "1";
        return str;
    }
    else if(root->right->symbol == ch)
    {
        str += "0";
        return str;
    }
    else
    {
        str += "0";
        return bstEncoder(root->right, ch, str);
    }
}

string HuffmanTree::encode(string str, Node *root)
{
    string s = "";
    for(auto ch : str)
        s += bstEncoder(root, ch);
    return s;
}

string HuffmanTree::decode(string str, Node *root)
{
    string s="";
    Node *r = root;
    for(char ch : str)
    {
        if(ch == '1')
        {
            s += r->left->symbol;
            r = root;
        }
        else if(ch == '0')
        {
            r = r->right;
            if(r->symbol != '\0')
            {
                s += r->symbol;
                r = root;
            }
        }
    }
    return s;
}

void HuffmanTree::buildTree(Node *root, vector<Node*> LeafNodes, int sum)
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