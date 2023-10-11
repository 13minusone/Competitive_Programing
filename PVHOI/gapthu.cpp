// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "gapthu"
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

const int N = 1e5 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 4e18 + 7;
const ll oo = 4e19 + 7;
int n, m, q, Maxr = 0, l[N], r[N], k;
ll SumBear = 0, lo, ro, ans, mid;
 long long u, o,s[N], pre[N], p[N], sum[N];
vector<ii>Total;
void init(void)
{
    cin >> n >> m >> q;
    FOR(i,1,n)
    {
        cin >> s[i];
        //cout << s[i] << endl;

    }
    FOR(i,0,n)
    {
        cin >> p[i];
    }
    FOR(i,1,n)
    {
        ll x = (s[i] - 1 - sum[i - 1]) / p[i - 1];
        x++;
        pre[i] = pre[i - 1] + x;
        if(sum[i - 1] > INF -  1LL * x * (p[i - 1])) sum[i] = oo;
        else sum[i] = sum[i - 1] +  1LL * x * (p[i - 1]);
        //cout << pre[i] << " "<< sum[i] << endl;
    }
    FOR(i,1,m)
    {
        cin >> l[i] >> r[i];
        maximize(Maxr, r[i]);
        SumBear += (r[i] - l[i] + 1);
    }
    Total.resize(Maxr + 1);
    FOR(i,1,m)
    {
        Total[l[i]].fi++;
        if(r[i] + 1 <= 10000000)Total[r[i] + 1].fi--;
    }
    ll cnt = 0;
    FOR(i,1,Maxr)
    {
        cnt+= (Total[i].fi);
        Total[i].fi = Total[i - 1].fi + cnt;
        Total[i].se = Total[i - 1].se + 1LL * cnt * i;
           // cout << Total[i].fi << " " << Total[i].se << endl;
    }
}
void process(void)
{
    FOR(i,1,q){
        register ll t;
            cin >> t;
            lo = 1, ro = SumBear, ans = -1;
            while(lo <= ro)
            {
                mid = (lo+ro) >> 1;
                k = lower_bound(all(Total),ii(mid,0)) - Total.begin();
                if(k == Maxr + 1 || Total[k].fi != mid)k--;
                u = Total[k].se;
                u += 1LL * (k + 1) * (mid - Total[k].fi);
                k = lower_bound(pre + 1, pre + 1 + n,mid) - pre;
                if(k == n + 1 || pre[k] != mid)k--;
                bool ok = false;
                o = sum[k];
               // cout << ok << endl;
                if(o > INF -  1LL *(mid - pre[k]) * p[k]) ok = true;
                else o += 1LL *(mid - pre[k]) * p[k];
                if(!ok && u - t >= o ){
                    ans = mid;
                    ro = mid - 1;
                }
                else lo = mid + 1;
               // cout << mid << " "<< ok<< " " << u- t << " " << o << endl;
                //break;
            }
            cout << ans << " " ;
           //cout << endl;

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
