#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Node
{
    int id;
    vector<Node*> adjList;
    Node(int id){this->id = id;}
};

struct Graph
{
    int vertices;
    int edges;
    map<int, Node*> nodes;
    map<pair<int, int>, int> weights;
    Graph(int vertices, int edges)
    {
        this->vertices = vertices;
        this->edges = edges;
    }
    void addEdge(int a, int b, int w = 0)
    {
        if(nodes[a] == NULL && nodes[b] == NULL)
        {
            nodes[a] = new Node(a);
            nodes[b] = new Node(b);
        }
        else if(nodes[a] == NULL)
            nodes[a] = new Node(a);
        else if(nodes[b] == NULL)
            nodes[b] = NULL;
        nodes[a]->adjList.push_back(nodes[b]);
        nodes[b]->adjList.push_back(nodes[a]);
        weights[{a, b}] = w;
        weights[{b, a}] = w;
    }
};

int main()
{
    int edges, vertices;
    printf("Edges: ");
    cin>>edges;
    printf("Vertices: ");
    cin>>vertices;
    return 0;
}