// Created: 04-08-2021 12:09:41

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

int T, N, A[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    int level[N + 5] = {0}, i = 0;

    for(int j = 1; j <= N; j++)
    {
    	if(A[j] == 1)
    	{
    		i += 1;
    		level[i] += 1;

    		cout << level[1];
    		if(i > 1)
    		{
    			for(int k = 2; k <= i; k++)
    				cout << '.' << level[k];
    		}
    		cout << '\n';
    	}
    	else
    	{
    		for(int k = i; k >= 1; k--)
    		{
    			if(level[k] + 1 == A[j])
    			{
    				level[k] += 1;
    				i = k;
    				break;
    			}
    		}

    		for(int k = i + 1; k <= N; k++)
    			level[k] = 0;

    		cout << level[1];
    		if(i > 1)
    		{
    			for(int k = 2; k <= i; k++)
    				cout << '.' << level[k];
    		}
    		cout << '\n';
    	}
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}