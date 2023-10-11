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

const int N = 1e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n;
int l[N], r[N], dp[2 * N][1 << 8], pos[2 * N], m, k;
bool d[9];
vector<ii>query;
void init()
{
    cin >> n >> m >> k;
    FOR(i,1,n){
        cin >> l[i] >> r[i];
        query.pb(ii(l[i], i));
        query.pb(ii(r[i] + 1, -i));
    }
    query.pb(ii(-1, -1));
    sort(all(query), [&](ii u, ii v){
         if(u.fi == v.fi)return u.se < v.se;
         else return u.fi < v.fi;});
    return;
}
void process(void)
{
    int u;
    memset(d,0,sizeof d);
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    FOR(i,0,SZ(query) - 2)
    {
        int x = query[i + 1].se;
        int add = query[i + 1].fi - query[i].fi;
       // cout << add << endl;
        if(x > 0)
        {
            FOR(j,0,7)
                if(d[j] == 0){
                    pos[x] = j;
                    d[j] = 1;
                    u = j;
                    break;
                }
            //cout << "ADD" << " "<< u << endl;
            FOR(j,0,(1 << 8) - 1){
                if(getbit(j, u) || dp[i][j] == -1)continue;
                if(__builtin_popcount(j) % 2 == 0)
                {
                    maximize(dp[i + 1][j + (1 << u)], dp[i][j]);
                    maximize(dp[i + 1][j], dp[i][j]);
                }
                else{
                    maximize(dp[i + 1][j], dp[i][j] + add);
                    maximize(dp[i + 1][j  + (1 << u)], dp[i][j] + add);
                }
            }
        }
        else
        {
            u = pos[abs(x)];
            d[u] = 0;
            FOR(j,0,(1 << 8) - 1){
                if(dp[i][j] == -1)continue;
                if(getbit(j,u))
                {
                    if(__builtin_popcount(j) % 2 == 1)
                        maximize(dp[i + 1][j - (1 << u)], dp[i][j] + add);
                    else  maximize(dp[i + 1][j - (1 << u)], dp[i][j]);
                    continue;
                }
                    if(__builtin_popcount(j) % 2 == 1)
                        maximize(dp[i + 1][j], dp[i][j] + add);
                    else maximize(dp[i + 1][j], dp[i][j]);
            }
        }
//        cout << i << endl;
//        FOR(j,0,(1 << 3) - 1)
//            cout << dp[i][j] << " ";
//        cout << endl;

       // cout << x << endl;
    }
    int ans =  -1;
    FOR(i,0,(1 << 8) - 1)
        maximize(ans, dp[SZ(query) - 1][i]);
    cout << ans << endl;
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
    //cerr << "TIME : " << TIME << "s\n";
}

