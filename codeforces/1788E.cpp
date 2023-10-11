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

const int N = 2e5 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, a[N], sz;
ll pre[N];
int st[4 * N], dp[N];
vector<ll>val;
void init(void)
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        val.pb(pre[i - 1]);
    }
}
void upd(int pos, int val, int id = 1, int l = 1, int r = sz)
{
    if(l == r){
        maximize(st[id], val);
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, val, id << 1, l, mid);
    else upd(pos, val, id << 1|1, mid + 1, r);
    st[id] = max(st[id << 1], st[id << 1|1]);
}
int getMax(int u, int v, int id = 1, int l = 1, int r = sz)
{
    if(l > r || u > v || l > v || r < u)return -INF;
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return max(getMax(u, v, id << 1, l, mid), getMax(u, v, id << 1|1, mid + 1, r));
}
void process(void)
{
    memset(st, -0x3f,sizeof st);
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    sz = SZ(val);
    dp[0] = 0;
    FOR(i,1,n)
    {
        int k = lower_bound(all(val), pre[i - 1]) - val.begin() + 1;
        upd(k, dp[i - 1] - i);
        k = upper_bound(all(val), pre[i]) - val.begin();
        dp[i] = i + 1 + getMax(1,k);
        //cout << i << " " << dp[i] <<  " " << k<< " " << getMax(1,k) << endl;
        maximize(dp[i], dp[i - 1]);

    }
    cout << dp[n] << endl;
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
