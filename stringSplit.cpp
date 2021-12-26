#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    char* ch = &s[0];
     // This will cut the string at space,','and '-'.
    char* ss = strtok(ch," ,-");                         
    while(ss!=NULL){
        cout<<ss<<endl;
        ss = strtok(NULL," ,-");
    }
    return 0;
}