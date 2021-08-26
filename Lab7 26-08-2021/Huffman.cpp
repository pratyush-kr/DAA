#include<iostream>
#include<map>
#include<algorithm>

class Node
{
    public:
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

class Frequencies
{
    public:
        char data;
        int freq;
};

class String
{
    private:
        std::string str;
        Frequencies *F;
        int n; //distinct elements
    public:
        String(std::string str);
        int length(){return str.length();}
        void printFrequencies()
        {
            for(int i=0; i<n; i++)
                printf("%c %d\n", F[i].data, F[i].freq);
        }
        Node* buildTree();
};

int main()
{
    String str("ABABCABADCADE");
    int length = str.length();
    str.printFrequencies();
    Node *MimHeap = str.buildTree();
    return 0;
}

String::String(std::string str)
{
    std::map<char, int> mp;
    this->str = str;
    for(int i=0; i<str.size(); i++)
        mp[str[i]]++;
    n = mp.size();
    F = new Frequencies[n];
    int j=0;
    for(auto i : mp)
    {
        F[j].data = i.first;
        F[j++].freq = i.second;
    }
    std::sort(&F[0], &F[n], [](const auto &a, const auto &b)
        {return (a.freq < b.freq)? 1:0;}
    );
}

Node* String::buildTree()
{
    Node *left = NULL, *right = NULL, *root = NULL;
    int n = this->n;
    while(n > 2)
    {
        if(right == NULL) left = new Node(F[0].data, F[0].freq);
        right = new Node(F[1].data, F[1].freq);
        root = new Node(left->frequency+right->frequency);
        root->left = left;
        root->right = right;
        left = right;
        n--;
    }
}