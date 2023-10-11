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

const int N = 5e5 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, a[N], Next[N][3];
ll st[4 * N], lz[4 * N];
vector<int>pos[N];
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
}
void upd(int u, int v, int val, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || u > v || l > r)return;
    if(l >= u && r <= v){
        lz[id] += val;
        if(lz[id] > 0)st[id] = r - l + 1;
        else if(r != l) st[id] = st[id << 1] + st[id << 1|1];
        else st[id] = 0;
        return;
    }
    int mid = (l+r) >> 1;
    upd(u, v, val, id << 1, l, mid);
    upd(u, v, val, id << 1|1, mid + 1, r);
    if(lz[id] == 0)st[id] = st[id << 1] + st[id << 1|1];
    else st[id] = r - l + 1;
}
void process(void)
{
    Next[n + 1][1] = Next[n + 1][2] = n + 1;
    FOR(i,1,n){
        Next[i][1] = Next[i][2] = n + 1;
        pos[a[i]].pb(i);
        int sz = SZ(pos[a[i]]);
        if(sz >= 2)
            Next[pos[a[i]][sz-2]][1] = pos[a[i]][sz - 1];
        if(sz >= 3)
            Next[pos[a[i]][sz-3]][2] = pos[a[i]][sz - 1];
    }
    FOR(i,1,n)
        if(pos[a[i]][0] == i){
            upd(i,Next[i][2] - 1, 1);
            upd(Next[Next[i][2]][1],n, 1);
        }
    ll ans = 0;
    FOR(i,1,n)
    {
        ans += n - (i - 1) - st[1];
        upd(i,Next[i][2] - 1, -1);
        upd(Next[Next[i][2]][1],n, -1);
        int id = Next[i][1];
        upd(id,Next[id][2] - 1, 1);
        upd(Next[Next[id][2]][1],n, 1);
    }
    cout << ans;
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
