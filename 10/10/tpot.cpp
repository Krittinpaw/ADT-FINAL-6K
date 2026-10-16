#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> adj;
vector<string> nodename;

void dfs(int u, vector<bool> &visit , stack<int> stack){

    visit[u] = true;
    for (int v : adj[u])
    {
        if (!visit[u])
        {
            dfs(v,visit,stack);
        }
        
    }

    stack.push(u);
    
}

void inputname(){

    int n = 8;
    nodename.resize(n + 1);
    cout << "\n---Input Names---\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter name #"<< i << ":";
        cin >> nodename[i];
    }
    
}

void inputgraph(){

    int n = nodename.size();
    int m;

    cin >> m;

    int u,v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);

    }
    


}

void topo(){

    if (adj.empty() || nodename.empty())
    {
        cout << "pls enter node and graph first";
        return;
    }

    int n = nodename.size() - 1;
    vector<bool> visit(n + 1 , false);
    stack<int> stack;

    for (int i = 1; i < n; i++)
    {
        if (!visit[i])
        {
            dfs(i,visit,stack);
        }
        
    }
    
    cout<<"\nTopological sort\n";
    cout<<"====================\n";
    bool first = true;
    while (!stack.empty())
    {
        if (!first)
        {
            cout<< "->";
        }

        cout << nodename[stack.top()];
        stack.pop();
        first = false;
        
    }

    cout <<"\n";


    
}