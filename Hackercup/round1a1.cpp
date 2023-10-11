// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "round1a1"
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

const int N = 5e5 + 5;
const ll MOD =1e9+7;
const ll MOD2 =1e9+9;
const ll base = 311;
//const int BLOCK = 488;

int a[N], n, k, b[N], cnt[N], change[N];
void solve(){
    if(k == 0){
            FOR(i,1,n)
                if(change[i] != 0){
                    cout << ": NO";
                    return;
                }
        cout << ": YES";
        return;
    }
    FOR(i,2,n)
        if(change[i] != change[i-1]){
            cout << ": NO" ;
            return;
        }
    if((k == 1 && change[1] == 0) || (k %2 == 1 && change[1] == 0 && n <= 2))
    {
        cout << ": NO";
        return;
    }
    if( (k%2 == 1 )  || (n > 2 && k%2 ==0) || (change[1] == 0 && k%2 == 0))cout << ": YES";
    else cout << ": NO";
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
    cin >> t;
    FOR(Test, 1, t)
    {
        cin >> n >> k;
        memset(cnt,0,sizeof cnt);
        FOR(i,1,n){
            cin >> a[i];
            cnt[a[i]] = i;
        }
        FOR(i,1,n){
            cin >> b[i];
            change[i] = i - cnt[b[i]];
            if(change[i] > 0)change[i] -= n;
        }
        cout << "Case #" << Test;
        solve();
        if(Test != t)cout << endl;
    }

}

