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

const int N = 1e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, q, a[N];
int gcd[N][22], mx[N][22], mn[N][22], last[N][22];
map<int,int>mp;
int getdif(int l, int r){
    int Log = log2(r-l + 1);
    return max(last[l][Log],last[r - (1 << Log) + 1][Log]);
}
int getmax(int l, int r){
    int Log = log2(r-l + 1);
   // cout << Log << " " <<l + (1 << Log)  << endl;
    return max(mx[l][Log],mx[r - (1 << Log) + 1][Log]);
}
int getmin(int l, int r){
    int Log = log2(r-l + 1);
    //cout << Log << " " <<l + (1 << Log)  << endl;
    return min(mn[l][Log],mn[r - (1 << Log) + 1][Log]);
}
int getgcd(int l, int r){
    if(l > r)return 0;
    int Log = log2(r-l + 1);
    //cout << l << " " << r << " " << Log << endl;
    return __gcd(gcd[l][Log],gcd[r - (1 << Log) + 1][Log]);
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
        cin >> n >> q;
        memset(mn, 0x3f, sizeof mn);
        FOR(i,1,n){
            cin >> a[i];
        }
        FOR(i,1,n){
            if(i != n)gcd[i][0] = abs(a[i] - a[i + 1]);
            mx[i][0] = a[i];
            mn[i][0] = a[i];
            last[i][0] = mp[a[i]];
            mp[a[i]] = i;
        }
        FOR(i,1,18)
            FOR(j,1,n - (1 << (i)) + 1){
                if(j < n - (1 << (i)) + 1)
                    gcd[j][i] = __gcd(gcd[j][i-1], gcd[j + (1 << (i-1))][i-1]);
                mx[j][i] = max(mx[j][i-1], mx[j + (1 << (i-1))][i-1]);
                mn[j][i] = min(mn[j][i-1], mn[j + (1 << (i-1))][i-1]);
                last[j][i] = max(last[j][i-1], last[j + (1 << (i-1))][i-1]);
               //cout <<j << " " << i << " " <<  mx[j][i] << endl;
            }
        while(q--){
                register int l, r;
            cin >> l >> r;
            int dif = getdif(l, r), maxx = getmax(l, r), minn = getmin(l, r), ck = getgcd(l, r-1);
          // cout << dif << " " << maxx << " " << minn << " "<< ck << endl;;
            if(dif < l && maxx - minn == (r- l) * ck){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }

}

