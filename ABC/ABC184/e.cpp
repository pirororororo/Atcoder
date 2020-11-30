#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- 配列は+10ぐらい余分にとっておく
- setとmultisetを間違えない
*/

/*
デバッグ時にチェック!
- RE
	配列の取りうる最大値、最小値を**すべて**チェックする
*/

char grid[2020][2020];
bool teleport_used[30]; //最短のマスからのテレポート以外は無意味
bool visited[2020][2020];
vector<vector<pair<int, int>>> alpha_teleport(26);

int	main(void)
{
	int h, w;
	cin >> h >> w;
	int start_h, start_w;
	int goal_h, goal_w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'S') start_h = i, start_w = j;
			if (grid[i][j] == 'G') goal_h = i, goal_w = j;
			if ('a' <= grid[i][j] && grid[i][j] <= 'z') alpha_teleport[grid[i][j] - 'a'].push_back({i, j});
		}
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push({0, start_h, start_w});
	vector<int> dx = {0, 0, 1, -1};
	vector<int> dy = {1, -1, 0, 0};
	while (pq.size())
	{
		int dist, x, y;
		tie(dist, x, y) = pq.top(); pq.pop();
		if (visited[x][y]) continue ;
		visited[x][y] = true;
		if (x == goal_h && y == goal_w)
		{
			cout << dist << endl;
			return (0);
		}
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] < 0 || x + dx[i] >= h) continue ;
			if (y + dy[i] < 0 || y + dy[i] >= w) continue ;
			if (grid[x + dx[i]][y + dy[i]] == '#') continue ;
			if (visited[x + dx[i]][y + dy[i]]) continue ;
			pq.push({dist + 1, x + dx[i], y + dy[i]});
		}
		if ('a' <= grid[x][y] && grid[x][y] <= 'z' && !teleport_used[grid[x][y] - 'a'])
		{
			for (auto teleport: alpha_teleport[grid[x][y] - 'a'])
			{
				if (visited[teleport.first][teleport.second]) continue ;
				pq.push({dist + 1, teleport.first, teleport.second});
			}
			teleport_used[grid[x][y] - 'a'] = true;
		}
	}
	cout << -1 << endl;
	return (0);
}
