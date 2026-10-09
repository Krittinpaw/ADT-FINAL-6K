#include<iostream>
#include<vector>
#include<list>
#define MAX_N 100000
using namespace std;

int n,m;
vector<int> adj[MAX_N];
bool visit[MAX_N];
int degree[MAX_N];
int layer[MAX_N];
int pred[MAX_N];
int d[MAX_N];
int f[MAX_N];
int timecout;

void initdfs(){

    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
        visit[i] = false;
        degree[i] = 0;
        d[i] = -1;
        f[i] = -1;
    }

    timecout = 0;
}

void dfs_visit(int u){

    timecout++;
    d[u] = timecout;
    visit[u] = true;

    for (int v : adj[u])
    {
        if (!visit[v])
        {
            visit[v] = true;
            pred[v] = u;
            dfs_visit(v);
        }
        
    }

    timecout++;
    f[u] = timecout;
    
}

void dfs(int s){

    pred[s] = -1;
    dfs_visit(s);

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            pred[i] = -1;
            dfs_visit(i);
            
        }
        
    }
    

}

void initbfs(){

    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
        visit[i] = false;
        degree[i] = 0;
        layer[i] = -1;
        pred[i] = -1;
    }
    
}

void bfs(int s){

    
    list<int> Q;
    pred[s] = -1;
    visit[s] = true;
    layer[s] = 0;
    Q.push_back(s);

    while (!Q.empty())
    {
        
        int u = Q.front();
        Q.pop_front();

        for (int v : adj[u])
        {
            if (!visit[v])
            {
                visit[v] = true;
                pred[v] = u;
                layer[v] = layer[u] + 1;
                Q.push_back(v);

            }
            
        }
        
    }
    
}

