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

const int N = 2e5 + 5;
const int INF =1e9+9;
//const ll base = 311;
//const int BLOCK = 488;

struct Data{
    int l, r, w, id;
    Data(int _l = 0, int _r = 0 ,int _w = 0, int _id = 0)
    {
        l = _l;
        r = _r;
        w = _w;
        id = _id;
    }
    bool operator < (const Data &other)const{
        return w > other.w;
    }
};
vector<Data>query;
ll bit[N + 10],res[N];
int n, a[N], dp[N][20], LOG = 19, q, maxx = 0,f[N];
int getGCD(int l, int r)
{
    if(l > r || r == n + 1)return INF;
    int k = log2(r - l + 1);
    return __gcd(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int findd(int id, int w)
{
    int l = id, r = n,ans = n + 1;
    while(l <= r)
    {
        int mid = (l+r) >> 1;
        if(getGCD(id, mid) <= w)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}
void upd(int x, int val)
{
    if(x <= 0)return;
    for(;x <= n; x += (x &(-x)))
        bit[x] += val;
    return;
}
ll get(int x)
{
    if(x == 0)return 0;
    ll s = 0;
    for(;x > 0; x -= (x & (-x)))
        s += bit[x];
    return s;
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
        cin >> n >> q;
        FOR(i,1,n){
            cin >> a[i];
            dp[i][0] = a[i];
        }
        FOR(j,1,LOG)
            FOR(i,1,n - (1 << j) + 1)
                dp[i][j] = __gcd(dp[i][j-1], dp[i + (1 << (j - 1))][j - 1]);
        FOR(i,1,q)
        {
            register int l, r, w;
            cin >> l >> r >> w;
            query.pb(Data(l, r, w, i));
            maximize(maxx,w);
        }
        sort(all(query));
        priority_queue<ii>qu;
        FOR(i,1,n){
            f[i] = findd(i,maxx);
            upd(i,f[i]);
            qu.push(ii(getGCD(i,f[i]), i));
            //cout << i << " " <<getGCD(i,f[i]) << endl;
        }
        for(Data i : query)
        {
            //cout << qu.top().fi << endl;
            while(!qu.empty())
            {
                ii x = qu.top();
                if(x.fi <= i.w)break;
                qu.pop();
                if(f[x.se] == n + 1)continue;
                int z = f[x.se];
                f[x.se] = findd(x.se,i.w);
                upd(x.se, f[x.se] - z);
                qu.push(ii(getGCD(x.se,f[x.se]), x.se));
                //cout << x.se << " " << getGCD(x.se,f[x.se]) << endl;
            }
            int L = i.l, R = i.r, ans = i.l-1;
//            cout << i.w << endl;
//            FOR(j,1,n)
//                cout << j << " " << f[j] << endl;
            while(L <= R)
            {
                int mid = (L + R) >> 1;
                if(f[mid] <= i.r)
                {
                    ans = mid;
                    L = mid + 1;
                }
                else R = mid - 1;
            }
          //  cout <<i.id <<  " " <<  ans << endl;
            res[i.id] = 1LL * (ans - i.l + 1) * (i.r+1) - (get(ans) - get(i.l - 1));
        }
        FOR(i,1,q)
            cout << res[i] << endl;
    }

}

