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
int n, k, a[N], maxx = 0, cnt[N], l[N], r[N], pre[N], vis[N];
vector<int>vec;
void init(void)
{
    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> a[i];
        cnt[a[i]]++;
        maximize(maxx, a[i]);
    }
    stack<int>st;
    FOR(i,1,n)
    {
        while(!st.empty() && a[st.top()] < a[i])st.pop();
        if(st.empty())l[i] = 1;
        else l[i] = st.top() + 1;
        st.push(i);
    }
    while(!st.empty())st.pop();
    FD(i,n,1)
    {
        while(!st.empty() && a[st.top()] < a[i])st.pop();
        if(st.empty())r[i] = n;
        else r[i] = st.top() - 1;
        st.push(i);
    }
}
bool check(int x)
{
    int le = 1;
    memset(pre, 0, sizeof pre);
    FOR(i,1,n)
        if(a[i] % x == 0){
            if(l[i] - 1 <= le){
                pre[l[i]]++;
                pre[r[i] + 1]--;
                maximize(le, r[i]);
            }
        }
    FOR(i,1,n){
        pre[i] += pre[i - 1];
        if(pre[i] <= 0)return false;
    }
    return true;
}
void process(void)
{
    vec.pb(1);
    FOR(x,2,maxx)
    {
        if(vis[x] == -1)continue;
        if(vis[x] != -1)
        {
            for(ll j = 1LL * x * 2; j <= maxx; j += x)
                    cnt[x] += cnt[j];
            if(cnt[x] < k)
                 for(ll j = 1LL * x * x; j <= maxx; j += x)
                    vis[j] = -1;
            else vec.pb(x);
            //cout << x << " " << cnt[x] << endl;
        }
    }
    reverse(all(vec));
    for(int i : vec)
        if(check(i)){
        cout << i;
        return;
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

