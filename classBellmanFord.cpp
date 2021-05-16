#include<bits/stdc++.h>
using namespace std;


#define MAXX 999999999

class Edge
{
public:
    int src, dest, weight;
};
class Graph
{
private:
    int V, E , S;
    Edge *edge;
    int *distancee;
    int *parent;
public:
    void addEdge();
    void outputEdge();
    void printResult();
    void BellmanFord();
    void Display();
    Graph(int V, int E, int S);
    ~Graph();
};

void Graph::addEdge()
{   
    for (int i = 1; i <= V; i++)
        parent[i] = -1;
    for (int i = 0; i < E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        this->edge[i].src = u;
        this->edge[i].dest = v;
        this->edge[i].weight = w;
    }
}

void Graph::outputEdge()
{
    for (int i = 0; i < E; i++)
    {
        cout << this->edge[i].src << " " << this->edge[i].dest << " " << this->edge[i].weight << "\n";
    }
}

void Graph::BellmanFord()
{
    for (int i = 1; i <= V; i++)
        distancee[i] = MAXX;
    distancee[S] = 0;
    for (int i = 1; i <= V - 1; i++)
        for (int j = 0; j < E; j++)
            {
                int u = this->edge[j].src;
                int v = this->edge[j].dest;
                int w = this->edge[j].weight;
                if (distancee[u] != MAXX && distancee[u] + w < distancee[v])
                    {
                        distancee[v] = distancee[u] + w;
                        parent[v] = u;
                    }
            }
    for (int i = 1; i <= V; i++)
    {
        int u = this->edge[i].src;
        int v = this->edge[i].dest;
        int w = this->edge[i].weight;
        if (distancee[u] != MAXX && distancee[u] + w < distancee[v])
            {
                cout << "Graph contains negative weight cycle";
                return;
            }
    }

}

void Graph::printResult()
{
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": " << distancee[i] << "\n";
    }
}

void Graph::Display()
{
    for (int i = 1; i <= V; i++)
    {
        int temp = parent[i];
        cout << i << "<-";
        while (temp != -1)
            {
                cout << temp << "<-";
                temp = parent[temp];
            }
        cout << "\n";
        cout << "Distance : " << distancee[i];
        cout << "\n";
    }
}


Graph::Graph(int V, int E, int S)
{
    this->V = V;
    this->E = E;
    this->S = S;
    this->edge = new Edge[E+1];
    distancee = new int[V+1];
    parent = new int[V+1];
}

Graph::~Graph()
{
    delete [] edge;
}
int main()
{
    int V, E, S; 
    cin >> V >> E >> S;
    Graph g(V,E, S);
    g.addEdge();
    g.BellmanFord();
    g.Display();
    return 0;
}
