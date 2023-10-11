/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define fi first
#define se second
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll N = 100005;
const ll mod =1e9+9;
const ll base = 311;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vector<ii>vec[N];
ll hi[N],up[N][25],maxx[N][25],minn[N][25],LOG=19;
void dfs(int u,int y)
{
    for(ii p : vec[u])
    {
        if(p.fi!=y)
        {
            up[p.fi][0]=u;
            maxx[p.fi][0]=p.se;
            minn[p.fi][0]=p.se;
            hi[p.fi]=hi[u]+1;
            dfs(p.fi,u);
        }
    }
}
int n,q,x,y,z;
void build(int n)
{
    for (int i = 0; i <=LOG; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            minn[j][i] = 2000000;
        }
    }
}
ii solve(int u,int v)
{
    ll maxl=0,minl=2000000;
    if(hi[u]<hi[v])swap(u,v);
    for(int i = LOG; i >= 0; i--)
    {
        if(hi[up[u][i]]>=hi[v])
        {
            minl=min(minl,minn[u][i]);
            maxl=max(maxl,maxx[u][i]);
            u=up[u][i];

        }
    }
    if(u==v)
    {
        return ii(maxl,minl);
    }
    for(int i = LOG; i >= 0 ; i--)
    {
        if(up[u][i]!=up[v][i])
        {
            maxl=max(maxl,max(maxx[u][i],maxx[v][i]));
            minl=min(minl,min(minn[u][i],minn[v][i]));
            u=up[u][i];
            v=up[v][i];
        }
    }
    maxl=max(maxl,max(maxx[u][0],maxx[v][0]));
    minl=min(minl,min(minn[u][0],minn[v][0]));
    return ii(maxl,minl);
}
void nhap()
{
    cin >> n ;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> x >> y >> z;
        vec[x].push_back({y,z});
        vec[y].push_back({x,z});
    }
    build(n);
    dfs(1,-1);
    for(int j = 1 ; j<=LOG; j++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            up[i][j]=up[ up[i][j-1] ][j-1];
            maxx[i][j]=max(maxx[up[i][j-1]][j-1],maxx[i][j-1]);
            minn[i][j]=min(minn[up[i][j-1]][j-1],minn[i][j-1]);
        }
    }
    cin >> q;
    for(int i = 1 ; i <= q ; i++)
    {
        cin >> x >> y;
        ii f=solve(x,y);
        cout << f.se << " "<< f.fi << endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}


