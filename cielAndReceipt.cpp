#include<bits/stdc++.h>

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
    int currentItem;
    int count=0;
    cin>>n;
    for(int i=11;i>=0;i--){
        currentItem = pow(2,i);
        while(n>=currentItem){
            count++;
            n-=currentItem;
        }
    }
    cout<<count<<endl;
    return;
}