// Author : Nyanpasuuuuu
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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e6 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, m, c[N], x[45], f[N];
bool d[45];
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n)
        cin >> c[i];
    FOR(i,1,m)
        cin >> x[i];
}
vector<ii>edge;
void process(void)
{
    edge.pb(ii(c[1], c[1]));
    edge.pb(ii(c[n], c[n]));
    FOR(i,3,n){
        edge.pb(ii(c[i], c[i - 1]));
       //edge.pb(ii(c[i], c[i - 2]));
    }
    for(ii &v : edge)
        if(v.fi > v.se)swap(v.fi, v.se);
    sort(all(edge));
    edge.resize(unique(all(edge)) - edge.begin());
    int mid = m/2, res = INF;
    FOR(i,0,(1 << mid) - 1)
    {
        memset(d,0,sizeof d);
        int val = 0;
        FOR(j,1,mid)
            if(getbit(i, j - 1)){
                val += x[j];
                d[j] = 1;
            }
        bool ok = true, ok1 = true;
        for(const ii v : edge)
        {
            if(!d[v.fi] && !d[v.se])
            {
                ok = false;
                if(v.se <= mid){
                    ok1 = false;
                    break;
                }
            }
        }
        if(ok)minimize(res, val);
        f[i] = (ok1 ? val : INF);
    }
    FOR(i,0,mid-1)
        FOR(j,0,(1 << mid) - 1)
        if(getbit(j,i))minimize(f[j ^ (1 << i)],f[j]);
    int mid1 = m - mid;
    FOR(i,0,(1 << mid1) - 1)
    {
        memset(d,0,sizeof d);
        int val = 0;
        FOR(j,1,mid1)
            if(getbit(i, j - 1)){
                val += x[j + mid];
                d[j + mid] = 1;
            }
        bool ok = true, ok1 = true;
        for(const ii v : edge)
        {
            if(!d[v.fi] && !d[v.se])
            {
                ok = false;
                if(v.fi > mid){
                    ok1 = false;
                    break;
                }
            }
        }
        if(ok)minimize(res, val);
        if(!ok1)continue;
        int mask = 0;
        if(c[1] <= mid)mask |= (1 << (c[1] - 1));
        for(const ii v : edge)
        {
            if(v.se <= mid || v.fi > mid)continue;
            if(!d[v.se]){
                mask |= (1 << (v.fi - 1));
//                if(i == 17)
//                    cout << v.fi << endl;
            }
        }
        minimize(res, val + f[mask]);
        //if(i == 17)cout << i <<" " << f[mask] << " " <<res  << endl;

    }
    cout << res;
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
        init();
        process();
    }

}
