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
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 3e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
ii st[4*N], a[4*N];
int n;
vector<int>speed;
ii pluss(ii a, ii b)
{
    return ii(a.fi + b.fi, a.se + b.se);
}
void upd(int pos, int val, int id = 1 ,int l = 1, int r = n+1)
{
    if(l == r)
    {
        st[id].fi += val;
        st[id].se += 1;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, val, id << 1, l, mid);
    else upd(pos, val, id << 1|1, mid + 1, r);
    st[id] = pluss(st[id << 1], st[id << 1|1]);
 }
 ii get(int v, int u = 1, int id = 1, int l = 1, int r = n+1)
 {
     if(l > v || r < u || u > v || l >r)return ii(0,0);
     if(l >= u && r <= v)return st[id];
     int mid = (l+r) >>1;
     return pluss(get(v,u,id << 1, l, mid), get(v, u, id << 1|1, mid + 1, r));
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
    cin >> n;
    FOR(i,1,n)
    {
        cin >> a[i].fi;
    }
    FOR(i,1,n){
        cin >> a[i].se;
        speed.pb(a[i].se);
    }
    sort(a + 1, a + 1 + n);
    sort(all(speed));
    //speed.resize(unique(all(speed)) - speed.begin());
    //for(int i : speed)cout << i << endl;
    ll ans = 0;
    FOR(i,1,n)
    {
        //cout << a[i].fi << endl;
        int k = lower_bound(all(speed), a[i].se) - speed.begin() + 1;
        ii res = get(k);
        ans += (1LL * a[i].fi * res.se - res.fi);
        upd(k,a[i].fi);
    }
    cout << ans;
}

