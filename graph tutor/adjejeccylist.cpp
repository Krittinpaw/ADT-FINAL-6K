//adjecency list 0(n + m) if n = vertice and m = edge
//adjency matrix BigO(O n ^ 2)
#include<iostream>
#include<vector>
#include<array>
using namespace std;

struct record{
    int value;
    struct record *next;
};

int main(){

    int n,m;
    cin >> n >> m;

    vector<int> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        
    }
    
}

/*
4 4
4 3
1 2
2 4
1 3

*/