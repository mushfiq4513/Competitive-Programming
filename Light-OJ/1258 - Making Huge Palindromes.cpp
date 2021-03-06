#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

vector<int> pi (MAX);

void prefix_function (string P) {
    int now;
    pi[0] = now = -1;
    int n = (int) P.length();
    for (int i=1; i<n; ++i) {
        while (now > -1 && P[i] != P[now+1]) {
            now = pi[now];
        }
        if (P[i] == P[now+1]) ++now;
        else now = -1;
        pi[i] = now;
    }
}

int kmp (string T, string P) {
    int now = -1;
    int n = (int) T.length();
    for (int i=0; i<n; ++i) {
        while (now > -1 && T[i] != P[now+1]) {
            now = pi[now];
        }
        if (T[i] == P[now+1]) ++now;
        else now = -1;
    }
    return n + (n - now - 1);
}

int main() {
    int t;
    string s;

    scanf("%d", &t);
    for (int cs=1; cs<=t; ++cs) {
        cin >> s;
        string p = s;
        reverse (p.begin(), p.end());
        prefix_function (p);
        printf("Case %d: %d\n", cs, kmp (s, p));
    }

    return 0;
}
