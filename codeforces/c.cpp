#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define SZ(a) (int)a.size()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FD(i,a,b) for(int i = a; i >= b; i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define ii pair<int,int>
#define task "test"

const int N = 1e6 + 5;
//const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
//const int base = 311;
int n;
ll dp[N][10], ans;
string s;
void add(ll &a,const ll b)
{
    a += b;
    while(a >= MOD)a-=MOD;
}
void init(void)
{
    scanf("%d",&n);
    cin >> s;
}
void process(void)
{
    FOR(i,1,n)
        FOR(j,0,9)dp[i][j] = 0;
    ans = 0;
    s = " " + s;
    FOR(i,1,n)
        {
            int x = s[i] - '0';
            if(x == 0 && dp[i - 1][x] > 0)add(dp[i][x],1);
            else if(x != 0)add(dp[i][x]
            FOR(j,0,9){
                dp[i][j] = dp[i - 1][j];
                add(dp[i][x], dp[i - 1][j]);
            }
        }
    add(ans, dp[n][0]);
    add(ans, dp[n][5]);
    printf("%lld\n", ans);
}
signed main(void)
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int t = 1;
    scanf("%d",&t);
    while(t--)
    {
        init();
        process();
    }
}
