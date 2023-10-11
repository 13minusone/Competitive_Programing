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

const int N = 2e5 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, k, a[N];
ll pre[N], dp[N];
struct Data{
    int l, r, p;
};
void init(void)
{
    cin >> n >> k;
    FOR(i,1,n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
}
ll W(int x, int y)
{
    int t = (y - x)/2;
    return -pre[x + t] + pre[x] + pre[y] - pre[y - t];
}
void process(void)
{
    deque<Data>dq;
    dq.push_back({1,n,0});
    FOR(i,1,n)
    {
        Data &x = dq.front();
        dp[i] = k + dp[x.p] + W(x.p, i);
       // cout << x.l << " " << x.r <<" " << x.p << endl;
        x.l++;
        if(x.l > x.r){
            dq.pop_front();
        }
        while(!dq.empty())
        {
            auto [l, r, p] = dq.back();
            if(dp[i] + W(i,l) < dp[p] + W(p,l))dq.pop_back();
            else break;
        }
        if(dq.empty())
            dq.push_back({i + 1, n, i});
        else{
            auto &[l, r, p] = dq.back();
            int low = l, high = r, pos = r + 1;
            while(low <= high)
            {
                int mid = (low + high) >> 1;
                if(dp[i] + W(i, mid) < dp[p] + W(p, mid))
                {
                    pos = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            r = pos - 1;
            if(pos <= n)dq.push_back({pos, n, i});
        }
    }
    cout << dp[n];
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


