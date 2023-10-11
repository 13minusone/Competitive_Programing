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

const int N = 1e6 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, a[2505], f[2505][2505];
int check[2*N];
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
        cin >> n;
        memset(f,0, sizeof f);
        memset(check,0, sizeof check);
        FOR(i,1,n)
            cin >> a[i];
        int ans = 0;

        FOR(i,1,n)
        {
            FOR(j,1,i-1)check[a[j] + (N-5)] = 0;
            FOR(j,1,i-1)
            {
                int k = a[i] - a[j] + (N-5);
                f[i][j] = 2;
                if( 0 <= k&& k <= 2 * N && check[k] ){
                    maximize(f[i][j], f[j][check[k]] + 1);
                    //cout << i << " " << j << " " << k<< endl;
                }
                check[a[j] + (N-5)] = j;
                //cout << a[j] + (N-5) << " "<<check[a[j] + (N-5)] << endl;;
                maximize(ans,f[i][j]);
            }
        }
        cout << ans << endl;;
    }

}
