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

const int N = 1e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, h[N], q, L[N], R[N], id[N], Le[N], Ri[N], Mid[N], ind[N], W[N], queries[N], ans[N];
struct node{
    int le, ri, mx, len;
}st[4*N];
node Merge(node a, node b)
{
    node c = {0,0,0,0};
    c.len = a.len + b.len;
    c.ri = b.ri;
    if(b.ri == b.len && b.len)c.ri += a.ri;
    c.le = a.le;
    if(a.le == a.len && b.len)c.le += b.le;
    c.mx = max({a.mx,b.mx,a.ri + b.le});
    return c;
}
void build(int id = 1, int l = 1, int r = n)
{
    if(l == r){
        st[id] = {0,0,0,1};
        return;
    }
    int mid= (l+r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    st[id] = Merge(st[id << 1], st[id << 1|1]);
}
void upd(int pos,int id = 1, int l = 1, int r = n)
{
    if(l == r)
    {
        st[id] = {1,1,1,1};
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, id << 1, l, mid);
    else upd(pos, id << 1|1, mid + 1, r);
    st[id] = Merge(st[id << 1], st[id << 1|1]);
}
node getmax(int u, int v, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || u > v || l > r)return {0,0,0,0};
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return Merge(getmax(u, v, id << 1, l, mid), getmax(u, v, id << 1|1, mid + 1, r));
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
            cin >> h[i];
            ind[i] = i;
        }
        sort(ind + 1, ind + 1 + n, [](const int &u, const int &v){
             return h[u] > h[v];});
        cin >> q;
        FOR(i,1,q){
            cin >> L[i] >> R[i] >> W[i];
            Le[i] = 1;
            Ri[i] = n;
        }
        FOR(pp,0,19)
        {
            int i = 1, j = 1, s = 0;
            build();
            FOR(i,1,q){
                if(Le[i] <= Ri[i]){
                    Mid[i] = (Le[i] + Ri[i]) >> 1;
                    queries[++s] = i;
                }
            }
            sort(queries + 1, queries + 1 + s, [](const int &u, const int &v){
                return h[ind[Mid[u]]] > h[ind[Mid[v]]]; });
            FOR(i,1,n)
            {
                int pts = i;
                while(pts+1 <= n && h[ind[i]] == h[ind[pts+1]]){
                    pts++;
                }
                FOR(o,i,pts)upd(ind[o]);
                i = pts;
                while(j <= s && h[ind[Mid[queries[j]]]] > h[ind[i]])j++;
                while(j <= s && h[ind[Mid[queries[j]]]] == h[ind[i]]){
                    node check = getmax(L[queries[j]], R[queries[j]]);
                    if(check.mx >= W[queries[j]]){
                        ans[queries[j]] = Mid[queries[j]];
                        Ri[queries[j]] = Mid[queries[j]] - 1;
                    }
                    else
                        Le[queries[j]] = Mid[queries[j]] + 1;
                    j++;
                }
            }
        }
        FOR(i,1,q)cout << h[ind[ans[i]]] << endl;
    }

}
