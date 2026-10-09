//Krittin pawaree 6830300029
#include<iostream>
#include<vector>
using namespace std;

#define MAX_N 100000

int n, m;
vector<int> adj[MAX_N];

bool visited[MAX_N];
int d[MAX_N];//start
int f[MAX_N];//back
int pred[MAX_N];
int time_counter;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        d[i] = -1;  
        f[i] = -1;  
        pred[i] = -1;
    }
    time_counter = 0;
}

void readinput()
{
    int u, v;
    cout << "Input here : \n"; 
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v); 
    }
}

void dfs_visit(int u)
{
    time_counter++;
    d[u] = time_counter;
    visited[u] = true;

    for (int v : adj[u])
    {
        if (visited[v] == false)
        {
            pred[v] = u;
            dfs_visit(v);
        }
    }
    
    time_counter++;
    f[u] = time_counter;
}

void dfs(int s)
{
    pred[s] = s;
    dfs_visit(s);
    
    for(int u = 1; u <= n; u++)
    {
        if(!visited[u])
        {
            pred[u] = u;
            dfs_visit(u);
        }
    }
}

int main()
{



    readinput();
    init(); 

    int start_node;
    cout << "Start node : ";
    cin >> start_node;


    
    dfs(start_node);

    cout << "Output \n";
    cout << "DFS \n";
    cout << "l  d  f  pred \n";
    cout << "---------------- \n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << d[i] << "  " << f[i] << "  " << pred[i] << "\n";
    }

    return 0;
}