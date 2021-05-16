#include<bits/stdc++.h>
using namespace std;
#define MAXX 9999999
class Edge
{
public:
    int src, dest, weight;
};
class Graph
{
private:
    int V, E;
    int *distancee;
    Edge *edge;
public:
    void addEdge();
    bool isNegativeCycle();
    Graph(int V, int E);
    ~Graph();
};
void Graph::addEdge()
{   
    for (int i = 0 ; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            this->edge[i].src = u;
            this->edge[i].dest = v;
            this->edge[i].weight = w;
        }
}
bool Graph::isNegativeCycle()
{
    for (int i = 1; i<= V; i++)
        distancee[i] = MAXX;
    distancee[1] = 0;
    for (int i = 1; i <= V-1;i++)
        for (int j = 0; j < E; j++)
            {
                int u = this->edge[j].src;
                int v = this->edge[j].dest;
                int w = this->edge[j].weight;
                if (distancee[u] != MAXX && distancee[v] > distancee[u] + w)
                    distancee[v] = distancee[u] + w;
            }
    for (int j = 0; j < E; j++)
        {
            int u = this->edge[j].src;
            int v = this->edge[j].dest;
            int w = this->edge[j].weight;
            if (distancee[u] != MAXX && distancee[v] > distancee[u] + w)
                return true;
        }
    return false;
}
Graph::Graph(int V, int E)
{
    this->V = V;
    this->E = E;
    this->edge = new Edge[V+1];
    distancee = new int[V+1];
}

Graph::~Graph()
{   
    delete [] edge;
    delete [] distancee;
}
void test_case()
{
    int V,E;
    cin >> V >> E;
    Graph g(V,E);
    g.addEdge();
    cout << g.isNegativeCycle() << "\n";
    g.~Graph();
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        test_case();
    }
    return 0;
}