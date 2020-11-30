#include <bits/stdc++.h>

#define rep(i, n) for(ll i = 0; i < (n); i++)
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
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    priority_queue<ll> pq;
    rep(i, n) pq.push(a[i]);
    rep(i, m)
    {
        ll a = pq.top();
        pq.pop();
        a /= 2;
        pq.push(a);
    }
    ll ans = 0;
    rep(i, n)
    {
        int a = pq.top();
        pq.pop();
        ans += a;
    }
    cout << ans << endl;
}
