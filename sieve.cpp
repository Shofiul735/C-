#include <bits/stdc++.h>
using namespace std;

#define shofiul
#define ll long long

void solve();

int main(){
    #ifdef shofiul
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    //cin>>t;

    while(t--){
        solve();
    }
    return 0;
}


void sieve(vector<bool>& primes,int n){
    int i,j,sq=sqrt(n);
    primes[1] = primes[0] = false;
    for(int i=2;i<=sq;i++){
        if(primes[i]){
            for(ll j=i*i;j<=n;j+=i){
                primes[j]=false;
            }
        }
    }
}

void solve(){
   int n;
   cin >> n;
   vector<bool> primes(n+1,true);
   sieve(primes,n);
   for(int i=0;i<primes.size();i++){
    if(primes[i]){
        cout<<i<<" ";
    }
   }
   cout<<endl;
}