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


void setSumBit(vector<int>& rs,int n){
    int ithBit = 0;
    
    for(int i=0;i<32;i++){
        ithBit = (n&(1<<i));
        if(ithBit != 0){
            rs[i]++;
        }
    }
}

int findUnique(vector<int> v,int n){
    int result = 0;
    for(int i=0;i<32;i++) v[i]%=n;
    for(int i=0;i<32;i++) result += (v[i]*(1<<i));
    return result;
}


int find3Nunique(vector<int> v,int n){
    vector<int> result(32,0);

    for(int i=0;i<v.size();i++){
        setSumBit(result,v[i]);
    }
    return findUnique(result,n);
}


void solve(){
    vector<int> v;
    int n,temp;
    cin>>n;
    v.reserve(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }


    int unique = find3Nunique(v,3);

    cout<<unique<<endl;

    return;
}