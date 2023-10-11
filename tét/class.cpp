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

const int N = 4e5 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, q, a[4], b[4], m[4], c[4];
ll Have[2 * N], pre[2 * N], ans[N], x[N], y[N], z[N], l[N], r[N], maxx = 0;
ii query[N];
vector<int>val;
void init(void)
{
    cin >> n >> q;
    cin >> x[1] >> x[2] >> a[1] >> b[1] >> c[1] >> m[1];
    cin >> y[1] >> y[2] >> a[2] >> b[2] >> c[2] >> m[2];
    cin >> z[1] >> z[2] >> a[3] >> b[3] >> c[3] >> m[3];
}
int Find(int k)
{
    int le = 0, ri = maxx, res = 0;
    while(le <= ri)
    {
        ll mid = (le + ri) >> 1, cnt = 0, bang = 0;
        FOR(i,1,n){
            if(l[i] >= (mid + 1))
                cnt += r[i] - l[i] + 1;
            else if(r[i] >= (mid + 1))
                cnt += r[i] - mid;
            if(l[i] <= mid && r[i] >= mid)bang++;
        }
        if(cnt < k && cnt + bang >= k){
            res = mid;
            break;
        }
        if(cnt + bang > k)le = mid + 1;
        else ri = mid - 1;
       // cout << mid << " " << cnt << " "<< bang << " " << res << endl;
    }
    return res;
}
bool cmp(ii u, ii v)
{
    if(u.fi != v.fi)return u.fi < v.fi;
    else return u.se > v.se;
}
vector<ii>vec;
void process(void)
{
    val.clear();
    vec.clear();
    maxx = 0;
    FOR(i,1,n){
        if(i >= 3){
            x[i] = (1LL * x[i - 1] * a[1] %m[1] + 1LL * x[i - 2] * b[1]%m[1] + c[1]) % m[1];
            y[i] = (1LL * y[i - 1] * a[2] %m[2] + 1LL * y[i - 2] * b[2]%m[2] + c[2]) % m[2];
        }
        l[i] = min(x[i], y[i]) + 1;
        r[i] = max(x[i], y[i]) + 1;
        vec.pb(ii(l[i],1));
        vec.pb(ii(r[i],0));
        vec.pb(ii(r[i] + 1,2));
        val.pb(l[i]);
        val.pb(r[i]);
        maximize(maxx, r[i]);
    }
    sort(all(vec), cmp);
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    ll cnt = 0;
    FOR(j,0,SZ(vec) - 1)
    {
        if(j > 0 && vec[j].fi != vec[j - 1].fi)
        {
            int o = j - 1;
            ii i = vec[j - 1];
            int k = lower_bound(all(val), i.fi) - val.begin() + 1;
            Have[k] = cnt;
        }
        ii i = vec[j];
        if(i.se == 2)cnt--;
        else cnt += i.se;

    }
    FD(i,SZ(val),1){
       // cout << val[i - 1] << " " << Have[i] << " ";
        ll add = 0, x = Have[i + 1];
        if(Have[i] == Have[i + 1] && val[i - 1] + 1 != val[i])x--;
        if(i < SZ(val))add = 1LL * x * (val[i] - val[i - 1] - 1);
        else add = 0;
        pre[i] = pre[i + 1] + add + Have[i];
       // cout << i << " " << pre[i] << endl;
    }
        FOR(i,1,q)
        {
            if(i >= 3)
                z[i] = (1LL * z[i - 1] * a[3]%m[3] + 1LL * z[i - 2] * b[3]%m[3] + c[3]) % m[3];
            query[i] = ii(z[i] + 1, i);
            ans[i] = 0;
        }
        sort(query + 1, query + 1 + q);
        int id = 1;
        pre[0] = pre[1];
        Have[0] = 0;
        FD(i,SZ(val), 0)
        {
          //cout << pre[i] - Have[i] << " " << query[id].fi << endl;
            while( id <= q && pre[i]  >= query[id].fi )
            {
                int j = i + 1;
                if(i != SZ(val)){
                    ll Dif = query[id].fi - pre[j];
                    int x = Have[j];
                    if(Have[j] == Have[j - 1]&& i != 0 && val[i] != val[i - 1] + 1 )x--;
                    int Sub = 0;
                    if(x != 0){
                    Sub = Dif / x;
                    if(Dif % x != 0)Sub++;
                    }
                    ans[query[id].se] = val[j - 1] - Sub;
                    //cout <<val[j - 1]<< " "<<  Sub <<" " << Dif << " "<< x << endl;
                }
                else{
                    ans[query[id].se] = val[i - 1];
                }
                id++;
            }
        }
        ll s  = 0;
        FOR(i,1,q){
           // cout <<z[i] + 1 << " " <<  ans[i] << endl;
            s += (1LL * ans[i] * i);
        }
        cout << s << endl;
        FOR(i,0,SZ(val))Have[i] = pre[i] = 0;
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
    cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


