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

const int N = 1e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
string s;
int k, st[4 * N], n, ans = -1, l[N],r[N];
void upd(int pos,int val, int id = 1, int l = 1, int r = n)
{
    if(l > pos || r < pos || l > r)return;
    if(l == r)
    {
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)upd(pos, val, id << 1, l, mid);
    else upd(pos, val, id << 1|1, mid + 1, r);
    st[id] = max(st[id << 1], st[id << 1|1]);
}
int getMax(int u, int v,int id = 1, int l = 1, int r = n)
{
    if(l > r || u > v || r < u || l > v)return 0;
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return max(getMax(u, v, id << 1, l, mid), getMax(u, v, id << 1|1, mid + 1, r));
}
void init(void)
{
    cin >> s;
    n = SZ(s);
    s = " " + s;
    cin >> k;
}
deque<ii>dq;
int id[N];
void process(void)
{
    stack<int>st;
    FOR(i,1,n)
    {
        if(s[i] == '(')
            st.push(i);
        else {
            if(!st.empty())
            {
                int x = getMax(st.top() + 1, i - 1);
                upd(i,x + 1);
                upd(st.top(),x + 1);
                id[i] = id[st.top()] = x + 1;
                if(x + 1 <= k){
                    while(!dq.empty() && dq.back().fi >= st.top() && dq.back().se <= i)dq.pop_back();
                    if(x + 1 == k)maximize(ans, i - st.top() + 1);
                    dq.push_back(ii(st.top(), i));
                }
                st.pop();
            }
        }
    }
    int le = -1, con = 0, sum = 0, fr = 0, ba = 0;
    ll num = 0;
    bool have = 0;
   while(!dq.empty())
    {
        ii i = dq.front();
        if(i.fi == le + 1){
            if(id[i.fi] == k)
            {
                num += 1LL * con * (ba + 1);
                maximize(ans, sum);
            }
            if(id[i.fi] < k)
                    ba++;
            else{
                ba++;
                con += ba;
                have = 1, ba = 0;
            }
            sum += (i.se - i.fi + 1);
        }
        else{
            maximize(ans,sum);
            sum = (i.se - i.fi + 1);
            num += 1LL * con * (ba + 1);
            if(id[i.fi] == k){
                con = 1;
                have = 1;
                ba = 0;
            }
            else{
                have  = 0;
                ba = 1;
                con = 0;
            }
        }
        le = i.se;
        //cout << i.fi << " " << i.se << " " << id[i.fi] << " " << num << " " << con << " " << ba << endl;
        dq.pop_front();
    }
    num += 1LL * con * (ba + 1);
    maximize(ans,sum);
    cout <<num << " ";
    if(num > 0)cout << ans;
    else cout << -1;

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


