---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: myLibrary/modint_dynamic.hpp
    title: myLibrary/modint_dynamic.hpp
  - icon: ':warning:'
    path: myLibrary/modint_static.hpp
    title: myLibrary/modint_static.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify_tests/modint_dynamic/modint_dynamic.test.cpp
    title: verify_tests/modint_dynamic/modint_dynamic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"myLibrary/inner_math_modint.hpp\"\n\n#include <bits/stdc++.h>\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing u128 = __uint128_t;\n\n// x\u306Emod\u3092\
    [0, mod)\u3067\u8FD4\u3059\nconstexpr ll safe_mod(ll x, ll mod) {\n    x %= mod;\n\
    \    if (x < 0) x += mod;\n    return x;\n}\n\nconstexpr ll pow_mod_constexpr(ll\
    \ x, ll n, ll mod) {\n    if (mod == 1) return 0;\n    ll ret = 1;\n    ll beki\
    \ = safe_mod(x, mod);\n    while (n) {\n        // LSB\u304B\u3089\u9806\u306B\
    \u898B\u308B\n        if (n & 1) {\n            ret = (ret * beki) % mod;\n  \
    \      }\n        beki = (beki * beki) % mod;\n        n >>= 1;\n    }\n    return\
    \ ret;\n}\n\n// int\u578B(2^32\u4EE5\u4E0B)\u306E\u9AD8\u901F\u306A\u7D20\u6570\
    \u5224\u5B9A\nconstexpr bool is_prime_constexpr(int n) {\n    if (n <= 1) return\
    \ false;\n    if (n == 2 || n == 7 || n == 61) return true;\n    if (n % 2 ==\
    \ 0) return false;\n    // \u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u5224\u5B9A int\u578B\
    \u306A\u3089a={2,7,61}\u3067\u5341\u5206\n    constexpr ll bases[] = {2, 7, 61};\n\
    \    // n-1 = 2^r * d\n    ll d = n - 1;\n    while (d % 2 == 0) d >>= 1;\n  \
    \  // \u7D20\u6570mod\u306F1\u306E\u5E73\u65B9\u6839\u3068\u3057\u3066\u975E\u81EA\
    \u660E\u306A\u89E3\u3092\u6301\u305F\u306A\u3044\n    // \u3064\u307E\u308A\u975E\
    \u81EA\u660E\u306A\u89E3\u304C\u3042\u308B\u2192\u5408\u6210\u6570\n    for (ll\
    \ a : bases) {\n        ll t = d;\n        ll y = pow_mod_constexpr(a, t, n);\n\
    \        // y\u304C1\u307E\u305F\u306Fn-1\u306B\u306A\u308C\u3070\u629C\u3051\u308B\
    \n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y = (y * y)\
    \ % n;\n            t <<= 1;\n        }\n        // 1\u306E\u5E73\u65B9\u6839\u3068\
    \u3057\u30661\u3068-1\u4EE5\u5916\u306E\u89E3(\u975E\u81EA\u660E\u306A\u89E3)\u304C\
    \u5B58\u5728\n        if (y != n - 1 && t % 2 == 0) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5 g = gcd(a,b)\u3068\u3001ax = g (mod b)\u306A\
    \u308B0 <= x <\n// b/g\u306E\u30DA\u30A2\u3092\u8FD4\u3059\nconstexpr std::pair<ll,\
    \ ll> inv_gcd(ll a, ll b) {\n    a = safe_mod(a, b);\n    // a\u304Cb\u306E\u500D\
    \u6570\n    if (a == 0) return {b, 0};\n    // \u4EE5\u4E0B 0 <= a < b\n    //\
    \ [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    // [3] s\
    \ * |m1| + t * |m0| <= b\n    ll s = b, t = a;\n    ll m0 = 0, m1 = 1;\n    while\
    \ (t) {\n        // s \u2192 s mod t\n        // m0 \u2192 m0 - m1 * (s / t)\n\
    \        ll u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        std::swap(s,\
    \ t);\n        std::swap(m0, m1);\n    }\n    // s = gcd(a, b)\n    // \u7D42\u4E86\
    \u306E\u76F4\u524D\u306E\u30B9\u30C6\u30C3\u30D7\u306B\u304A\u3044\u3066\n   \
    \ // [1] k * s - m0 * a = 0 (mod b)\n    // [2] s - m1 * a = 0 (mod b)\n    //\
    \ [3] (k * s) * |m1| + s * |m0| <= b\n    // |m0| < b / s\n    if (m0 < 0) m0\
    \ += b / s;\n    return {s, m0};\n}\n\n// barret reduction \u639B\u3051\u7B97\u306E\
    mod\u306E\u5B9A\u6570\u500D\u9AD8\u901F\u5316(mod\u304C\u5B9A\u6570\u3067\u306A\
    \u3044\u5834\u5408\u306B\u4F7F\u7528)\nstruct barretReduction {\n   public:\n\
    \    explicit barretReduction(uint _mod)\n        : mod(_mod),\n          imod((ull)(-1)\
    \ / mod + 1) {}  // unsigned\u306E\u5834\u5408\u3001\u8CA0\u3067\u5DE1\u56DE\u3059\
    \u308B\n\n    uint get_mod() const { return mod; }\n    \n    uint mul(int a,\
    \ int b) const {\n        ull z = a;\n        z *= b;\n#ifdef _MSC_VER\n     \
    \   ull x;\n        _umul128(z, im, &x)\n#else\n        // x = z / mod \u307E\u305F\
    \u306F\u305D\u306E +1\n        // \u5272\u308A\u7B97\u3092\u30D3\u30C3\u30C8\u30B7\
    \u30D5\u30C8\u306B\u3059\u308B\u3053\u3068\u3067\u9AD8\u901F\u5316\n        ull\
    \ x = (ull)(((u128)z * imod) >> 64);\n#endif\n            // z - x * mod = z %\
    \ mod - mod \u306E\u5834\u5408\u3001uint\u306A\u306E\u3067 2^32 - (mod - z %\n\
    \            // mod) \u3064\u307E\u308Amod\u3092\u8DB3\u305B\u3070 2^32 + z %\
    \ mod\u3068\u306A\u308A\u3001\u6C42\u3081\u308Bmod\u306B\u306A\u308B\n       \
    \     uint v = (uint)(z - x * mod);\n        if (v >= mod) v += mod;\n       \
    \ return v;\n    }\n\n   private:\n    uint mod;\n    ull imod;  // ceil(2^64\
    \ / mod)\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nusing ll = long long;\nusing ull = unsigned long long;\nusing u128 =\
    \ __uint128_t;\n\n// x\u306Emod\u3092[0, mod)\u3067\u8FD4\u3059\nconstexpr ll\
    \ safe_mod(ll x, ll mod) {\n    x %= mod;\n    if (x < 0) x += mod;\n    return\
    \ x;\n}\n\nconstexpr ll pow_mod_constexpr(ll x, ll n, ll mod) {\n    if (mod ==\
    \ 1) return 0;\n    ll ret = 1;\n    ll beki = safe_mod(x, mod);\n    while (n)\
    \ {\n        // LSB\u304B\u3089\u9806\u306B\u898B\u308B\n        if (n & 1) {\n\
    \            ret = (ret * beki) % mod;\n        }\n        beki = (beki * beki)\
    \ % mod;\n        n >>= 1;\n    }\n    return ret;\n}\n\n// int\u578B(2^32\u4EE5\
    \u4E0B)\u306E\u9AD8\u901F\u306A\u7D20\u6570\u5224\u5B9A\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    // \u30DF\u30E9\u30FC\u30E9\u30D3\
    \u30F3\u5224\u5B9A int\u578B\u306A\u3089a={2,7,61}\u3067\u5341\u5206\n    constexpr\
    \ ll bases[] = {2, 7, 61};\n    // n-1 = 2^r * d\n    ll d = n - 1;\n    while\
    \ (d % 2 == 0) d >>= 1;\n    // \u7D20\u6570mod\u306F1\u306E\u5E73\u65B9\u6839\
    \u3068\u3057\u3066\u975E\u81EA\u660E\u306A\u89E3\u3092\u6301\u305F\u306A\u3044\
    \n    // \u3064\u307E\u308A\u975E\u81EA\u660E\u306A\u89E3\u304C\u3042\u308B\u2192\
    \u5408\u6210\u6570\n    for (ll a : bases) {\n        ll t = d;\n        ll y\
    \ = pow_mod_constexpr(a, t, n);\n        // y\u304C1\u307E\u305F\u306Fn-1\u306B\
    \u306A\u308C\u3070\u629C\u3051\u308B\n        while (t != n - 1 && y != 1 && y\
    \ != n - 1) {\n            y = (y * y) % n;\n            t <<= 1;\n        }\n\
    \        // 1\u306E\u5E73\u65B9\u6839\u3068\u3057\u30661\u3068-1\u4EE5\u5916\u306E\
    \u89E3(\u975E\u81EA\u660E\u306A\u89E3)\u304C\u5B58\u5728\n        if (y != n -\
    \ 1 && t % 2 == 0) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
    \u6CD5 g = gcd(a,b)\u3068\u3001ax = g (mod b)\u306A\u308B0 <= x <\n// b/g\u306E\
    \u30DA\u30A2\u3092\u8FD4\u3059\nconstexpr std::pair<ll, ll> inv_gcd(ll a, ll b)\
    \ {\n    a = safe_mod(a, b);\n    // a\u304Cb\u306E\u500D\u6570\n    if (a ==\
    \ 0) return {b, 0};\n    // \u4EE5\u4E0B 0 <= a < b\n    // [1] s - m0 * a = 0\
    \ (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    // [3] s * |m1| + t * |m0| <=\
    \ b\n    ll s = b, t = a;\n    ll m0 = 0, m1 = 1;\n    while (t) {\n        //\
    \ s \u2192 s mod t\n        // m0 \u2192 m0 - m1 * (s / t)\n        ll u = s /\
    \ t;\n        s -= t * u;\n        m0 -= m1 * u;\n        std::swap(s, t);\n \
    \       std::swap(m0, m1);\n    }\n    // s = gcd(a, b)\n    // \u7D42\u4E86\u306E\
    \u76F4\u524D\u306E\u30B9\u30C6\u30C3\u30D7\u306B\u304A\u3044\u3066\n    // [1]\
    \ k * s - m0 * a = 0 (mod b)\n    // [2] s - m1 * a = 0 (mod b)\n    // [3] (k\
    \ * s) * |m1| + s * |m0| <= b\n    // |m0| < b / s\n    if (m0 < 0) m0 += b /\
    \ s;\n    return {s, m0};\n}\n\n// barret reduction \u639B\u3051\u7B97\u306Emod\u306E\
    \u5B9A\u6570\u500D\u9AD8\u901F\u5316(mod\u304C\u5B9A\u6570\u3067\u306A\u3044\u5834\
    \u5408\u306B\u4F7F\u7528)\nstruct barretReduction {\n   public:\n    explicit\
    \ barretReduction(uint _mod)\n        : mod(_mod),\n          imod((ull)(-1) /\
    \ mod + 1) {}  // unsigned\u306E\u5834\u5408\u3001\u8CA0\u3067\u5DE1\u56DE\u3059\
    \u308B\n\n    uint get_mod() const { return mod; }\n    \n    uint mul(int a,\
    \ int b) const {\n        ull z = a;\n        z *= b;\n#ifdef _MSC_VER\n     \
    \   ull x;\n        _umul128(z, im, &x)\n#else\n        // x = z / mod \u307E\u305F\
    \u306F\u305D\u306E +1\n        // \u5272\u308A\u7B97\u3092\u30D3\u30C3\u30C8\u30B7\
    \u30D5\u30C8\u306B\u3059\u308B\u3053\u3068\u3067\u9AD8\u901F\u5316\n        ull\
    \ x = (ull)(((u128)z * imod) >> 64);\n#endif\n            // z - x * mod = z %\
    \ mod - mod \u306E\u5834\u5408\u3001uint\u306A\u306E\u3067 2^32 - (mod - z %\n\
    \            // mod) \u3064\u307E\u308Amod\u3092\u8DB3\u305B\u3070 2^32 + z %\
    \ mod\u3068\u306A\u308A\u3001\u6C42\u3081\u308Bmod\u306B\u306A\u308B\n       \
    \     uint v = (uint)(z - x * mod);\n        if (v >= mod) v += mod;\n       \
    \ return v;\n    }\n\n   private:\n    uint mod;\n    ull imod;  // ceil(2^64\
    \ / mod)\n};"
  dependsOn: []
  isVerificationFile: false
  path: myLibrary/inner_math_modint.hpp
  requiredBy:
  - myLibrary/modint_static.hpp
  - myLibrary/modint_dynamic.hpp
  timestamp: '2023-03-03 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify_tests/modint_dynamic/modint_dynamic.test.cpp
documentation_of: myLibrary/inner_math_modint.hpp
layout: document
redirect_from:
- /library/myLibrary/inner_math_modint.hpp
- /library/myLibrary/inner_math_modint.hpp.html
title: myLibrary/inner_math_modint.hpp
---
