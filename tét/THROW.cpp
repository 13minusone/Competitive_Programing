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

const int N = 1e6;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, a[N], cnt[4 * N + 5], q;
ll ans[5005][5005];
void init(void)
{
    cin >> n >> q;
    FOR(i,1,n)
        cin >> a[i];
}
void process(void)
{
    FOR(i,1,n)
    {
        FD(j,i-1,1)
        {
            if(i - j + 1 >= 3)
            {
                int x = a[i] + a[j];
                ans[j][i] = cnt[-x + 2 * N] + ans[j + 1][i] + ans[j][i - 1] - ans[j + 1][i - 1];
            }
            cnt[a[j]+ 2 * N]++;
        }
        FD(j,i - 1,1)
            cnt[a[j]+ 2 * N] = 0;
    }
    FOR(i,1,q)
    {
        register int l, r;
        cin >> l >> r;
        cout << ans[l][r] << endl;
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


