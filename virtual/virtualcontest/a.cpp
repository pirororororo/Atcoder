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
    int x;
    cin >> x;
    int ng = -1;
    int ok = 1000000;

    while (ok - ng > 1)
    {
        int m = (ng + ok) / 2;
        if (m >= x) ok = m;
        else ng = m;
    }
    cout << ok << endl;
}

