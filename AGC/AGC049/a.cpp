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
    int n;
    string s, t;
    cin >> n >> s>> t;

    int s_1 = 0, t_1 = 0;
    rep(i, n)
    {
        if (s[i] == '1')s_1++;
        if (t[i] == '1') t_1++;
    }
    
}