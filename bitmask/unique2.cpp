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


void solve(){
    vector<int> v;
    int n,x,temp;
    cin>>n;
    v.reserve(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    x = v[0];
    for(int i=1;i<n;i++) x^=v[i];
    
    //find the first up bit position
    int pos = 0;
    temp = x;
    while((temp&1)==0){
        pos++;
        temp = temp>>1;
    }
    int mask = 1<<pos;
    // find two uniquwe elements based on mask.
    int offUnique = 0,onUnique = 0;
    for(int i=0;i<n;i++){
        if((v[i]&mask) == 0){
            // if bit is off
            offUnique^=v[i];
        }else{
            // if bit is on
            onUnique^=v[i];
        }
    }

    cout<<offUnique<<endl;
    cout<<onUnique<<endl;

    return;
}