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

const ll mod = 1e9 + 7;
const int INF = 100000000;
const double PI = acos(-1);

int dp[2000][2000];
int x[2000][2000], y[2000][2000],  z[2000][2000];
string s[2000];
int main()
{
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> s[i];
    dp[0][0] = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 && j == 0) continue;
            if (s[i][j] == '#') continue;
            if (j > 0) x[i][j] = (x[i][j - 1] + dp[i][j - 1]) % mod;
            if (i > 0) y[i][j] = (y[i - 1][j] + dp[i - 1][j]) % mod;
            if (i > 0 && j > 0) z[i][j] = (z[i - 1][j - 1] + dp[i - 1][j - 1]) % mod;
            dp[i][j] = ((ll)x[i][j] + y[i][j] + z[i][j]) % mod;
        }
    }
    cout << dp[h - 1][w - 1] << endl;
}
