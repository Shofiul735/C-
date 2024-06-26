#include<bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {
private:
    vll ft; // internal fenwick tree, index 0 is not used
public:
    FenwickTree(int m) {
        ft.assign(m + 1, 0); // index 0 is not used
    }

    void build(const vll& f) {
        int m = (int)f.size();
        ft.assign(m + 1, 0); 
        for (int i = 1; i <= m; ++i) {
            ft[i] += f[i-1];  // add the values
            if (i + LSOne(i) <= m) { // i has parent
                ft[i + LSOne(i)] += ft[i]; // add to that parent
            }
        }
    }

    FenwickTree(const vll& f) {
        build(f);
    }

    FenwickTree(int m, const vi& s) {
        vll f(m, 0); // Initialize f with size m+1 and all elements 0
        for (int i = 0; i < s.size(); ++i) {
            f[i] = s[i]; // Note the index adjustment here
        }
        build(f);
    }

    ll rsq(int j) {
        ll sum = 0;
        while (j > 0) {
            sum += ft[j];
            j -= LSOne(j);
        }
        return sum;
    }

    ll rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
    }

    void update(int i, ll x) {
        while (i < ft.size()) {
            ft[i] += x;
            i += LSOne(i);
        }
    }

    // find the smallest index i so that the cumulative frequency in the range [1..i] >= k
    int select(ll k) {
        int low = 1, high = ft.size() - 1;

        // Binary search to find the smallest index with cumulative frequency >= k
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (rsq(1, mid) < k) {
                low = mid + 1;  // Look in the right half
            } else {
                high = mid;     // Look in the left half
            }
        }
        return low;
    }
};

int main() {
    vll s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    FenwickTree ft(s);
    ft.update(8,200);
    cout<<"Select:" << ft.select(10) <<endl; 
    cout << ft.rsq(8, 10) << endl; // Outputs 10 (sum of elements from index 1 to 4)
    return 0;
} 