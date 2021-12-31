#include<bits/stdc++.h>
#include <iostream>

using namespace std;

void solve();

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}


void solve(){
    int n;
    vector<int> prime;
    cin>>n;
    if(n==1){
        cout<<"no"<<endl;
        return;
    }
    int sq = sqrt(n);
    bool notPrime;
    for(int i=2;i<=sq;i++){
        notPrime = false;
        for(int j=2;j<i;j++){
            if(i%j == 0){
                notPrime = true;
                break;
            }
        }
        if(!notPrime){
            prime.push_back(i);
        }
    }
    for(auto x:prime){
        if(n%x == 0){
            cout<<"no"<<endl;
            return;
        }
    }   
    cout<<"yes"<<endl;
    return;
}