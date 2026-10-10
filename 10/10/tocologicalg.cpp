//Krittin pawaree 6830300029
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

vector<string> noden;
vector<vector<int>> adj;

void dfs(int u,vector<bool>& visit, stack<int>& stack){
    visit[u] = true;
    
    for(int v : adj[u]){
        if(!visit[v]){
            dfs(v, visit ,stack);
        }
    }
    stack.push(u);
}

void inputName(){
    int n = 8;
    noden.resize(n + 1);
    cout << "\n---Input Names---\n";
    for(int i = 1; i <= n; i++){
        cout << "Enter name #"<< i << ":";
        cin>>noden[i];
    }
}

void inputGraph(){
    int numnode, numedge;
    cout << "\n---Input Graph---\n";
    cout << "Enter number of nodes and edges: ";
    cin >> numnode >> numedge;
    
    adj.assign(numnode + 1, vector<int>());
    
    cout << "Enter " << numedge << " edges: \n";
    for(int i =0; i < numedge; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void topologicalSort(){
    if(adj.empty() || noden.empty()){
        cout << "\nPlease input names and graph first!\n";
        return;
    }
    
    int n = noden.size() - 1;
    vector<bool> visited(n + 1, false);
    stack<int> Stack;
    
    for(int i =1; i <= n; i++){
        if(!visited[i]){
            dfs(i, visited, Stack);
        }
    }
    
    cout<<"\nTopological sort\n";
    cout<<"====================\n";
    bool first = true;
    while(!Stack.empty()){
        if(!first) cout<< "->";
        cout << noden[Stack.top()];
        Stack.pop();
        first = false;
    }
    cout <<"\n";
}

int main() {
    int choice;
     do {
            cout << "\n============MENU============\n";
            cout << "1) Input name\n";
            cout << "2) Input Graph\n";
            cout << "3) Topological sort\n";
            cout << "4) Exit\n";
            cout << "Please choose > ";
            cin >> choice;

    switch (choice){
                    case 1:
                    inputName();
                    break;
                    case 2:
                    inputGraph();
                    break;
                    case 3:
                    topologicalSort();
                    break;
                    case 4:
                    
                    break;
                    default:
                    cout << "Invalid choice! Please try again.\n";
                    return 0;
                    }
                    
        } while (choice != 4);
        return 0;
}
























