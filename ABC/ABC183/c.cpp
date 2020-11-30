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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> t(n, vector<ll>(n));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> t[i][j];
        }
    }

    int p[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    ll ans = 0;
    do
    {
        ll dis = 0;
        for (int i = 0; i < n - 1; i++)
        {
            dis += t[p[i]][p[i + 1]];
        }
        dis += t[p[n - 1]][p[0]];
        if (dis == k) ans++;
    }while(next_permutation(p + 1, p + n));
    cout << ans << endl;
}
