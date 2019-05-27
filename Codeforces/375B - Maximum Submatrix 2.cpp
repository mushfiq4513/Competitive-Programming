#include<bits/stdc++.h>
using namespace std;

const int MAX = 5001;

string s[MAX];
vector<int> mat[MAX];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; ++i) {
        cin >> s[i];
        int Count[m+1] = {};
        for (int j=0; j < m; ++j) {
            if (!j)
                Count[j] = s[i][j] - '0';
            else
                Count[j] = s[i][j-1]=='1' && s[i][j]=='1' ? Count[j-1]+1 : s[i][j]-'0';
            if (Count[j])
                mat[j].push_back(Count[j]);
        }
    }

    int ans = 0;
    for (int i=0; i<m; ++i) {
        sort (mat[i].begin(), mat[i].end());
        for (int j=0, sz=mat[i].size(); j < sz; ++j)
            ans = max ((sz-j) * mat[i][j], ans);
    }

    cout << ans << endl;

    return 0;
}
