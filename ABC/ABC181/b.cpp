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

const ll mod = 998244353;
const int INF = 100000000;
const double PI = acos(-1);


int main()
{
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (a[i] + b[i]) * (b[i] - a[i] + 1) / 2;
    }
    cout << ans << endl;
}