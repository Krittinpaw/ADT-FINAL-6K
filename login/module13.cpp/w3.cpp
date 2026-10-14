#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<vector<int>> adj;
vector<string> nodename;

void dfs(int u , vector<bool> &visit , stack<int> &stack){

    visit[u] = true;
    for (int v : adj[u])
    {
        if (!visit[v])
        {
            dfs(v,visit,stack);
        }
        
    }

    stack.push(u);
    
}
void inputname(){

    nodename.resize(8);
    for (int i = 0; i < nodename.size(); i++)
    {
        cin >> nodename[i];
    }
    
}

void inputgraph(){

    adj.resize(nodename.size());
    int m;
    cin >> m;

    int u ,v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    
}

void topological(){

    if (adj.empty() || nodename.empty())
    {
        cout << "Pleas enter data first";
        return;
    }

    vector<bool> visit(nodename.size(),false);
    stack<int> stack;

    for (int i = 0; i < nodename.size(); i++)
    {
       if (!visit[i])
       {
            dfs(i,visit,stack);
       }
       
    }

    bool first = true;
    int u;
    while (!stack.empty())
    {
        
        int u = stack.top();
        stack.pop();

        if (!first)
        {
            cout << " -> ";
        }

        cout << nodename[u];

        first = false;

        
    }

    cout << "\n";
    
    
    
}

int main(){
    int choice;

    do {
        cout << "==========MENU==========\n";
        cout << "1)\tInput name\n";
        cout << "2)\tInput Graph\n";
        cout << "3)\tTopological sort\n";
        cout << "4)\tExit\n";
        cout << "Please choose > ";
        cin >> choice;

        if (choice == 1) {
            inputname();
        } 
        else if (choice == 2) {
            inputgraph();
        } 
        else if (choice == 3) {
            topological();
        }
        
    } while (choice != 4);

    return 0;
}

