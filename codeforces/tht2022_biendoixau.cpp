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
int bl = 1000;
int n,a[N],l,r,q, num = 0, le[N*26], ri[N*26], cnt[N*26], rt[27];
char x, y;
void add(int &cur, int pos, int l = 1, int r = n)
{
    if(!cur) cur = ++num;
    if(l == r){
        cnt[cur] = 1;
        return;
    }
    int mid = (l+r) >>1;
    if(pos <= mid)add(le[cur], pos, l, mid);
    else add(ri[cur], pos, mid+1, r);
    cnt[cur] = cnt[le[cur]] + cnt[ri[cur]];
}
void upd(int &old, int &neww, int u, int v, int l = 1, int r = n)
{
    if(l > v || r < u || l > r)return;
    if(old == 0 || cnt[old] == 0)return;
    if(l >= u && r <= v && (!neww))
    {
        //cout << old << " " << neww << endl;
        neww = old;
        old= 0;
        return;
    }
    int mid = (l+r) >> 1;
    if(!neww)neww = ++num;
    upd(le[old], le[neww], u, v, l, mid);
    upd(ri[old], ri[neww], u, v, mid + 1, r);
    cnt[old] = cnt[le[old]] + cnt[ri[old]];
    cnt[neww] = cnt[le[neww]] + cnt[ri[neww]];
    //cout <<old << " " << neww << " " << cnt[old] << " " << cnt[neww] << endl;
    if(!cnt[old])old  = 0;
}
void query(int cur, int digit, int l = 1, int r = n)
{
    if(!cur || !cnt[cur])return;
    if(l == r){
        a[l] = digit;
        return;
    }
    int mid = (l+r) >> 1;
    query(le[cur],digit, l, mid);
    query(ri[cur],digit, mid + 1, r);
}
string s;
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
    FOR(i,1,n)
    {
        a[i] = s[i] - 'a';
        add(rt[a[i]],i);
        //cout << rt[a[i]] << endl;
    }
    cin >> q;
    while(q--)
    {
        //cout << q <<  endl;
        cin >> l >> r >> x >> y;
        //cout << rt[int(x - 'a')] << " " << rt[int(y - 'a')] << endl;
        upd( rt[int(x - 'a')], rt[int(y - 'a')],l+1, r+1);
    }
    FOR(i,0,26){
        //cout << rt[i] <<endl;
        query(rt[i], i);
    }
    FOR(i,1,n)cout << char(a[i] + 'a');
}
