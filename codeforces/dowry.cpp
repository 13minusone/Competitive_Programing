// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "dowry"
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

int n, m, a[N][N];
ll f[N][N];
ll cal(int x, int y, int a, int b)
{
    return f[a][b] - f[a][y-1] - f[x-1][b] + f[x-1][y-1];
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
    cin >> n >> m;
    FOR(i,1,n)
    {
        FOR(j,1,m)cin >> a[i][j];
    }
    FOR(i,1,n)
        FOR(j,1,m)f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
    //cout << cal(1,1,2,2);
    int N,D;
    bool te  = false;
    FOR(i,1,n-1)
    {
        FOR(j,1,m-1)
        {
            ll s1 = cal(1,1,i,j);
            ll s3 = cal(i+1,1,n,j);
            ll s2 = cal(1,j+1,i,m);
            ll s4 = cal(i+1,j+1,n,m);
            if(s3 == s4 &&s1 + s2 == s3)te = true;
            if(s1 == s2 && s3 + s4 == s2)te= true;
            if(s1 == s3 && s2 + s4 == s1)te= true;
            if(s4 == s2 && s3 + s1 == s2)te= true;
            if(te){
            N = i, D= j;
            break;
            }
        }
        if(te)break;
    }
    if(te)
    {
        cout << "YES" << endl;
        cout << "N" << N << endl;
        cout << "D" << D << endl;
    }else cout << "NO" << endl;
}

