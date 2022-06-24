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

        void DFShelper(int start,unordered_map<int,bool>& v,vector<int>& p){
            v[start] = true;
            p.push_back(start);
            for(auto x:graph[start]){
                if(!v.count(x)){
                    DFShelper(x,v,p);
                }
            }
            return;
        }

        vector<int> DFS(int start){
            vector<int> path;
            unordered_map<int,bool> visited;
            DFShelper(start,visited,path);
            return path;
        }

         vector<int> shortestPath(int start,int end){
            unordered_map<int,bool> visited;
            unordered_map<int,int> parent;
            unordered_map<int,int> distance;
            queue<int> q;
            stack<int> s;
            vector<int> result;
            int p,temp;

            q.push(start);
            parent[start] = -1;
            distance[start] = 0;
            visited[start] = true;
            while(!q.empty()){
                p = q.front();
                q.pop();
                for(auto x:graph[p]){
                    if(!visited[x]){
                        visited[x] = true;
                        q.push(x);
                        parent[x] = p;
                        distance[x] = distance[p]+1; // it's optional
                    } 
                }
            }
            for(auto d:distance){
                cout<<"Shortest distance from "<<d.first<<" is: "<<d.second<<endl;
            }
            cout<<"Shortest Path is:"<<endl;
            temp = end;
            while(temp!=start){
                s.push(temp);
                temp = parent[temp];
            }
            s.push(start);
            
            while(!s.empty()){
                result.push_back(s.top());
                s.pop();
            }
            return result;

        }

        bool cycleDetector(int node,unordered_map<int,bool>& visited,int parent){
            visited[node] = true;
            for(auto nbr:graph[node]){
                if(!visited[nbr]){
                    return cycleDetector(nbr,visited,node);
                }else if(nbr != parent){
                    return true;
                }
            }
            return false;
        }

        bool hasCycle(int start){
            unordered_map<int,bool> visited;
            return cycleDetector(start,visited,-1);
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

    cout<<"DFS:";
    vector<int> dfs = g.DFS(1);
    for(int x:dfs){
        cout<<x<<" ";
    }
    cout<<endl;

    if(g.hasCycle(0)){
        cout<<"Graph has a cycle"<<endl;
    }else{
        cout<<"Graph doesn't have a cycle"<<endl;
    }

    return 0;
}