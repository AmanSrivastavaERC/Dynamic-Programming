#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, x, M = 1e9 + 7;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int j = 0; j < n; j++) {
        if (a[j] <= x) dp[a[j]] += 1;
        for (int i = 1; i <= x; i++) {
            if (i + a[j] <= x)
                dp[i + a[j]] = (dp[i] + dp[i + a[j]]) % M;
        }
    }
    cout << dp[x];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}