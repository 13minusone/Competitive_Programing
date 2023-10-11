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
typedef pair<short,short> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 5e3 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int dirx[5] = {1,0,-1,0};
int diry[5] = {0,-1,0,1};
bool a[N][N];
int n, m, d[N][N],dist[N][N];
bool can(int x,int y)
{
    if(x <= n && y <= n && x >= 1 && y >= 1)return true;
    return false;
}
pair<ii,int>qu[N*4000];
int solve()
{
    int start = 1, endd = 0;
    memset(dist,0x3f,sizeof dist);
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            if(!a[i][j])dist[i][j] = 0;
            if(d[i][j] >= 2 && a[i][j])qu[++endd] = (make_pair(ii(i,j),1)), dist[i][j] = 1;
        }
    }
     while(start <= endd)
    {
        pair<ii,int> x = qu[start];
        start++;
        if(dist[x.fi.fi][x.fi.se] < x.se)continue;
        FOR(i,0,3)
        {
            int nx = x.fi.fi + dirx[i], ny = x.fi.se + diry[i];
            if( a[nx][ny] && d[nx][ny] >= 1 && minimize(dist[nx][ny], x.se + 1))
            {
                qu[++endd] = (make_pair(ii(nx,ny),x.se + 1));
            }
            d[nx][ny]++;
        }
    }
    int maxx = 0;
    FOR(i,1,n)
    {
        FOR(j,1,n)maximize(maxx,dist[i][j]);
    }
    return maxx;
}
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
    cin >> n;
    FOR(i,1,n){
        cin >> s;
        s = ' ' + s;
        FOR(j,1,n)
            a[i][j] = int(s[j]-'0');
    }
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            int sum =0;
            FOR(k,0,3)
            {
                int nx = i + dirx[k], ny = j + diry[k];
                sum += 1 - a[nx][ny];
            }
            d[i][j] = sum;
        }
    }
//    FOR(i,1,n)
//    {
//        FOR(j,1,n)cout << d[i][j] << " " ;
//        cout << endl;
//    }
    cout << solve();
}
