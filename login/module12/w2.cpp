#include<iostream>
#include<vector>
#define MAX_N 100000
using namespace std;

vector<int> adj[MAX_N];
bool visit[MAX_N];
int degree[MAX_N];
int pred[MAX_N];
int d[MAX_N];
int f[MAX_N];
int timecout;

int n,m;

void init(){

    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
        degree[i] = 0;
        visit[i] = false;
        pred[i] = -1;
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

    pred[s] = s;
    dfs_visit(s);
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            pred[i] = i;
            dfs_visit(i);
        }
        
    }
    
}

void print_path(int s,int v){

    if (s == v)
    {
        cout << s + 1 << " ";
    }else if (pred[v] == -1)
    {
        cout << "No path";
    }else{
        print_path(s,pred[v]);
        cout << v + 1 << " ";
    }
        
}

int main() {
    cin >> n >> m;
    init();

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v); // กราฟมีทิศทาง (Directed)
    }

    int start_node;
    cout << "Start node : ";
    cin >> start_node;

    dfs(start_node - 1);

    cout << "\nOutput\n";
    cout << "DFS\n";
    cout << "I d f pred\n";
    cout << "-----------------\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " : " << d[i] << " " << f[i] << " " << pred[i] + 1 << "\n";
    }

    int end_node;
    cout << "\nEnter end of Path : ";
    cin >> end_node;
    
    print_path(start_node - 1, end_node - 1);
    cout << "\n";

    return 0;
}