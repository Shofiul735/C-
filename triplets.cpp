#include<bits/stdc++.h>

using namespace std;

void solve();

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while (t--) solve();
    return 0;
}

vector<vector<int>> findTriplets(vector<int> arr, int target){
    unordered_map<int,int> um;
    vector<vector<int>> result;

    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        if(um[arr[i]]!=0){
            um[arr[i]]++;
        }else{
            um[arr[i]]=1;
        }
    }

    int j,k;
    for(int i=0;i<=arr.size()-3;i++){
        if(um[arr[i]]<=0)continue;
        j=i+1;
        k=arr.size()-1;
        while(j<k){
            if(arr[i]+arr[j]+arr[k]>target){
                k--;
            }else if(arr[i]+arr[j]+arr[k]<target){
                j++;
            }else if(arr[i]+arr[j]+arr[k] == target){
                if(um[arr[i]]>0 && um[arr[j]]>0 && um[arr[k]]>0){
                    result.push_back({arr[i],arr[j],arr[k]});
                    um[arr[i]]--;
                    um[arr[j]]--;
                    um[arr[k]]--;
                }
                j++;
                k--;
            }
        }
    }
    return result;
}

void solve(){
   int sz,target,temp;
   vector<int> v;
   cin>>sz;
   cin>>target;
   for(int i=0;i<sz;i++){
       cin>>temp;
       v.push_back(temp);
   }
   auto result = findTriplets(v,target);
   for(auto i:result){
       for(auto x:i){
           cout<<x<<",";
       }
       cout<<endl;
   }
}