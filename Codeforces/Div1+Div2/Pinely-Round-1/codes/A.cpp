#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b <= n - 2 or a + b == 2 * n) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}