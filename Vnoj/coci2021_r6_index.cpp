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

const int N = 2e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
const int BLOCK = 488;

struct Data
{
    int l, r, id;
    Data(int _l = 0, int _r = 0, int _id = 0)
    {
        l = _l;
        r = _r;
        id = _id;
    }
    bool operator <(const Data &other)const
    {
        if((l / BLOCK) != (other.l / BLOCK))return (l /BLOCK) < (other.l/ BLOCK);
        else return r < other.r;
    }
};
int n, a[N], q, BIT[N + 15], maxx = 0;
vector<Data>query;
void upd(int x, int val)
{
    if(x == 0)return;
    for(; x <= maxx; x += (x &(-x)))
        BIT[x] += val;
    return;
}
int get(int x)
{
    if(x == 0)return 0;
    int ans = 0;
    for(;x > 0; x -=(x &(-x)))
        ans += BIT[x];
    return ans;
}
int ans[N];
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
        cin >> n >> q;
        FOR(i,1,n){
            cin >> a[i];
            maximize(maxx, a[i]);
        }
        FOR(i,1,q)
        {
            register int l, r;
            cin >> l >> r;
            query.pb(Data(l, r, i));
        }
        sort(all(query));
        int L = 1, R = 0;
        for(Data i : query)
        {
            while(L < i.l)upd(a[L], -1), L++;
            while(L > i.l)L--,upd(a[L],1);
            while(R > i.r)upd(a[R], -1), R--;
            while(R < i.r)R++, upd(a[R], 1);
            int l = 1, r = (i.r - i.l + 1);
            while(l <= r)
            {
                int mid = (l+r) >> 1;
                if(get(maxx) - get(mid - 1) >= mid){
                    ans[i.id] = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
        }
        FOR(i,1,q)
            cout << ans[i] << endl;
    }

}

