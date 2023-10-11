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
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, a[N], pos[N];
vector<ii>vec;

bool cmp(ii u, ii v)
{
    if( (u.fi&1) == (v.fi & 1))return u.fi < v.se;
    else return (u.fi&1) < (v.fi & 1);
}
void Sortt(vector<ii>&vec, int u, int v)
{
    sort(all(vec),cmp);
    for(int i = u;i <= v)
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
    while(t--)
    {
        cin >> n;
        FOR(i,1,n){
            cin >> a[i];
            pos[i] = i;
        }
        sort(a + 1, a + 1 + n,cmp);
        solve(1,n,0);
        FOR(i,1,n)
            cout << pos[i] << " ";
        cout << endl;
    }

}

