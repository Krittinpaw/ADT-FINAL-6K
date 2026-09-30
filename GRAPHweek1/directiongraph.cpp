#include<iostream>
#include<vector>
using namespace std;

#define MAX_N 100000

int n , m;

vector<int> adj[MAX_N];
int deg[MAX_N];

void init(){

    for (int i = 0; i < n; i++)
    {
        deg[i] = 0;
    }
    
}

void readinput(){

    int u,v;
    cout << "input directgraph\n";
    cin >> n , m;

    init();

    for (int i = 0; i < m; i++)
    {
        cin >> u , v;
        u--;
        v--;
        adj[u].push_back(v);
        deg[u]++;
    }


    
}

void show(){

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " : ";

        for (int j = 0; j < deg[i]; j++)
        {
            cout << adj[i][j] + 1 << " ";
        }

        cout << endl;
        
    }
    
}

int main(){

    readinput();
    show();
}