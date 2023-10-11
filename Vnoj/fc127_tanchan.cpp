// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, a[N];
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		//assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
}dp;
ll mul[N], pre[N];
/*
    mul[i] = mul[i - 1] + a[i] * i;
    pre[i] = pre[i - 1] + a[i];
    dp[i] = max(mul[i] - mul[j-1] - (j-1) * (pre[i] - pre[j-1]) (1 <= j < = i)
    dp[i] = max(mul[i] - mul[j-1] - (j-1) * pre[i] + (j-1) *  pre[j-1]) (1 <= j < = i)
    dp[i] = max(mul[i]  - (j-1) * pre[i] + - mul[j-1] + (j-1) *  pre[j-1]) (1 <= j < = i)
*/
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n)
            cin >> a[i];
        ll ans = 0;
        dp.add(0,0);
        int node = -1;
        FOR(i,1,n)
        {
            pre[i] = pre[i - 1] + a[i];
            mul[i] = mul[i - 1] + 1LL * a[i] * i;
            dp.add(i-1, 1LL * (i-1) * pre[i-1] - mul[i-1]);
            if(maximize(ans, dp.query(-pre[i]) + mul[i]))
            {
                node = i;
            }
        }
        cout << ans << endl;
        FOR(i,1,node-1)
        {
            if( (mul[node] - mul[i - 1] -1LL * (i- 1) * (pre[node] - pre[i - 1])) == ans )
            {
                cout << i << " " << node << endl;
                return 0;
            }
        }
    }

}
