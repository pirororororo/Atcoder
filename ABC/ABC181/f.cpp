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

const ll mod = 998244353;
const int INF = 100000000;
const double PI = acos(-1);
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
    int n; cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            v.emplace_back(dist, i, j);
        }
        v.emplace_back((100 - y[i]) * (100 - y[i]), i, n);
        v.emplace_back((100 + y[i]) * (100 + y[i]), i, n + 1);
    }
    sort(v.begin(), v.end());
    UnionFind uf(n + 2);
    int ans = 0;
    for(auto it : v)
    {
        auto d = get<0>(it);
        auto i = get<1>(it);
        auto j = get<2>(it);
        uf.unite(i, j);
        if(uf.issame(n, n + 1))
        {
            double r = sqrt(d) / 2.0;
            printf("%.10f", r);
            return 0;
        }
        ans = d;
    }
}