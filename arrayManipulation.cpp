#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <iostream>

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

long arrayManipulation(int n, vector<vector<int>> queries){
    int a1,a2,a3;
    long temp,m;
    vector<long> v(n+1,0);

    for(int i=0;i<queries.size();i++){
        a1=queries[i][0];
        a2=queries[i][1];
        a3=queries[i][2];
        v[a1] = v[a1]+a3;
        v[a2+1] = v[a2+1]-a3;
    }
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    temp = v[0];
    m = LONG_MIN;
    for(int i=1;i<v.size();i++){
        temp+=v[i];
        m = max(temp,m);
    }

    return m;
}


void solve(){
    int cl,ro,temp;
    cin>>cl;
    cin>>ro;
    vector<vector<int>> v(ro);
    for(int i=0;i<ro;i++){
        for(int j=0;j<3;j++){
            cin>>temp;
            v[i].push_back(temp);
        }
    }
    auto result = arrayManipulation(cl,v);
    cout<<result;
}