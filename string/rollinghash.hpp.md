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
  bundledCode: "#line 2 \"string/rollinghash.hpp\"\n\n#ifdef NOBUNDLE\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n#endif\n\nstruct rolhash_mod {\n\
    \   public:\n    // [2, MOD - 2]\u306Ebase\u3092\u4E71\u6570\u3068\u3057\u3066\
    \u751F\u6210\n    static ll genBase() {\n        random_device seed;     // \u975E\
    \u6C7A\u5B9A\u7684\u306A\u4E71\u6570\n        mt19937_64 mt(seed());  // \u30E1\
    \u30EB\u30BB\u30F3\u30CC\u30FB\u30C4\u30A4\u30B9\u30BF 64bit\n        uniform_int_distribution<ll>\
    \ randbase(2LL, MOD - 2);\n        return randbase(mt);\n    }\n    // \u3079\u304D\
    \u4E57\u306Emod(table\u3092\u7528\u610F\u305B\u305A\u305D\u306E\u5834\u3067\u3084\
    \u3063\u3066\u308B\u306E\u3067log(beki)\u304B\u304B\u308B)\n    constexpr static\
    \ ll power(ll base, ll beki) {\n        rolhash_mod curbekiMod(base);\n      \
    \  rolhash_mod ret(1);\n        while(beki > 0) {\n            if(beki & 1) ret\
    \ *= curbekiMod;\n            curbekiMod *= curbekiMod;\n            beki >>=\
    \ 1;\n        }\n        return ret.val();\n    }\n\n    constexpr rolhash_mod(ll\
    \ x = 0) : value(calcMod(x)) {}\n\n    constexpr ll val() const { return value;\
    \ }\n\n    constexpr rolhash_mod &operator+=(const rolhash_mod &a) {\n       \
    \ if((value += a.value) >= MOD) value -= MOD;\n        return *this;\n    }\n\
    \    constexpr rolhash_mod &operator-=(const rolhash_mod &a) {\n        *this\
    \ += (MOD - a.value);\n        return *this;\n    }\n    constexpr rolhash_mod\
    \ &operator*=(const rolhash_mod &a) {\n        __int128_t product = (__int128_t)value\
    \ * a.value;\n        product = (product >> 61) + (product & MOD);\n        if(product\
    \ >= MOD) product -= MOD;\n        value = product;\n        return *this;\n \
    \   }\n    constexpr rolhash_mod operator+(const rolhash_mod &a) const {\n   \
    \     rolhash_mod cpy(*this);\n        return cpy += a;\n    }\n    constexpr\
    \ rolhash_mod operator-(const rolhash_mod &a) const {\n        rolhash_mod cpy(*this);\n\
    \        return cpy -= a;\n    }\n    constexpr rolhash_mod operator*(const rolhash_mod\
    \ &a) const {\n        rolhash_mod cpy(*this);\n        return cpy *= a;\n   \
    \ }\n    constexpr bool operator==(const rolhash_mod &a) { return value == a.value;\
    \ }\n\n   private:\n    ll value;  // \u4E2D\u3067\u4FDD\u6301\u3057\u3066\u304A\
    \u304Fmod\n    constexpr static ll MOD = (1LL << 61) - 1;\n    constexpr static\
    \ ll calcMod(const ll &x) {\n        ll cur = x >> 61;\n        if((cur += (x\
    \ & MOD)) >= MOD) cur -= MOD;\n        return cur;\n    }\n};\n\n// \u90E8\u5206\
    \u6587\u5B57\u5217[l,r)\u306Ehash\u5024\u3092\u8FD4\u3059query\u3092\u5B9A\u6570\
    \u6642\u9593\u3067\nstruct rolhash {\n   public:\n    template <class T>\n   \
    \ rolhash(const vector<T> &input) {\n        base = rolhash_mod::genBase();\n\
    \        N = input.size();\n        basebeki_table.resize(N + 1);\n        basebeki_table[0]\
    \ = 1;\n        for(int i = 1; i <= N; i++) {\n            basebeki_table[i] =\
    \ basebeki_table[i - 1] * base;\n        }\n        front_table.resize(N + 1);\n\
    \        for(int i = 1; i <= N; i++) {\n            front_table[i] = front_table[i\
    \ - 1] * base + input[i - 1];\n        }\n    }\n\n    // \u90E8\u5206\u5217[l,r)\u306E\
    hash\u5024\u3092\u8FD4\u3059\n    rolhash_mod query(int l, int r) const { return\
    \ (front_table[r] - front_table[l] * basebeki_table[r - l]); }\n\n    // base\u306E\
    beki\u4E57\u3092\u8FD4\u3059\n    rolhash_mod get_basebeki(int beki) const { return\
    \ basebeki_table[beki]; }  // query\u3067\u8DB3\u308A\u306A\u3044\u3068\u304D\u7528\
    \n\n    // \u90E8\u5206\u5217[0,i)\u306Ehash\u5024\u3092\u8FD4\u3059\n    rolhash_mod\
    \ get_front(int i) const { return front_table[i]; }  // query\u3067\u8DB3\u308A\
    \u306A\u3044\u3068\u304D\u7528\n\n   private:\n    constexpr static ll MOD = (1LL\
    \ << 61) - 1;\n    const ll base;\n    const int N;\n    // base\u306E0\u4E57\u304B\
    \u3089N\u4E57\u3092\u8A18\u9332\n    vector<rolhash_mod> basebeki_table;\n   \
    \ // [0,i)\u306E\u90E8\u5206\u5217\u306Ehash\u5024\u3092\u8A18\u9332\n    vector<rolhash_mod>\
    \ front_table;\n};\n"
  code: "#pragma once\n\n#ifdef NOBUNDLE\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#endif\n\nstruct rolhash_mod {\n   public:\n  \
    \  // [2, MOD - 2]\u306Ebase\u3092\u4E71\u6570\u3068\u3057\u3066\u751F\u6210\n\
    \    static ll genBase() {\n        random_device seed;     // \u975E\u6C7A\u5B9A\
    \u7684\u306A\u4E71\u6570\n        mt19937_64 mt(seed());  // \u30E1\u30EB\u30BB\
    \u30F3\u30CC\u30FB\u30C4\u30A4\u30B9\u30BF 64bit\n        uniform_int_distribution<ll>\
    \ randbase(2LL, MOD - 2);\n        return randbase(mt);\n    }\n    // \u3079\u304D\
    \u4E57\u306Emod(table\u3092\u7528\u610F\u305B\u305A\u305D\u306E\u5834\u3067\u3084\
    \u3063\u3066\u308B\u306E\u3067log(beki)\u304B\u304B\u308B)\n    constexpr static\
    \ ll power(ll base, ll beki) {\n        rolhash_mod curbekiMod(base);\n      \
    \  rolhash_mod ret(1);\n        while(beki > 0) {\n            if(beki & 1) ret\
    \ *= curbekiMod;\n            curbekiMod *= curbekiMod;\n            beki >>=\
    \ 1;\n        }\n        return ret.val();\n    }\n\n    constexpr rolhash_mod(ll\
    \ x = 0) : value(calcMod(x)) {}\n\n    constexpr ll val() const { return value;\
    \ }\n\n    constexpr rolhash_mod &operator+=(const rolhash_mod &a) {\n       \
    \ if((value += a.value) >= MOD) value -= MOD;\n        return *this;\n    }\n\
    \    constexpr rolhash_mod &operator-=(const rolhash_mod &a) {\n        *this\
    \ += (MOD - a.value);\n        return *this;\n    }\n    constexpr rolhash_mod\
    \ &operator*=(const rolhash_mod &a) {\n        __int128_t product = (__int128_t)value\
    \ * a.value;\n        product = (product >> 61) + (product & MOD);\n        if(product\
    \ >= MOD) product -= MOD;\n        value = product;\n        return *this;\n \
    \   }\n    constexpr rolhash_mod operator+(const rolhash_mod &a) const {\n   \
    \     rolhash_mod cpy(*this);\n        return cpy += a;\n    }\n    constexpr\
    \ rolhash_mod operator-(const rolhash_mod &a) const {\n        rolhash_mod cpy(*this);\n\
    \        return cpy -= a;\n    }\n    constexpr rolhash_mod operator*(const rolhash_mod\
    \ &a) const {\n        rolhash_mod cpy(*this);\n        return cpy *= a;\n   \
    \ }\n    constexpr bool operator==(const rolhash_mod &a) { return value == a.value;\
    \ }\n\n   private:\n    ll value;  // \u4E2D\u3067\u4FDD\u6301\u3057\u3066\u304A\
    \u304Fmod\n    constexpr static ll MOD = (1LL << 61) - 1;\n    constexpr static\
    \ ll calcMod(const ll &x) {\n        ll cur = x >> 61;\n        if((cur += (x\
    \ & MOD)) >= MOD) cur -= MOD;\n        return cur;\n    }\n};\n\n// \u90E8\u5206\
    \u6587\u5B57\u5217[l,r)\u306Ehash\u5024\u3092\u8FD4\u3059query\u3092\u5B9A\u6570\
    \u6642\u9593\u3067\nstruct rolhash {\n   public:\n    template <class T>\n   \
    \ rolhash(const vector<T> &input) {\n        base = rolhash_mod::genBase();\n\
    \        N = input.size();\n        basebeki_table.resize(N + 1);\n        basebeki_table[0]\
    \ = 1;\n        for(int i = 1; i <= N; i++) {\n            basebeki_table[i] =\
    \ basebeki_table[i - 1] * base;\n        }\n        front_table.resize(N + 1);\n\
    \        for(int i = 1; i <= N; i++) {\n            front_table[i] = front_table[i\
    \ - 1] * base + input[i - 1];\n        }\n    }\n\n    // \u90E8\u5206\u5217[l,r)\u306E\
    hash\u5024\u3092\u8FD4\u3059\n    rolhash_mod query(int l, int r) const { return\
    \ (front_table[r] - front_table[l] * basebeki_table[r - l]); }\n\n    // base\u306E\
    beki\u4E57\u3092\u8FD4\u3059\n    rolhash_mod get_basebeki(int beki) const { return\
    \ basebeki_table[beki]; }  // query\u3067\u8DB3\u308A\u306A\u3044\u3068\u304D\u7528\
    \n\n    // \u90E8\u5206\u5217[0,i)\u306Ehash\u5024\u3092\u8FD4\u3059\n    rolhash_mod\
    \ get_front(int i) const { return front_table[i]; }  // query\u3067\u8DB3\u308A\
    \u306A\u3044\u3068\u304D\u7528\n\n   private:\n    constexpr static ll MOD = (1LL\
    \ << 61) - 1;\n    const ll base;\n    const int N;\n    // base\u306E0\u4E57\u304B\
    \u3089N\u4E57\u3092\u8A18\u9332\n    vector<rolhash_mod> basebeki_table;\n   \
    \ // [0,i)\u306E\u90E8\u5206\u5217\u306Ehash\u5024\u3092\u8A18\u9332\n    vector<rolhash_mod>\
    \ front_table;\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2023-02-28 18:04:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: string/rollinghash.hpp
---
