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

const int N = 3e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

struct fast_dsu{
    int dsu_par[N], dsu_sz[N];

	void init(int n) {
		for (int i = 0; i < n; i++) {
			dsu_par[i] = i;
		}

	}

	int find(int v) {
		// while (v != dsu_par[v]) v = dsu_par[v];
		while ((v = dsu_par[v]) != dsu_par[v]);
		return v;
	}

	bool connected(int v, int u) {
		return find(v) == find(u);
	}

	int merge(int v, int u) {
		// v = find(v);
		// u = find(u);

		if (dsu_sz[v] > dsu_sz[u]) {
			int t = v;
			v = u;
			u = t;
		}

		dsu_par[u] = v;
		dsu_sz[v] += dsu_sz[u];
	}
}
};
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
