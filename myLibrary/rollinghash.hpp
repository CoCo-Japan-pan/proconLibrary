#pragma once

#include <bits/stdc++.h>

struct rolhash_mod {
    using u128 = __uint128_t;
    using u64 = uint64_t;

   public:
    constexpr rolhash_mod(u64 x = 0) : value(calcMod(x)) {}

    constexpr u64 val() const { return value; }

    constexpr rolhash_mod &operator+=(const rolhash_mod &a) {
        if ((value += a.value) >= MOD) value -= MOD;
        return *this;
    }
    constexpr rolhash_mod &operator-=(const rolhash_mod &a) {
        *this += (MOD - a.value);
        return *this;
    }
    constexpr rolhash_mod &operator*=(const rolhash_mod &a) {
        u128 product = (u128)value * a.value;
        product = (product >> 61) + (product & MOD);
        if (product >= MOD) product -= MOD;
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
    constexpr bool operator==(const rolhash_mod &a) const {
        return value == a.value;
    }

    // べき乗のmod(tableを用意せずその場でやってるのでlog(beki)かかる)
    constexpr static u64 power(u64 base, u64 beki) {
        rolhash_mod curbekiMod(base);
        rolhash_mod ret(1);
        while (beki > 0) {
            if (beki & 1) ret *= curbekiMod;
            curbekiMod *= curbekiMod;
            beki >>= 1;
        }
        return ret.val();
    }

   private:
    u64 value;  // 中で保持しておくmod
    constexpr static u64 MOD = (1ULL << 61) - 1;
    constexpr static u64 calcMod(const u64 &x) {
        u64 cur = x >> 61;
        if ((cur += (x & MOD)) >= MOD) cur -= MOD;
        return cur;
    }
};

// 部分文字列[l,r)のhash値を返すqueryを定数時間で
struct rolhash {
    using u64 = uint64_t;

   public:
    template <class T>
    rolhash(const std::vector<T> &input) : base(genBase()), N(input.size()) {
        basebeki_table.resize(N + 1);
        basebeki_table[0] = 1;
        for (int i = 1; i <= N; i++) {
            basebeki_table[i] = basebeki_table[i - 1] * base;
        }
        front_table.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            front_table[i] = front_table[i - 1] * base + input[i - 1];
        }
    }
    rolhash(const std::string &input_string)
        : rolhash(std::vector<char>(input_string.begin(), input_string.end())) {
    }

    // 部分列[l,r)のhash値を返す l==rのときは0を返す
    rolhash_mod query(int l, int r) const {
        assert(l <= r);
        if (l == r) return rolhash_mod(0);
        return (front_table[r] - front_table[l] * basebeki_table[r - l]);
    }

    // baseのbeki乗を返す
    rolhash_mod get_basebeki(int beki) const {
        return basebeki_table[beki];
    }  // queryで足りないとき用

    // 部分列[0,i)のhash値を返す
    rolhash_mod get_front(int i) const {
        return front_table[i];
    }  // queryで足りないとき用

   private:
    constexpr static u64 MOD = (1ULL << 61) - 1;
    const u64 base;
    const int N;
    // baseの0乗からN乗を記録
    std::vector<rolhash_mod> basebeki_table;
    // [0,i)の部分列のhash値を記録
    std::vector<rolhash_mod> front_table;

    // [2, MOD - 2]のbaseを乱数として生成
    static u64 genBase() {
        auto rand_time =
            std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch())
                .count();               // 非決定的な乱数
        std::mt19937_64 mt(rand_time);  // メルセンヌ・ツイスタ 64bit
        std::uniform_int_distribution<u64> randbase(2ULL, MOD - 2);
        return randbase(mt);
    }
};