#pragma once

#include <bits/stdc++.h>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace innermath_modint{
    using ll = long long;
    using ull = unsigned long long;
    using u128 = __uint128_t;

    // xのmodを[0, mod)で返す
    constexpr ll safe_mod(ll x, ll mod) {
        x %= mod;
        if (x < 0) x += mod;
        return x;
    }

    constexpr ll pow_mod_constexpr(ll x, ll n, ll mod) {
        if (mod == 1) return 0;
        ll ret = 1;
        ll beki = safe_mod(x, mod);
        while (n) {
            // LSBから順に見る
            if (n & 1) {
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
        while (d % 2 == 0) d >>= 1;
        // 素数modは1の平方根として非自明な解を持たない
        // つまり非自明な解がある→合成数
        for (ll a : bases) {
            ll t = d;
            ll y = pow_mod_constexpr(a, t, n);
            // yが1またはn-1になれば抜ける
            while (t != n - 1 && y != 1 && y != n - 1) {
                y = (y * y) % n;
                t <<= 1;
            }
            // 1の平方根として1と-1以外の解(非自明な解)が存在
            if (y != n - 1 && t % 2 == 0) {
                return false;
            }
        }
        return true;
    }

    // 拡張ユークリッドの互除法 g = gcd(a,b)と、ax = g (mod b)なる0 <= x <
    // b/gのペアを返す
    constexpr std::pair<ll, ll> inv_gcd(ll a, ll b) {
        a = safe_mod(a, b);
        // aがbの倍数
        if (a == 0) return {b, 0};
        // 以下 0 <= a < b
        // [1] s - m0 * a = 0 (mod b)
        // [2] t - m1 * a = 0 (mod b)
        // [3] s * |m1| + t * |m0| <= b
        ll s = b, t = a;
        ll m0 = 0, m1 = 1;
        while (t) {
            // s → s mod t
            // m0 → m0 - m1 * (s / t)
            ll u = s / t;
            s -= t * u;
            m0 -= m1 * u;
            std::swap(s, t);
            std::swap(m0, m1);
        }
        // s = gcd(a, b)
        // 終了の直前のステップにおいて
        // [1] k * s - m0 * a = 0 (mod b)
        // [2] s - m1 * a = 0 (mod b)
        // [3] (k * s) * |m1| + s * |m0| <= b
        // |m0| < b / s
        if (m0 < 0) m0 += b / s;
        return {s, m0};
    }

    // barret reduction 掛け算のmodの定数倍高速化(modが定数でない場合に使用)
    struct barretReduction {
       public:
        explicit barretReduction(uint _mod)
            : mod(_mod),
              imod((ull)(-1) / mod + 1) {}  // unsignedの場合、負で巡回する

        uint get_mod() const { return mod; }

        uint mul(int a, int b) const {
            ull z = a;
            z *= b;
#ifdef _MSC_VER
            ull x;
            _umul128(z, im, &x)
#else
            // x = z / mod またはその +1
            // 割り算をビットシフトにすることで高速化
            ull x = (ull)(((u128)z * imod) >> 64);
#endif
                // z - x * mod = z % mod - mod の場合、uintなので 2^32 - (mod -
                // z % mod) つまりmodを足せば 2^32 + z %
                // modとなり、求めるmodになる
                uint v = (uint)(z - x * mod);
            if (v >= mod) v += mod;
            return v;
        }

       private:
        uint mod;
        ull imod;  // ceil(2^64 / mod)
    };
}