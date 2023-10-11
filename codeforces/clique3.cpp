// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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

const int N = 3e6;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, m, k;
int a[N], res= 0, clique[N+5],deg[N+5], pos[N+5];
int cnt[N+5];
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
    while(t--)
    {
        cin >> n;
        memset(pos, 0, sizeof pos);
        FOR(i,1,n)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        res = 0;
        FOR(i,1,N)
        {
            if(pos[i])
                for(int j = 2 * i ; j <= N; j+= i)
                {
                    if(pos[j])
                    cnt[i]++;
                }
        }

        FOR(i,1,N)
        {
            if(pos[i])
                for(int j = 2 * i ; j <= N; j+= i)
                {
                    if(pos[j])
                    res += cnt[j];
                }
        }
        cout << res;
    }
}


