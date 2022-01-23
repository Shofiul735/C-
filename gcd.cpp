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
    cin>>t;
    while (t--) solve();
    return 0;
}

void solve(){
    int n,temp;
    cin>>n;
    vector<int> v;
    v.reserve(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    int divisor = __gcd(v[0], v[1]);
    for(int i=2;i<n;i++){
        divisor = __gcd(divisor,v[i]);
    }

    for(auto x:v){
        cout<<x/divisor<<" ";
    }
    cout<<endl;
    return;
}