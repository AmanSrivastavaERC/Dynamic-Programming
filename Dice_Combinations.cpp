#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(arr) arr.begin(), arr.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define print(arr) forn(i, size(arr)) cout << arr[i] << " "
#define scan(arr) forn(i, size(arr)) cin >> arr[i]
void solve() {
    int n, M = 1e9 + 7;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j > max(-1 + i - i, i - 7); j--)
            dp[i] = (dp[i] % M + dp[j] % M) % M;
    }
    cout << dp[n];
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