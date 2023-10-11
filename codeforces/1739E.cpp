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
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, f[2][N];
bool a[2][N];
ii minn[2];
vector<ii>vec[2][N];
string up, down;
void init(void)
{
    cin >> n;
    cin >> up;
    cin >> down;
    up = " " + up;
    down = " " + down;
    FOR(i,1,n)
        a[0][i] = int(up[i] - '0');
    FOR(i,1,n)
        a[1][i] = int(down[i] - '0');
}
int dist(ii a, ii b)
{
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}
void process(void)
{
    minn[0] == ii(0, n + 1);
    minn[1] == ii(1, n + 1);
    FOR(j,1,n)
    {
        FOR(i,0,1){
            int op = a[i ^ 1][j];
            if(op){

            }
        }
    }
    cout << f[0][1];
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


