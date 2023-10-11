// Author : Nyanpasuuuuu
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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
int INF = 1e6 + 2;
int n, a[N], q, ans[N], id[N];
vector<ii> query[N];
struct Segtree
{
    vector<int>st;
    int n;
    void init(int _n = 0)
    {
        n = _n;
        st.assign(4 * n, INF);
    }
    void upd(int pos, int val, int id, int l, int r)
    {
        if(l == r)
        {
            minimize(st[id], val);
            return;
        }
        int mid = (l+r) >> 1;
        if(pos <= mid)upd(pos, val, id << 1, l, mid);
        else upd(pos, val, id << 1|1, mid + 1, r);
        st[id] = min(st[id << 1], st[id << 1|1]);
    }
    int getMin(int u, int v, int id, int l, int r)
    {
        if(l > v || r < u || l > r || u > v)return INF;
        if(l >= u && r <= v)return st[id];
        int mid = (l+r) >> 1;
        return min(getMin(u, v, id << 1, l, mid), getMin(u, v, id << 1|1, mid + 1, r));
    }
    void upd(int u, int v)
    {
        upd(u, v,1,1,n);
    }
    int getMin(int u, int v)
    {
        return getMin(u, v,1,1,n);
    }
}pos, Minn;
vector<int>val;
void init(void)
{
    cin >> n >> q;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,q)
    {
        register int l, r;
        cin >> l >> r;
        query[r].pb(ii(l, i));
    }
}
int getPos(int x)
{
    int P = lower_bound(all(val), x) - val.begin() + 1;
    return P;
}
void solve()
{
    val.clear();
    FOR(i,1,n)
        val.pb(a[i]);
    sort(all(val));
    pos.init(n);
    Minn.init(n);
    FOR(i,0,INF)
        id[i] = getPos(i);
    FOR(i,1,n)
    {
        int tmp = 0, cur = id[a[i]];
        while(true){
            int u = INF - pos.getMin(id[tmp], cur);
            if(u == 0)break;
            Minn.upd(u, abs(a[i] - a[u]));
            if(a[i] == a[u])break;
            else{
                tmp = (a[i] + a[u] + 1)/2;
            }
        }
        pos.upd(cur, INF - i);
        for(ii j : query[i])
           minimize(ans[j.se], Minn.getMin(j.fi, i));
    }
}
void process(void)
{
    INF = n + 2;
    FOR(i,1,q)
    {
        ans[i] = INF;
    }
    solve();
    FOR(i,1,n)
        a[i] = INF - a[i];
    solve();
    FOR(i,1,q)
        cout << ans[i] << endl;
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
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }

}
