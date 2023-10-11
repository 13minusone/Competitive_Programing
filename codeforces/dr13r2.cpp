// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "dr13r2"
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

const int N = 1e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n;
ll st[4*N];
void upd(int pos, int id = 1,int l = 1, int r = n)
{
    if(l == r){
        st[id] = 1;
        return;
    }
    int mid= (l+r) >> 1;
    if(pos <= mid)upd(pos, id << 1, l, mid);
    else upd(pos, id << 1|1, mid+1, r);
    st[id] = st[id << 1] + st[id << 1|1];
}
ll get(int u, int v,int id = 1,int l = 1, int r = n)
{
    if(l > r || l > v || r < u || u > v)return 0;
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return get(u, v, id << 1, l, mid) + get(u, v, id << 1|1, mid+1, r);
}
vector<int>vec;
int a[N],cnt[N],dem[N],tru[N];
ll ans = 0;
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
        cin >> a[i];
        ans += get(a[i],n);
        upd(a[i]);
    }
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    memset(dem,0,sizeof dem);
    ll maxx = 0;
    int xmax = 0;
    FOR(i,1,n)
        if(maximize(xmax,a[i])) cnt[i] = 1;
    xmax = N+5;
    FD(i,n,1)
        if(minimize(xmax,a[i]))dem[i] = 1;
    FOR(i,1,n)
    {
        int v0 = -1,s = 0;
        if(dem[i])
            for(int v : vec){
                maximize(maxx,get(a[i],v)-tru[v]);
            }
        if(!cnt[i])upd(a[i]);
        else vec.pb(a[i]),tru[a[i]] = get(1,a[i]);
    }
    cout <<ans - 2*maxx;
}
