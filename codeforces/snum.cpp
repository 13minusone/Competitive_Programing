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
const int oo = 0x3c3c3c3c;

int n, m, Num[N], Low[N], cnt = 0, id[N], c, deg[N];
vector<int> a[N];
stack<int> st;
int Count = 0;
vector<int>vec[N];
void dfs(int u) {
    Low[u] = Num[u] = ++cnt;
    st.push(u);

    for (int v : a[u])
        if (Num[v])
            Low[u] = min(Low[u], Num[v]);
        else {
            dfs(v);
            Low[u] = min(Low[u], Low[v]);
        }

    if (Num[u] == Low[u]) {  // found one
        Count++;
        int v;
        do {
            v = st.top();
            st.pop();
            id[v] = Count;
            vec[Count].pb(v);
            Num[v] = Low[v] = oo;  // remove v from graph
        } while (v != u);
    }
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
    cin >> n >> m >> c;
    FOR(i,1,m)
    {
        register int x, y;
        cin >> x >> y;
        a[x].pb(y);
    }
    FOR(i,1,n)if(!Num[i])dfs(i);
    FOR(i,1,n)
    {
        for(int j : a[i])
        {
            if(id[i] != id[j])deg[id[i]]++;
        }
    }
    vector<ii>ans;
    FOR(i,1,Count)
    {
        if(!deg[i] && i != id[c])
            ans.pb(ii(vec[i][0], c));
    }
    cout << SZ(ans) << endl;
    for(ii v : ans)cout << v.fi << " "<< v.se << endl;

}
