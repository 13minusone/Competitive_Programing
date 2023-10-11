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
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

const int N = 3e5 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, q, a[N], id[N], last[N];
ll st[4 * N], ans[N];
vector<int>val;
vector<ii>query[N];
void init(void)
{
    cin >> n >> q;
    FOR(i,1,n){
        cin >> a[i];
        val.pb(a[i]);
    }
    FOR(i,1,q)
    {
        register int l, r;
        cin >> l >> r;
        query[r].pb(ii(l, i));
    }
}
void upd(int pos, int val, int id = 1, int l = 1, int r = n)
{
    if(l == r){
        st[id] = val;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, val, id << 1, l, mid);
    else upd(pos, val, id << 1|1, mid + 1, r);
    st[id] = st[id << 1] ^ st[id << 1|1];
}
ll getXor(int u, int v, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || l > r || u > v)return 0;
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return (getXor(u, v, id << 1, l, mid) ^ getXor(u, v,  id << 1|1, mid + 1, r));
}
void process(void)
{
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    FOR(i,1,n)
        id[i] = lower_bound(all(val), a[i]) - val.begin() + 1;
    FOR(i,1,n)
    {
        if(last[id[i]] != 0)
            upd(last[id[i]], 0);
        upd(i, a[i]);
        for(ii j : query[i])
            ans[j.se] = getXor(j.fi, i);
        last[id[i]] = i;
    }
    FOR(i,1,q)
        cout << ans[i] << " " ;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    cerr << "TIME : " << TIME << "s\n";
}


