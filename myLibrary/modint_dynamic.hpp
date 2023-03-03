#pragma once

#include <bits/stdc++.h>
#include "myLibrary/innermath_modint.hpp"

struct modint_dynamic {
    using ll = long long;

   private:
    ll value;
    static innermath_modint::barretReduction &get_bt() {
        static innermath_modint::barretReduction bt(1);
        return bt;
    }

   public:
    modint_dynamic(ll x = 0) noexcept : value(x % get_mod()) {
        if(value < 0) value += get_mod();
    }
    static void set_mod(int mod) noexcept {
        assert(1 <= mod);
        get_bt() = innermath_modint::barretReduction((uint)mod);
    }
    static int get_mod() noexcept { return (int)(get_bt().get_mod()); }
    ll val() const noexcept { return value; }
    modint_dynamic operator-() const noexcept {
        return modint_dynamic(-value);
    }
    modint_dynamic& operator++() noexcept {
        ++value;
        if(value == get_mod()) value = 0;
        return *this;
    }
    modint_dynamic& operator--() noexcept {
        if(value == 0) value = get_mod();
        --value;
        return *this;
    }
    modint_dynamic operator++(int) noexcept {
        modint_dynamic cpy(*this);
        ++(*this);
        return cpy;
    }
    modint_dynamic operator--(int) noexcept {
        modint_dynamic cpy(*this);
        --(*this);
        return cpy;
    }
    modint_dynamic& operator+=(const modint_dynamic &rhs) noexcept {
        value += rhs.value;
        if(value >= get_mod()) value -= get_mod();
        return *this;
    }
    modint_dynamic& operator-=(const modint_dynamic &rhs) noexcept {
        value += (get_mod() - rhs.value);
        if(value >= get_mod()) value -= get_mod();
        return *this;
    }
    modint_dynamic& operator*=(const modint_dynamic &rhs) noexcept {
        // barret reduction でコンパイラの代わりに定数倍高速化
        value = get_bt().mul(value, rhs.value);
        return *this;
    }
    modint_dynamic operator+(const modint_dynamic &rhs) const noexcept {
        modint_dynamic cpy(*this);
        return cpy += rhs;
    }
    modint_dynamic operator-(const modint_dynamic &rhs) const noexcept {
        modint_dynamic cpy(*this);
        return cpy -= rhs;
    }
    modint_dynamic operator*(const modint_dynamic &rhs) const noexcept {
        modint_dynamic cpy(*this);
        return cpy *= rhs;
    }
    modint_dynamic pow(ll beki) {
        modint_dynamic curbekimod(*this);
        modint_dynamic ret(1);
        while(beki > 0) {
            if(beki & 1) ret *= curbekimod;
            curbekimod *= curbekimod;
            beki >>= 1;
        }
        return ret;
    }

    // valueの逆元を求める
    modint_dynamic inv() const noexcept {
        // 拡張ユークリッドの互除法
        auto [gcd_value_mod, inv_value] =
            innermath_modint::inv_gcd(value, get_mod());
        assert(gcd_value_mod == 1);
        return modint_dynamic(inv_value);
    }
    modint_dynamic& operator/=(const modint_dynamic &rhs) noexcept {
        return (*this) *= rhs.inv();
    }
    modint_dynamic operator/(const modint_dynamic &rhs) const noexcept {
        modint_dynamic cpy(*this);
        return cpy /= rhs;
    }
};