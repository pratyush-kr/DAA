#include<iostream>
#include<vector>
#include<map>
#include<queue>
#define MAX_EDGES 100

using namespace std;


int arr[MAX_EDGES] = {INT16_MAX};

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
            nodes[b] = new Node(b);
        nodes[a]->adjList.push_back(nodes[b]);
        nodes[b]->adjList.push_back(nodes[a]);
        weights[{a, b}] = w;
        weights[{b, a}] = w;
    }
    void dfs(int s);
    void bfs(int s);
    void dijkstra(int s, int t);
};

int main()
{
    int edges, vertices;
    int a, b, w;
    printf("Edges: ");
    cin>>edges;
    printf("Vertices: ");
    cin>>vertices;
    Graph g(vertices, edges);
    printf("a b w\n");
    for(int i=0; i<edges; i++)
    {
        cin>>a>>b>>w;
        g.addEdge(a, b, w);
    }
    g.dfs(1);
    cout<<'\n';
    g.bfs(1);
    for(auto x : g.nodes[1]->adjList)

    g.dijkstra(1, 1);
    return 0;
}

void Graph::dfs(int s)
{
    static map<int, bool> visited;
    visited[s] = true;
    cout<<nodes[s]->id<<" ";
    for(auto x : nodes[s]->adjList)
        if(!visited[x->id])
        {
            visited[x->id] = true;
            dfs(x->id);
        }
}

void Graph::bfs(int s)
{
    map<int, bool> visited;
    visited[s] = true;
    queue<Node*> Q;
    Q.push(nodes[s]);
    while(!Q.empty())
    {
        Node *ptr = Q.front();
        cout<<ptr->id<<" ";
        Q.pop();
        for(auto x : ptr->adjList)
            if(!visited[x->id])
            {
                visited[x->id] = true;
                dfs(x->id);
            }
    }
    cout<<'\n';
}

void Graph::dijkstra(int s, int t)
{
    static map<int, bool> visited;
    visited[s] = true;
    int minDis = INT16_MAX;
    Node *ptr = NULL;
    for(auto x : nodes[s]->adjList)
    {
        if(!visited[x->id])
        {
        }
    }
}