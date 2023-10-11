// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define endl '\n'
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e5 + 5;
const ll mod =1e14+9;
//const ll base = 311;
//const int bl = 488;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k > o.k; }
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
}vec[12];
int n, k,a[N];
ll sum[N], s[N], dp[N][15];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    FD(i,n,1)
        cin >> a[i];
    FOR(i,1,n)
    {
        sum[i] = sum[i-1] + a[i];
        s[i] = s[i-1]+ sum[i];
       //cout << s[i] << " " <<sum[i]<<endl ;
    }
    ll res = mod;
    memset(dp,0x3f,sizeof dp);
   //vec[0].add(0,0);
    FOR(i,1,n)
    {
        FOR(j,1,min(i,k))
        {
            dp[i][j] =s[i-1] + vec[j-1].query(i);
            vec[j].add(-sum[i],dp[i][j] + -s[i]  + sum[i]*(i+1));
        }
    }
    cout << dp[n][k] << endl;
}

