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
bool  visited[2020][2020];
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
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, s_h, s_w});
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1,  0, 0};
    while (pq.size())
    {
        int dist, x, y;
        tie(dist, x, y) = pq.top();
        pq.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        if (x == g_h && y == g_w)
        {
            cout << dist << endl;
            return (0);
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x +  dx[i] >= h) continue;
            if (y + dy[i] < 0 || y + dy[i] >= w) continue;
            if (grid[x + dx[i]][y + dy[i]]) continue;
            pq.push({dist + 1, x + dx[i], y + dy[i]});
        }
        if ('a' <= grid[x][y] && grid[x][y] <= 'z' && !teleport_used[grid[x][y] - 'a'])
        {
            for (auto teleport : alpha_teleport[grid[x][y] - 'a'])
            {
                if (visited[teleport.first][teleport.second]) continue;
                pq.push({dist + 1, teleport.first, teleport.second});
            }
            teleport_used[grid[x][y] - 'a'] = true;
        }
    }
    
    cout << -1 << endl;
    return 0;
}