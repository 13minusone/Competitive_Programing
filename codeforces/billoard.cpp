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

const int N = 25;
const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int n, m, mask[N], masknow[N];
char c;
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
        FOR(j,0,m-1){
            cin >> c;
        if(c == 'X')mask[i] += (1 << j);
        }
    }
    int res = mod;
    FOR(i,0,(1<<m)-1)
    {
        int ans = i, cnt = 0;
        cnt += __builtin_popcount(ans);
        FOR(i,1,n)masknow[i] = mask[i];
        //cout << ans << " ";
        int leftt = (ans << 1)&((1<<m)-1);
        int rightt = (ans >> 1)&((1<<m)-1);
        masknow[1] ^= leftt;
        masknow[1] ^= rightt;
        masknow[1] ^= ans;
        masknow[2] ^= ans;
        ans = masknow[1];
        FOR(j,2,n)
        {
            //if(i == 0)cout << mask[j] << endl;
            cnt += __builtin_popcount(ans);
            leftt = (ans << 1)&((1 << m)-1);
            rightt = (ans >> 1)&((1 << m)-1);
            masknow[j] ^= ans;
            masknow[j] ^= leftt;
            masknow[j] ^= rightt;
            masknow[j+1] ^= ans;
            ans = masknow[j];
        }
        //cout << cnt << " " << masknow[n] << endl;
        if(!masknow[n])minimize(res, cnt);
    }
    if(res == mod)cout << "Damaged billboard." << endl;
    else cout << "You have to tap " << res << " tiles.";
}

