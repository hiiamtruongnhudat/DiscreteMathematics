#include<bits/stdc++.h>
using namespace std;

#define MAXX 999999
int V, E, S;
vector<pair<int,int>> adj[1001];
int distancee[1001];
bool visited[1001];
void __init__()
{
    cin >> V >> E >> S;
    for (int i = 0; i < E ; ++i)
        {
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
    for (int i = 1; i<= 1001; i++)  
        distancee[i] = MAXX;
    distancee[S] = 0;
}
int findMinVertex()
{
    int minVertex = -1;
    for (int i = 1; i <= V; ++i)
        if(!visited[i] && (minVertex == -1 || distancee[minVertex] > distancee[i]))
            minVertex = i;
    return minVertex;
}
void Dijkstra(int node)
{
    for (int i = 1 ; i <= V; ++i)
        {
            int minVertex = findMinVertex();
            visited[minVertex] = true;
            for (int i = 0; i < adj[minVertex].size(); ++i)
                {   
                    if(!visited[adj[minVertex][i].first] && distancee[adj[minVertex][i].first] > distancee[minVertex] + adj[minVertex][i].second)
                    {   
                        distancee[adj[minVertex][i].first] = distancee[minVertex] + adj[minVertex][i].second;
                    }
                }
        }
    for (int i = 1; i <= V; ++i)
        cout << distancee[i] << " ";
}
void test_case()
{
    Dijkstra(S);
}
int main()
{   
    // __init__();
    // test_case();
    int t; cin >> t;
    while (t--)
    {
        __init__();
        test_case();
        cout << endl;
    }
    return 0;
}