#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vv = vector<vi>;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

const ll mod = 1000000007;
const int INF = 100000000;
const double PI = acos(-1);

int main()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> s(n), t(n), p(n);
    rep(i, n) cin>> s[i] >> t[i] >> p[i];

    vector<ll> v(1e6, 0);
    rep(i, n)
    {
        v[s[i]] += p[i];
        v[t[i]] -= p[i];
    }
    for (int i = 0; i < 1e6 - 1; i++)
    {
        v[i + 1] += v[i];
    }
    bool flag = true;
    rep(i, 1e6)
    {
        if (v[i] > w)flag = false;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}