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

void setSumBit(vector<int>& v,int n){
    int ithbit = 0;
    for(int i=0;i<32;i++){
        ithbit = (n&(1<<i));
        if(ithbit!=0){
            v[i]++;
        }
    }
}

int unique(vector<int>& bits,int n){
    int result = 0;
    for(int i=0;i<32;i++){
        bits[i]%=n;
        bits[i] = bits[i]!=0 ? 1 : 0;
        result += (bits[i]*(1<<i));
    } 
    return result; 
}

int findUnique(vector<int>& v,int n){
    vector<int> bits(32,0);
    for(int i=0;i<v.size();i++){
        setSumBit(bits,v[i]);
    }
    return unique(bits,n);
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

    cout<<findUnique(v,4)<<endl;
    return;
}