#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

class Graph
{
    private:
        int vertex;
        vector<int> *adj;
    public:
        void addEdge(int v, int w);
        void bfs(int s);
        Graph(int v);
};

Graph::Graph(int v)
{
    this->vertex = v;
    adj = new vector<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::bfs(int s)
{
    map<int, bool> visited;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        s = Q.front();
        cout<<s<<" ";
        Q.pop();
        for(auto i : adj[s])
        {
            if(!visited[i])
            {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}

int main()
{
    int s;
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 0);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 2);
    g.addEdge(4, 6);
    g.addEdge(5, 1);
    g.addEdge(5, 2);
    g.addEdge(6, 1);
    g.addEdge(6, 4);
    g.bfs(2);
    return 0;
}