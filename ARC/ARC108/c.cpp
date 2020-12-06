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
    string s;
    cin >> s;
    rep(i, s.size())
    {
        if (s[i] == ' ')
        {
            if (s[i + 1] != ' ')
            {
                cout << ',';
            }
        }
        else
        {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}
