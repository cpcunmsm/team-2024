#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for(auto &x : a) cin >> x; sort(a.begin(), a.end());
    if(k == 0) {
        if(a[0] == 1)
            cout << -1;
        else
            cout << 1;
        return;
    }
    if(k == n){
        cout << a.back();
        return;
    } else {
        if(a[k] == a[k-1]) {
            cout << -1;
            return;
        } else {
            cout << a[k-1];
            return;
        }
    }
}
 
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
