#include<iostream>
#include<vector>
#include<stack>
#define MAX_N 100000
using namespace std;

vector<int> adj[MAX_N];
vector<int> transpose[MAX_N];
int degree[MAX_N];
int n,m;

stack<int> st;
bool visit[MAX_N];

void read_input(){

    cin >> n >> m;
    int u , v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        degree[u]++;
        transpose[v].push_back(u);
    }
    
}

void dfs_visit(int u){

    visit[u] = true;
    for (int v : adj[u])
    {
        if (!visit[v])
        {
            dfs_visit(v);
        }
        
    }

    st.push(u);
    
}

void dfs_transpose(int u){
    visit[u] = true;
    for (int v : transpose[u]) 
    {
        if (!visit[v])
        {
            dfs_transpose(v);
        }
    }
}

void dfs(int s){

    
    dfs(s);
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            dfs_visit(i);
        }
        
    }
    

}

int countscc(){
    
    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visit[i]) 
        {
            dfs_visit(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }

    
    int scccount = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        if (!visit[u])
        {
            scccount++;
            dfs_transpose(u); 
        }
    }

    return scccount;
}