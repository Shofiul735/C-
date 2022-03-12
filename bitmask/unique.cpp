#include<bits/stdc++.h>
using namespace std;

#define Shofiul

void solve();

int main(){
    #ifdef Shofiul
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}


void solve(){
    vector<int> v;
    int n,x,temp;
    cin>>n;
    v.reserve(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    x = v[0];
    for(auto it=v.begin()+1;it!=v.end();it++){
        x^=*it;
    }
    cout<<x<<endl;
    return;
}