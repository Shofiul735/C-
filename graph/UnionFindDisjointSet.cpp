#include <bits/stdc++.h>

using namespace std;

class UnionFindDisjointSet{
    vector<int> parent,rank;
    public:
        UnionFindDisjointSet(int s){
            parent.reserve(s);
            rank.assign(s,0);
            for(int i=0;i<s;i++){
                parent.push_back(i);
            }
        }
        int findSet(int i){
            if(parent[i] == i){
                return i;
            }else{
                return parent[i] = findSet(parent[i]);
            }
        }

        void unionSet(int i,int j){
            if(findSet(i)!=findSet(j)){
                if(rank[i]>rank[j]){
                    parent[j] = i;
                    rank[i]++;
                }else{
                    parent[i] = j;
                    rank[j]++;
                }
            }
        }

        bool findCycle(vector<pair<int,int>>& p){
            for(auto x:p){
                if(findSet(x.first) == findSet(x.second)){
                    return true;
                }else{
                    unionSet(x.first, x.second);
                }
            }
            return false;
        }

};