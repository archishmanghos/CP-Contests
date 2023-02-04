#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N + 2], sum = 0, minn = 1e15;
	int neg = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		neg += A[i] < 0;
		sum += abs(A[i]);
		minn = min(minn, abs(A[i]));
	}

	if (neg & 1) cout << sum - (2 * minn) << '\n';
	else cout << sum << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}