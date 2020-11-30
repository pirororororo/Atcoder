#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
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

const int MAX = 1000000;
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> node(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    bool check[n + 1];
    fill(check, check + n + 1, false);
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    check[1] = true;

    while (!q.empty())
    {
        int n = q.top();
        q.pop();
        if (n > 1) cout << " ";
        cout << n;

        for (auto v : node[n])
        {
            if (!check[v])
            {
                q.push(v);
                check[v] = true;
            }
        }
    }
    cout << endl;
}
