#include <bits/stdc++.h>

using namespace std;

class Graph{
    unordered_map<int,vector<int>> graph;
    vector<int> visited;
    queue<int> q;
    public:
        void addEdge(int v,int e,bool undir=true){
            if(!count(graph[v].begin(),graph[v].end(),e)){
                graph[v].push_back(e);
            }
            if(!count(graph[e].begin(),graph[e].end(),v) and undir){
                graph[e].push_back(v);
            }
        }

        void printAll(){
            for(auto m:graph){
                cout<<m.first<<"--> ";
                for(auto i:m.second){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
        }

        vector<int> BFS(int start){
            int vertex;
            queue<int> q;
            q.push(start);
            visited.push_back(start);

            while(!q.empty()){
                vertex = q.front();
                q.pop();
                for(auto x:graph[vertex]){
                    if(find(visited.begin(),visited.end(),x) == visited.end()){
                        q.push(x);
                        visited.push_back(x);
                    }
                }
            }
            return visited;
        }

};

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(4,0);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(5,3);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.printAll();
    vector<int> bfs = g.BFS(1);
    cout<<"BFS: ";
    for(auto i:bfs){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}