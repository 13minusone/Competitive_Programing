#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(c) (c).begin(),(c).end()
#define SZ(c) (int)(c).size()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FD(i,a,b) for(int i = a; i >= b; i--)
#define GetBit(x,i) (x & (1 << i))
#define fi first
#define se second
#define pb push_back
#define task "ADN"

typedef pair<ll,ll> ii;

const int N = 1e6 + 5;
//const int MOD = 1e9 + 7;
const ll INF = 1e18 + 7;
//const int base = 311;
//const int BLOCK = 488;

string s;
char a[N];
int n, id[N], r[N][5];
ii dp[N][5];
vector<int>edge[N];
bool vis[N];
void init()
{
    cin >> s;
    n = SZ(s);
    s = " " + s;
}
void dfs(int j, int pre)
{
    vis[j] = true;
    a[j] = a[pre];
    for(int i : edge[j])if(!vis[i])dfs(i, pre);
}
int check()
{
    int ans = 0, A = 0, G = 0, T = 0, X = 0;
    FOR(i,1,n)
    {
        if(a[i] == '?')return n * n;
        if(a[i] == 'G')ans += G;
        if(a[i] == 'A')ans += A;
        if(a[i] == 'T')ans += T;
        if(a[i] == 'X')ans += X;
        if(a[i] != 'X')X = max(X, i);
        if(a[i] != 'G')G = max(G, i);
        if(a[i] != 'A')A = max(A, i);
        if(a[i] != 'T')T = max(T, i);
    }
    return ans;
}
void sub2()
{
    vector<int>vec;
    FOR(i,1,n)
        if(s[i] == '?')
            vec.pb(i);
    FOR(i,1,n)
        a[i] = s[i];
    if(SZ(vec) == n)
        cout << 0 << endl;
    else
    {
        int ans = n * n;
        int Svec = SZ(vec);
        if(Svec == 0)
        {
            cout << check();
            return;
        }
        FOR(i,0,(1 << Svec) - 1)
        {
            FOR(j,1,n){
                edge[j].clear();
                a[j] = s[j];
                vis[j] = false;
            }
            FOR(j,0,Svec - 1)
                if(GetBit(i,j))
                {
                    edge[vec[j] + 1].pb(vec[j]);
                }
                else edge[vec[j] - 1].pb(vec[j]);
            FOR(j,1,n)
                if(a[j] != '?')
                    dfs(j, j);
            ans = min(ans, check());
        }
        cout << ans << endl;
    }
}
/*
    A = 1;
    G = 2;
    X = 3;
    T = 4;
*/
void solve()
{
    vector<int>o[5];
    o[4].pb(1),o[4].pb(2),o[4].pb(3);
    o[3].pb(1),o[3].pb(4),o[3].pb(2);
    o[2].pb(1),o[2].pb(4),o[2].pb(3);
    o[1].pb(3),o[1].pb(4),o[1].pb(2);
    id[int('G' - 'A')] = 2;
    id[int('A' - 'A')] = 1;
    id[int('X' - 'A')] = 3;
    id[int('T' - 'A')] = 4;
    FOR(i,1,n)
        FOR(j,1,4)
        dp[i][j] = ii(INF,INF);
    dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = ii(0,0);
    if(s[n] != '?')
    {
        int j;
        j = id[int(s[n] - 'A')];
        r[n][j] =  1;
    }
    else FOR(i,1,4)r[n][i] = 1;
    FD(i,n - 1,1)
    {
        if(s[i] == '?')
            FOR(j,1,4)
                r[i][j] = r[i + 1][j]  + 1;
        else
        {
            int j;
            j = id[int(s[i] - 'A')];
            r[i][j] = r[i + 1][j] + 1;
        }
//        FOR(j,1,4)
//            cout << s[i] << " " << j << " " << r[i][j] << endl;
    }
    FOR(i,1,n)
    {
        if(s[i] == '?')
        {
            FOR(j, 1, 4)
            {
                ii x = ii(INF, INF);
                for(int k : o[j]){
                    x = min(x, ii(dp[i - 1][k].fi  + i - 1, i - 1));
                }
                dp[i][j] = min(dp[i][j], min(ii(dp[i - 1][j].fi + dp[i - 1][j].se, dp[i - 1][j].se), x));
                dp[i + r[i][j] - 1][j] = min(dp[i + r[i][j] - 1][j], ii(dp[i][j].fi + 1LL * dp[i][j].se * (r[i][j] - 1), dp[i][j].se));
                //cout << i + r[i][j] << "  " << j << " " <<   dp[i + r[i][j]][j].fi << endl;
            }
        }
        else
        {
            ii x = ii(INF,INF);
            int j;
            j = id[int(s[i] - 'A')];
            for(int k : o[j]){
                    dp[i][k] = ii(INF,INF);
                x = min(x, ii(dp[i - 1][k].fi  + i - 1,i - 1));
            }
            dp[i][j] = min(dp[i][j], min(ii(dp[i - 1][j].fi + dp[i - 1][j].se, dp[i - 1][j].se), x));
            dp[i + r[i][j] - 1][j] = min(dp[i + r[i][j] - 1][j], ii(dp[i][j].fi + 1LL * dp[i][j].se * (r[i][j] - 1), dp[i][j].se));
        }
//        FOR(j,1,4)
//        cout << i << " " << j << " " << dp[i][j].fi << " " << dp[i][j].se << endl;
    }
    if(s[n] == '?')
        cout << min(min(dp[n][1].fi, dp[n][2].fi), min(dp[n][3].fi, dp[n][4].fi));
    else{
        int  j = id[int(s[n] - 'A')];
        cout << dp[n][j].fi;
    }
}
void process()
{
    if(n <= 20)sub2();
    else solve();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }
}

