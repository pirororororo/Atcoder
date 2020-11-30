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
const ll INF = 100000000000000;
const double PI = acos(-1);

using Graph = vector<vector<int>>;

int main()
{
    int n, k;
    cin >> n >> k;

    int t[n][k];
    rep(i, n) rep(j, k) cin >> t[i][j];

    bitset<9> bit;
    bool flag  = true;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            for (int c = 0; c < n; c++)
            {
                for (int d = 0; d < n; d++)
                {
                    for (int e = 0; e < n; e++)
                    {
                        bit = t[0][a] + t[1][b] + t[2][c] + t[3][d] +t[4][e];
                        //cout << bit << endl;
                        bool flag2 = true;
                        for (int i = 0; i < 9; i++)
                        {
                            if (bit[i] != 0) flag2 = false;
                        }
                        if (flag2) flag = false;
                    }
                }
            }
        }
    }
    if (flag) cout << "Nothing" << endl;
    else cout << "Found" << endl;
}

