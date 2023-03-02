#pragma once

#include<bits/stdc++.h>
#include "myLibrary/innermath_modint.hpp"

template <const int MOD>
struct modint_static {
    using ll = long long;

   public:
    constexpr modint_static(ll x = 0) noexcept : value(x % MOD) {
        if (value < 0) value += MOD;
    }
    constexpr int get_mod() const noexcept { return MOD; }
    constexpr ll val() const noexcept { return value; }
    constexpr modint_static operator-() const noexcept {
        return modint_static(-value);
    }
    constexpr modint_static& operator++() noexcept {
        ++value;
        if(value == MOD) value = 0;
        return *this;
    }
    constexpr modint_static& operator--() noexcept {
        if(value == 0) value = MOD;
        --value;
        return *this;
    }
    constexpr modint_static operator++(int) noexcept {
        modint_static cpy(*this);
        ++(*this);
        return cpy;
    }
    constexpr modint_static operator--(int) noexcept {
        modint_static cpy(*this);
        --(*this);
        return cpy;
    }
    constexpr modint_static& operator+=(const modint_static& rhs) noexcept {
        value += rhs.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    constexpr modint_static& operator-=(const modint_static& rhs) noexcept {
        value += (MOD - rhs.value);
        if (value >= MOD) value -= MOD;
        return *this;
    }
    constexpr modint_static& operator*=(const modint_static& rhs) noexcept {
        (value *= rhs.value) %= MOD; // 定数だとコンパイラ最適化がかかる
        return *this;
    }
    constexpr modint_static operator+(const modint_static& rhs) const noexcept {
        modint_static cpy(*this);
        return cpy += rhs;
    }
    constexpr modint_static operator-(const modint_static& rhs) const noexcept {
        modint_static cpy(*this);
        return cpy -= rhs;
    }
    constexpr modint_static operator*(const modint_static& rhs) const noexcept {
        modint_static cpy(*this);
        return cpy *= rhs;
    }
    constexpr modint_static pow(ll beki) const noexcept {
        modint_static curbekimod(*this);
        modint_static ret(1);
        while (beki > 0) {
            if (beki & 1) ret *= curbekimod;
            curbekimod *= curbekimod;
            beki >>= 1;
        }
        return ret;
    }

    // valueの逆元を求める
    constexpr modint_static inv() const noexcept {
        // 拡張ユークリッドの互除法
        auto [gcd_value_mod, inv_value] = innermath_modint::inv_gcd(value, MOD);
        assert(gcd_value_mod == 1);
        return modint_static(inv_value);
    }
    constexpr modint_static& operator/=(const modint_static& rhs) noexcept {
        return (*this) *= rhs.inv();
    }
    constexpr modint_static operator/(const modint_static& rhs) const noexcept {
        modint_static cpy(*this);
        return cpy /= rhs;
    }

   private:
    ll value;
};

using mint998244353 = modint_static<998244353>;
using mint1000000007 = modint_static<1000000007>;