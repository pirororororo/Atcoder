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

char grid[2020][2020];
bool teleport_used[30];
bool visited[2020][2020];
vector<vector<pair<int, int>>> alpha_teleport(26);
int main()
{
    int h, w;
    cin >> h >> w;
    int s_h, s_w, g_h, g_w;
    rep(i, h) rep(j, w)
    {
        cin >> grid[i][j];
        if (grid[i][j] == 'S') s_h = i, s_w = j;
        if (grid[i][j] == 'G') g_h = i, g_w = j;
        if ('a' <= grid[i][j] && grid[i][j] <= 'z') alpha_teleport[grid[i][j] - 'a'].push_back({i, j});
    }
    
}