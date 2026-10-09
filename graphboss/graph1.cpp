#include<iostream>
#include<list>
#include<vector>
using namespace std;

#define MAX_N 100000

vector<int> adj[MAX_N];
int degree[MAX_N];
bool visited[MAX_N];
int pred[MAX_N];
int layer[MAX_N];

list<int> Q;




int n,m;


void init(){

    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
        degree[i] = 0;
        visited[i] = false;
        pred[i] = 0;
        layer[i] = 0;
    }
    
}

void read(){

    int u,v;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        degree[u]++;
        adj[v].push_back(u);
        degree[v]++;
    }
    
}

void bfs(int s){

    
    visited[s] = true;
    layer[s] = 0;
    pred[s] = s;

    Q.push_back(s);
    
    while (Q.empty())
    {
      
        int u =  Q.front();
        Q.pop_front();

        for (int d = 0; d < degree[u]; d++)
        {
            int v = adj[u][d];

            if (visited[v] == false)
            {
                visited[v] == true;
                layer[v] == layer[u] + 1;
                pred[v] = u;
                Q.push_back(v);
            }
            
        }
        
    }
    
}