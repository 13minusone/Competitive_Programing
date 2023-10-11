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
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e4 + 5;
//const ll MOD =1e9+7;
const int INF =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int a[55][N], n, m, k;
ll st[4 * N], lz[4 * N], dp[55][N], pos, pre[55][N];
void push(int id)
{
    lz[id << 1] += lz[id];
    lz[id << 1|1] += lz[id];
    st[id << 1|1] += lz[id];
    st[id << 1] += lz[id];
    lz[id] = 0;
}
void upd(int u, int v, int val, int id = 1, int l = 1, int r = m)
{
    if(l > r || u > v || l > v || r < u)return;
    if(l >= u && r <= v)
    {
        st[id] += val;
        lz[id] += val;
        return;
    }
    push(id);
    int mid = (l+r) >> 1;
    upd(u, v,val, id << 1, l, mid);
    upd(u, v, val,id << 1|1, mid + 1, r);
    st[id] = max(st[id << 1|1], st[id << 1]);
}
int get(int i1, int i2, int j1, int j2)
{
    return pre[i1][j2] - pre[i1][j1-1] + pre[i2][j2] - pre[i2][j1 - 1];
}
void init(void)
{
    cin >> n >> m >> k;
    FOR(i,1,n)
        FOR(j,1,m){
            cin >> a[i][j];
            pre[i][j] = pre[i][j - 1] + a[i][j];
       // cout << pre[i][j] << " \n"[j == m];
        }
}
void process(void)
{
    FOR(j,1,m - k + 1)
        dp[1][j] = get(1,2,j,j + k - 1);
    FOR(i,2,n)
    {
        memset(st,0,sizeof st);
        memset(lz,0,sizeof lz);
        FOR(j,1,m - k + 1)
            upd(j,j,dp[i - 1][j]);
        FOR(j,1,k)
            upd(1,j,-a[i][j]);
        FOR(j,1,m - k + 1)
        {
            dp[i][j] = st[1] + get(i,i+1,j, j + k -1);
            if(j != m - k + 1)
            {
                upd(max(1, j -k + 1), j,a[i][j]);
                upd(j + 1, j + k, -a[i][j + k]);
            }
        }
    }
//    FOR(i,1,n)
//        FOR(j,1,m)
//            cout << dp[i][j] << " \n"[j == m];
    ll ans = 0;
    FOR(j,0,m)
        maximize(ans, dp[n][j]);
    cout << ans << endl;
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

