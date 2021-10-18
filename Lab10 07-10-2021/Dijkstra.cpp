#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int id;
    vector<Node*> adj;
};

struct Graph
{
    int vertices;
    int edges;
    vector<Node*> nodes;
    
};

int main()
{
    return 0;
}