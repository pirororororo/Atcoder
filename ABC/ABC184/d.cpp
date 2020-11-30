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

double dp[110][110][110];
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    dp[a][b][c] = 1;
    for (int i = a; i <= 99; i++)
    {
        for (int j = b; j <= 99; j++)
        {
            for (int k = c; k <= 99; k++)
            {
                dp[i + 1][j][k] += (i / (double)(i + j + k)) * dp[i][j][k];
                dp[i][j + 1][k] += (j / (double)(i + j + k)) * dp[i][j][k];
                dp[i][j][k + 1] += (k / (double)(i + j + k)) * dp[i][j][k];

            }
        }
    }
    double ans = 0;
    for (int j = b; j <= 99; j++)
    {
        for (int k = c; k <= 99; k++)
        {
            ans += dp[100][j][k] * (100 + j + k - a- b - c);
        }
    }
    for (int j = a; j <= 99; j++)
    {
        for (int k = c; k <= 99; k++)
        {
            ans += dp[j][100][k] * (100 + j + k - a- b - c);
        }
    }
    for (int j = a; j <= 99; j++)
    {
        for (int k = b; k <= 99; k++)
        {
            ans += dp[j][k][100] * (100 + j + k - a- b - c);
        }
    }
    cout <<fixed << setprecision(10) <<  ans << endl;

}