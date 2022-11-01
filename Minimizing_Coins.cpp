#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(arr) arr.begin(), arr.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define print(arr) forn(i, size(arr)) cout << arr[i] << " "
#define scan(arr) forn(i, size(arr)) cin >> arr[i]
const int MAXXN = 1e6 + 1;
vector<int> dp(MAXXN, 1e9);
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    scan(a);
    sort(all(a));
    for (auto& i : a)
        dp[i] = 1;
    for (int i = a[0]; i < x; i++) {
        if (dp[i] == 1e9)
            continue;
        for (auto& j : a)
            if (i + j <= x)
                dp[i + j] = min(dp[i + j], 1 + dp[i]);
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    forn(i, t) {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}