#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int>* l;
    public:
        Graph(int v){
            V = v;
            l = new list<int>[V];
        }

        void addEdge(int v,int e,bool undir=true){
            if(!(find(l[v].begin(),l[v].end(),e)!=l[v].end())){
                l[v].push_back(e);
            }
            if(undir and !(find(l[e].begin(),l[e].end(),v)!=l[e].end())){
                l[e].push_back(v);
            }
        }

        void printGraph(){
            for(int i=0;i<V;i++){
                cout<<i<<" vertex:"<<"-->";
                for(auto x:l[i]){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,0);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.printGraph();
}