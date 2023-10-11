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
typedef pair<ll,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
/*
    pre[i] - pre[j] <= x
    l[i] = j; the most min position that pre[i] - pre[j - 1] <= x
*/
int n, x, a[N], l[N], r[N];
ll pre[N], sum[N];
void init(void)
{
    cin >> n >> x;
    FOR(i,1,n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        sum[i] = sum[i - 1] + pre[i];
    }
    FOR(i,n + 1, 2 * n - 1)
    {
        a[i] = a[i - n];
        pre[i] = pre[i - 1] + a[i];
        sum[i] = sum[i - 1] + pre[i];
    }
}
void process(void)
{
    int id = 1;
    FOR(i,1,2 * n-1)
    {
        while(id <= i && pre[i] - pre[id - 1] > x)
            id++;
        l[i] = id;
    }
    id = 2 * n - 1;
    FD(i,2 * n - 1, 1)
    {
        while(id >= i && pre[id] - pre[i - 1] > x)
            id--;
        r[i] = id;
        //cout << i << " " << r[i] << endl;
    }
    if(n <= 10000){
        FOR(i,n,2 * n-1)
        {
            ii best = ii(0,0);
            FOR(j,i - n + 1, i)
            {
            maximize(l[j], i - n + 1);
            if(j < l[j])continue;
            int Num = j - l[j] + 1;
            best.fi += (1LL * pre[j] * Num - sum[j - 1] + sum[max(0,l[j] - 2)]);
            best.se += Num;
            //cout << i << " " << j << " " << l[j] << endl;
            }
            cout << best.fi << " " << best.se << endl;
        }
    }
    else{
            ii best = ii(0,0);
            FOR(j,1, n)
            {
                if(j >= l[j]){
                int Num = j - l[j] + 1;
                best.fi += (1LL * pre[j] * Num - sum[j - 1] + sum[max(0,l[j] - 2)]);
                best.se += Num;
                }
            }
            cout << best.fi << " " << best.se << endl;
            int Num = r[1];
            best.fi -= (sum[r[1]] - Num * pre[0]);
            best.se -= Num;
            FOR(i,n + 1, 2 * n - 1)
            {
                //cout << best.fi << " " << best.se << endl;
                maximize(l[i], i - n + 1);
                if(l[i] <= i){
                    int Num = i - l[i] + 1;
                    best.fi += (1LL * pre[i] * Num - sum[i - 1] + sum[max(0,l[i] - 2)]);
                    best.se += Num;
                }
                cout << best.fi << " " << best.se << endl;
                int le = i - n + 1;
                if(r[le] < le)continue;
                Num = r[le] - le + 1;
                best.fi -= (sum[r[le]] - Num * pre[le - 1] - sum[le - 1]);
                best.se -= Num;
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


