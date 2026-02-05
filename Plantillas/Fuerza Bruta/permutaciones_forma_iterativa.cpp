#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// F de fuerza bruta y recursión.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // ordenar a la permutación lexicograficamente menor
    sort(s.begin(), s.end());

    vector<string> vec;
    do{
        // cout << s << "\n";        
        vec.push_back(s);
    } while(next_permutation(s.begin(), s.end()));

    cout << vec.size() << "\n";
    for (string s : vec)
        cout << s << "\n";
    // cout << "\n";

    return 0;
}