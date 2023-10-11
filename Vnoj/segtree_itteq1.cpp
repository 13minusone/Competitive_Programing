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

const int N = 3e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int st[4 * N], maxx[4 * N], minn[4*N],lzsum[4 * N],lzst[4*N], c[N], n, m;
string s;
ll sum[4*N];
// IT for 1010
void pushst(const int &id)
{
    if(lzst[id] == -1)
        return;
    int &t = lzst[id];
    lzst[id << 1] = lzst[id << 1|1] = st[id << 1|1] = st[id << 1] = t;
    t = -1;
}
void updst(const int &u,const int &v,const int &val, int id = 1 ,int l = 1, int r = n)
{
    if(l > v || r < u || u > v || l > r)return;
    if(l >= u && r <= v)
    {
        st[id]  = lzst[id] = val;
        return;
    }
    pushst(id);
    int mid = (l+r) >> 1;
    updst(u, v, val, id << 1, l ,mid);
    updst(u, v, val, id << 1|1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1|1]);
}
int findl(const int &pos, int id = 1, int l = 1, int r = n)
{
    if(l > pos || l > r || r < 1)return n+1;
    if(l >= 1 && r <= pos)
    {
        if(st[id] >= 1)return l;
        int mid, ans = n+1;
        while(l <= r)
        {
            if(l == r)return (st[id] >= 1 ? l : ans);
            pushst(id);
            mid = (l+r) >> 1;
            if(st[id << 1|1] >= 1)
            {
                id = id  << 1;
                r = mid;
                ans = mid+1;
            }
            else{
                l = mid + 1;
                id = id << 1 | 1;
            }
        }
        return ans;
    }
    pushst(id);
    int mid = (l+r) >> 1;
    if(pos <= mid)return findl(pos,id << 1, l, mid);
    int res = findl(pos, id << 1|1, mid + 1, r);
    if(res == mid + 1)minimize(res, findl(pos, id << 1, l, mid));
    return res;
}
int findr(const int &pos, int id = 1, int l = 1, int r = n)
{
    if(r < pos || l > r || r < 1)return 0;
    if(l >= pos && r <= n){
        if(st[id] >= 1)return r;
        int mid, ans = 0;
        while(l <= r)
        {
            if(l == r)return (st[id] >= 1 ? l : ans);
            pushst(id);
            mid = (l+r) >> 1;
            if(st[id << 1] >= 1){
                id = id  << 1|1;
                l = mid + 1;
                ans = mid;
            }
            else{
                r = mid ;
                id = id << 1;
            }
        }
        return ans;
    }
    pushst(id);
    int mid = (l+r) >> 1;
    int res = 0;
    if(pos > mid) return findr(pos, id << 1|1, mid + 1, r);
    res = findr(pos, id << 1, l, mid);
    if(res == mid)maximize(res, findr(pos, id << 1|1, mid + 1, r));
    return res;
}
//end IT FOR 1010
// start IT FOR C[i] = r which is used to have i to r is full of 1
void pushC(const int &id, const int &l, const int& r)
{
    if(lzsum[id] == 0)return;
    int &t = lzsum[id];
    int mid = (l+r) >> 1;
    maxx[id << 1] = maxx[id << 1|1] = minn[id << 1|1] = minn[id << 1] = lzsum[id << 1] = lzsum[id << 1|1] =  t;
    sum[id << 1] = 1LL *(mid -l + 1) * t;
    sum[id << 1|1] = 1LL *(r - mid) * t;
    t = 0;
    return;
}
void build(int id = 1, int l = 1, int r = n)
{
    if(l == r)
    {
        sum[id] = maxx[id] = minn[id] = c[l];
        return;
    }
    int mid= (l+r) >>1;
    build(id << 1, l, mid);
    build(id << 1|1, mid+1, r);
    maxx[id] = max(maxx[id << 1], maxx[id << 1|1]);
    minn[id] = min(minn[id << 1], minn[id << 1|1]);
    sum[id] = sum[id << 1] + sum[id << 1|1];
}
void updC(const int u, const int v, const int val, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || minn[id] >= val)return;
    if(l >= u && r <= v && maxx[id] <= val)
    {
        maxx[id] = minn[id] = lzsum[id] = val;
        sum[id] = 1LL * (r- l + 1) * val;
        //cout << l << " " << r <<" " <<  sum[id] <<endl;
        return;
    }
    pushC(id, l, r);
    int mid = (l+r) >>1;
    updC(u, v, val, id << 1, l, mid);
    updC(u, v, val, id << 1|1, mid + 1, r);
    maxx[id] = max(maxx[id << 1], maxx[id << 1|1]);
    minn[id] = min(minn[id << 1], minn[id << 1|1]);
    sum[id] = sum[id << 1] + sum[id << 1|1];

    return;
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
        cin >> n >> m;
        cin >> s;
        s= " " + s;
        ll sub = (1LL *n * (n-1))/2;
        memset(lzst, -1,sizeof lzst);
        //memset(minn,0x3f,sizeof minn);
        FOR(i,1,n)updst(i,i,int(s[i]-'0'));
        FOR(i,1,n){
            c[i] = i-1;
            if(s[i] == '1')c[i] = findr(i);
            //cout << c[i] << " " ;
        }
        build();
        cout <<  sum[1] - sub << endl;
        while(m--)
        {
            register int l, r, val;
            cin >> l >> r >> val;
            updst(l, r, val);
            if(val == 1)
            {
                int L = findl(l);
                int R = findr(r);
                updC(L,R,R);
               // cout << L << " " << R<< endl;
            }
            cout << sum[1]-sub << endl;
        }
    }

}
