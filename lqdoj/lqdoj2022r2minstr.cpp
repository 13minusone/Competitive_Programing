// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "minstr"
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

const int N = 1e4 + 5;
const int N2 = 1e3;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, m, Sz[N],cnt = 0,Sub = 0;
string s, query[N];
struct tree
{
    struct node{
        int nx[26], cnt;
        node(){
            cnt = 0;
            FOR(i,0,25)nx[i] = 0;
        }
    };
    vector<node> trie;
    tree() { trie.pb(node()); }
    void add(int i, int j, int length)
    {
        int root = 0;
        FOR(k,j,min(Sz[i],j+length)){
            int bit = int(query[i][k] - 'a');
            if(!trie[root].nx[bit]){
                    trie[root].nx[bit] = SZ(trie);
                    trie.pb(node());
            }
            root  = trie[root].nx[bit];
        }
    }
    bool ans(int i, int val)
    {
        int res = 0, root = 0;
        FOR(k,i,min(i + val,2*n))
        {
            int bit = int(s[k] - 'a');
            if(!trie[root].nx[bit])return 1;
            res++;
            root = trie[root].nx[bit];
        }
        return (res <= val);
    }
};
bool check(int length)
{
    if(length >= n)return 1;
    int s = 0;
    int j = 1;
    tree cay;
    cay = tree();
    FOR(i,1,m)
        FOR(j,1,Sz[i]-length + 1)
            cay.add(i,j,length);
    while(j <= 2 * n - length + 1)
    {
        if(cay.ans(j, length))s++;
        else s = 0;
        //cout <<j << " " <<  s << endl;
        if(s == n - length)return 1;
        j++;
    }
    return 0;
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
        cin >> n >> m;
        cin >> s;
        s = s + s;
        s = " " + s;
        FOR(i,1,m)
        {
            cin >> query[i];
            Sz[i] =  SZ(query[i]);
            query[i] = " "+ query[i];
            maximize(Sub, Sz[i]);
        }
        int l = 1, r = n, res = n;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(check(mid))
            {
                r = mid-1;
                res = mid;
            }
            else l = mid + 1;
          // if(check(mid))cout << mid << endl;
        }
        cout << res << endl;
    }
}
