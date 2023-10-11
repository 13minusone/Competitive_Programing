///KoJa
#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define vec vector
#define fi first
#define se second
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(n) (1LL << (n))
#define MASK(x, i) (((x) >> (i))&1)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
struct Points
{
    ll x, y;
    Points(){}
    Points(ll _x, ll _y)
    {
        x = _x;
        y = _y;
    }
    Points operator - (const Points &other) const { return Points(x - other.x, y - other.y);}
    ll operator * (const Points &other) const { return x * other.y - y * other.x;}
    ll triangle(const Points &b, const Points &c)
    {
        return (*this - b) * (*this - c);
    }
};
const int N = int(1e4) + 100;
const ll INF = 1e18;
int n;
void init()
{
    cin >> n;
}
char ask1(int i, int j)
{
    cout << "compare " << i << " " << j << '\n';
    char in;
    cin >> in;
    return in;
}
char ask2(int i)
{
    cout << "compare_k " << i << '\n';
    char in;
    cin >> in;
    return in;
}
bool del[N];
void process(int tc = 0)
{
    int ans1 = -1, ans2 = -1;
    for(int i = 1; i <= n; i++)
    {
        if(del[i]) continue;
        char c = ask2(i);
        if(c == '<')
        {
            ans1 = i;
            for(int j = i + 1; j <= n; j++) if(del[j] == 0)
            {
                char c1 = ask1(i, j);
                if(c1 == '>') del[j] = 1;
            }
        }
        else
        {
            ans2 = i;
            for(int j = i + 1; j <= n; j++) if(del[j] == 0)
            {
                char c1 = ask1(i, j);
                if(c1 == '<') del[j] = 1;
            }
        }
    }
    if((ans1 != -1)&&(ans2 != -1)) cout << "answer " << ans1 << " " << ans2;
    else cout << "no_answer";
}

int main()
{
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}
