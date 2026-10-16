#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> adj;
vector<string> nodename;

void dfs(int n , vector<bool> &visit , stack<int> &sstack){

    visit[n] = true;
    for (int v : adj[n])
    {
        if (!visit[v])
        {
            dfs(v,visit,sstack);
        }
        
    }

    sstack.push(n);
    
}

void inputnodename(){

    int n;
    cin >> n;
    nodename.resize(n);

    

    for (int i = 0; i < n; i++)
    {
        cout << "enter the name";
        cin >> nodename[i];
    }
    
    
}

void inputgraph(){

    int m;
    cin >> m;

    int u,v;
    int n = nodename.size();
    adj.assign(n,vector<int>());
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    

}

void topological(){

    if (!adj.empty() || !nodename.empty())
    {
        cout << "Pleas enter first";
        return;
    }

    stack<int> sstack;
    int n = nodename.size();
    vector<bool> visit(n,false);

    for (int i = 0; i < n; i++)
    {
        dfs(i,visit,sstack);
    }

    bool first = true;
    while (!sstack.empty())
    {
        if (!first)
        {
            cout<< "->";
        }

        cout << nodename[sstack.top()];
        sstack.pop();
        first = true;

        
    }

    cout <<"\n";
    
    
    
    
}