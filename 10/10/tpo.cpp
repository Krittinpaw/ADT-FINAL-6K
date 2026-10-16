#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<string> nodename;
vector<vector<int>> adj;

void dfs(int u,vector<bool> &visit , stack<int> &Q){

    visit[u] = true;//check if the node already in
    for (int v : adj[u])//see all u adjecrncy
    {
        if (!visit[v])
        {
            dfs(v,visit,Q);//recursive
        }
        
    }

    Q.push(u);//when finish node u gonna push to this
    
}

void inputn(){

    int n = 8;
    nodename.resize(n + 1);
    cout << "\n---Input Names---\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name #"<< i << ":";
        cin >> nodename[i];
    }
    
}

void inputgraph(){
    int n,m;
    cout << "\n---Input Graph---\n";
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter " << m << " edges: \n";
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);       
    }
    
}

void topologival(){

    if (adj.empty() || nodename.empty())
    {
        cout << "\nPlease input names and graph first!\n";
        return;
    }

    int n = nodename.size() - 1;
    vector<bool> visit(n + 1 , false);
    stack<int> stack;

    for (int i = 1; i <= n; i++)
    {
        if (visit[i])
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


