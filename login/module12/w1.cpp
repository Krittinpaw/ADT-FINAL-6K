#include<iostream>
#include<vector>
#include<list>
#define MAX_N 100000
using namespace std;

vector<int> adj[MAX_N];
int degree[MAX_N];
bool visit[MAX_N];
int pred[MAX_N];
int layer[MAX_N];

int n,m;

void init(){

    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
        degree[i] = 0;
        visit[i] = false;
        pred[i] = -1;
        layer[i] = -1;
    }
    

}

void readinput(){

    cin >> n >> m;
    int u,v;

    init();

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



void bfs1(int s){

    list<int> Q;
    visit[s] = true;
    pred[s] = s;
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

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "," << layer[i] << endl;
    }
    
    
}

int main(){

    readinput();

    cout << "start node : ";
    int star_node;
    cin >> star_node;

    bfs1(star_node-1);
    return 0;
}