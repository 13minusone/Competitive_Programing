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

const int N = 4e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

ii a[N];

void unique_arr(vector <int> &S){
    S.pb(INT_MIN); // avoid zero
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
}

vector <int> fake_bit[N];

void fake_update(int x, int y, int limit_x){
    for(int i = x; i < limit_x; i += i&(-i))
        fake_bit[i].pb(y);
}

void fake_get(int x, int y){
    for(int i = x; i >= 1; i -= i&(-i))
        fake_bit[i].pb(y);
}

vector <int> bit[N];

void update(int x, int y, int limit_x, int val){
    for(int i = x; i < limit_x; i += i&(-i)){
        for(int j = lower_bound(fake_bit[i].begin(), fake_bit[i].end(), y) - fake_bit[i].begin(); j < fake_bit[i].size(); j += j&(-j))
            bit[i][j] = max(bit[i][j], val);
    }
}

int get(int x, int y){
    int ans = 0;
    for(int i = x; i >= 1; i -= i&(-i)){
        for(int j = lower_bound(fake_bit[i].begin(), fake_bit[i].end(), y) - fake_bit[i].begin(); j >= 1; j -= j&(-j))
            ans = max(ans, bit[i][j]);
    }
    return ans;
}

int main(){

    int n; cin >> n;
    vector <int> Sx, Sy;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        Sx.pb(a[i].fi);
        Sy.pb(a[i].se);
    }
    unique_arr(Sx);
    unique_arr(Sy);
    // unique all value
    for(int i = 1; i <= n; i++){
        a[i].fi = lower_bound(Sx.begin(), Sx.end(), a[i].fi) - Sx.begin();
        a[i].se = lower_bound(Sy.begin(), Sy.end(), a[i].se) - Sy.begin();
    }

    // do fake BIT update and get operator
    for(int i = 1; i <= n; i++){
        fake_get(a[i].fi-1, a[i].se-1);
        fake_update(a[i].fi, a[i].se, (int)Sx.size());
    }

    for(int i = 0; i < Sx.size(); i++){
        fake_bit[i].pb(INT_MIN); // avoid zero
        sort(fake_bit[i].begin(), fake_bit[i].end());
        fake_bit[i].resize(unique(fake_bit[i].begin(), fake_bit[i].end()) - fake_bit[i].begin());
        bit[i].resize((int)fake_bit[i].size(), 0);
    }

    // real update, get operator
    int res = 0;
    for(int i = 1; i <= n; i++){
        int maxCurLen = get(a[i].fi-1, a[i].se-1) + 1;
        res = max(res, maxCurLen);
        update(a[i].fi, a[i].se, (int)Sx.size(), maxCurLen);
    }
    // final answer
    cout << res;
}
