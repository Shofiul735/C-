#include <bits/stdc++.h>
#include <iostream>

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
            if(undir and !count(graph[e].begin(),graph[e].end(),v)){
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

        bool hasCycleUndir(int start){
            unordered_map<int,bool> visited;
            return cycleDetector(start,visited,-1);
        }

        bool cycleDetetorDir(int node,unordered_map<int,bool>& visisted, unordered_map<int,bool>& stack){
            visisted[node] = true;
            stack[node] = true;
            for(auto e:graph[node]){
                if(stack[e]){
                    return true;
                }else if(!visisted[e]){
                    if(cycleDetetorDir(e,visisted,stack)){
                        return true;
                    }
                }
            }
            stack[node] = false;
            return false;
        }

        bool hasCycleDir(){
            unordered_map<int,bool> visited,stack;
            for(auto g:graph){
                if(cycleDetetorDir(g.first, visited, stack)){
                    return true;
                }
            }
            return false;
        }

};

int main(){
    Graph g;
    Graph gDir;
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

    if(g.hasCycleUndir(0)){
        cout<<"Graph has a cycle"<<endl;
    }else{
        cout<<"Graph doesn't have a cycle"<<endl;
    }


    // Directed Graph
    // gDir.addEdge(1,1,false);
    // gDir.addEdge(2,1,false);
    // gDir.addEdge(2,5,false);
    // gDir.addEdge(5,1,false);
    // gDir.addEdge(5,3,false);
    // gDir.addEdge(3,4,false);
    // gDir.addEdge(4,7,false);
    // gDir.addEdge(7,5,false);

    gDir.addEdge(1,2,false);
    gDir.addEdge(1,4,false);
    gDir.addEdge(2,3,false);
    gDir.addEdge(3,4,false);

    if(gDir.hasCycleDir()){
        cout<<"This directed graph has cycle"<<endl;
    }else{
        cout<<"this directed graph doesn't contain cycle"<<endl;
    }


    return 0;
}