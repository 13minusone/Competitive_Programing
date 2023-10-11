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
typedef pair<ll,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e19 + 7;
char p,q;
ii st[4 * N], pre[N], suf[N];
ll ans = 0;
int k, n, maxx = 0;
vector<ii>vec;
vector<ll>val;
ii Merge(ii a, ii b)
{
    return ii(a.fi + b.fi, a.se + b.se);
}
void upd(int pos, ii val, int id = 1, int l = 1, int r = maxx)
{
    if(l == r)
    {
        st[id].fi += val.fi;
        st[id].se += val.se;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, val, id << 1, l, mid);
    else upd(pos, val, id << 1|1, mid + 1, r);
    st[id] = Merge(st[id <<  1], st[id << 1|1]);
    return;
}
ii getSum(int u, int v, int id = 1, int l = 1, int r = maxx)
{
    if(l > v || r < u || l > r || u > v)return ii(0, 0);
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return Merge(getSum(u ,v, id << 1, l, mid), getSum(u, v, id << 1|1, mid + 1, r));
}
int s[N], t[N];
void init(void)
{
    cin >> k >> n;
    FOR(i,1,n)
    {
        cin >> p >> s[i] >> q >> t[i];
        s[i]++;
        t[i]++;
        if(s[i] > t[i])swap(s[i], t[i]);
        ans += abs(s[i] - t[i]);
        val.pb(s[i]);
        val.pb(t[i]);
        if(p != q){
            ans++;
            vec.pb(ii(min(s[i], t[i]), -i));
            vec.pb(ii(max(s[i], t[i]), i));
        }
        else t[i] = s[i] = -1;
    }
    sort(all(vec));
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    maxx = SZ(val);
    FOR(i,1,n)
    if(s[i] != -1)
    {
        int o = lower_bound(all(val), min(s[i], t[i])) - val.begin() + 1;
        upd(o,ii(min(s[i], t[i]), 1));
    }
}
void process(void)
{
    ll add = INF;
    if(k == 1)
    {
        int tmp = 0, sub = 0;
        if(!vec.empty()){
            FOR(i,0,2 * n - 1)
            {
                ii x = vec[i];
                if(x.fi != vec[i - 1].fi && i > 0)
                {
                    ii x1 = vec[i - 1];
                    int o = lower_bound(all(val), x1.fi) - val.begin() + 1;
                    upd(o,ii(1LL * x1.fi * (-sub), -sub));
                    ii Left = getSum(1,o - 1);
                    ii Right = getSum(o + 1,maxx);
                    minimize(add, 1LL * Left.se * x1.fi - Left.fi + Right.fi - 1LL * Right.se * x1.fi);
                    upd(o, ii(1LL * x1.fi * tmp, tmp));
                    tmp = 0;
                    sub = 0;
                }
                if(x.se == -1)
                    sub++;
                else
                    tmp++;
            }
        }
        else add = 0;
        cout << ans + add * 2LL << endl;
    }
    else if(n <= 100)
    {
        if(!vec.empty()){
        int tmp = 0, num = 0;
        FD(i,SZ(vec) - 1, 0)
        {
            if(i < SZ(vec) - 1)
                suf[i] = suf[i + 1];
            if(vec[i] != vec[i + 1] && i < SZ(vec) - 1)
            {
                suf[i].fi += 1LL * tmp * vec[i + 1].fi;
                suf[i].se += tmp;
                tmp = 0;
            }
            if(vec[i].se < 0)
                tmp++;
        }
        tmp = 0;
        FOR(i,0,SZ(vec) - 1)
        {
            if(i > 0)
                pre[i] = pre[i - 1];
            if(vec[i] != vec[i - 1] && i > 0)
            {
                pre[i].fi -= (1LL * tmp * vec[i - 1].fi);
                pre[i].se += tmp;
                tmp = 0;
                FOR(j,i-1,SZ(vec) - 1){
                if(vec[j].fi != vec[j + 1].fi){
                    ll pl = 0;
                    FOR(o,1,n)
                    {
                        if(s[o] > vec[i].fi && t[o] < vec[j].fi){
                            pl += min(s[o] - vec[i].fi, vec[j].fi - t[o]);
                        }
                    }
                    minimize(add, pl + 1LL * vec[i].fi * pre[i].se + pre[i].fi - 1LL * vec[j].fi * suf[j].se + suf[j].fi);
                   //cout << vec[i].fi << " " << vec[j].fi << " "<<add << " " << pl << endl;
                }
                }
            }
            if(vec[i].se > 0)
                tmp++;
        }
//        FOR(i,0,2 * n - 1)
//            cout << pre[i].fi << " " << pre[i].se << " " << suf[i].fi << " " << suf[i].se << endl;
        }else add = 0;
        cout <<ans + 2LL *  add << endl;
    }
    else cout << ans << endl;
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


