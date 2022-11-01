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
    string s;
    vector<vector<int>> dp(n, vector<int>(n));
    forn(i, n) {
        cin >> s;
        forn(j, n) if (s[j] == '*') dp[i][j] = -1;
        else dp[i][j] = 0;
    }
    dp[0][0] += 1;
    forn(i, n) {
        forn(j, n) {
            if (dp[i][j] == -1) continue;
            if (i + 1 < n and dp[i + 1][j] != -1)
                dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % M;
            if (j + 1 < n and dp[i][j + 1] != -1)
                dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % M;
        }
    }
    cout << (dp[n - 1][n - 1] > 0 ? dp[n - 1][n - 1] : 0);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}