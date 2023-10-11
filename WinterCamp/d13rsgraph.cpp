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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
//const ll base = 311;
//const int BLOCK = 488;

int powe(int a,ll b)
{
    if(b == 1)return a;
    if(b == 0)return 1;
    int t = powe(a, b/2)%MOD;
    if(b&1)return (1LL * (1LL * t * t %MOD) * a)%MOD;
    else return (1LL * t * t %MOD);
}
ll C2(int a)
{
    if(a < 2)return 0;
    return (1LL * (a-1) * a)/2;
}
int n, m, d[N],cnt[N],Equal[N], Bigger[N];
vector<int>node[N];
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
        d[1] = 0;
        FOR(i,2,n){
            cin >> d[i];
            cnt[d[i]]++;
            node[d[i]].pb(i);
        }
        cnt[0] = 1;
        d[1] = 0;
        FOR(i,1,m)
        {
            register int x, y;
            cin >>x >> y;
            if(abs(d[x] - d[y]) > 1){
                cout << 0 << endl;
                return 0;
            }
            if(d[x] == d[y]){
                Equal[d[x]]++;
                continue;
            }
            if(d[x] > d[y])swap(x,y);
            Bigger[y]++;
        }
        FOR(i,1,n)
        if(cnt[i] > 0 && cnt[i-1] *cnt[i] == 0)
        {
                cout << 0<< endl;
                return 0;
        }
        int ans = 1;
        FOR(i,1,n)
        {
            if(cnt[i] == 0)break;
            for(int v : node[i])
            {
                if(!Bigger[v])
                {
                    ans = 1LL *ans * max(1,powe(2,cnt[i-1])-1+ MOD)%MOD;
                }
                else
                ans = 1LL *ans * max(1,powe(2,cnt[i-1] - Bigger[v]))%MOD;
                //cout << powe(2,cnt[i-1] - Bigger[v])-1 << endl;
            }
            //cout << ans << endl;
            ans = 1LL *ans * powe(2,C2(cnt[i])- Equal[i])%MOD;
        }
        cout << ans;
    }

}

