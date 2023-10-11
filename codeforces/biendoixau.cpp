// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define endl '\n'
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
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 1000;
int n,a[N],lazy[4*N][27],l,r,q;
char oldval,newval;
string s;
void down(int id)
{
    bool te = false;
    FOR(i,0,25)
    {
        if(lazy[id][i] != i)te = true;
        lazy[id << 1][i] = lazy[id][ lazy[id << 1][i] ];
        lazy[id << 1|1][i] = lazy[id][ lazy[id << 1|1][i] ];
    }
    if(te)FOR(i,0,25)lazy[id][i] = i;
    return;
}
void upd(int u, int v, int x, int y, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || l > r)return;
    if(l >= u && r <= v)
    {
        FOR(i,0,25)if(lazy[id][i] == x)lazy[id][i] = y;
        return;
    }
    down(id);
    int mid = (l+r) >> 1;
    if(l <= v && mid >= u)upd(u, v, x, y, id << 1, l, mid);
    if(mid +1 <= v && r >= u)upd(u, v, x, y, id << 1|1, mid+1, r);
}
void get(int id = 1, int l = 1, int r = n)
{
    if(l == r)
    {
        a[l] = lazy[id][a[l]];
        return;
    }
    down(id);
    int mid = (l+r) >> 1;
    get(id << 1, l, mid);
    get(id << 1|1, mid+1, r);
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
    cin >> s;
    n = SZ(s);
    s= ' '+s;
    FOR(i,1,n)a[i] = int(s[i] - 'a');
    FOR(i,1,4*n)
    {
        FOR(j,0,25)lazy[i][j] = j;
    }
    //cout << int('z'-'a');
    cin >> q;
    while(q--)
    {
        cin >> l >> r >> oldval >> newval;
        l++;
        r++;
        upd(l, r, int(oldval-'a'), int(newval-'a'));
    }
    get();
    FOR(i,1,n)cout << char(a[i] + 'a');
}

