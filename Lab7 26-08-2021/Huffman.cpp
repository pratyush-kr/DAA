#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
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
    void showTree(Node *root); //Shows Tree in level order
};

int main()
{
    string str;
    cout<<"String: ";
    getline(cin, str);
    cout<<str<<'\n';
    String msg(str);   
    vector<Node*> LeafNodes;
    int i=0;
    for(auto mp : msg.freq)
        LeafNodes.push_back(new Node(mp.second, mp.first));
    sort(LeafNodes.begin(), LeafNodes.end(), [](Node *a, Node *b){return (a->frequecy > b->frequecy)? 1:0;});
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
    if(root->left->symbol == ch) {str += "0"; return str;}
    else if(root->right->symbol == ch) {str += "1"; return str;}
    else if(root->left->symbol == '\0') {str += "0"; return bstEncoder(root->left, ch, str);}
    else if(root->right->symbol == '\0') {str += "1"; return bstEncoder(root->right, ch, str);}
    return str;
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
        if(ch == '0')
            r = r->left;
        else if(ch == '1')
            r = r->right;
        if(r->symbol != '\0')
        {
            s += r->symbol;
            r = root;
        }
    }
    return s;
}

void HuffmanTree::buildTree(Node *root, vector<Node*> LeafNodes, int sum)
{
    int i=0;
    Node *r = root;
    for(i=0; i<LeafNodes.size()-2; i++)
    {
        sum = sum - LeafNodes[i]->frequecy;
        Node *node = LeafNodes[i];
        if(node->frequecy < sum)
        {
            root->left = node;
            root->right = new Node(sum);
            root = root->right;
        }
        else
        {
            root->left = new Node(sum);
            root->right = node;
            root = root->left;
        }
    }
    Node *n1 = LeafNodes[i];
    Node *n2 = LeafNodes[i+1];
    root->left = (n1->frequecy < n2->frequecy)? n1:n2;
    root->right = (n1->frequecy >= n2->frequecy)? n1:n2;
    showTree(r);
}

void HuffmanTree::showTree(Node *root)
{
    if(root == NULL)
        return;
    queue<Node*> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        Node *ptr = Queue.front();
        Queue.pop();
        if(ptr->symbol)
            printf("(%c, %d)\n", ptr->symbol, ptr->frequecy);
        else
            printf("%d\n", ptr->frequecy);
        if(ptr->left) Queue.push(ptr->left);
        if(ptr->right) Queue.push(ptr->right);
    }
}