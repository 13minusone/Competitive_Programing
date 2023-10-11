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

const int N = 3e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int n, a[N];
queue<int>que;
queue<ii>qu;
vector<int>edge[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin >> t;
    while(t--){
    cin >> n;
    int s = 0;
    FOR(i,1,n){
        cin >> a[i];
        s += a[i];
        if(a[i] > 1)qu.push(ii(a[i], i));
        else que.push(i);
        edge[i].clear();
    }
    if(s != 2 *(n-1)){
            cout << -1 << endl;
        continue;
    }
    while(!que.empty() && !qu.empty())
    {
        ii x = qu.front();
        int y = que.front(), z =x.se;
        edge[y].pb(z);
        edge[z].pb(y);
        qu.pop();
        que.pop();
        x.fi--;
        if(x.fi > 1)qu.push(x);
        else que.push(x.se);
    }
    while(!que.empty())
    {
        int x = que.front();
        que.pop();
        edge[x].pb( que.front());
        edge[qu.front()].pb(x);
        que.pop();
    }
    }
}
