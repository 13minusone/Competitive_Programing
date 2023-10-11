// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define endl '\n'
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

const int N = 1e3 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, m,dp[N][N];
char a[N][N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    FOR(i,1,n)
        FOR(j,1,m){
            cin >> a[i][j];
            if(a[i][j] == '#')dp[i][j] = 0;
            else dp[i][j] = 1;
        }
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            if(a[i][j] == '#')continue;
            FD(k,i-1,1)
                if(a[k][j] == '#')break;
                else dp[i][j]++;
            FOR(k,i+1,n)
                if(a[k][j] == '#')break;
                else dp[i][j]++;
            FOR(k,j+1,m)
                if(a[i][k] == '#')break;
                else dp[i][j]++;
            FD(k,j-1,1)
                if(a[i][k] == '#')break;
                else dp[i][j]++;
            int o = i+1, k = j+1;
            while(o <=n && k <= m)
            {
                if(a[o][k] == '#')break;
                else dp[i][j]++;
                o++,k++;
            }
            o = i + 1, k = j-1;
            while(o <=n && k >=1 )
            {
                if(a[o][k] == '#')break;
                else dp[i][j]++;
                o++,k--;
            }
            o = i-1,k = j - 1;
            while(o > 0 && k > 0)
            {
                if(a[o][k] == '#')break;
                else dp[i][j]++;
                o--,k--;
            }
            o = i-1, k = j+1;
            while(o > 0 && k <= m)
            {
                if(a[o][k] == '#')break;
                else dp[i][j]++;
                o--,k++;
            }
        }
    }
    FOR(i,1,n)
    {
        FOR(j,1,m)cout << dp[i][j] << " ";
        cout << endl;
    }
}

