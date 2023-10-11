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
#define cnt4 first
#define cnt7 second
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
//const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;

int n, m;
ii st[4 * N];
int lz[4*N];
string s, query;
ii Merge(ii u, ii v)
{
    ii re;
    re=ii(u.cnt4 + v.cnt4,u.cnt7 + v.cnt7);
    return re;
}
ii swapp(ii u)
{
    ii v;
    v.cnt4 = u.cnt7;
    v.cnt7 = u.cnt4;
    return v;
}
void push_down(int id)
{
    int &t = lz[id];
    if(t&1)
    {
        st[id << 1] = swapp(st[id << 1]);
        st[id << 1|1] = swapp(st[id << 1|1]);
        lz[id <<1]+= t;
        lz[id <<1|1]+= t;
        lz[id << 1]%= 2;
        lz[id << 1|1]%= 2;
    }
    t = 0;
    return;
}
void build(int id = 1 , int l = 1, int r = n)
{
    if(l == r)
    {
        int cnt4 = 0, cnt7 = 0;
        if(s[l] == '<')cnt4++;
        else cnt7++;
        st[id] = ii(cnt4,cnt7);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid +1, r);
    st[id] = Merge(st[id << 1], st[id << 1|1]);
}
void upd(int u, int v, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || l > r)return;
    if(l >= u && r <= v){
        st[id] =swapp(st[id]);
        lz[id]++;
        lz[id]%=2;
        return;
    }
    int m = (l+r) >> 1;
    push_down(id);
    upd(u, v, id << 1, l, m);
    upd(u, v, id << 1|1, m+1, r);
    st[id] = Merge(st[id << 1], st[id << 1|1]);
}
ii get(int u, int v, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || l > r)return ii (0,0);
    if(l >= u && r <= v){
        return st[id];
    }
    int m = (l+r) >> 1;
    push_down(id);
    return Merge(get(u, v, id << 1, l, m),get(u, v, id << 1|1, m+1, r));
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
    cin >> n >> m;
    cin >> s;
    s= " " + s;
    build(1,1,n);
    while(m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if(type==1)upd(l,r-1);
        else
        {
            ii ans = get(min(l,r),max(l,r)-1);
            if(r > l)cout <<  ans.cnt4 << endl;
            else if(l > r)cout <<ans.cnt7<< endl;
            else cout << 0 << endl;
        }
    }
}

