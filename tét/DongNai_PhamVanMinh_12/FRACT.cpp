// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "FRACT"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

const int N = 2e6 + 5;
const int MOD =1e9+7;
const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int p, q, k, vis[N];
ll hashH[N], Pow10[N], t = 0;
string s, ans;
ll getHash(int l, int r)
{
    return (hashH[r] - 1LL  * hashH[l - 1] * Pow10[r - l + 1] % MOD + MOD)%MOD;
}
void init(void)
{
    cin >> p >> q >> k;
    cin >> s;
    Pow10[0] = 1;
    FOR(i,0,SZ(s) - 1)
    {
        t = (1LL  * t * base % MOD + s[i]) % MOD;
        Pow10[i + 1] = 1LL * Pow10[i] * base % MOD;
    }
}
void process(void)
{
    int x = p, y = q;
    ans = " " + ans;
    memset(vis,0,sizeof vis);
    while(vis[x] == 0){
        vis[x] = SZ(ans);
        if(x / y > 0){
            if(x / y < 10){
            ans += char(x/y + '0');
            }
        }
        else if(SZ(ans) > 1)ans += '0';
        x = x % y;
        x *= 10;
    }
    int n = SZ(ans) - 1;
    if(SZ(s) == 1)
    {
        int cnt = 0, o = 0, pos = 0, add = 0;
        FOR(i,1,vis[x] - 1){
               if(o == k){
                cout << pos + SZ(s) - 1;
                return;
            }
            pos++;
            if(ans[i] == s[0])o++;
        }
        if(o == k){
            cout << pos + SZ(s) - 1;
            return;
        }
        pos = vis[x] - 1;
        FOR(i,vis[x], n)
            if(ans[i] == s[0])cnt++;
        add = n - vis[x] + 1;
        //cout <<o << " " <<  cnt << " " << add << endl;
        if(cnt == 0){
            cout << 0;
            return;
        }
        while(o + cnt < k)
        {
            o += cnt;
            pos += add;
        }
        FOR(i,vis[x], n){
             if(o == k){
                cout << pos;
                return;
            }
            pos++;
            if(ans[i] == s[0])o++;
        }
        if(o == k){
            cout << pos;
            return;
        }
    }
    else{
       // cout << ans << endl;
        while(SZ(ans) - 1 < SZ(s)){
            FOR(i,vis[x],n)ans += ans[i];
        }
        int nNew = SZ(ans) - 1;
        FOR(i,vis[x], n)ans += ans[i];
        Pow10[0] = 1;
        hashH[0] = 0;
        FOR(i,1,SZ(ans) - 1)
        {
            hashH[i] = (1LL  * hashH[i - 1] * base % MOD + ans[i]) % MOD;
            Pow10[i] = 1LL * Pow10[i - 1] * base % MOD;
        }
        int cnt = 0, o = 0, pos = 0, add = 0;
        FOR(i,1,vis[x] - 1){
            if(o == k){
                cout << pos + SZ(s) - 1;
                return;
            }
            pos++;
            if(i >= SZ(s))
                if(getHash(i, i + SZ(s) - 1) == t)o++;
        }
        if(o == k){
            cout << pos + SZ(s) - 1;
            return;
        }
        pos = vis[x] - 1;
        //cout << getHash(4,7) << endl;
        int w = SZ(ans) - 1 - SZ(s) + 1;
        FOR(i,vis[x],min(nNew, w))
        {
            if(getHash(i, i + SZ(s) - 1) == t)cnt++;
            //cout << i << " " << cnt << endl;
        }
        add = n - vis[x] + 1;
        if(cnt == 0){
            cout << 0;
            return;
        }
        //cout <<t << " " << o << " " <<  cnt << " " << add << " " << min(nNew,w)<< endl;
        while(o + cnt < k)
        {
            o += cnt;
            pos += add;
        }
        FOR(i,vis[x],min(nNew, w)){
             if(o == k){
                cout << pos + SZ(s) - 1;
                return;
            }
            pos++;
            if(getHash(i, i + SZ(s) - 1) == t)o++;
        }
        if(o == k){
            cout << pos;
            return;
        }
    }
    cout << 0;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


