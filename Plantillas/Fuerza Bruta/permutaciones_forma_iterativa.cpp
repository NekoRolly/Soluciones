#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 2e5 + 4;

void solve(){
    string s;
    cin >> s;

    set<string> st;
    sort(s.begin(), s.end());

    do{
        st.insert(s);
    } while (next_permutation(s.begin(), s.end())); // O(n!)

    cout << st.size() << '\n';

    for (string s : st)
        cout << s << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kou = 1;
    // cin >> kou;

    while (kou--)
        solve();

    return 0;
}