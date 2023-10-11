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
typedef unsigned long long ull ;
typedef pair<ull,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e7 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
const int MAXN = 2.5e6;

vector<int>vec;
bool vis[MAXN];
vector<ii>ans;
int k,cnt[MAXN];
ull n;
int cal(int j, int i)
{
    int s = 0;
    while(j %i == 0){
        s++;
        j/=i;
    }
    return s;
}
ull powe(int i, int j)
{
    if(j == 0)return 1;
    if(j == 1)return i;
    ull t = powe(i,j/2);
    if(j&1)return 1uLL * (1ull * t * t) * i;
    else return (1ull * t * t);
}
void pre()
{
    FOR(i,1,MAXN-5)cnt[i] = 1;
    for(int i = 2; i <= MAXN-5;i++)
    {
        if(!vis[i])
        {
            vec.pb(i);
            cnt[i]++;
            for(ll j = 1LL *2* i; j <= MAXN-5; j += i){
                    vis[j] = 1;
                    cnt[j] = 1LL * cnt[j] * (cal(j,i) + 1);
            }
        }
    }
    FOR(i,1,MAXN-5)
        if(cnt[i] <= 10)
        ans.pb(ii(powe(i,cnt[i]), i));
}
bool check(ll val)
{
    if(val == 1)return 0;
   for(int i : vec)
   {
       if(i < sqrt(val)){
            if(val %i ==  0)return 0;
       }else break;
   }
   return 1;
}
ll solve(ull val)
{
    ll x = sqrt(n);
    if(x * x == n)
    {
        if(check(x))return x;
    }
    if(val == 1)return 1;
    int k = lower_bound(all(ans),ii(val, 0)) - ans.begin();
    //cout << k << endl;
    if(ans[k].fi == val)return ans[k].se;
    return -1;
}
signed main()
{
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    pre();
    sort(all(ans));
    cout << MAXN << endl;
    cin >> t;
    while(t--)
    {
        scanf("%lld", &n);
        printf("%lld ",solve(n));
    }

}


