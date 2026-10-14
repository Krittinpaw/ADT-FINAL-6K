#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<vector<int>> adj;
vector<string> nodename;

void dfs(int u , vector<bool> &visit , stack<int> &stack){

    visit[u] = true;
    for (int v : adj[u])
    {
        if (!visit[v])
        {
            dfs(v,visit,stack);
        }
        
    }

    stack.push(u);
    
}
void inputname(){

    nodename.resize(8);
    for (int i = 0; i < nodename.size(); i++)
    {
        cin >> nodename[i];
    }
    
}

void inputgraph(){

    adj.resize(nodename.size());
    int m;
    cin >> m;

    int u ,v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
}

