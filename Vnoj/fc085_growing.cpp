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

const int N = 1e3 + 5;
//const ll MOD =1e9+7;
//const int base = 311 ;// 131;
//const int block = 488;
int n, h[N], p[N], c[N], pos[N];
ll st[4  * N], lz[4 * N], lef[N], pre[N];
void down(int id)
{
    st[id << 1] += lz[id];
    st[id << 1|1] += lz[id];
    lz[id << 1] += lz[id];
    lz[id << 1|1] += lz[id];
    lz[id] = 0;
    return;
}
void updChange(int pos, ll val, int id = 1, int l = 0, int r = n)
{
    if(l > pos || r < pos)return;
    if(l == r){
        st[id] = val;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)updChange(pos, val, id << 1, l, mid);
    else updChange(pos, val, id << 1|1, mid + 1, r);
    st[id] = max(st[id << 1], st[id << 1|1]);
}
void upd(int u, int v, ll val, int id = 1, int l = 0, int r = n)
{
    if(l > v || r < u || l > r || u > v)return;
    if(l >= u && r <= v){
        st[id] += val;
        lz[id] += val;
        return;
    }
    down(id);
    int mid = (l+r) >> 1;
    upd(u, v, val, id << 1, l, mid);
    upd(u, v, val, id << 1|1, mid + 1, r);
    st[id] = max(st[id << 1], st[id << 1|1]);
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
        cin >> n;
        FOR(i,1,n){
            cin >> h[i] >> p[i] >> c[i];
            pos[i] = i;
        }
        memset(st,-0x3f, sizeof st);
        sort(pos + 1, pos + 1 + n, [&](int u, int v){
             return (h[u] == h[v] ? (u < v) : (h[u] < h[v]));});
        FOR(i, 1, n)
            pre[i] = pre[i - 1] + c[pos[i]];
        updChange(0,0);
        FOR(i,1,n)
        {
            //cout << h[pos[i]] << " " << c[pos[i]] << " " << p[pos[i]] << endl;
            lef[i] = st[1] + pre[i] + p[pos[i]];
            upd(0,i-1, c[pos[i]]);
            updChange(i,lef[i] - pre[i + 1]);
//            cout << lef[i] << " ";
        }
    }
}
