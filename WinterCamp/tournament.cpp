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
const ll INF =1e9+9;
//const ll base = 311;
//const int BLOCK = 488;

struct Data
{
    int pos, id;
    bool close;
    Data(int _pos = 0, int _id = 0, bool _close = 0)
    {
        pos = _pos;
        id = _id;
        close = _close;
    }
    bool operator < (const Data &other)const
    {
        if(pos == other.pos)return close < other.close;
        else return pos < other.pos;
    }
};
vector<Data>vec;
int n, m, type, st[4 * N],ans[N];
void upd(int pos, bool type, int id = 1, int l = 1, int r = n)
{
    if(l == r)
    {
        if(type)st[id] = l;
        else st[id] = INF;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, type, id << 1, l, mid);
    else upd(pos, type, id << 1|1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1|1]);
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
        cin >> type;
        cin >> n >> m;
        memset(st,0x3f,sizeof st);
        FOR(i,1,m)
        {
            register int l, r, w;
            cin >> l >> r >> w;
            if(w-1 >= l)
            {
                vec.pb(Data(l,i,1));
                vec.pb(Data(w,i,0));
            }
            if(w+1 <= r)
            {
                vec.pb(Data(w + 1,i,1));
                vec.pb(Data(r+1,i,0));
            }
            ans[i] = w;
        }
        sort(all(vec));
        int Sz = vec.size() - 1, j = 0;
        FOR(i,1,n)
        {
            while(j <= Sz && vec[j].pos <= i){
                upd(vec[j].id,vec[j].close);
                j++;
            }
            if(st[1] > n)cout << 0 << " " ;
           else  cout << ans[st[1]] << " ";
        }
    }

}

