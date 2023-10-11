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

const int N = 1e2 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int dp[N][N][4];
int n, cnt[N][4], u, v;
string s;
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
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = SZ(s);
        s =  " " + s;
        memset(dp,0,sizeof dp);
        memset(cnt,0x3f,sizeof cnt);
        FOR(i,1,n)
            dp[i][i][s[i] - 'a' + 1] = 1;
        FOR(i,1,n)
            FD(j,i-1,1){
            FOR(type,1,3){
                if(type == 1)u = 2, v = 3;
                if(type == 2)u = 1, v = 3;
                if(type == 3)u = 2, v = 1;
                FOR(k,j,i-1){
                        maximize(dp[j][i][type], dp[k + 1][i][u] * dp[j][k][v]);
                        maximize(dp[j][i][type], dp[k+1][i][v] * dp[j][k][u]);
                    }
           // cout << i << " " << j << " " << type << " " << dp[j][i][type] << endl;
            }
        }
    cnt[0][1] = cnt[0][2] = cnt[0][3]  =0;
    FOR(type, 1, 3)
        FOR(i,1,n)
            FOR(j,1,i)
                if(dp[j][i][type])
                    minimize(cnt[i][type], cnt[j-1][type]  + 1);
        cout << min({cnt[n][1], cnt[n][2], cnt[n][3]}) << endl;
    }

}

