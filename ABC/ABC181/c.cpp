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
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    ll ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int a = x[j] - x[i];
                int b = y[j] - y[i];
                int c = x[k] - x[j];
                int d = y[k] - y[j];

                if (a * d - b * c == 0)ans++;
            }
        }
    }
    if(ans > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}