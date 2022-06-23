#include <bits/stdc++.h>

using namespace std;

#define Shofiul

void solve();

int main() {
#ifdef Shofiul
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  // cin>>t;
  while (t--)
    solve();
  return 0;
}

void solve(){
    /*
    sample input: 1 2 3 5 7 4 3 8 9
    sample out: 4 5
    */
    vector<int> v;
    int temp;
    int index,smallest,largest;
    bool first = true;
    while(cin>>temp){
        v.push_back(temp);
    }



    index = 1;
    while(index < v.size()){
        if(v[index-1] > v[index] and first){
            largest = v[index-1];
            smallest = v[index];
            first = false;
        }else if(!first and largest>v[index]){
            if(smallest > v[index]){
                smallest = v[index];
            }
        }
        index++;
    }
    if(first){
        // array is sorted
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    index = 0;
    while(index < v.size()){
        if(smallest<v[index]){
            cout<<index<<" ";
            break;
        }
        index++;
    }

    index = v.size()-1;
    while(index >=0){
        if(largest>v[index]){
            cout<<index<<endl;
            break;
        }
        index--;
    }

    return;
}