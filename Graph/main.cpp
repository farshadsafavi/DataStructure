#include <iostream>
#include<list>
#include<stack>
using namespace std;
void BFS(int G[][7], int start, int n){
    int visited[8] = {0};
    list<int> Queue;
    Queue.push_back(start);
    visited[start] = 1;
    cout <<start <<" ";
    while(!Queue.empty()){
        int node = Queue.front();
        Queue.pop_front();
        for(int i = 1; i <= n; i++){
            if(G[node][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                Queue.push_back(i);
                cout <<i <<" ";
            }
        }
    }
    cout << endl;
}

void DFS1(int G[][7], int start, int n){
    int visited[8] = {0};
    stack<int> Stack;
    Stack.push(start);
    visited[start] = 1;
    while(!Stack.empty()){
        int node = Stack.top();
        cout <<node <<" ";
        Stack.pop();
        for(int i = 1; i <= n; i++){
            if(G[node][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                Stack.push(i);
            }
        }
    }
    cout << endl;
}

void DFS(int G[][7], int start, int n){
    static int visited[8] = {0};
    if(visited[start] == 0){
        cout <<start << " ";
        visited[start] = 1;
    }
    for(int i = 1; i<=n;i++){
        if(G[start][i] == 1 && visited[i] != 1)
            DFS(G, i, n);
    }
}
int main()
{
    cout << "Graph BFS and DFS:" << endl;
    int G[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0},
                  };

    //BFS(G, 2, 7);

    DFS(G, 2, 7);
    /*
    list<int> Queue;
    for(int i = 0; i < 6; i++)
        Queue.push_back(i);

    cout <<Queue.front()<<endl;
    Queue.pop_front();
    cout <<Queue.front()<<endl;*/

    return 0;
}
