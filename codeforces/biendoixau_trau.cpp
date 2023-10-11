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

const int N = 1e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
int bl = 1000;
int n,a[N],l,r,x,y, q;
char oldval,newval;
string s;
void upd(int u, int v, int x, int y)
{
   FOR(i,u,v)if(a[i] == x)a[i] = y;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".ans","w",stdout);
    }
    cin >> s;
    n = SZ(s);
    s= ' '+s;
    FOR(i,1,n)a[i] = int(s[i] - 'a');
    cin >> q;
    while(q--)
    {
        cin >> l >> r >> oldval >> newval;
        l++;
        r++;
        upd(l, r, int(oldval-'a'), int(newval-'a'));
    }
    FOR(i,1,n)cout << char(a[i] + 'a');
}

