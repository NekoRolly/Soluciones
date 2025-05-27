#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool es_primo(int n){ // O(sqrt(n))
    if (n <= 1) return false;
    for (int i=2; i*i<=n; i++)
        if (n%i == 0)
            return false;
    return true;
}

void criba(int n,bool esPrimo[]){ // O(nloglogn)
    esPrimo[0] = esPrimo[1] = false;
    for (int i=2; i<=n; i++)
        esPrimo[i] = true;
    for (int i=2; i*i<=n; i++)
        if (esPrimo[i]){
            for (int j=i*i; j<=n; j+=i)
                esPrimo[j] = false;
        }
}

typedef pair<int,int> pii;

vector<pii> desc_sqrt(int n){ // O(sqrt(n))
    vector<pii> vec;
    for (int i=2; i*i<=n; i++)
        if (n%i == 0){
            int e = 0;
            while (n%i == 0){
                e++;
                n /= i;
            }
            vec.push_back({i, e});
        }
    if (n > 1)
        vec.push_back({n, 1});
    return vec;
}

vector<int> desc(int n){ // O(sqrt(n))
    vector<int> vec;
    for (int i=1; i*i<=n; i++)
        if (n%i == 0){
            vec.push_back(i);
            if (i != n/i)
                vec.push_back(n/i);
        }
    return vec;
}

void criba_plusplus(int n,int lp[]){ // O(nloglogn)
    for (int i=0; i<=n; i++)
        lp[i] = 0;
    for (int i=2; i<=n; i++)
        if (lp[i] == 0)
            for (int j=i; j<=n; j+=i)
                lp[j] = i;
}

const int N = 1e6+4;
int lp[N];
vector<pii> desc_logn(int n){ // O(logn)
    // criba_plusplus(n, lp);
    vector<pii> vec;
    while (n > 1){
        int p = lp[n];
        int e = 0;
        while (n%p == 0){
            n /= p;
            e++;
        }
        vec.push_back({p, e});
    }
    return vec;
}

int mcd(int a,int b){ // O(log(min(a, b))))
    return __gcd(a, b);
}

const int mod = 1e9+7;
int S(int a,int b){ // O(1)
    return (a+b)%mod;
}

int P(int a,int b){
    return 1ll*a*b%mod;
}

int bin_pow_rec(int a,int b){ // O(logb)
    if (b == 0) return 1;
    int x = bin_pow_rec(a, b/2);
    x = P(x, x);
    if (b%2 == 1) return P(a, x);
    else return x;
}

int bin_pow_it(int a,int b){ // O(logb)
    int ans = 1;
    while (b > 0){
        if (b%2 == 1)
            ans = P(ans, a);
        a = P(a, a);
        b /= 2;
    }
    return ans;
}

int inv(int b){ // O(logb)
    return bin_pow_it(b, mod-2);
}

int fac[N];

void get_fac(int n){ // O(n)
    fac[0] = 1;
    for (int i=1; i<=n; i++)
        fac[i] = P(fac[i], i);
}

int Comb(int a,int b){ // O(logn)
    if (a < 0 || b < 0 || a < b)
        return 0;
    else return P(fac[a], inv(P(fac[a-b], fac[b])));
}

int Ifac[N];
void get_fac_plusplus(int n){// O(n + logn)
    fac[0] = 1;
    for (int i=1; i<=n; i++)
        fac[i] = P(fac[i], i);
    Ifac[n] = inv(fac[n]);
    for (int i=n-1; i>=0; i--)
        Ifac[i] = P(Ifac[i+1], i+1);
}

int Comb_plusplus(int a,int b){ // O(1)
    if (a < 0 || b < 0 || a < b)
        return 0;
    else return P(fac[a], P(Ifac[a-b], Ifac[b]));
}

const int M = 2e3+4;
int comb[M][M];
void get_comb(int n){ // O(n^2)
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            comb[i][j] = (j == 0);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=i; j++)
            comb[i][j] = S(comb[i-1][j], comb[i-1][j-1]);
}

void unknown(int n){ // O(Nlogn)
    int ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j+=i)
            ans++;
}

int mcm(int a,int b){ // O(logn)
    return 1ll*a*b/mcd(a, b);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}