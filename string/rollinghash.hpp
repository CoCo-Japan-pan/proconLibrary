#pragma once

#ifdef NOBUNDLE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#endif

struct rolhash_mod {
   public:
    // [2, MOD - 2]のbaseを乱数として生成
    static ll genBase() {
        random_device seed;     // 非決定的な乱数
        mt19937_64 mt(seed());  // メルセンヌ・ツイスタ 64bit
        uniform_int_distribution<ll> randbase(2LL, MOD - 2);
        return randbase(mt);
    }
    // べき乗のmod(tableを用意せずその場でやってるのでlog(beki)かかる)
    constexpr static ll power(ll base, ll beki) {
        rolhash_mod curbekiMod(base);
        rolhash_mod ret(1);
        while(beki > 0) {
            if(beki & 1) ret *= curbekiMod;
            curbekiMod *= curbekiMod;
            beki >>= 1;
        }
        return ret.val();
    }

    constexpr rolhash_mod(ll x = 0) : value(calcMod(x)) {}

    constexpr ll val() const { return value; }

    constexpr rolhash_mod &operator+=(const rolhash_mod &a) {
        if((value += a.value) >= MOD) value -= MOD;
        return *this;
    }
    constexpr rolhash_mod &operator-=(const rolhash_mod &a) {
        *this += (MOD - a.value);
        return *this;
    }
    constexpr rolhash_mod &operator*=(const rolhash_mod &a) {
        __int128_t product = (__int128_t)value * a.value;
        product = (product >> 61) + (product & MOD);
        if(product >= MOD) product -= MOD;
        value = product;
        return *this;
    }
    constexpr rolhash_mod operator+(const rolhash_mod &a) const {
        rolhash_mod cpy(*this);
        return cpy += a;
    }
    constexpr rolhash_mod operator-(const rolhash_mod &a) const {
        rolhash_mod cpy(*this);
        return cpy -= a;
    }
    constexpr rolhash_mod operator*(const rolhash_mod &a) const {
        rolhash_mod cpy(*this);
        return cpy *= a;
    }
    constexpr bool operator==(const rolhash_mod &a) { return value == a.value; }

   private:
    ll value;  // 中で保持しておくmod
    constexpr static ll MOD = (1LL << 61) - 1;
    constexpr static ll calcMod(const ll &x) {
        ll cur = x >> 61;
        if((cur += (x & MOD)) >= MOD) cur -= MOD;
        return cur;
    }
};

// 部分文字列[l,r)のhash値を返すqueryを定数時間で
struct rolhash {
   public:
    template <class T>
    rolhash(const vector<T> &input) {
        base = rolhash_mod::genBase();
        N = input.size();
        basebeki_table.resize(N + 1);
        basebeki_table[0] = 1;
        for(int i = 1; i <= N; i++) {
            basebeki_table[i] = basebeki_table[i - 1] * base;
        }
        front_table.resize(N + 1);
        for(int i = 1; i <= N; i++) {
            front_table[i] = front_table[i - 1] * base + input[i - 1];
        }
    }

    // 部分列[l,r)のhash値を返す
    rolhash_mod query(int l, int r) const { return (front_table[r] - front_table[l] * basebeki_table[r - l]); }

    // baseのbeki乗を返す
    rolhash_mod get_basebeki(int beki) const { return basebeki_table[beki]; }  // queryで足りないとき用

    // 部分列[0,i)のhash値を返す
    rolhash_mod get_front(int i) const { return front_table[i]; }  // queryで足りないとき用

   private:
    constexpr static ll MOD = (1LL << 61) - 1;
    const ll base;
    const int N;
    // baseの0乗からN乗を記録
    vector<rolhash_mod> basebeki_table;
    // [0,i)の部分列のhash値を記録
    vector<rolhash_mod> front_table;
};