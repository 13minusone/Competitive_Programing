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

const int N = 2e5 + 5;
//const ll mod =1e17+9;
//const ll base = 311;
//const int block = 488;

bool type[N];
int n, u[N], v[N], sta[N], fin[N], cnt = 0, node = 1, trie[25 * N][2], path[N];
vector<int>edge[N];
void dfs(const int &u)
{
    sta[u] = ++cnt;
    for(int v : edge[u])
        dfs(v);
    fin[u] = cnt;
}
set<int>vec[N * 25];
void add(const int& val, const int &pos)
{
    int u = 0, k;
    FD(i,29,0){
        k = getbit(val, i);
        if(!trie[u][k]) trie[u][k] = ++cnt;
        u = trie[u][k];
        vec[u].insert(pos);
    }
}
int findd(const int &val, const int &l,const int &r)
{
    int ans = 0, u = 0, k;
    FD(i,29,0)
    {
        k = getbit(val,i);
        int c = trie[u][k ^ 1];
        if(c && vec[c].upper_bound(r)  !=  vec[c].lower_bound(l)){
            ans |= (1 << i);
            u = c;
        }
        else u = trie[u][k];
        if(!u)break;
    }
    return ans;
}
signed main()
{
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        FOR(i,1,n){
            char s[5];
            scanf("%s", s);
            scanf("%d%d", &u[i],&v[i]);
            if(s[0] == 'A'){
                    node++;
                type[i] = 1;
                edge[u[i]].pb(node);
                path[node] = path[u[i]] ^ v[i];
            }
        }
        dfs(1);
        cnt = 0, node = 1;
        add(0,1);
        FOR(i,1,n)
        {
            if(type[i] == 1){
                node++;
                add(path[node], sta[node]);
            }
            else
            {
                printf("%d\n", findd(path[u[i]], sta[v[i]], fin[v[i]]));
            }
        }
    }

}
