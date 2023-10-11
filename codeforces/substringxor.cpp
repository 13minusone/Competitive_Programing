// Onegai no bug
// Author : Nyanpasuuuuu
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

const int N = 1e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;
int n,  trie[20 *N][3], cnt = 0, sum[N], a[N];
ll d;
void upd(int x)
{
    int cur = 0;
    FD(i,20,0)
    {
        int  k = getbit(x,i);
        if(!trie[cur][k])trie[cur][k] = ++cnt;
        cur = trie[cur][k];
        trie[cur][2]++;
    }
}
void del(int x)
{
    int cur = 0;
    FD(i,20,0)
    {
        int  k = getbit(x,i);
        cur = trie[cur][k];
        trie[cur][2]--;
    }
}
ll get(int x,int k)
{
    int cur = 0;
    ll ans =0;
    FD(i,20,0)
    {
        int bitx = getbit(x,i);
        int bitk = getbit(k,i);
        if(!bitk)
        {
            if(trie[cur][bitx])cur = trie[cur][bitx];
            else return ans;
        }
        else
        {
            if(trie[cur][bitx])ans += trie[trie[cur][bitx]][2];
            if(trie[cur][bitx^1])cur = trie[cur][bitx^1];
            else return ans;
        }
    }
    return ans;
}
bool check(ll s)
{
    ll ans = 0,cnt = 0;
    //memset(trie,0,sizeof trie);
    FOR(i,1,n){
        del(sum[i]);
        ans+=get(sum[i],s);
        cnt += (sum[i] < s);
        upd(sum[i]);

    }
    ans++;
    ans/=2;
    ans += cnt;
    //cout << ans << endl;
    if(ans < d)return true;
    else return false;
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
    cin >> n >> d;
    d = 1LL*n*(n+1)/2-d+1;
   // cout << d << endl;
    FOR(i,1,n){
        cin >> a[i];
        sum[i]=sum[i-1]^ a[i];
        upd(sum[i]);
        //upd(x);
    }
    //cout << check(100);
    int l = 0, r = (1 << 21);
    ll ans =0;
    while(l <= r)
    {
        int mid = (l+r) >> 1;
        if(check(mid))
        {
            ans = mid;
            l= mid+1;
        }
        else r= mid-1;
    }
    cout << ans;
}
