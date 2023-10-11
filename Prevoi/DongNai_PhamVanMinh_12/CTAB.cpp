// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "CTAB"
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

const int N = 1e2 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, a[N][N], b[N][N], Col[N], Row[N], Needchange = 0, Num0[N];
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        FOR(j,1,n)
            cin >> a[i][j];
    FOR(i,1,n)
        FOR(j,1,n)
            cin >> b[i][j];
}
// change 1 row = multiple that row with -1
// change 1 col = multiple that col with -1
bool check()
{
    FOR(i,1,n)
        FOR(j,1,n)
            if((a[i][j] * Row[i] * Col[j]) != b[i][j])return false;
    return true;
}
bool Cal()
{
    FOR(i,1,n)Num0[i] = 0;
    FOR(i,1,n)
        FOR(j,1,n)
            if( (a[i][j] * Row[i]) != b[i][j])Col[j] += -1;
            else if(a[i][j] == 0)Num0[j]+= -1;
            else if(Col[j] < 0)return false;
    FOR(i,1,n)
        if(Col[i] == 0 || Col[i] + Num0[i] == -n )
            Needchange += (Col[i] < 0);
        else return false;
    return true;
}
void process(void)
{
    FOR(i,1,n)
        Row[i] = Col[i] = 1;
    FOR(i,1,n)
        FOR(j,1,n)
            if(a[i][j] != b[i][j])
                if(a[i][j] == 0 || b[i][j] == 0){
                    cout << -1;
                    return;
                }
    if(n <= 10){
        int ans = INF;
        FOR(i,0,(1 << (2 * n)) - 1)
        {
            int cnt = 0;
            FOR(j,1,n)Row[j] = Col[j] = 1;
            FOR(j,1,2 * n)
                if(getbit(i,j - 1)){
                    if(j <= n)
                        Col[j] *= (-1);
                    else
                        Row[j - n] *= (-1);
                    cnt++;
                }
            if(cnt > ans)continue;
            if(check())minimize(ans, cnt);
        }
        if(ans != INF)cout << ans;
        else cout << -1;
    }
    else{
        int ans = INF;
        FOR(i,0,(1 << n) - 1)
        {
            int cnt = 0;
            Needchange = 0;
            FOR(j,1,n)Row[j] = 1, Col[j] = 0;
            FOR(j,1,n)
                if(getbit(i,j - 1)){
                        Row[j] *= (-1);
                    cnt++;
                }
            if(cnt > ans)continue;
            if(Cal())minimize(ans, cnt + Needchange);
        }
        if(ans != INF)cout << ans;
        else cout << -1;
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


