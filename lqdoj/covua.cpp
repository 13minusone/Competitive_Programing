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
const ll MOD =1e9+9;
//const ll base = 311;
//const int BLOCK = 488;

int dx[5] = {-1,-1,-2,-2};
int dy[5] = {-2,2,1,-1};
int k, m;
ll n;
struct Matrix
{
    int a[N][N];
    int n, m;
    Matrix(int _n = 0, int _m = 0){
        n = _n;
        m = _m;
        FOR(i,1,n)
            FOR(j,1,m)a[i][j] = 0;
    }
    Matrix operator *(const Matrix &other) const{
        Matrix res = Matrix(n,other.m);
        FOR(i,1,n)
            FOR(j,1,other.m){
                FOR(k,1,m){
                    res.a[i][j] += 1LL * a[i][k] * other.a[k][j]%MOD;
                    res.a[i][j] %= MOD;
                }
            }
        return res;
    }
}pw[61];
Matrix powe(Matrix a, ll b)
{
    Matrix res = Matrix(2 *m, 2 * m);
    int o = 0;
    FOR(i,1, 2 * m)res.a[i][++o] = 1;
    while( b > 0){
        if(b & 1)res = res* a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void build()
{
     Matrix res = Matrix(2 * m, 2 * m);
    int o = 0;
    FOR(i,1,m)res.a[i][++o] = 1;
    for(int i = m + 1, j = 1;i <= 2 * m; i++,j++){
            FOR(k,0,1)
            {
                int newY = j + dy[k];
                if(1 <= newY && newY <= m)res.a[i][newY + m] = 1;
            }
            FOR(k,2,3)
            {
                int newY = j + dy[k];
                if(1 <= newY && newY <= m)res.a[i][newY] = 1;
            }
    }
    pw[0] = res;
    FOR(i,1,60)pw[i] = (pw[i-1] * pw[i-1]);
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
        cin >> n >> m >> k;
        build();
    }

}
