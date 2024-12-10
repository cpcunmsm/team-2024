#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mm;

int main() {
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int cur = 0;
        for (char c: s)
            cur ^= (1 << (c - 'a'));
        ans += mm[cur];
        for (int i = 0; i < 26; ++i)
            ans += mm[cur ^ (1 << i)];
        ++mm[cur];
    }
    cout << ans << "\n";
    return 0;
}
