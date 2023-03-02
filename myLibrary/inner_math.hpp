#pragma once

#include <bits/stdc++.h>

namespace inner_math {
    using ll = long long;

    // xのmodを[0, mod)で返す
    constexpr ll safe_mod(ll x, ll mod) {
        assert(mod > 0);
        x %= mod;
        if (x < 0) x += mod;
        return x;
    }

    constexpr ll pow_mod_constexpr(ll x, ll n, ll mod) {
        if (mod == 1) return 0;
        ll ret = 1;
        ll beki = safe_mod(x, mod);
        while(n) {
            // LSBから順に見る
            if(n & 1) {
                ret = (ret * beki) % mod;
            }
            beki = (beki * beki) % mod;
            n >>= 1;
        }
        return ret;
    }

    // int型(2^32以下)の高速な素数判定
    constexpr bool is_prime_constexpr(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 7 || n == 61) return true;
        if (n % 2 == 0) return false;
        // ミラーラビン判定 int型ならa={2,7,61}で十分
        constexpr ll bases[] = {2, 7, 61};
        // n-1 = 2^r * d
        ll d = n - 1;
        while(d & 1 == 0) d >>= 1;
        // 素数modは1の平方根として非自明な解を持たない
        // つまり非自明な解がある→合成数
        for(ll a : bases){
            
        }
    }
}