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
#define fi first
#define se second
#define endl '\n'
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 5e5 + 5;
const int mod =1e9+9;
//const ll base = 311;
//const int block = 488;

int n, a[N],q,bit[N + 100], last[N],pos[N] ,ans[N];
vector<ii> queries[N];
vector<int>val;
void upd(int x,int val)
{
    for(; x <=n ; x += x & (-x))bit[x] = min(bit[x],val);
}
int getMin(int x)
{
    if(x == 0)return mod;
    int ans = mod;
    for(; x > 0; x -= x & (-x))ans = min(ans,bit[x]);
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
//    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        FOR(i,1,n){
            cin >> a[i];
            val.pb(a[i]);
        }
        sort(all(val));
        val.resize(unique(all(val) )- val.begin());
        memset(bit,mod,sizeof bit);
        FD(i,n,1)
        {
            a[i] = lower_bound(all(val), a[i]) - val.begin() + 1;
            last[i] = pos[a[i]];
            pos[a[i]] = i;
        }
        memset(bit,mod,sizeof bit);
        FOR(i,1,q)
        {
            int l,r;
            cin >> l >> r;
            queries[l].pb(ii(i,r));
        }
        FD(i,n,1)
        {
            if(last[i]){
                    upd(last[i],last[i]-i);
            }
            for(ii j : queries[i])
            {
                ans[j.fi] = getMin(j.se);
            }
        }
        FOR(i,1,q)cout << (ans[i] == mod ? -1: ans[i] ) << endl;
    }
}
