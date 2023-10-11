// Onegai no bug
// Author : Nyanpasuuuuu
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
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

const int N = (1 << 20);
const ll mod =1e9+7;
//const ll base = 311;
//const int bl = 488;

int n, f[N],x,powe[N];
void add(int &a, const int &b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub(int &a, const int &b)
{
    a -= b;
    if (a < 0)
        a += mod;
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
    cin >> n;
    powe[0] = 1;
    FOR(i,1,n)
    {
        cin >>x;
        f[x]++;
    }
    FOR(i,1,N-1)
       powe[i]= (1LL * powe[i-1]*2)%mod;
    FOR(i,0,19)
        FOR(j,0,(1<<20)-1)
            if(getbit(j,i))
                f[j ^ (1 << i)] += f[j];
    int ans = 0;
    FOR(i,0,(1<<20)-1)
    {
        //cout << f[i] << endl;
        if(__builtin_popcount(i)&1)sub(ans, powe[f[i]] - 1);
        else add(ans, powe[f[i]] - 1);
        //if(i <= 10)cout << ans << endl;
    }
    cout << ans;
}
