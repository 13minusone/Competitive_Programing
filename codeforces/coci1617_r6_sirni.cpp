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

const int N = 1e5 + 5;
const int mod =1e7+1;
//const ll base = 311;
//const int bl = 488;
int par[N], n,nxt[mod+2];
vector<int>a;
int pos[mod + 2], vt[mod+2];
int root(int x)
{
    return (par[x] < 0 ? x : par[x] = root(par[x]));
}
bool join(int u, int v)
{
    if((u = root(u)) == (v = root(v)) )return false;
    if(- par[u] < -par[v])swap(u,v);
    par[u] += par[v];
    par[v] = u;
    return true;
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
    int tplt , dist = 0, sum = 0, maxx;
    FOR(i,1,n){
        int x;
        cin >> x;
        a.pb(x);
    }
    sort(all(a));
    a.resize(unique(all(a))- a.begin());
    int cnt = SZ(a) - 1;
    maxx = a[cnt];
    FOR(i,0,cnt)nxt[a[i]] = a[i],pos[a[i]] = 1, par[i] = -1, vt[a[i]] = i;
    tplt = cnt;
    nxt[maxx+1] = maxx+1;
    FD(i,maxx,1){
        if(!nxt[i])nxt[i] = nxt[i+1];
        //cout << i << " " << nxt[i] << endl;
    }
    int res = 0;
    while(tplt)
    {

       FOR(i,0,cnt){
            int j = a[i] + dist;
            while(j <= maxx){
//                    if(!pos[j] || j == a[i]){
//                            j += a[i]; continue;}
                if(pos[j]  != 0  && join(i, vt[j])){
                    sum += dist;
                    //cout << a[i] << " " << j << " " << dist << endl;
                    tplt--;
                    if(tplt <= 0)break;
                }
                int k = j + 1;
               // cout << j << endl;
                if((nxt[k] - j) % a[i] == 0)j = nxt[k];
                else j =  dist + ((nxt[k] - dist) / a[i] + 1)*a[i];
                //j += a[i];
                //cout << i <<" " <<nxt[k] <<  " " << dist << " " << j << endl;
//                res++;
//                if(res >= 10)return 0;
            }
            if(tplt  <=  0)break;
        }
        dist++;
    }
    cout << sum << endl;
}

