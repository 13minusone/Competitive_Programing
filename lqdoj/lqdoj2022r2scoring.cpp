// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "scoring"
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

const int N = 1e5 + 5;
const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;

void add(int &a, int b)
{
    a += b;
    while(a >= MOD)
        a-=MOD;
}
vector<ii>edge;
int w[N], s = 0, a[N], n, k;
bool check()
{
    for(ii x : edge)
    {
        if(w[x.fi] < w[x.se])swap(x.fi, x.se);
        if(a[x.fi] < a[x.se])return 0;
    }
    return 1;
}
void backtrack(int num, int o)
{
    if(num == n + 1)
    {
        if(check())add(s,1);
        return;
    }
    FOR(i,1,n)
    {
        FOR(j,o,k)
        {
            if(!a[i])
            {
                a[i] = j;
                backtrack(num + 1,j + 1);
                a[i] = 0;
            }
        }
    }
    return;
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
        cin >> n >> k;
        if(n > k){
            cout << 0;
            return 0 ;
        }
        FOR(i,1,n-1)
        {
            register int x, y;
            cin >> x >> y;
            edge.pb(ii(x,y));
        }
        FOR(i,1,n){
            cin >> w[i];
        }
        backtrack(1,1);
        cout << s ;
    }

}
