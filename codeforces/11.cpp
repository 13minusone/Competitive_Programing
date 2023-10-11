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

const int N = 50 + 5;
const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n,m;
vector<ii> edge[N][14];

struct Data
{
    int x, w, mod13;
    Data(int _x = 0, int _w = 0, int _mod13 = 0)
    {
        x = _x;
        w = _w;
        mod13 = _mod13;
    }
    bool operator  < (const Data &other) const{
        return w > other.w;
    }
};
bool cmp(Data a, Data b)
{
    return a.w < b.w;
}
int dp[N][(1 << 13) + 1][14], dpp[N];
bool vt[55][(1 << 13) + 1][14];
bool te;
string s;
void dist()
{
    memset(dp,0x3f, sizeof dp);
    memset(vt,0,sizeof vt);
    memset(dpp,0x3f, sizeof dpp);
    dp[1][0][1] = 0;
    if(te){
        priority_queue<Data>qu;
        qu.push(Data(1,0,1));
        while(!qu.empty()){
            Data x = qu.top();
            qu.pop();
            if(x.w > dp[x.x][x.mod13][x.w%13])continue;

            FOR(k,0,12)
                if( !getbit(x.mod13,k)) {
                    int res = (13+k-(x.w%13))%13;
                    //cout << k << " " <<x.w%13 << " " << res << endl;
                    for(ii v : edge[x.x][res])
                        {
                            minimize(dp[v.fi][x.mod13 + (1 << k)][k], x.w + v.se);
                            qu.push(Data(v.fi, x.w + v.se, x.mod13 + (1 <<k)));
                        }
                }

        }
        int minn = mod;
        FOR(i,1,(1<<13)-1)
        {
            FOR(j,0,12)
            {
                minimize(minn,dp[n][i][j]);
            }
        }
        if(minn != mod)cout << minn << endl;
        else cout << -1 << endl;
    }
    else
    {
         priority_queue<ii,vector<ii>>qu;
         qu.push(ii(1,0));
         dpp[1] = 0;
        while(!qu.empty()){
            ii x = qu.top();
            qu.pop();
            FOR(i,0,13)
            for(ii v : edge[x.fi][i])
                if(v.fi != x.fi && minimize(dpp[v.fi], x.se + v.se))
                    qu.push(ii(v.fi, x.se + v.se));
        }
        if(dpp[n] !=1061109567)cout << dpp[n] << endl;
        else cout << -1 << endl;
    }

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
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(k,0,13)FOR(i,1,n)edge[i][k].clear();
        FOR(i,1,m){
            int x, y;
            ll w;
            cin >> x >> y >> w;
            edge[x][w%13].pb(ii(y,w));
        }
        cin >> s;
        if(s == "True")te = true;
        else te = false;
        dist();
    }

}
