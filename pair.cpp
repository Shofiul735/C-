#include<bits/stdc++.h>
#include <vector>

using namespace std;

void solve();

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while (t--) solve();
    return 0;
}
vector<int> findPair(vector<int> v, int t){
    vector<int> result;
    unordered_set<int> s;
    int value;
    for(int i=0;i<v.size();i++){
        value = t-v[i];
        if(s.find(value)!=s.end()){
            result.push_back(v[i]);
            result.push_back(value);
        }
        s.insert(v[i]);
    }

    return result;
}
void solve(){
    vector<int> v;
    int sz,temp,target;
    cin>>sz;
    for(int i=0;i<sz;i++){
        cin>>temp;
        v.push_back(temp);
    }
    cin>>target;
    auto result = findPair(v,target);
    for(auto x:result){
        cout<<x<<" ";
    }
}