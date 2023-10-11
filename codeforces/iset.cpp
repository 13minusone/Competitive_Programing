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
typedef pair<ll,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n,m,a[N];
ii q[N], ans[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    FOR(i,0,n-1)cin >> a[i];
    FOR(i,1,n-1)
    {
        cin  >> q[i].fi >> q[i].se;
    }
    FD(i,n-1,0)
    {
        ans[i].fi += a[i];
        if(q[i].se == 0){
            ans[q[i].fi].se = max(ans[i].se + ans[q[i].fi].fi,ans[i].se + ans[q[i].fi].se);
            ans[q[i].fi].fi += ans[i].se;
        }
        if(q[i].se == 2){
            ans[q[i].fi].fi = max(ans[q[i].fi].fi + ans[i].se, ans[i].fi + ans[q[i].fi].se);
            ans[q[i].fi].se += ans[i].se;
        }
        if(q[i].se == 1)
        {
            ans[q[i].fi].fi =max(ans[q[i].fi].fi + max(ans[i].fi,ans[i].se), ans[i].fi + max(ans[q[i].fi].se,ans[q[i].fi].fi))
            ans[q[i].fi].se += ans[i].se;
        }
    }
    cout << max(ans[0].fi, ans[0].se);
}
