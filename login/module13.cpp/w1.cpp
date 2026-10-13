#include<iostream>
#include<vector>
#include<stack>
#define MAX_N 100000
using namespace std;

vector<int> adj[MAX_N];
vector<int> transpose[MAX_N];
int degree[MAX_N];
int degreetranposr[MAX_N];

int n , m;

void read_input(){

    cin >> n >> m;

    int u,v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        degree[u]++;
        transpose[v].push_back(u);
        degreetranposr[v]++;
    }
    
}

void show_normarg(){

    cout << "show\n" << endl;

    for (int u = 0; u < n; u++)
    {
        cout << u + 1 << " : ";
        for (int v : adj[u])
        {
            cout << v + 1 << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void showtranspose(){

    cout << "Transpose\n" << endl;

    for (int u = 0; u < n; u++)
    {
        cout << u + 1 << " : ";
        for (int v : transpose[u])
        {
            cout << v + 1 << " ";
        }
        cout << "\n";
    }
    cout << endl;

}

int main(){

    read_input();
    show_normarg();
    showtranspose();
    return 0;
}