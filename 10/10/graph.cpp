#include<iostream>
#include<vector>
#include<list>
using namespace std;

#define MAX_N 100000

int n,m;

vector<int> adj[MAX_N];
int degree[MAX_N];
int layer[MAX_N];
int pred[MAX_N];
bool visit[MAX_N];
int d[MAX_N];
int f[MAX_N];
int timecount;

void initdfs(){

    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
        degree[i] = 0;
        layer[i] = -1;
        pred[i] = -1;
        visit[i] = false;
        d[i] = -1;
        f[i] = -1;
    }

    timecount = 0;
    
}

void dfs_visit(int u){

    timecount++;
    d[u] = timecount;
    visit[u] = true;

    for (int v  : adj[u])
    {
        if (!visit[v])
        {
            visit[v] = true;
            pred[v] = u;
            dfs_visit(v);
        }

        
    }

    timecount++;
    f[u] = timecount;
    
    
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