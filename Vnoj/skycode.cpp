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

const int N = 1e4 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, a, cnt[N];
ll ans[N], divide[N];
ll C(ll b){
    if(b < 4)return 0;
    return (1LL * (1LL * (1LL *b * (b-1)/2)*(b-2)/3) *(b-3)/4);
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
    while(cin >> n)
    {
        memset(cnt,0,sizeof cnt);
        memset(divide,0,sizeof divide);
        memset(ans,0,sizeof ans);
        FOR(i,1,n){
            cin >> a;
            cnt[a]++;
        }
        //cout << C(6) << endl;;
        FD(i,N-5,1)
        {
            for(int j = i ;j <= N-5; j += i)divide[i] += cnt[j];
        }
        FOR(i,1,N-5){
            ans[i] = C(divide[i]);
           // if(ans[i])cout <<i << " "<< ans[i] << " " << endl;
        }
        FD(i,N-5,1){
            for(int j = 2 * i; j <= N-5; j += i)ans[i] -= ans[j];
            //if(ans[i])cout <<i << " " << ans[i] << endl;
        }
        cout << ans[1] << endl;
    }

}

