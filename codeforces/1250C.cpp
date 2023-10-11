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

const int N = 2e5 + 5;
const ll mod =-1e17+9;
//const ll base = 311;
//const int block = 488;
int n, l[N], r[N];
ll k,x;
ii st[4 * N];
vector<ii>edge[N];
void upd(int x,int val,int id = 1,int l = 1,int r = N - 5)
{
    if(l == r)
    {
        st[id].fi += val;
        st[id].se = x;
        return ;
    }
    int mid = (l+r) /2;
    if(x <= mid)upd(x, val, id<< 1, l, mid);
    else upd(x, val, id << 1|1, mid+1, r);
    st[id] = max(st[id << 1],st[id << 1|1]);
}
ii get(int u, int v, int id = 1, int l = 1, int r = N-5)
{
    if(u > v || l > v || r < u)return ii(0, 0);
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return max(get(u, v, id << 1, l , mid), get(u, v, id << 1|1, mid+1, r));
}
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
    FOR(i,1,n)
    {
        cin >> l[i] >> r[i] >> x;
        edge[l[i]].pb(ii(x,r[i]));
        upd(r[i],x);
    }
    cout << get(1,7).fi << endl;
    FOR(i,1,N-5)
        upd(i,-1LL* k * i);
    ll ans = 0, le, ri;
    FOR(i,1,N-5)
    {
        ii maxx = get(i, N-5);
        if(ll(1LL * i +  maxx.fi) > ans)
        {
            ans = 1LL * i +  maxx.fi;
            le = i;
            ri= maxx.se;
        }
        for(ii v : edge[i])
        {
            upd(v.se, -v.fi);
        }
        cout << ans << endl;;
    }
    if(ans == 0)cout << 0;
    else {
        vector<int>vec;
        FOR(i,1,n)
        {
            if(l[i] >= le && r[i] <= ri)vec.pb(i);
        }
        cout << ans <<  " " << le << " " << ri << " " << SZ(vec) << endl;
        for(int i : vec)cout << i << " " ;
    }
}


