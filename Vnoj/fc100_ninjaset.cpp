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
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, w[N];
vector<int>edge[N];
multiset<int> solve(int u)
{
    multiset<int>d;
     for(int v : edge[u])
        {
            multiset<int>V = solve(v);
            if(SZ(d) < SZ(V))swap(d,V);
            d.insert(all(V));
        }
   if(d.empty())d.insert(w[u]);
   else
   {
       auto it = d.lower_bound(w[u]);
       if(it != d.end())d.erase(it);
       d.insert(w[u]);
   }
   return d;
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
    cin >> n;
    FOR(i,1,n)
    {
        register int u;
        cin >> w[i] >> u;
        if(u != 0){
            edge[u].pb(i);
        }
    }
    cout << SZ(solve(1));
}

