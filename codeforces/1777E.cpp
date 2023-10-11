// Author : Nyanpasuuuuu
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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e5 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, m, Numcc[N], Numcom = 0, cnt = 0, Num[N], Low[N], Deg[N];
vector<ii>edge[N];
vector<int> vec[N];
stack<int>st;
void dfs(int u){
    Num[u] = Low[u] = ++cnt;
    st.push(u);
    for(int v : vec[u]){
        if(!Num[v]){
            dfs(v);
            minimize(Low[u], Low[v]);
        }
        else minimize(Low[u], Num[v]);
    }
    if(Num[u] == Low[u]){
        Numcom++;
        int v;
        do{
            v = st.top();
            st.pop();
            Num[v] = Low[v] = INF;
            Numcc[v] = Numcom;
        }
        while(v != u);
    }
}
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n)
        edge[i].clear();
    FOR(i,1,m){
        register int x, y, w;
        cin >> x >> y >> w;
        edge[x].pb(ii(y, w));
    }
}
void process(void)
{
    int l = 0, r = INF - 7, res = -1;
    while(l <= r)
    {
        int mid = (l+r) >> 1 ;
        FOR(i,1,n)vec[i].clear();
        FOR(i,1,n){
            Numcc[i] = -1;
            Numcom = cnt = Num[i] = Low[i] = Deg[i] = 0;
            for(ii &j : edge[i])
            {
                vec[i].pb(j.fi);
                if(j.se <= mid){
                    vec[j.fi].pb(i);
                }
            }
        }
        FOR(i,1,n)
            if(Numcc[i] == -1)
                dfs(i);
        int ans = 0;
        FOR(i,1,n)
            for(ii &j : edge[i])
                if(j.se > mid && Numcc[i] != Numcc[j.fi] && Deg[Numcc[j.fi]] == 0){
                    ans++;
                    Deg[Numcc[j.fi]]++;
                }
        //cout << Numcom << endl;
        if(ans == Numcom - 1){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
        //break;
    }
    cout << res << endl;
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
        init();
        process();
    }

}
