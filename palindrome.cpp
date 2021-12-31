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
    int n,d;
    cin>>n;
    string s = to_string(n);
    int i = 0;
    int j = s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            cout<<"loses"<<endl;
            return;
        }
        i++;
        j--;
    }
    cout<<"wins"<<endl;
    return;
}