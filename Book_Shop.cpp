#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(arr) arr.begin(), arr.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define print(arr) forn(i, size(arr)) cout << arr[i] << " "
#define scan(arr) forn(i, size(arr)) cin >> arr[i]
void solve() {
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> h(n), p(n), dp(x + 1, 0), dp2(x + 1, 0);
    scan(h);
    scan(p);
    forn(i, n) {
        forn(j, x + 1) {
            if (dp[j] == 0) continue;
            if (j + h[i] <= x) {
                dp2[j + h[i]] = max(dp2[j + h[i]], dp[j] + p[i]);
                ans = max(ans, dp2[h[i] + j]);
            }
        }
        if (h[i] <= x) {
            dp[h[i]] = dp2[h[i]] = max(p[i], dp[h[i]]);
            ans = max(ans, dp[h[i]]);
        }
        dp = dp2;
    }
    cout << ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}