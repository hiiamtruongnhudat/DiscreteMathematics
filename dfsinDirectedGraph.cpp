#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001] = {false};
int V, E, S;
void __init__()
{   
    for (int i = 0 ; i < 1001; ++i)
        adj[i].clear();
    cin >> V >> E >> S;
    for (int i = 0 ; i < E; ++i)
        {
            int v, w;
            cin >> v >> w;
            adj[v].push_back(w);
        }
}
void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < adj[node].size(); i++)
        if(!visited[adj[node][i]])
            DFS(adj[node][i]);
}
void test_case()
{   
    memset(visited,false,sizeof(visited));
    __init__();
    DFS(S);
    cout << "\n";
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