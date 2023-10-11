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

const int N = 1e3 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, cnt, minn[N], num[N], dp[N][10005], Sz[N], pos[N];
string s;
bool cmp(int u, int v)
{
    if(minn[u] < 0 && minn[v] < 0 && num[u] < 0 && num[v] < 0)return minn[u] - num[u] < minn[v] - num[v];
    if(num[u] > 0 &&  num[v] > 0)return minn[u] > minn[v];
    else return num[u] > num[v];
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
        cin >> n;
        memset(minn,0x3f,sizeof minn);
        int maxx = 0;
        FOR(i,1,n)
        {
            cin >> s;
            cnt = 0;
            for(char c : s)
            {
                cnt += (c == '(' ? 1 : -1);
                minimize(minn[i], cnt);
            }
            pos[i] = i;
            num[i] = cnt;
            Sz[i] = SZ(s);
            maxx += Sz[i];
        }
        sort(pos + 1, pos + 1 + n, cmp);
        memset(dp,-0x3f,sizeof dp);
        dp[0][0] = 0;
        FOR(i,0,n-1){
            int id = pos[i + 1];
            //cout << id << endl;
            FOR(j,0,maxx)
                if(dp[i][j] >= 0){
               maximize(dp[i + 1][j], dp[i][j]);
              if(j + minn[id] >= 0)
                maximize(dp[i + 1][j + num[id]], dp[i][j] + Sz[id]);
            }
        }
        cout << dp[n][0] << endl;
    }

}
