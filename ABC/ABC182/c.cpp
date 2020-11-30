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
    string n;
    cin >> n;
    vector<int> s(3, 0);
    rep(i, n.size())
    {
        int a = (n[i] - '0') % 3;
        s[a]++;
    }
    int sum = 0;
    rep(i, n.size())
    {
        sum += (n[i] - '0');
    }
    sum %= 3;
    if (sum == 0) cout << 0 << endl;
    else if (sum == 1)
    {
        if (s[1] >= 1 && n.size() > 1) cout << 1 << endl;
        else if (s[2] >= 2 && n.size() > 2) cout << 2 << endl;
        else cout << -1 << endl;
    }
    else if (sum == 2)
    {
        if (s[2] >= 1 && n.size() > 1) cout << 1 << endl;
        else if (s[1] >= 2 && n.size() > 2) cout << 2 << endl;
        else cout << -1 << endl;
    }
}