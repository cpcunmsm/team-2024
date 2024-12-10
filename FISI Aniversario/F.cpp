#include <bits/stdc++.h>
using namespace std;
    
int main () {
    long long n, k;
    cin >> n >> k;
    
    if (n * (n - 1) / 2 < k) {
        cout << "Impossible\n";
        return (0);
    }
    
    long long len = 2 * n, p = 0;
    string ans;
    
    while (len--) {
        if (k >= p) {
            ans += "(";
            k -= p;
            ++p;
        } else {
            ans += ")";
            --p;
        }
    }
    
    cout << ans;
    
    return 0;
}
