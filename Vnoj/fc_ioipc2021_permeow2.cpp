// Onegai no bug
// Author : 13minusone
#include "permeow2.h"
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
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

const int N = 5e3 + 5;
const int MOD = 1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int dp[N][N];
int count_permutation(vector<int>p)
{
    int n = SZ(p);
    FOR(i,1,n)
        dp[0][i] = 1;
    FOR(i,1,n){
        int maxx = p[i-1], minn = p[i - 1];
        FD(j,i,1){
            maximize(maxx, p[j - 1]);
            minimize(minn, p[j - 1]);
            dp[i][maxx] = (dp[i][maxx]  + dp[j - 1][minn]) % MOD;
        }
        FD(j,n,1){
            //cout << i << " " << j << " " << dp[i][j] << endl;
            dp[i][j] = (dp[i][j] + dp[i][j + 1])%MOD;
        }
    }
    return dp[n][1];
}

