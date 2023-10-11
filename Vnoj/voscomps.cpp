// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "tp"
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

const int N = 1e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

struct DSU
{
    vector<int>par;
    stack<ii>Back;
    void init(int n)
    {
        par.assign(n + 1, -1);
    }
    int root(int u){
        return (par[u] < 0 ? u : root(par[u]));
    }
    void join(int u, int v)
    {
        if((u = root(u)) == (v = root(v)))
            return;
        if(par[u] > par[v])swap(u ,v);
         Back.push(ii(u, par[u]));
        Back.push(ii(v, par[v]));
        par[u] += par[v];
        par[v] = u;
    }
    int getSize(int u)
    {
        return -par[root(u)];
    }
    int getST()
    {
        return SZ(Back);
    }
    void rollback(int op)
    {
        while(Back.size() > op)
        {
            ii x = Back.top();
            par[x.fi] = x.se;
            Back.pop();
        }
    }
}tree;
struct Data
{
    int type, u, v;
};
Data Q[N];
int q, R[N], L[N], cnt = 0, ans[N], n;
map<ii, int>d;
stack<int>Next[N];
void preCal()
{
    FD(i,q,1)
    {
        int t = Q[i].type, u = Q[i].u, v = Q[i].v;
        if(t == 2)
        {
            if(!d.count(ii(u, v)))d[ii(u, v)] = ++cnt;
            int id = d[ii(u, v)];
            Next[id].push(i);
            L[i] = q + 1;
        }
        if(t == 1)
        {
            if(!d.count(ii(u, v)))d[ii(u, v)] = ++cnt;
            int id = d[ii(u ,v)];
            if(Next[id].empty())R[i] = q + 1;
            else{
                R[i] = Next[id].top();
                L[Next[id].top()] = i;
                Next[id].pop();
            }
        }
    }
}
void solve(int l, int r)
{
    if(l == r)
    {
        if(Q[l].type == 3)
            ans[l] = (tree.root(Q[l].u) == tree.root(Q[l].v));
        return;
    }
    int mid = (l+r) >> 1;
    int pre = tree.getST();
    FOR(i,mid + 1, r)
        if(Q[i].type == 2 && L[i] < l)
                tree.join(Q[i].u, Q[i].v);
    solve(l, mid);
    tree.rollback(pre);
    FOR(i,l, mid)
        if(Q[i].type == 1 && R[i] > r)
                tree.join(Q[i].u, Q[i].v);
    solve(mid + 1, r);
    tree.rollback(pre);
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
        cin >> n >> q;
        FOR(i,1,q)
        {
            cin >> Q[i].type >> Q[i].u >> Q[i].v;
            if(Q[i].u > Q[i].v)swap(Q[i].u, Q[i].v);
        }
        tree.init(n + 5);
        preCal();
        solve(1,q);
        FOR(i,1,q)
            if(Q[i].type == 3)cout << ans[i];
    }

}

