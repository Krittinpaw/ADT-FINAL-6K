#include<iostream>
#include<vector>
#include<list>
using namespace std;

#define MAX_N 100000

int n,m;

vector<int> adj[MAX_N];
int deg[MAX_N];
bool visit[MAX_N];
int layer[MAX_N];
int pred[MAX_N];

list<int> Q;

void init(){

    for (int i = 0; i < n; i++)
    {
        deg[i] = 0;
        visit[i] = false;
        layer[i] = -1;
        pred[i] = -1;
    }
    
}

void readinput(){

    int u,v;
    cout << "Input : \n";
    cin >> n >> m;

    init();

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        deg[u]++;
        adj[v].push_back(u);
        deg[u]++;

    }
    
}

void show(){

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " : ";
        for (int j = 0; j < deg[i]; j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
        
    }
    
}


void bfs(int s){

    int u = s;
    visit[s] = true;
    layer[s] = 0;
    pred[s] = 0;
    Q.push_back(s);
    
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();

        for (int d = 0; d < deg[u]; d++)
        {
            
            int v = adj[u][d];
            if (visit[v] == false)
            {
                visit[v] = true;
                pred[v] = u;
                layer[v] = layer[u] + 1;
                Q.push_back(v);
            }
            
        }
        

    }
    

}

