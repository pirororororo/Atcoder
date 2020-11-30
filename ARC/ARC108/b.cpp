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
    cin >> n;
    string s;
    cin >> s;
    vector<char> v;
    int ans = 0;
    rep(i, n)
    {
        if (s[i] == 'f')v.push_back(s[i]);
        else if (s[i] == 'o')v.push_back(s[i]);
        else if (s[i] == 'x')
        {
            if (v.size()  >= 2 && v[v.size() - 2] == 'f' && v[v.size() - 1] == 'o' )
            {
                ans++;
                v.pop_back();
                v.pop_back();
            }
            else v.clear();
        }
        else
        {
            v.clear();
        }
        
    }
    cout << n - 3 * ans << endl;
}