// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "SHOPPING"
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
const int BLOCK = 500;

int l, u, v, k;
int n,a[N],q, neww[N], ou, ov;
ll sum[202][N], sq = 0;

vector<int>val;
int get()
{
    sq = 0;
    int Lef = l / BLOCK, Rig = n / BLOCK ;
    if(Lef == Rig)
    {
        FOR(i,l,n){
            if(a[i] >= ou && a[i] <= ov)sq += neww[i];
            if(sq > k)return i - 1;
        }
        return n;
    }
    FOR(i,l,(Lef + 1) * BLOCK - 1){
        if(a[i] >= ou && a[i] <= ov)sq += neww[i];
        if(sq > k)return i - 1;
    }
    FOR(i,Lef + 1, Rig){
        sq += sum[i][ov] - sum[i][ou-1];
        if(sq > k){
            sq -= sum[i][ov] - sum[i][ou - 1];
            FOR(j,i * BLOCK, min(n,(i + 1) * BLOCK - 1))
            {
                if(a[j] >= ou && a[j] <= ov)sq += neww[j];
                if(sq > k)return j - 1;
            }
        }
    }
    return n;
}
signed main()
{
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&q);
        FOR(i,1,n){
            scanf("%d",&a[i]);
            val.pb(a[i]);
        }
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        FOR(i,1,n)
        {
            neww[i] = a[i];
            a[i] = lower_bound(all(val), neww[i]) - val.begin() + 1;
            sum[i / BLOCK][a[i]] += neww[i];
        }
        FOR(i,0,n / BLOCK)
            FOR(j,1,SZ(val))
                sum[i][j] += sum[i][j - 1];
        FOR(i,1,q)
        {
            scanf("%d%d%d%d",&l,&u,&v,&k);
            ou = lower_bound(all(val), u)- val.begin() + 1;
            ov = upper_bound(all(val), v)- val.begin();
            printf("%d\n", get() - l + 1);
        }
        return 0;
    }

}
