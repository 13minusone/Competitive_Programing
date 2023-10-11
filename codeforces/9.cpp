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
const ll mod = 1e9+7;
//const ll base = 311;
//const int bl = 488;

int n,m,i1,i2,l;
//ii st[4*N];
//vector<int>vec[N];
//ii Merge(ii a, ii b)
//{
//    return ii((1LL*a.fi * powe(b.se)%mod + b.fi)%mod, a.se + b.se);
//}
//void upd(int pos, int val,int id = 1, int l = 1, int r = n)
//{
//    if(l == r)
//    {
//        st[id].fi = val;
//        return;
//    }
//    int m = (l+r) >> 1;
//    if(pos <= m)upd(pos, val, id << 1, l, m);
//    else upd(pos, val, id << 1|1, m + 1, r);
//    st[id] = Merge(st[id << 1], st[id << 1|1]);
//}
//ii get(int u, int v, int id = 1, int l = 1, int r = n)
//{
//    if(u > r || v < l || l > r)return ii(0,0);
//    if(u <= l && r <= v)return st[id];
//    int mid = (l+r) >> 1;
//    return Merge(get(u, v, id << 1, l, mid), get(u, v, id << 1|1, mid+1, r));
//}
//void solve(int i1, int i2, int l)
//{
//    int le = 0, r = l-1;
//    while(le <= r)
//    {
//        int mid = (le+r) >> 1, ri = r, res;
//        while(le <= ri)
//            if(get(i1 + le,i1 + mid) == get(i2 + le, i2 + mid))
//                le = mid + 1, res = le;
//            else ri = mid-1;
//        upd(le+1,)
//    }
//}
int par[N][20];
int root(int u, int k)
{
    return (par[u][k] < 0 ? u : par[u][k] = root(par[u][k], k));
}
void join(int u, int v, int k)
{
    if( (u = root(u,k)) == (v = root(v,k)))return;
    if(-par[u][k] < -par[v][k])swap(u,v);
    par[u][k] += par[v][k];
    par[v][k] = u;
    return;
}
void solve(int i1,int i2, int l)
{
    FD(i,19,0)
    {
        if((1 << i) <= l)
        {
            join(i1,i2,i);
            l -= (1 << i);
            i1 += (1 << i);
            i2 += (1 << i);
        }
    }
}
ll powe(int a, int b)
{
    if(b == 1)return a;
    if(b == 0)return 1;
    ll t = powe(a,b/2);
    if(b&1)return (1LL*(1LL * t * t%mod) * a)%mod;
    else return (1LL * t * t %mod);
}
void down()
{
    FD(i,19,1)
    {
        FOR(j,1,n - (1<<(i-1) ) )
        {
            int u = root(j,i);
            join(j,u,i-1);
            join(j + (1 << (i-1)), u    + (1 << (i-1)) ,i-1);
        }
    }
    int component = 0;
    FOR(i,1,n)
        if(par[i][0] <= -1)component++;
    cout << powe(2,component);
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
    cin >> n >> m;
    memset(par,-1,sizeof par);
    FOR(i,1,m)
    {
        cin >> i1 >> i2 >> l;
        solve(i1,i2,l);
    }
    down();
}

