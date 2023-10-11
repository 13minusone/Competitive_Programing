// Onegai no bug
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

const int N = 5e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, m, a[N], l[N][21],LOG = 20, r[N][21], pos[N];\
vector<int>val;
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n){
        cin >> a[i];
        val.pb(a[i]);
    }
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    FOR(i,1,n)
        a[i] = lower_bound(all(val), a[i]) - val.begin();
}
ii findd(int le, int ri)
{
    int k = log2(ri - le + 1);
    return ii(max(l[le][k], l[ri - (1 << k) + 1][k]),
              min(r[le][k], r[ri - (1 << k) + 1][k]));
}
void process(void)
{
    FOR(i,1,n)
    {
        l[i][0] = pos[a[i]];
        pos[a[i]] = i;
    }
    memset(pos,0,sizeof pos);
    r[n + 1][0] = n + 1;
    FD(i,n,1)
    {
        if(pos[a[i]] == 0)r[i][0] = n + 1;
        else r[i][0] = pos[a[i]];
        pos[a[i]] = i;
        //cout << r[i][0] << " " ;
    }
   // cout << endl;
    FOR(i,1,LOG)
        FOR(j,1,n - (1 << i) + 1)
        {
            r[j][i] = min(r[j][i - 1], r[j + (1 << (i-1))][i - 1]);
            l[j][i] = max(l[j][i - 1], l[j + (1 << (i-1))][i - 1]);
        }
    while(m--)
    {
        register int le, ri;
        cin >> le >> ri;
        ii x = findd(le, ri);
        //cout << x.fi << " " << x.se << endl;
        if(l[x.fi][0] < le && r[x.se][0] > ri && x.se >= x.fi)
            cout << min(x.se,ri) - max(x.fi,le)<< endl;
        else cout << 0 << endl;
    }
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

