#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(arr) arr.begin(), arr.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define print(arr) forn(i, size(arr)) cout << arr[i] << " "
#define scan(arr) forn(i, size(arr)) cin >> arr[i]
void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[n] = 0;
    for (int i = n; i > 0; i--) {
        int x = i;
        while (x) {
            int d = x % 10;
            if (i - d >= 0)
                dp[i - d] = min(dp[i - d], dp[i] + 1);
            x /= 10;
        }
    }
    cout << dp[0];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}