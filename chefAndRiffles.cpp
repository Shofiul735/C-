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

vector<int> fire(vector<int> p){
    vector<int> v;
    for(int i=0;i<p.size();i+=2){
        v.push_back(p[i]);
    }
    for(int i=1;i<p.size();i+=2){
        v.push_back(p[i]);
    }
    return v;
}


int swapTime(vector<int> p){
    int k=0;
    bool yes = true;
    vector<int> temp;
    temp.insert(temp.end(),p.begin(),p.end());
    while(yes){
        p = fire(p);
        yes = false;
        for(int i=0;i<p.size();i++){
            if(p[i]!=temp[i]){
                yes = true;
            }
        }
        k++;
        if(!yes)break;
    }
    return k;
}


void solve(){
    int n,m;
    unsigned long long k;
    cin>>n;
    cin>>k;
    vector<int> p;
    for(int i=1;i<=n;i++){
        p.push_back(i);
    }
    double l = log2(n);
    int il = l;
    if(l-il == 0){
        k = k%il;
    }else{
        m = swapTime(p);
        k = k%m;
        cout<<m<<" "<<k<<endl;
    }
    while(k>0){
        p = fire(p);
        k--;
    }
    for(auto x:p){
        cout<<x<<" ";
    }
    cout<<endl;
    return;
}