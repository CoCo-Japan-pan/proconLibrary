---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_tests/rollinghash/z_algorithm.test.cpp
    title: verify_tests/rollinghash/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"myLibrary/rollinghash.hpp\"\n\n#include <bits/stdc++.h>\n\
    \nstruct rolhash_mod {\n    using u128 = __uint128_t;\n    using u64 = uint64_t;\n\
    \n   public:\n    constexpr rolhash_mod(u64 x = 0) noexcept : value(calcMod(x))\
    \ {}\n\n    constexpr u64 val() const noexcept { return value; }\n\n    constexpr\
    \ rolhash_mod &operator+=(const rolhash_mod &a) noexcept {\n        if ((value\
    \ += a.value) >= MOD) value -= MOD;\n        return *this;\n    }\n    constexpr\
    \ rolhash_mod &operator-=(const rolhash_mod &a) noexcept {\n        *this += (MOD\
    \ - a.value);\n        return *this;\n    }\n    constexpr rolhash_mod &operator*=(const\
    \ rolhash_mod &a) noexcept {\n        u128 product = (u128)value * a.value;\n\
    \        product = (product >> 61) + (product & MOD);\n        if (product >=\
    \ MOD) product -= MOD;\n        value = product;\n        return *this;\n    }\n\
    \    constexpr rolhash_mod operator+(const rolhash_mod &a) const noexcept {\n\
    \        rolhash_mod cpy(*this);\n        return cpy += a;\n    }\n    constexpr\
    \ rolhash_mod operator-(const rolhash_mod &a) const noexcept {\n        rolhash_mod\
    \ cpy(*this);\n        return cpy -= a;\n    }\n    constexpr rolhash_mod operator*(const\
    \ rolhash_mod &a) const noexcept {\n        rolhash_mod cpy(*this);\n        return\
    \ cpy *= a;\n    }\n    constexpr bool operator==(const rolhash_mod &a) const\
    \ noexcept {\n        return value == a.value;\n    }\n    constexpr bool operator!=(const\
    \ rolhash_mod &a) const noexcept {\n        return value != a.value;\n    }\n\n\
    \    // \u3079\u304D\u4E57\u306Emod(table\u3092\u7528\u610F\u305B\u305A\u305D\u306E\
    \u5834\u3067\u3084\u3063\u3066\u308B\u306E\u3067log(beki)\u304B\u304B\u308B)\n\
    \    constexpr static u64 power(u64 base, u64 beki) noexcept {\n        rolhash_mod\
    \ curbekiMod(base);\n        rolhash_mod ret(1);\n        while (beki > 0) {\n\
    \            if (beki & 1) ret *= curbekiMod;\n            curbekiMod *= curbekiMod;\n\
    \            beki >>= 1;\n        }\n        return ret.val();\n    }\n\n   private:\n\
    \    u64 value;  // \u4E2D\u3067\u4FDD\u6301\u3057\u3066\u304A\u304Fmod\n    constexpr\
    \ static u64 MOD = (1ULL << 61) - 1;\n    constexpr static u64 calcMod(const u64\
    \ &x) noexcept {\n        u64 cur = x >> 61;\n        if ((cur += (x & MOD)) >=\
    \ MOD) cur -= MOD;\n        return cur;\n    }\n};\n\n// \u90E8\u5206\u6587\u5B57\
    \u5217[l,r)\u306Ehash\u5024\u3092\u8FD4\u3059query\u3092\u5B9A\u6570\u6642\u9593\
    \u3067\nstruct rolhash {\n    using u64 = uint64_t;\n\n   public:\n    template\
    \ <class T>\n    explicit rolhash(const std::vector<T> &input) : base(genBase()),\
    \ N(input.size()) {\n        basebeki_table.resize(N + 1);\n        basebeki_table[0]\
    \ = 1;\n        for (int i = 1; i <= N; i++) {\n            basebeki_table[i]\
    \ = basebeki_table[i - 1] * base;\n        }\n        front_table.resize(N + 1);\n\
    \        for (int i = 1; i <= N; i++) {\n            front_table[i] = front_table[i\
    \ - 1] * base + input[i - 1];\n        }\n    }\n    explicit rolhash(const std::string\
    \ &input_string)\n        : rolhash(std::vector<char>(input_string.begin(), input_string.end()))\
    \ {\n    }\n\n    // \u90E8\u5206\u5217[l,r)\u306Ehash\u5024\u3092\u8FD4\u3059\
    \ l==r\u306E\u3068\u304D\u306F0\u3092\u8FD4\u3059\n    rolhash_mod query(int l,\
    \ int r) const {\n        assert(l <= r);\n        if (l == r) return rolhash_mod(0);\n\
    \        return (front_table[r] - front_table[l] * basebeki_table[r - l]);\n \
    \   }\n\n    // base\u306Ebeki\u4E57\u3092\u8FD4\u3059\n    rolhash_mod get_basebeki(int\
    \ beki) const {\n        return basebeki_table[beki];\n    }  // query\u3067\u8DB3\
    \u308A\u306A\u3044\u3068\u304D\u7528\n\n    // \u90E8\u5206\u5217[0,i)\u306Ehash\u5024\
    \u3092\u8FD4\u3059\n    rolhash_mod get_front(int i) const {\n        return front_table[i];\n\
    \    }  // query\u3067\u8DB3\u308A\u306A\u3044\u3068\u304D\u7528\n\n   private:\n\
    \    constexpr static u64 MOD = (1ULL << 61) - 1;\n    const u64 base;\n    const\
    \ int N;\n    // base\u306E0\u4E57\u304B\u3089N\u4E57\u3092\u8A18\u9332\n    std::vector<rolhash_mod>\
    \ basebeki_table;\n    // [0,i)\u306E\u90E8\u5206\u5217\u306Ehash\u5024\u3092\u8A18\
    \u9332\n    std::vector<rolhash_mod> front_table;\n\n    // [2, MOD - 2]\u306E\
    base\u3092\u4E71\u6570\u3068\u3057\u3066\u751F\u6210\n    static u64 genBase()\
    \ {\n        auto rand_time =\n            std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                .count();               // \u975E\u6C7A\u5B9A\u7684\u306A\u4E71\
    \u6570\n        std::mt19937_64 mt(rand_time);  // \u30E1\u30EB\u30BB\u30F3\u30CC\
    \u30FB\u30C4\u30A4\u30B9\u30BF 64bit\n        std::uniform_int_distribution<u64>\
    \ randbase(2ULL, MOD - 2);\n        return randbase(mt);\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\nstruct rolhash_mod {\n    using\
    \ u128 = __uint128_t;\n    using u64 = uint64_t;\n\n   public:\n    constexpr\
    \ rolhash_mod(u64 x = 0) noexcept : value(calcMod(x)) {}\n\n    constexpr u64\
    \ val() const noexcept { return value; }\n\n    constexpr rolhash_mod &operator+=(const\
    \ rolhash_mod &a) noexcept {\n        if ((value += a.value) >= MOD) value -=\
    \ MOD;\n        return *this;\n    }\n    constexpr rolhash_mod &operator-=(const\
    \ rolhash_mod &a) noexcept {\n        *this += (MOD - a.value);\n        return\
    \ *this;\n    }\n    constexpr rolhash_mod &operator*=(const rolhash_mod &a) noexcept\
    \ {\n        u128 product = (u128)value * a.value;\n        product = (product\
    \ >> 61) + (product & MOD);\n        if (product >= MOD) product -= MOD;\n   \
    \     value = product;\n        return *this;\n    }\n    constexpr rolhash_mod\
    \ operator+(const rolhash_mod &a) const noexcept {\n        rolhash_mod cpy(*this);\n\
    \        return cpy += a;\n    }\n    constexpr rolhash_mod operator-(const rolhash_mod\
    \ &a) const noexcept {\n        rolhash_mod cpy(*this);\n        return cpy -=\
    \ a;\n    }\n    constexpr rolhash_mod operator*(const rolhash_mod &a) const noexcept\
    \ {\n        rolhash_mod cpy(*this);\n        return cpy *= a;\n    }\n    constexpr\
    \ bool operator==(const rolhash_mod &a) const noexcept {\n        return value\
    \ == a.value;\n    }\n    constexpr bool operator!=(const rolhash_mod &a) const\
    \ noexcept {\n        return value != a.value;\n    }\n\n    // \u3079\u304D\u4E57\
    \u306Emod(table\u3092\u7528\u610F\u305B\u305A\u305D\u306E\u5834\u3067\u3084\u3063\
    \u3066\u308B\u306E\u3067log(beki)\u304B\u304B\u308B)\n    constexpr static u64\
    \ power(u64 base, u64 beki) noexcept {\n        rolhash_mod curbekiMod(base);\n\
    \        rolhash_mod ret(1);\n        while (beki > 0) {\n            if (beki\
    \ & 1) ret *= curbekiMod;\n            curbekiMod *= curbekiMod;\n           \
    \ beki >>= 1;\n        }\n        return ret.val();\n    }\n\n   private:\n  \
    \  u64 value;  // \u4E2D\u3067\u4FDD\u6301\u3057\u3066\u304A\u304Fmod\n    constexpr\
    \ static u64 MOD = (1ULL << 61) - 1;\n    constexpr static u64 calcMod(const u64\
    \ &x) noexcept {\n        u64 cur = x >> 61;\n        if ((cur += (x & MOD)) >=\
    \ MOD) cur -= MOD;\n        return cur;\n    }\n};\n\n// \u90E8\u5206\u6587\u5B57\
    \u5217[l,r)\u306Ehash\u5024\u3092\u8FD4\u3059query\u3092\u5B9A\u6570\u6642\u9593\
    \u3067\nstruct rolhash {\n    using u64 = uint64_t;\n\n   public:\n    template\
    \ <class T>\n    explicit rolhash(const std::vector<T> &input) : base(genBase()),\
    \ N(input.size()) {\n        basebeki_table.resize(N + 1);\n        basebeki_table[0]\
    \ = 1;\n        for (int i = 1; i <= N; i++) {\n            basebeki_table[i]\
    \ = basebeki_table[i - 1] * base;\n        }\n        front_table.resize(N + 1);\n\
    \        for (int i = 1; i <= N; i++) {\n            front_table[i] = front_table[i\
    \ - 1] * base + input[i - 1];\n        }\n    }\n    explicit rolhash(const std::string\
    \ &input_string)\n        : rolhash(std::vector<char>(input_string.begin(), input_string.end()))\
    \ {\n    }\n\n    // \u90E8\u5206\u5217[l,r)\u306Ehash\u5024\u3092\u8FD4\u3059\
    \ l==r\u306E\u3068\u304D\u306F0\u3092\u8FD4\u3059\n    rolhash_mod query(int l,\
    \ int r) const {\n        assert(l <= r);\n        if (l == r) return rolhash_mod(0);\n\
    \        return (front_table[r] - front_table[l] * basebeki_table[r - l]);\n \
    \   }\n\n    // base\u306Ebeki\u4E57\u3092\u8FD4\u3059\n    rolhash_mod get_basebeki(int\
    \ beki) const {\n        return basebeki_table[beki];\n    }  // query\u3067\u8DB3\
    \u308A\u306A\u3044\u3068\u304D\u7528\n\n    // \u90E8\u5206\u5217[0,i)\u306Ehash\u5024\
    \u3092\u8FD4\u3059\n    rolhash_mod get_front(int i) const {\n        return front_table[i];\n\
    \    }  // query\u3067\u8DB3\u308A\u306A\u3044\u3068\u304D\u7528\n\n   private:\n\
    \    constexpr static u64 MOD = (1ULL << 61) - 1;\n    const u64 base;\n    const\
    \ int N;\n    // base\u306E0\u4E57\u304B\u3089N\u4E57\u3092\u8A18\u9332\n    std::vector<rolhash_mod>\
    \ basebeki_table;\n    // [0,i)\u306E\u90E8\u5206\u5217\u306Ehash\u5024\u3092\u8A18\
    \u9332\n    std::vector<rolhash_mod> front_table;\n\n    // [2, MOD - 2]\u306E\
    base\u3092\u4E71\u6570\u3068\u3057\u3066\u751F\u6210\n    static u64 genBase()\
    \ {\n        auto rand_time =\n            std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                .count();               // \u975E\u6C7A\u5B9A\u7684\u306A\u4E71\
    \u6570\n        std::mt19937_64 mt(rand_time);  // \u30E1\u30EB\u30BB\u30F3\u30CC\
    \u30FB\u30C4\u30A4\u30B9\u30BF 64bit\n        std::uniform_int_distribution<u64>\
    \ randbase(2ULL, MOD - 2);\n        return randbase(mt);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: myLibrary/rollinghash.hpp
  requiredBy: []
  timestamp: '2023-03-04 20:56:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_tests/rollinghash/z_algorithm.test.cpp
documentation_of: myLibrary/rollinghash.hpp
layout: document
title: rollinghash
---

### 概要
文字列を数字とみなすことで文字列一致判定を高速に行う

### 使い方
- `rolhash(vector<T> &vec)` または `rolhash(string &str)` : $O(n)$ で構築  
- `query(int l, int r)` :  $O(1)$ で連続する部分列 $[l, r)$ にあたるhash値(rolhash_mod型)を返す  
- `get_basebeki(int beki)` : $O(1)$ で内部でランダムに生成しているbaseのbeki乗を返す  
- `get_front(int i)` : $O(1)$ で連続する部分列 $[0, i)$ にあたるhash値を返す

[参照したサイト](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)