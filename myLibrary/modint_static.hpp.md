---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: myLibrary/innermath_modint.hpp
    title: myLibrary/innermath_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"myLibrary/modint_static.hpp\"\n\n#include<bits/stdc++.h>\n\
    #line 2 \"myLibrary/innermath_modint.hpp\"\n\n#line 4 \"myLibrary/innermath_modint.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace innermath_modint{\n\
    \    using ll = long long;\n    using ull = unsigned long long;\n    using u128\
    \ = __uint128_t;\n\n    // x\u306Emod\u3092[0, mod)\u3067\u8FD4\u3059\n    constexpr\
    \ ll safe_mod(ll x, ll mod) {\n        x %= mod;\n        if (x < 0) x += mod;\n\
    \        return x;\n    }\n\n    constexpr ll pow_mod_constexpr(ll x, ll n, ll\
    \ mod) {\n        if (mod == 1) return 0;\n        ll ret = 1;\n        ll beki\
    \ = safe_mod(x, mod);\n        while (n) {\n            // LSB\u304B\u3089\u9806\
    \u306B\u898B\u308B\n            if (n & 1) {\n                ret = (ret * beki)\
    \ % mod;\n            }\n            beki = (beki * beki) % mod;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    // int\u578B(2^32\u4EE5\
    \u4E0B)\u306E\u9AD8\u901F\u306A\u7D20\u6570\u5224\u5B9A\n    constexpr bool is_prime_constexpr(int\
    \ n) {\n        if (n <= 1) return false;\n        if (n == 2 || n == 7 || n ==\
    \ 61) return true;\n        if (n % 2 == 0) return false;\n        // \u30DF\u30E9\
    \u30FC\u30E9\u30D3\u30F3\u5224\u5B9A int\u578B\u306A\u3089a={2,7,61}\u3067\u5341\
    \u5206\n        constexpr ll bases[] = {2, 7, 61};\n        // n-1 = 2^r * d\n\
    \        ll d = n - 1;\n        while (d % 2 == 0) d >>= 1;\n        // \u7D20\
    \u6570mod\u306F1\u306E\u5E73\u65B9\u6839\u3068\u3057\u3066\u975E\u81EA\u660E\u306A\
    \u89E3\u3092\u6301\u305F\u306A\u3044\n        // \u3064\u307E\u308A\u975E\u81EA\
    \u660E\u306A\u89E3\u304C\u3042\u308B\u2192\u5408\u6210\u6570\n        for (ll\
    \ a : bases) {\n            ll t = d;\n            ll y = pow_mod_constexpr(a,\
    \ t, n);\n            // y\u304C1\u307E\u305F\u306Fn-1\u306B\u306A\u308C\u3070\
    \u629C\u3051\u308B\n            while (t != n - 1 && y != 1 && y != n - 1) {\n\
    \                y = (y * y) % n;\n                t <<= 1;\n            }\n \
    \           // 1\u306E\u5E73\u65B9\u6839\u3068\u3057\u30661\u3068-1\u4EE5\u5916\
    \u306E\u89E3(\u975E\u81EA\u660E\u306A\u89E3)\u304C\u5B58\u5728\n            if\
    \ (y != n - 1 && t % 2 == 0) {\n                return false;\n            }\n\
    \        }\n        return true;\n    }\n\n    // \u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5 g = gcd(a,b)\u3068\u3001ax = g (mod\
    \ b)\u306A\u308B0 <= x <\n    // b/g\u306E\u30DA\u30A2\u3092\u8FD4\u3059\n   \
    \ constexpr std::pair<ll, ll> inv_gcd(ll a, ll b) {\n        a = safe_mod(a, b);\n\
    \        // a\u304Cb\u306E\u500D\u6570\n        if (a == 0) return {b, 0};\n \
    \       // \u4EE5\u4E0B 0 <= a < b\n        // [1] s - m0 * a = 0 (mod b)\n  \
    \      // [2] t - m1 * a = 0 (mod b)\n        // [3] s * |m1| + t * |m0| <= b\n\
    \        ll s = b, t = a;\n        ll m0 = 0, m1 = 1;\n        while (t) {\n \
    \           // s \u2192 s mod t\n            // m0 \u2192 m0 - m1 * (s / t)\n\
    \            ll u = s / t;\n            s -= t * u;\n            m0 -= m1 * u;\n\
    \            std::swap(s, t);\n            std::swap(m0, m1);\n        }\n   \
    \     // s = gcd(a, b)\n        // \u7D42\u4E86\u306E\u76F4\u524D\u306E\u30B9\u30C6\
    \u30C3\u30D7\u306B\u304A\u3044\u3066\n        // [1] k * s - m0 * a = 0 (mod b)\n\
    \        // [2] s - m1 * a = 0 (mod b)\n        // [3] (k * s) * |m1| + s * |m0|\
    \ <= b\n        // |m0| < b / s\n        if (m0 < 0) m0 += b / s;\n        return\
    \ {s, m0};\n    }\n\n    // barret reduction \u639B\u3051\u7B97\u306Emod\u306E\
    \u5B9A\u6570\u500D\u9AD8\u901F\u5316(mod\u304C\u5B9A\u6570\u3067\u306A\u3044\u5834\
    \u5408\u306B\u4F7F\u7528)\n    struct barretReduction {\n       public:\n    \
    \    explicit barretReduction(uint _mod)\n            : mod(_mod),\n         \
    \     imod((ull)(-1) / mod + 1) {}  // unsigned\u306E\u5834\u5408\u3001\u8CA0\u3067\
    \u5DE1\u56DE\u3059\u308B\n\n        uint get_mod() const { return mod; }\n\n \
    \       uint mul(int a, int b) const {\n            ull z = a;\n            z\
    \ *= b;\n#ifdef _MSC_VER\n            ull x;\n            _umul128(z, im, &x)\n\
    #else\n            // x = z / mod \u307E\u305F\u306F\u305D\u306E +1\n        \
    \    // \u5272\u308A\u7B97\u3092\u30D3\u30C3\u30C8\u30B7\u30D5\u30C8\u306B\u3059\
    \u308B\u3053\u3068\u3067\u9AD8\u901F\u5316\n            ull x = (ull)(((u128)z\
    \ * imod) >> 64);\n#endif\n                // z - x * mod = z % mod - mod \u306E\
    \u5834\u5408\u3001uint\u306A\u306E\u3067 2^32 - (mod -\n                // z %\
    \ mod) \u3064\u307E\u308Amod\u3092\u8DB3\u305B\u3070 2^32 + z %\n            \
    \    // mod\u3068\u306A\u308A\u3001\u6C42\u3081\u308Bmod\u306B\u306A\u308B\n \
    \               uint v = (uint)(z - x * mod);\n            if (v >= mod) v +=\
    \ mod;\n            return v;\n        }\n\n       private:\n        uint mod;\n\
    \        ull imod;  // ceil(2^64 / mod)\n    };\n}\n#line 5 \"myLibrary/modint_static.hpp\"\
    \n\ntemplate <const int MOD>\nstruct modint_static {\n    using ll = long long;\n\
    \n   public:\n    constexpr modint_static(ll x = 0) noexcept : value(x % MOD)\
    \ {\n        if (value < 0) value += MOD;\n    }\n    constexpr int get_mod()\
    \ const noexcept { return MOD; }\n    constexpr ll val() const noexcept { return\
    \ value; }\n    constexpr modint_static operator-() const noexcept {\n       \
    \ return modint_static(-value);\n    }\n    constexpr modint_static& operator++()\
    \ noexcept {\n        ++value;\n        if(value == MOD) value = 0;\n        return\
    \ *this;\n    }\n    constexpr modint_static& operator--() noexcept {\n      \
    \  if(value == 0) value = MOD;\n        --value;\n        return *this;\n    }\n\
    \    constexpr modint_static operator++(int) noexcept {\n        modint_static\
    \ cpy(*this);\n        ++(*this);\n        return cpy;\n    }\n    constexpr modint_static\
    \ operator--(int) noexcept {\n        modint_static cpy(*this);\n        --(*this);\n\
    \        return cpy;\n    }\n    constexpr modint_static& operator+=(const modint_static&\
    \ rhs) noexcept {\n        value += rhs.value;\n        if (value >= MOD) value\
    \ -= MOD;\n        return *this;\n    }\n    constexpr modint_static& operator-=(const\
    \ modint_static& rhs) noexcept {\n        value += (MOD - rhs.value);\n      \
    \  if (value >= MOD) value -= MOD;\n        return *this;\n    }\n    constexpr\
    \ modint_static& operator*=(const modint_static& rhs) noexcept {\n        (value\
    \ *= rhs.value) %= MOD; // \u5B9A\u6570\u3060\u3068\u30B3\u30F3\u30D1\u30A4\u30E9\
    \u6700\u9069\u5316\u304C\u304B\u304B\u308B\n        return *this;\n    }\n   \
    \ constexpr modint_static operator+(const modint_static& rhs) const noexcept {\n\
    \        modint_static cpy(*this);\n        return cpy += rhs;\n    }\n    constexpr\
    \ modint_static operator-(const modint_static& rhs) const noexcept {\n       \
    \ modint_static cpy(*this);\n        return cpy -= rhs;\n    }\n    constexpr\
    \ modint_static operator*(const modint_static& rhs) const noexcept {\n       \
    \ modint_static cpy(*this);\n        return cpy *= rhs;\n    }\n    constexpr\
    \ modint_static pow(ll beki) const noexcept {\n        modint_static curbekimod(*this);\n\
    \        modint_static ret(1);\n        while (beki > 0) {\n            if (beki\
    \ & 1) ret *= curbekimod;\n            curbekimod *= curbekimod;\n           \
    \ beki >>= 1;\n        }\n        return ret;\n    }\n\n    // value\u306E\u9006\
    \u5143\u3092\u6C42\u3081\u308B\n    constexpr modint_static inv() const noexcept\
    \ {\n        // \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
    \u6CD5\n        auto [gcd_value_mod, inv_value] = innermath_modint::inv_gcd(value,\
    \ MOD);\n        assert(gcd_value_mod == 1);\n        return modint_static(inv_value);\n\
    \    }\n    constexpr modint_static& operator/=(const modint_static& rhs) noexcept\
    \ {\n        return (*this) *= rhs.inv();\n    }\n    constexpr modint_static\
    \ operator/(const modint_static& rhs) const noexcept {\n        modint_static\
    \ cpy(*this);\n        return cpy /= rhs;\n    }\n\n   private:\n    ll value;\n\
    };\n\nusing mint998244353 = modint_static<998244353>;\nusing mint1000000007 =\
    \ modint_static<1000000007>;\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\n#include \"myLibrary/innermath_modint.hpp\"\
    \n\ntemplate <const int MOD>\nstruct modint_static {\n    using ll = long long;\n\
    \n   public:\n    constexpr modint_static(ll x = 0) noexcept : value(x % MOD)\
    \ {\n        if (value < 0) value += MOD;\n    }\n    constexpr int get_mod()\
    \ const noexcept { return MOD; }\n    constexpr ll val() const noexcept { return\
    \ value; }\n    constexpr modint_static operator-() const noexcept {\n       \
    \ return modint_static(-value);\n    }\n    constexpr modint_static& operator++()\
    \ noexcept {\n        ++value;\n        if(value == MOD) value = 0;\n        return\
    \ *this;\n    }\n    constexpr modint_static& operator--() noexcept {\n      \
    \  if(value == 0) value = MOD;\n        --value;\n        return *this;\n    }\n\
    \    constexpr modint_static operator++(int) noexcept {\n        modint_static\
    \ cpy(*this);\n        ++(*this);\n        return cpy;\n    }\n    constexpr modint_static\
    \ operator--(int) noexcept {\n        modint_static cpy(*this);\n        --(*this);\n\
    \        return cpy;\n    }\n    constexpr modint_static& operator+=(const modint_static&\
    \ rhs) noexcept {\n        value += rhs.value;\n        if (value >= MOD) value\
    \ -= MOD;\n        return *this;\n    }\n    constexpr modint_static& operator-=(const\
    \ modint_static& rhs) noexcept {\n        value += (MOD - rhs.value);\n      \
    \  if (value >= MOD) value -= MOD;\n        return *this;\n    }\n    constexpr\
    \ modint_static& operator*=(const modint_static& rhs) noexcept {\n        (value\
    \ *= rhs.value) %= MOD; // \u5B9A\u6570\u3060\u3068\u30B3\u30F3\u30D1\u30A4\u30E9\
    \u6700\u9069\u5316\u304C\u304B\u304B\u308B\n        return *this;\n    }\n   \
    \ constexpr modint_static operator+(const modint_static& rhs) const noexcept {\n\
    \        modint_static cpy(*this);\n        return cpy += rhs;\n    }\n    constexpr\
    \ modint_static operator-(const modint_static& rhs) const noexcept {\n       \
    \ modint_static cpy(*this);\n        return cpy -= rhs;\n    }\n    constexpr\
    \ modint_static operator*(const modint_static& rhs) const noexcept {\n       \
    \ modint_static cpy(*this);\n        return cpy *= rhs;\n    }\n    constexpr\
    \ modint_static pow(ll beki) const noexcept {\n        modint_static curbekimod(*this);\n\
    \        modint_static ret(1);\n        while (beki > 0) {\n            if (beki\
    \ & 1) ret *= curbekimod;\n            curbekimod *= curbekimod;\n           \
    \ beki >>= 1;\n        }\n        return ret;\n    }\n\n    // value\u306E\u9006\
    \u5143\u3092\u6C42\u3081\u308B\n    constexpr modint_static inv() const noexcept\
    \ {\n        // \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
    \u6CD5\n        auto [gcd_value_mod, inv_value] = innermath_modint::inv_gcd(value,\
    \ MOD);\n        assert(gcd_value_mod == 1);\n        return modint_static(inv_value);\n\
    \    }\n    constexpr modint_static& operator/=(const modint_static& rhs) noexcept\
    \ {\n        return (*this) *= rhs.inv();\n    }\n    constexpr modint_static\
    \ operator/(const modint_static& rhs) const noexcept {\n        modint_static\
    \ cpy(*this);\n        return cpy /= rhs;\n    }\n\n   private:\n    ll value;\n\
    };\n\nusing mint998244353 = modint_static<998244353>;\nusing mint1000000007 =\
    \ modint_static<1000000007>;"
  dependsOn:
  - myLibrary/innermath_modint.hpp
  isVerificationFile: false
  path: myLibrary/modint_static.hpp
  requiredBy: []
  timestamp: '2023-03-03 03:13:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: myLibrary/modint_static.hpp
layout: document
redirect_from:
- /library/myLibrary/modint_static.hpp
- /library/myLibrary/modint_static.hpp.html
title: myLibrary/modint_static.hpp
---
