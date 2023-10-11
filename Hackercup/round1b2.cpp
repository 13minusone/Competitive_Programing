// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "round1b2"
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

const int N = 3e3 + 5;
const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;

int n, x, y, q;
int cntx, cnty, sqy, sqx;
int sq(int val)
{
    return (1LL * val * val %MOD);
}
int costx(int x)
{
    int p = (1LL * n *sq(x)%MOD- (2LL *x * cntx%MOD) + sqx + MOD )%MOD;
    return p;
}
int costy(int y)
{
    int p = (1LL * n *sq(y)%MOD- (2LL *y * cnty%MOD) + sqy + MOD )%MOD;
    return p;
}
void add(int &a, int b){
    a += b;
    if(a >= MOD)a-=MOD;
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
    cin >> t;
    FOR(Test, 1, t)
    {
        cin >> n;
        cntx = cnty = sqx = sqy = 0;
        FOR(i,1,n){
            cin >> x >> y;
            add(cntx, x);
            add(cnty, y);
            add(sqx, sq(x));
            add(sqy, sq(y));
        }
        cin >> q;
       int s = 0;
        while(q--){
            cin >> x >> y;
            add(s, costx(x));
            add(s, costy(y));
        }
        cout << "Case #" << Test<< ": " << s;
        if(Test != t)cout << endl;
    }

}


