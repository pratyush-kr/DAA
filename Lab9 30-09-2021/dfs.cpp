#include <bits/stdc++.h>
using namespace std;

map<int, bool> visited;

class Graph 
{
    private:
        int vertex;
        vector<int> *adj;
    public:
        void addEdge(int v, int w);
        void DFS(int v);
        Graph(int v)
        {
            vertex = v;
            adj = new vector<int>[v];
        }
};
  
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
  
void Graph::DFS(int v)
{
    visited[v] = true;
    cout<<v<<" ";
    for(int i : adj[v])
        if(!visited[i])
            DFS(i);
}
  
int main()
{
    Graph g(7);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);
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
    g.DFS(2);
    return 0;
}