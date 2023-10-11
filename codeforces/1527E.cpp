// Onegai no bug
// Author : Nyanpasuuuuu
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

const int N = 35005;
const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;

int n, k, a[N], b[N], pos[N], st[4*N], lz[4*N], last[N], dp[105][N];
void push(int id)
{
    int &t = lz[id];
    st[id << 1] += t;
    st[id << 1|1] += t;
    lz[id << 1] += t;
    lz[id << 1|1] += t;
    t = 0;
    return;
}
void reset()
{
    FOR(i,1,4*n)st[i] = lz[i] = 0;
}
void upds(int u,int v, int val, int id = 1, int l = 1, int r = n)
{
    if(l > r || l > v || r < u || v < u)return;
    if(l >= u && r <= v)
    {
        st[id] += val;
        lz[id] += val;
        return;
    }
    int m = (l + r) >>1;
    push(id);
    upds(u, v, val, id << 1, l, m);
    upds(u, v, val, id << 1|1, m+1, r);
    st[id] = min(st[id << 1], st[id << 1|1]);
}
int gets(int u,int v, int id = 1, int l = 1, int r = n)
{
    if(l > r || l > v || r < u)return mod;
    if(l >= u && r <= v)
    {
        return st[id];
    }
    int m = (l + r) >>1;
    push(id);
    return min(gets(u, v, id << 1, l, m),
    gets(u, v, id << 1|1, m+1, r));
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
    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> a[i];
        if(pos[a[i]] != 0)b[i] = i - pos[a[i]];
        last[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    FOR(i,1,n)dp[1][i] = dp[1][i-1] + b[i];
    FOR(j,2,k)
    {
        reset();
        FOR(i,1,n)upds(i,i,dp[j-1][i]);
        FOR(i,2,n)
        {
            upds(1,last[i]-1,b[i]);
            int cnt = gets(1,i-1);
            dp[j][i] = cnt;
            //cout << i <<" "<< j << " " << b[i] << endl;
        }
    }
    cout << dp[k][n];
}

