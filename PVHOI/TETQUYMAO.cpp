// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "TETQUYMAO"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

const int N = 1e6 + 5;
const ll MOD =1e9 + 19972207;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int r, c, a[62], allow[(1 << 10)][1 << 10];
int f[62][(1 << 10)][(1 << 10)], dp[(1 << 10)], g[61][(1 << 10)][(1 << 10)], ans[11];
void init(void)
{
    cin >> r >> c;
    FOR(i,1,r)
        cin >> a[i];
}
void add(int &a, const int &b)
{
    a += b;
    while(a >= MOD) a-= MOD;
}
void cal_dp()
{
    FOR(i,0,c - 1)
        FOR(j,0,(1 << c)  -1)
            if(getbit(j,i))
                add(dp[j], dp[j ^(1 << i)]);
}
void process(void)
{
    a[0] = 3;
    a[r + 1] = 3;
    FOR(i,0, (1 << c) - 1)
        FOR(j,0,(1 << c) - 1){
            FOR(k,0,c - 1)
                if(getbit(j,k) && ( (k  >= 2  && getbit(i,k - 2)) || (k < c- 2 &&  getbit(i,k + 2))))
                {
                    allow[i][j] = -1;
                    break;
                }
            if(allow[i][j] == -1)continue;
            FOR(k,0,c - 1)
                if((k == c  -1 || !getbit(j,k + 1))
                   && (k == c - 2 || !getbit(i, k + 2))
                   && (k < 2 || !getbit(i, k - 2))
                   && (k < 1 || !getbit(j, k - 1)))
                    allow[i][j] ^= (1 << (k));
          // cout << i << " " << j << " " << allow[i][j] << endl;
        }
    FOR(k,0, (1 << c) - 1)
        if(a[1] == 3 ||  __builtin_popcount(k) % 3 == a[1])
        f[1][0][k] = 1;
    FOR(i,2,r)
    {
        FOR(j,0, (1 << c) - 1){
            if(a[i - 1] != 3 &&  __builtin_popcount(j) % 3 != a[i - 1])
                continue;
            FOR(k,0,(1 << c) - 1)
                dp[k] = f[i - 1][k][j];
            cal_dp();
            FOR(k,0,(1 << c) - 1){
                 if(a[i] != 3 &&  __builtin_popcount(k) % 3 != a[i])
                    continue;
               if(allow[j][k] != -1)add(f[i][j][k], dp[allow[j][k]]);
           // cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
            }
        }
    }
    FOR(k,0, (1 << c) - 1)
        if(a[r] == 3 ||  __builtin_popcount(k) % 3 == a[r])
            g[r][0][k] = 1;
    FD(i,r - 1,0)
    {
        FOR(j,0, (1 << c) - 1){
             if(a[i + 1] != 3 &&  __builtin_popcount(j) % 3 != a[i + 1])
                continue;
            FOR(k,0,(1 << c) - 1)
                dp[k] = g[i + 1][k][j];
            cal_dp();
            FOR(k,0,(1 << c) - 1){
                if(a[i] != 3 &&  __builtin_popcount(k) % 3 != a[i])
                    continue;
                if(allow[j][k] != -1)add(g[i][j][k], dp[allow[j][k]]);
          //  cout << i << " " << j << " " << k << " " << g[i][j][k] << endl;
            }
        }
    }
    FOR(i,1,r)
    {
        FOR(j,0,c - 1)ans[j] = 0;
        FOR(j,0,(1 << c) - 1){
            FOR(k,0,(1 << c) - 1)
            {
                int tmp = 1LL * f[i][j][k] * g[i - 1][k][j] % MOD;
                //cout <<i << " " <<  j <<" " << k << " " << g[i  -1][k][j] << endl;
                FOR(o,0,c - 1)
                    if(getbit(k,o))
                        add(ans[o], tmp);

            }
        }
        FOR(j,0,c - 1)
            printf("%d ", ans[j]);
        printf("\n");
    }

}
signed main()
{
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}
