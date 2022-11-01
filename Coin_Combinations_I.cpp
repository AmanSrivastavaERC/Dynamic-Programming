#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(arr) arr.begin(), arr.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define print(arr) forn(i, size(arr)) cout << arr[i] << " "
#define scan(arr) forn(i, size(arr)) cin >> arr[i]
void solve() {
    int n, x, M = 1e9 + 7;
    cin >> n >> x;
    vector<int> a(n), dp(x + 1, 0);
    scan(a);
    sort(all(a));
    forn(i, n) if (a[i] <= x) dp[a[i]] = 1;
    for (int i = 1; i < x; i++) {
        if (dp[i] == 0) continue;
        forn(j, n) if (i + a[j] <= x) dp[i + a[j]] = (dp[i] + dp[i + a[j]]) % M;
    }
    cout << dp[x];
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