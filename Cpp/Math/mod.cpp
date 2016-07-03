/*
 * Created by KeigoOgawa
 * Factorial, Extgcd, Mod
 */



#include "../myHeahder.h"

const int MOD = 1e9 + 7;
const int MAX_P = 100;

// n! mod p のテーブル O(p)
ll fact[MAX_P];

void init_fact() {
    fact[0] = 1;
    FOR(i, 1, MAX_P) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// ax + by = gcd(a, b)を返す
// x, yは整数解になっている
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

// ax ≡ 1(mod m) となるxを返す
ll mod_inverse(ll a, ll m) {
    ll x, y;
    // x, yがax + my = 1 の解になっている
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

// n! = a*p^e としたときの a mod p, e を求める. O(log_p n)
// e = (n!の中にあるpの数) => n!からpを取り出した残りがa, つまり,
// a = (pで割り切れないものの積) * (pで割り切れるものをpで割った商)
// よって, (n! mod p) = (a mod p) となる
ll mod_fact(ll n, ll p, ll &e) {
    e = 0;
    if (n == 0) {
        return 1;
    }

    // pの倍数の部分を計算
    ll res = mod_fact(n / p, p, e);
    e += n / p;

    // (p-1)! ≡ -1 より (p-1)!^(n/p)は n/p の偶奇だけで計算できる
    if (n / p % 2 != 0) {
        return res * (p - fact[n % p] % p);
    }
    return res * fact[n % p] % p;
}

ll mod_comb(ll n, ll k, ll p) {
    if (n < 0 || k < 0 || n < k) {
        return 0;
    }
    ll e1, e2, e3;
    ll a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);

    if (e1 > e2 + e3) {
        return 0;
    }
    return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

// 桁Mod
int digitsMod(string s, int m) {
  int s_mod_m = 0;
  REP(i, (int)s.size()) {
    s_mod_m = (s_mod_m * 10 + s[i] - '0') % m;
  }
  return s_mod_m;
}
