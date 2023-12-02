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

double postfixSum(string s){
    stack<double> stk;
    vector<string> v;
    char *temp = &s[0];
    char *token = strtok(temp," ");

    while(token != nullptr){
        v.push_back(token);
        token = strtok(nullptr," ");
    }

    // typeid(x).name() find the variable type
    for(auto x: v){
        if(x.compare("/") == 0){
            auto a = stk.top(); stk.pop();
            auto b = stk.top(); stk.pop();
            stk.push(b/a);
        }else if(x.compare("-") == 0){
            auto a = stk.top(); stk.pop();
            auto b = stk.top(); stk.pop();
            stk.push(b-a);
        }else if(x.compare("+") == 0){
            auto a = stk.top(); stk.pop();
            auto b = stk.top(); stk.pop();
            stk.push(b+a);
        }else if(x.compare("*") == 0){
            auto a = stk.top(); stk.pop();
            auto b = stk.top(); stk.pop();
            stk.push(b*a);
        }else{
            stk.push(stod(x));
        }
    }
    if(!stk.empty()){
        return stk.top();
    }
    return 0;
}


// Postfix Sum: "4 1 2 9 3 / * + 5 - *"

void solve(){
   string s;
   getline(cin,s);
   cout<<postfixSum(s)<<endl;
}