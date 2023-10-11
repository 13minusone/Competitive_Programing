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

const int N = 1e3 + 5;
const ll MOD =1e9+7;
const int base = 311 ;// 131;
//const int block = 488;

int hashs[N][N], nz[N], vis[30], n, res = 0, in[30], out[30], num[30], low[30], cnt = 0;
string s, pre;
int findd(int id)
{
    int fir = id-1, se = id, l = 0, r, ans = 0;
    r = min(nz[fir], nz[se]);
    while(l <= r)
    {
        int mid = (l+r) >> 1;
        if(hashs[fir][mid]== hashs[se][mid]){
            l = mid + 1;
            ans = mid;
        }
        else r = mid-1;
    }
    if(ans == min(nz[fir], nz[se]))return MOD;
    return ans;
}
char c;
vector<int>adj[30];
stack<int> st;
void dfs(int u)
{
    num[u] = low[u] = ++cnt;
    st.push(u);
    for(int v : adj[u])
        if(!num[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else low[u] = min(low[u], num[v]);
    int numNode = 0;
    if(low[u] == num[u])
    {
        int v;
        do
        {
            numNode++;
            v = st.top();
            low[v] = num[v] = MOD;
            st.pop();
        }
        while(u != v);
        if(numNode > 1) res = 1;
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
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> c >> n;
        FOR(i,1,n)
        {
            pre = s;
            cin >> s;
            nz[i] = SZ(s);
            s = ' '+ s;
            FOR(j,1,nz[i])
                hashs[i][j] = (1LL * hashs[i][j-1] * base%MOD + s[j])%MOD;
            if(i == 1)continue;
            int k = findd(i);
            if(k == MOD)continue;
            adj[int(pre[k+1] - 'a')].pb( int( s[k+1] - 'a'));
            out[int(pre[k+1] - 'a')]++;
            in[int(s[k+1] - 'a')]++;
        }
        int te = 0;
        FOR(i,0,int(c-'a')){
            if(!num[i])
                dfs(i);
            if(in[i] == 0 ){
                    te++;
            }
            //cout << num[i] << endl;
        }
        if(res > 0) return cout << "IMPOSSIBLE", 0;
        else if(te > 1) return cout << "AMBIGUOUS", 0;
        queue<int> q;
        for(int i = 0; i <= int(c - 'a'); i++) if(!in[i]) q.push(i);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << char(u +'a');
            for(int v : adj[u]) if(--in[v] == 0) q.push(v);
        }


    }

}

