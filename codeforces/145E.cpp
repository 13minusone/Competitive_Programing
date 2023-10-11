// Onegai no bug
// Author : nyanpasuuuuu
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
//const int block = 488;

struct node
{
    int maxup = 0, maxdown = 0, cnt4 = 0, cnt7 = 0;
    node(int _maxup = 0,int _maxdown = 0, int _cnt4 = 0, int _cnt7 = 0)
    {
        maxup = _maxup;
        maxdown = _maxdown;
        cnt4 = _cnt4;
        cnt7 = _cnt7;
    }
};
node st[4 * N];
int lz[4*N], n, m,res = 0;
string s, query;
node Merge(node u, node v)
{
    node re;
    re.cnt4 = u.cnt4 + v.cnt4;
    re.cnt7 = u.cnt7 + v.cnt7;
    re.maxup = max(u.maxup + v.cnt7, u.cnt4 + v.maxup);
    re.maxdown = max(u.maxdown + v.cnt4, u.cnt7 + v.maxdown);
    return re;
}
node swapp(node u)
{
    node v;
    v.cnt4 = u.cnt7;
    v.cnt7 = u.cnt4;
    v.maxdown = u.maxup;
    v.maxup = u.maxdown;
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
        if(l == 1)res = id;
        int cnt4 = 0, cnt7 = 0;
        if(s[l] == '4')cnt4++;
        else cnt7++;
        st[id] = node(1,1,cnt4,cnt7);
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
    s = " "+ s;
    build();
    //cout << st[8].cnt7 << " "<< st[8].cnt4 << endl;
    while(m--)
    {
        cin >> query;
        if(query == "count")cout << st[1].maxup << endl;
        else {
            int l, r;
            cin >> l >> r;
            upd(l,r);
            //cout << st[1].maxup << " "<< st[1].maxdown <<" "<< st[1].cnt4 << " "<< st[1].cnt7 << endl;
                //cout << st[8].cnt7 << " "<< st[8].cnt4 << endl;

        }
    }
}

