#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vv = vector<vi>;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

const ll mod = 1000000007;
const int INF = 100000000;
const double PI = acos(-1);

ll gcd(ll p, ll q)
{
    if (p % q == 0) return q;
    else return gcd(q, p % q);
}
ll lcm(ll p, ll q)
{
    ll r = gcd(p, q);
    return ((p / r) * q);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = -1;
    for (int i = 2; i <= 1000; i++)
    {
        int cnt = 0;
        rep(j, n)
        {
            if (a[j] % i == 0)cnt++;
        }
        ans = max(ans, cnt);
    }
    for (int i = 2; i <= 1000; i++)
    {
        int cnt = 0;
        rep(j, n)
        {
            if (a[j] % i == 0)cnt++;
        }
        if (ans == cnt)
        {
            cout << i << endl;
            return 0;
        }
    }
}