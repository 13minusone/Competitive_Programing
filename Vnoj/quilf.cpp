// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "quilf"
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
const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int a[N], minn[N][25], LOG = 20, res = MOD, n;
ll pre[N], sum = 0;
int getM(int l, int r)
{
    int k = log2(r - l + 1);
    return min(minn[l][k], minn[r - (1 << k) + 1][k]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        memset(minn,0x3f,sizeof minn);
        FOR(i,1,n){
            cin >> a[i];
            minn[i][0] = a[i];
            sum += a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        sum /= 2;
        FOR(j,1,LOG)
            FOR(i,1,n - (1 << j) + 1)
                minn[i][j] = min(minn[i][j-1], minn[i + (1 << (j - 1)) - 1][j - 1]);
        FOR(i,1,n)
        {
            int l = 1, r = i, ans = 0;
            while(l <= r)
            {
                int mid = (l+r) >> 1;
                if(pre[i] - pre[mid - 1] - getM(mid, i) >= sum){
                    l = mid + 1;
                     ans = mid;
                }
                else r = mid - 1;
            }
            if(ans != 0)minimize(res, i - ans);
            //cout << i << " " << ans << endl;
        }
        cout << res;


    }

}

