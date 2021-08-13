#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debugarr(x,i,j) cerr << #x <<" "; _print(x,i,j); cerr << endl;
#else
#define debugarr(x)
#endif

void _print(int t){cerr << t;}
void _print(string t){cerr << t;}
void _print(bool t){cerr << t;}
void _print(char t){cerr << t;}
void _print(long double t){cerr << t;}
void _print(double t){cerr << t;}
void _print(unsigned long long t){cerr << t;}
template <class T> void _print(T arr[], int i, int j){cerr << "[ " ;for ( int k = i; k <= j; k++) cerr << arr[k] << ", " ;cerr << "]\n";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.ff);cerr << ",";_print(p.ss);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

int N, D, A[mxN];

const int MOD = 1e9 + 7;
int fact[mxN], invfact[mxN];

int pow(int a, int b, int m)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans *a) % m;
		b /= 2;
		a = (a *a) % m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD - 2, MOD);
}

void precompute()
{
	fact[0] = fact[1] = 1;
	for(int i = 2; i < mxN; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
	invfact[mxN - 1] = modinv(fact[mxN - 1]);
	
	for(int i = mxN - 2; i >= 0; i--)
	{
		invfact[i] = invfact[i + 1] * (i + 1);
		invfact[i] %= MOD;
	}
}

int nCr(int x, int y)
{
	if(y > x)
		return 0;
	int num = fact[x];
	num *= invfact[y];
	num %= MOD;
	num *= invfact[x - y];
	num %= MOD;
	return num;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	precompute();

	cin >> N >> D;
	for(int i = 1; i <= N; i++)
		cin >> A[i];

	if(N < 3)
	{
		cout << 0;
		return 0;
	}

	int i = 1, j = 3, ans = 0, pre = -1;
	while(j <= N)
	{
		if(abs(A[j] - A[i]) <= D)
		{
			if(j - i + 1 >= 3)
			{
				ans += ((j - i) * (j - i - 1)) / 2;
			}
			j += 1;
		}
		else
		{
			
			i += 1;
		}
	}
	cout << ans;

    return 0;
}