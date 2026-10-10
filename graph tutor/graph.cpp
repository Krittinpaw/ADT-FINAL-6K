#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj;

int main(){

    int n,m;
    cin >> n >> m;

    adj.resize(n + 1);
    for (int i = 1; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        
    }

    for (int u = 1; u <= n; u++)
    {
        
        cout << u << " : ";

        for (int v : adj[u])
        {
            /* code */
        }
        
        
    }
    
    

}