#include<bits/stdc++.h>

using namespace std;

void solve();

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}

int getDigit(int n){
    return (1 + floor(log(n)/log(10)));
}

void solve(){
   int n,temp,i=0;
   int result=0;
   cin>>n;
   i = getDigit(n);
   while(n){
       temp = n%10;
       n/=10;
       result += temp*pow(10,--i);
   }
   cout<<result<<endl;
}