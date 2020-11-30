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

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> x(n), y(n);

	UnionFind uf(n);
	rep(i, n)
	{
		cin >> x[i].first >> y[i].first;
		x[i].second = y[i].second = i;
	}
	sort(x.begin(), x.end()), sort(y.begin(), y.end());
	vector<pair<int, pair<int, int>>> cost(0);
	rep(i, n - 1)
	{
		int money = abs(x[i].first - x[i + 1].first);
		int x1 = x[i].second;
		int x2 = x[i + 1].second;
		cost.push_back({money,pair<int, int>(x1, x2)});
	}
	rep(i, n - 1)
	{
		int money = abs(y[i].first - y[i + 1].first);
		int y1 = y[i].second;
		int y2 = y[i + 1].second;
		cost.push_back({money,{y1,y2}});
	}
	sort(cost.begin(), cost.end());
	ll ans = 0;
	rep(i, cost.size())
	{
		pair<int, int> kuni = cost[i].second;
		int x1 = kuni.first;
		int x2 = kuni.second;
		ll tmp = cost[i].first;
		//cout << x1 << x2 << tmp << endl;
		if (uf.issame(x1, x2)) continue;
		else
		{
			uf.unite(x1, x2);
			ans += tmp;
		}
	}
	cout << ans << endl;
}
