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
    vector<ll> a(n + 10);
    rep(i, n) cin >> a[i];

    vector<ll> sum(n+ 1, 0);
    rep(i, n) sum[i + 1] = sum[i] + a[i];
    //for (int i = 1; i <= 5; i++) cout << sum[i] << endl;
    vector<ll> sum_max(n + 1, 0);
    rep(i, n)
    {
        sum_max[i + 1] = max(sum[i + 1], sum_max[i]);
    }
    //for (int i = 1; i <= 5; i++) cout << sum_max[i] << endl;
    ll ans = 0;
    vector<ll> sum2(n + 1, 0);
    rep(i, n) sum2[i + 1] = sum2[i] + sum[i + 1];
    for (int i = 1; i <= n; i++)
    {
        //cout << sum2[i] << endl;
        ans = max(ans, sum2[i - 1] + sum_max[i]);
    }
    cout << ans << endl;
}