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
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>temp;
            v[i].push_back(temp);
        }
    }
    vector<vector<int>> dp(n);
    for(int i=0;i<n;i++){
        dp[n-1].push_back(v[n-1][i]);
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i].push_back((v[i][j] + max(dp[i+1][j],dp[i+1][j+1])));
        }
    }
    cout<<dp[0][0]<<endl;
    return;
}