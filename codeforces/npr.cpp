// Onegai no bug
// Author : Nyanpasuuuuu
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

const int N = 250005;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int n = 0,trie[N*27][27], cnt = 0, min1[N*27], min2[N*27],st[N];
char s[N][33];
inline bool cmp(int a, int b)
{
    return strcmp(s[a], s[b]) < 0;
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
    while(true)
    {
        ++n;
        st[n] = n;
        if(!gets(s[n]))break;
        if(!s[n][0])break;
    }
    cout << n << endl;
    sort(st+1,st+n,cmp);
    FOR(i,1,n)
    {
         cout << s[st[i]];
        cout << endl;
    }
}

