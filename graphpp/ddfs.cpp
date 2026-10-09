#include<iostream>
#include<vector>
#define MAX_N 100000
using namespace std;

int n,m;

vector<int> adj[MAX_N];
int degree[MAX_N];
bool visit[MAX_N];
int pred[MAX_N];
int d[MAX_N];
int f[MAX_N];

int timecount;

void init(){

    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
        visit[i] = false;
        degree[i] = 0;
        pred[i] = -1;
        d[i] = -1;
        f[i] = -1;
    }

    timecount = 0;
    
}

void dfs_visit(int u){

    
    timecount++;
    visit[u] = true;
    d[u] = timecount;

    for (int v : adj[u])
    {
        
        if (!visit[v])
        {
            visit[v] = true;
            dfs_visit(v);
        }
        
        
    }

    timecount++;
    f[u] = timecount;
    
    
}

void dfs(int s){

    pred[s] = s;
    dfs_visit(s);

    for (int u = 0; u < n; u++)
    {
        if (!visit[u])
        {
            visit[u] = true;
            dfs_visit(u);
        }
        
    }
    
}

