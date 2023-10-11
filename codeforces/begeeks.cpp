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

const int N = 2e5 + 5;
const ll mod = 1e9+7;
//const ll base = 311;
//const int bl = 488;

int n;
int Gcd[N][25],maxx[N][25],a[N],cong;
ll res = 0;
int get(int u,int v)
{
    int LOG = __lg(v-u+1);
    return __gcd(Gcd[u][LOG],Gcd[v - (1 << (LOG))+1][LOG]);
}
int getmax(int u,int v)
{
    int LOG = __lg(v-u+1);
    return  max(maxx[u][LOG],maxx[v - (1 << (LOG))+1][LOG]);
}
int findr(int val,int pos, int i)
{
    int r = n ,ans = pos;
    while(pos <= r)
    {
        int mid = (r+pos) >> 1;
        if(get(i,mid) == val && getmax(i,mid) <= a[i]){
            ans = mid;
            pos = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}
int findl(int val,int pos,int old, int i)
{
    int l = 1 ,ans = pos;
    pos--;
    while(l <= pos)
    {
        int mid = (l+pos) >> 1;
        if(get(mid,i) == val && getmax(mid,old) < a[i]){
            ans = mid;
            pos = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}
vector<int>vecl,vecr;
void add(ll &a, int x)
{
    a+=x;
    if(a >= mod)a-=mod;
    return ;
}
signed main()
{

    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    scanf("%d",&n);
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        Gcd[i][0] = a[i];
        maxx[i][0] = a[i];
    }
    int Log = __lg(n)+1;
    FOR(i,1,Log)
        FOR(j,1,n - (1 << i)+1)
            {
                Gcd[j][i] = __gcd(Gcd[j][i-1], Gcd[j +(1LL << (i-1))][i-1]);
                maxx[j][i] = max(maxx[j][i-1], maxx[j + (1LL << (i-1))][i-1]);
            }
    FOR(i,1,n)
    {
        int pos = i;
        vecl.clear();
        vecr.clear();
        vecl.pb(i);
        vecr.pb(i);
        while(pos <= n && a[pos] <= a[i])
        {
            int val = get(i,pos);
            pos = findr(val,pos,i);
            if(pos != i)vecr.pb(pos);
            pos++;
        }
        pos  = i;
        if(i >=2)
        {
            while(1 <= pos)
            {
                int val = get(pos,i);
                pos = findl(val,pos,i-1,i);
                if(pos != i)vecl.pb(pos);
                pos--;
                if(a[pos] >= a[i])break;
            }
        }
        int lsz = SZ(vecl);
        int rsz = SZ(vecr);
        ll them  = (1LL*a[i] * a[i])%mod;
        add(res,them);
        REP(l,1,lsz)
        {
            cong =  (1LL*(vecl[l-1] - vecl[l])*a[i])%mod;
            cong = (1LL*cong* get(vecl[l],i))%mod;
            add(res,cong);
            //if(i == 5)cout << vecl[l] << " " ;
            REP(r,1,rsz)
            {
                cong = (1LL*(vecl[l-1] - vecl[l]) * (vecr[r] - vecr[r-1]))%mod;
                cong = (1LL*cong *a[i])%mod;
                cong = (1LL*cong * get(vecl[l],vecr[r]))%mod;
                add(res,cong);
            }
        }
        REP(r,1,rsz)
        {
            //if(i == 5)cout << vecr[r] << " " ;
                cong =  (1LL*(vecr[r] - vecr[r-1])*a[i])%mod;
                cong = (1LL*cong* get(i,vecr[r]))%mod;
                add(res,cong);
        }
        //cout << res << endl;
    }
    cout << res;
}
