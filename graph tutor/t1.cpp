#include<iostream>
#include<vector>
#include<list>
using namespace std;

#define max_n 100000
int n,m;
vector<int> adj[max_n];
int degree[max_n];
bool visited[max_n];
int layer[max_n];
int pred[max_n];
list<int> Q;

void init(){

    for (int i = 0; i < n; i++)
    {
        degree[i] = 0;
        visited[i] = false;
        layer[i] = -1;
        pred[i] = -1;
    }
    
}


void readinput(){

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

void show(){

    for (int i = 0; i < n; i++)
    {

        cout << i + 1 << " : ";
        for (int j = 0;j < degree[i]; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
        
    }
    
}

void bfs(int s){

    int u = s;
    visited[s] = true;
    layer[s] = 0;
    pred[s] = 0;
    Q.push_back(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        

        for (int d = 0; d < degree[u]; d++)
        {
            int v = adj[u][d];
            if (visited[v] == false)
            {
                visited[u] = true;
                layer[v] = layer[u] + 1;
                pred[v] = u;
                Q.push_back(v);
            }
            
        }
        

    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << layer[i] << endl;
    }
    
    

}


