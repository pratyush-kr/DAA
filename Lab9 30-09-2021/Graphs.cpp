#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

struct Node
{
    int data;
    vector<Node*> connectedTo;
    Node(int data) {this->data = data;}
};

struct Graph
{
    map<int, Node*> node;
    map<pair<int, int>, int> weight;
    void addEdge(int a, int b, int w=1)
    {
        if(node[a] == NULL && node[b] == NULL)
        {
            node[a] = new Node(a);
            node[b] = new Node(b);
        }
        else if(node[a] == NULL)
            node[a] = new Node(a);
        else if(node[b] == NULL)
            node[b] = new Node(b);
        node[a]->connectedTo.push_back(node[b]);
        node[b]->connectedTo.push_back(node[a]);
        weight[{a, b}] = w;
        weight[{b, a}] = w;
    }
    void bfs(int s);
    void dfs(int s);
    void dijkstra(int src);
};

int main()
{
    int edges;
    cout<<"Edges: ";
    cin>>edges;
    Graph g;
    for(int i=0; i<edges; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        g.addEdge(a, b, c);
    }
    int s;
    cout<<"Start Point: ";
    cin>>s;
    printf("bfs(%d) = ", s);
    g.bfs(s);
    printf("dfs(%d) = ", s);
    g.dfs(s);
    cout<<'\n';
    return 0;
}

void Graph::bfs(int s)
{
    if(node[s] == NULL) return;
    queue<Node*> Queue;
    map<int, bool> visited;
    Queue.push(node[s]);
    visited[s] = true;
    while(!Queue.empty())
    {
        Node *ptr = Queue.front();
        cout<<ptr->data<<" ";
        Queue.pop();
        for(auto x:ptr->connectedTo)
        {    
            if(!visited[x->data])
            {
                visited[x->data] = true;
                Queue.push(x);
            }
        }
    }
    cout<<'\n';
}

void Graph::dfs(int s)
{
    if(node[s] == NULL) return;
    static map<int, bool> visited;
    visited[s] = true;
    cout<<s<<" ";
    for(auto x:node[s]->connectedTo)
    {
        if(!visited[x->data])
        {
            visited[x->data] = true;
            dfs(x->data);
        }
    }
}

void Graph::dijkstra(int src)
{
    if(node[src] == NULL) return;
    Node *min = NULL;
    map<pair<int, int>, int> distance;
    for(auto x : node[src]->connectedTo)
    {
        distance[{src, min->data}] = distance[{min->data, src}] = weight[{src, min->data}];
    }
    distance[{src, src}] = 0;
    distance[{src, min->data}] = distance[{min->data, src}] = weight[{src, min->data}];
}