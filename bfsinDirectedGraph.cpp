#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int V, E, S;
void BFS(int node)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        cout << u << " ";
        visited[u] = true;
        for (int i = 0 ; i < adj[u].size(); ++i)
            if(!visited[adj[u][i]])
            {
                visited[adj[u][i]] = true;
                q.push(adj[u][i]);
            }
    }
}
void test_case()
{
    memset(visited,false,sizeof(visited));
    for (int i = 0; i <= 1001; ++i)
        adj[i].clear();
    cin >> V >> E >> S;
    for (int i = 0 ; i < E ;++i)
        {
            int v,w;
            cin >> v >> w;
            adj[v].push_back(w);
            // adj[w].push_back(v);
        }
    BFS(S);
    cout << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        test_case();
    }
    return 0;
}