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
    unsigned long long int a,b,gcd,lcm;
    cin>>a>>b;
    gcd = __gcd(a,b);
    lcm = (a/gcd)*(b/gcd)*gcd;
    cout<<gcd<<" "<<lcm<<endl;
    return;
}