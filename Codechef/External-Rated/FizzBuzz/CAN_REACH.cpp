#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, X, Y, K;

void solve()
{
    cin >> X >> Y >> K;
    X = abs(X);
    Y = abs(Y);
    cout << (X % K == 0 && Y % K == 0 ? "YES" : "NO") << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}