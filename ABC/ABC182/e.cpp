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
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<int> a(n), b(n);
    vector<vector<int>> board(h, vector<int>(w, 0));

    rep(i, n)
    {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    rep(i, m)
    {
        int c, d;
        cin >> c >>d ;
        c--, d--;
        board[c][d] = -1;
    }
    rep(k, n)
    {
        int j = b[k];
        for (int i = a[k]; i < h; i++)
        {
            if (board[i][j] == 1 || board[i][j] == -1) break;
            board[i][j] = 1;
        }
        for (int i = a[k] - 1; i >= 0; i--)
        {
            if (board[i][j] == 1 || board[i][j] == -1) break;
            board[i][j] = 1;
        }
    }
    rep(k, n)
    {
        int i = a[k];
        for (int j = b[k]; j < w; j++)
        {
            if (board[i][j] == 2 || board[i][j] == -1) break;
            board[i][j] = 2;
        }
        for (int j = b[k] - 1; j >= 0; j--)
        {
            if (board[i][j] == 2 || board[i][j] == -1) break;
            board[i][j] = 2;
        }
    }
    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if (board[i][j] == 1 || board[i][j] == 2) ans++;
        }
    }
    cout << ans << endl;
}