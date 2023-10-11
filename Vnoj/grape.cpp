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

const int N = 5e2 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, m, q, l, r, a[N][N], lef[N], rig[N];;
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
        cin >> n >> m >> q;
        FOR(i,1,n)
            FOR(j,1,m)cin >> a[i][j];
        while(q--)
        {
            memset(lef, 0, sizeof lef);
            memset(rig, 0, sizeof rig);
            cin >> l >> r;
            FOR(i,1,n){
                int le = 1, ri = m;
                while(le <= ri){
                    int mid = (le + ri) >> 1;
                    if(a[i][mid] <= r){
                        lef[i] = mid;
                        ri = mid -1;
                    }
                    else le = mid + 1;
                }
                 le = 1, ri = m;
                while(le <= ri){
                    int mid = (le + ri) >> 1;
                    if(a[i][mid] >= l){
                        rig[i] = mid;
                        le = mid  + 1;
                    }
                    else ri = mid - 1;
                }
            }
//            FOR(i,1,n)
//                cout << lef[i] << " " << rig[i] << endl;
            int ans =  0;
            FOR(i,1,n){
                int le = ans + 1, ri = min(n,m);
                if(lef[i] == 0 || rig[i] == 0)continue;
                while(le <= ri){
                    int mid = (le + ri) >> 1;
                    if(i - mid + 1 < 1 || rig[i-mid + 1] - lef[i]  +1 < mid)ri = mid-1;
                    else {
                        ans = mid;
                        le = mid + 1;
                    }
                }
            }
            cout << ans * ans << endl;
        }
    }

}

