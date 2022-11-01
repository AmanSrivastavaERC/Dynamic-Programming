#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(arr) arr.begin(), arr.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define print(arr) forn(i, size(arr)) cout << arr[i] << " "
#define scan(arr) forn(i, size(arr)) cin >> arr[i]
int NoOfChicks(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5 and i + 1 + j <= n; j++)
            dp[i + 1 + j] += dp[i] * 2;
    }
    int ans = 0;
    for (int i = max(n - 5, (int)1); i <= n; i++) ans += dp[i];
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    forn(i, t) {
        // cout << "Case #" << i + 1 << ": ";
        int n;
        cin >> n;
        cout << NoOfChicks(n) << "\n";
    }
    return 0;
}