#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<vector<int>> adj;
vector<string> nodename;



void dfs(int u ,vector<bool> &visit , stack<int> &stack){

    visit[u] = true;
    for ( int v : adj[u])
    {
        if (!visit[v])
        {
            dfs(v,visit,stack);
        }
        
    }

    stack.push(u);
    
}

void inputnodename(){

    int n;
    cin >> n;
    nodename.resize(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number #" << i;
        cin >> nodename[i];
    }
    
}

void inputgraph(){

    adj.resize(nodename.size());
    int n,m;
    cin >> n >> m;

    int u,v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    
}

void topological(){

    if (adj.empty() || nodename.empty())
    {
        cout << "pls enter infor mation first";
        return;
    }

    vector<bool> visit(nodename.size(),false);
    stack<int> stack;

    int n = nodename.size();

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            dfs(i,visit,stack);
        }
        
    }

    bool first = true;

    while (!stack.empty())
    {
        int u = stack.top();
        stack.pop();

        if (!first)
        {
            cout << " -> ";
        }

        cout << nodename[u];

        first = false;
        
    }
    
    
    
}

int main() {
    inputnodename();
    inputgraph();
    topological();

    return 0;
}