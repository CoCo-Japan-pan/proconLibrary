---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"myLibrary/inner_math.hpp\"\n\n#include <bits/stdc++.h>\n\
    \nnamespace inner_math {\n    using ll = long long;\n\n    // x\u306Emod\u3092\
    [0, mod)\u3067\u8FD4\u3059\n    constexpr ll safe_mod(ll x, ll mod) {\n      \
    \  assert(mod > 0);\n        x %= mod;\n        if (x < 0) x += mod;\n       \
    \ return x;\n    }\n\n    constexpr ll pow_mod_constexpr(ll x, ll n, ll mod) {\n\
    \        if (mod == 1) return 0;\n        ll ret = 1;\n        ll beki = safe_mod(x,\
    \ mod);\n        while(n) {\n            // LSB\u304B\u3089\u9806\u306B\u898B\u308B\
    \n            if(n & 1) {\n                ret = (ret * beki) % mod;\n       \
    \     }\n            beki = (beki * beki) % mod;\n            n >>= 1;\n     \
    \   }\n        return ret;\n    }\n\n    // int\u578B(2^32\u4EE5\u4E0B)\u306E\u9AD8\
    \u901F\u306A\u7D20\u6570\u5224\u5B9A\n    constexpr bool is_prime_constexpr(int\
    \ n) {\n        if (n <= 1) return false;\n        if (n == 2 || n == 7 || n ==\
    \ 61) return true;\n        if (n % 2 == 0) return false;\n        // \u30DF\u30E9\
    \u30FC\u30E9\u30D3\u30F3\u5224\u5B9A int\u578B\u306A\u3089a={2,7,61}\u3067\u5341\
    \u5206\n        constexpr ll bases[] = {2, 7, 61};\n        // n-1 = 2^r * d\n\
    \        ll d = n - 1;\n        while(d & 1 == 0) d >>= 1;\n        // \u7D20\u6570\
    mod\u306F1\u306E\u5E73\u65B9\u6839\u3068\u3057\u3066\u975E\u81EA\u660E\u306A\u89E3\
    \u3092\u6301\u305F\u306A\u3044\n        // \u3064\u307E\u308A\u975E\u81EA\u660E\
    \u306A\u89E3\u304C\u3042\u308B\u2192\u5408\u6210\u6570\n        for(ll a : bases){\n\
    \            \n        }\n    }\n}\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\nnamespace inner_math {\n    using\
    \ ll = long long;\n\n    // x\u306Emod\u3092[0, mod)\u3067\u8FD4\u3059\n    constexpr\
    \ ll safe_mod(ll x, ll mod) {\n        assert(mod > 0);\n        x %= mod;\n \
    \       if (x < 0) x += mod;\n        return x;\n    }\n\n    constexpr ll pow_mod_constexpr(ll\
    \ x, ll n, ll mod) {\n        if (mod == 1) return 0;\n        ll ret = 1;\n \
    \       ll beki = safe_mod(x, mod);\n        while(n) {\n            // LSB\u304B\
    \u3089\u9806\u306B\u898B\u308B\n            if(n & 1) {\n                ret =\
    \ (ret * beki) % mod;\n            }\n            beki = (beki * beki) % mod;\n\
    \            n >>= 1;\n        }\n        return ret;\n    }\n\n    // int\u578B\
    (2^32\u4EE5\u4E0B)\u306E\u9AD8\u901F\u306A\u7D20\u6570\u5224\u5B9A\n    constexpr\
    \ bool is_prime_constexpr(int n) {\n        if (n <= 1) return false;\n      \
    \  if (n == 2 || n == 7 || n == 61) return true;\n        if (n % 2 == 0) return\
    \ false;\n        // \u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u5224\u5B9A int\u578B\
    \u306A\u3089a={2,7,61}\u3067\u5341\u5206\n        constexpr ll bases[] = {2, 7,\
    \ 61};\n        // n-1 = 2^r * d\n        ll d = n - 1;\n        while(d & 1 ==\
    \ 0) d >>= 1;\n        // \u7D20\u6570mod\u306F1\u306E\u5E73\u65B9\u6839\u3068\
    \u3057\u3066\u975E\u81EA\u660E\u306A\u89E3\u3092\u6301\u305F\u306A\u3044\n   \
    \     // \u3064\u307E\u308A\u975E\u81EA\u660E\u306A\u89E3\u304C\u3042\u308B\u2192\
    \u5408\u6210\u6570\n        for(ll a : bases){\n            \n        }\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: myLibrary/inner_math.hpp
  requiredBy: []
  timestamp: '2023-03-02 10:15:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: myLibrary/inner_math.hpp
layout: document
redirect_from:
- /library/myLibrary/inner_math.hpp
- /library/myLibrary/inner_math.hpp.html
title: myLibrary/inner_math.hpp
---
