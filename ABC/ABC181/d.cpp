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

int main()
{
    string s;
    cin >> s;
    map<char, int> ans;
    if(s.size() == 1)
    {
        if(s[0] == '8') cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if (s.size() == 2)
    {
        for (int j = 0; j < s.size(); j++)
    {
        ans[s[j]]++;
    }
        for (int i = 16; i <= 92; i+= 8)
        {
            int k = i;
            char a = (char)(k % 10 + '0');
            k /= 10;
            char b = (char)(k % 10 + '0');
            map<char, int>copy(ans);
            copy[a]--, copy[b]--;
            bool flag = true;
            for (auto j : copy)
            {
                if (j.second < 0) flag = false;
            }
            if(flag)
            {
                cout << "Yes" << endl;
                return 0;
            }
    }
    cout << "No" << endl;
    }
    else if(s.size() >= 3)
    {
    for (int j = 0; j < s.size(); j++)
    {
        ans[s[j]]++;
    }
        for (int i = 8; i <= 992; i+= 8)
        {
            int k = i;
            char a = (char)(k % 10 + '0');
            k /= 10;
            char b = (char)(k % 10 + '0');
            k /= 10;
            char c = (char)(k % 10 + '0');
            map<char, int>copy(ans);
            copy[a]--, copy[b]--, copy[c]--;
            bool flag = true;
            for (auto j : copy)
            {
                if (j.second < 0) flag = false;
            }
            if(flag)
            {
                cout << "Yes" << endl;
                return 0;
            }
    }
    cout << "No" << endl;
    }
    }

