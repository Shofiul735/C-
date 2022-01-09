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
    int n,temp;
    cin>>n;
    int smallest,sSmallest;
    cin>>smallest;
    cin>>sSmallest;
    if(smallest>sSmallest){
        temp = smallest;
        smallest = sSmallest;
        sSmallest = temp;
    }
    for(int i=2;i<n;i++){
        cin>>temp;
        if(temp<smallest){
            sSmallest = smallest;
            smallest =temp;
        }else if(temp>smallest and temp<sSmallest){
            sSmallest = temp;
        }
    }
    cout<<smallest+sSmallest<<endl;
    return;
}