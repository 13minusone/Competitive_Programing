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
const int MOD =1e9+7;
const int base = 131;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int q, x, Hashd, Pow, n;
string s, d;
void init(void)
{
    cin >> q;
}
bool check(int x)
{
     if(Hashd == x)return 1;
        FOR(i,0,127)
            if((1LL * Hashd * base % MOD + i) % MOD == x)
                return 1;
    return 0;
}
void process(void)
{
    cin >> x;
    x = 0;
    while(q--)
    {
        cin >> s;
        if(s == "setPassword")
        {
            cin >> d;
            Hashd = 0;
            n = SZ(d);
            d = " " + d;
            FOR(i,1,n)
                Hashd = (1LL * Hashd * base % MOD + d[i]) % MOD;
            //cout << Hashd << endl;
        }
        else
        {
            cin >> x;
            if(check(x))cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
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
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


