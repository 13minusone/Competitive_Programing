// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "compress"
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
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

ll x;
int n, k, s[N], tmp[N], se[N], d[N];
void sol21()
{
    if(x > n){
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    FOR(k,1,min(n,s[1] - 1)){
        tmp[1] = k;
        bool  ok = true;
        FOR(i,2,n){
            tmp[i] = s[i - 1] - tmp[i-1];
            if(tmp[i] == tmp[i-1] || tmp[i] < 0 || tmp[i] > n){ok = false;break;}
        }
        if(ok)cnt++;
        if(cnt == x){
            FOR(i,1,n)
                cout << tmp[i] << " " ;
            cout << endl;
            return;
        }
    }
    if(cnt < x)cout << -1;
    cout << endl;
}
void sol2()
{
    if(x > n){
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    FOR(k,1,min(n,s[1] - 1)){
        tmp[1] = k;
        bool ok = true;
        if(s[1] - tmp[1] == tmp[1] || s[1] - tmp[1] == s[2] - s[1] + tmp[1] || s[1] - tmp[1] > n || s[2] - s[1] + tmp[1]  > n)
            ok = false;
        if(ok)cnt++;
        if(cnt == x){
            cout << tmp[1] << " " ;
            FOR(i,2,n){
                tmp[i] = s[i-1] - tmp[i-1];
                cout << tmp[i] << " " ;
            }
            cout << endl;
            return;
        }
    }
    if(cnt < x)cout << -1;
    cout << endl;
}
bool check()
{
    if(tmp[1] < 0 || tmp[2] < 0 || tmp[3] < 0 || tmp[3] > n)return false;
    if(n > 3 && (tmp[4] < 0 || tmp[5] < 0 || tmp[4] > n || tmp[5] > n))return false;
    d[tmp[1]]++ ;
    d[tmp[2]]++;
    if(d[tmp[2]] >= 2)return false;
    d[tmp[3]]++;
    if(d[tmp[3]] >= 2)return false;
    d[tmp[4]]++;
    if(d[tmp[4]] >= 2)return false;
    d[tmp[5]]++;
    if(d[tmp[5]] >= 2)return false;
    return true;
}
void sol3()
{
    ll cnt = 0;
    FOR(i,1,n -3 )
        FOR(j,1,min(n-2,s[1] - i - 1))
            if(i != j)
            {
                tmp[1] = i;
                tmp[2] = j;
                if(n >= 3)
                {   tmp[3] = s[1] - i - j;
                    tmp[4] = s[2] - j - tmp[3];
                    tmp[5] = s[3] - tmp[3] - tmp[4];
                }
                d[tmp[1] ] = d[tmp[2]] = d[tmp[3]] = d[tmp[4]] = d[tmp[5]] = 0;
                if(check())cnt++;
                if(cnt == x){
                    cout << tmp[1] << " " << tmp[2] << " ";
                    FOR(i,3,n){
                        tmp[i] = s[i-k + 1] - tmp[i-1] - tmp[i-2];
                        cout << tmp[i] << " " ;
                    }
                    cout << endl;
                    return;
                }
            }
    cout << -1 << endl;
    return;
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
        cin >> n >> k >> x;
        FOR(i,1,n - k + 1)
        {
            cin >> s[i];
        }
        if(k == 2 && n <= 10000)sol21();
        else if(k == 2)sol2();
        else if(k == 3)sol3();
    }
    return 0;
}

