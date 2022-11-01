#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(arr) arr.begin(), arr.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define print(arr) forn(i, size(arr)) cout << arr[i] << " "
#define scan(arr) forn(i, size(arr)) cin >> arr[i]
void solve() {
    int n, s, M = 1e9 + 7;
    cin >> n >> s;
    vector<int> a(n), dp(s + 1, 0);
    scan(a);
    sort(all(a));
    forn(i, n) {
        if (a[i] <= s) dp[a[i]] += 1;
        forn(j, s) if (j + 1 + a[i] <= s) dp[j + 1 + a[i]] = (dp[j + 1] + dp[j + 1 + a[i]]) % M;
    }
    cout << dp[s];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}