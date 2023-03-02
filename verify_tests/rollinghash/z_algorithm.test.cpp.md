---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: myLibrary/rollinghash.hpp
    title: rollinghash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify_tests/rollinghash/z_algorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n// \u63D0\u51FA\u6642\
    \u306Bassert\u306F\u30AA\u30D5\n#ifndef DEBUG\n#ifndef NDEBUG\n#define NDEBUG\n\
    #endif\n#endif\n\n#include <bits/stdc++.h>\n#line 2 \"myLibrary/rollinghash.hpp\"\
    \n\n#line 4 \"myLibrary/rollinghash.hpp\"\n\nstruct rolhash_mod {\n    using u128\
    \ = __uint128_t;\n    using u64 = uint64_t;\n\n   public:\n    constexpr rolhash_mod(u64\
    \ x = 0) : value(calcMod(x)) {}\n\n    constexpr u64 val() const { return value;\
    \ }\n\n    constexpr rolhash_mod &operator+=(const rolhash_mod &a) {\n       \
    \ if ((value += a.value) >= MOD) value -= MOD;\n        return *this;\n    }\n\
    \    constexpr rolhash_mod &operator-=(const rolhash_mod &a) {\n        *this\
    \ += (MOD - a.value);\n        return *this;\n    }\n    constexpr rolhash_mod\
    \ &operator*=(const rolhash_mod &a) {\n        u128 product = (u128)value * a.value;\n\
    \        product = (product >> 61) + (product & MOD);\n        if (product >=\
    \ MOD) product -= MOD;\n        value = product;\n        return *this;\n    }\n\
    \    constexpr rolhash_mod operator+(const rolhash_mod &a) const {\n        rolhash_mod\
    \ cpy(*this);\n        return cpy += a;\n    }\n    constexpr rolhash_mod operator-(const\
    \ rolhash_mod &a) const {\n        rolhash_mod cpy(*this);\n        return cpy\
    \ -= a;\n    }\n    constexpr rolhash_mod operator*(const rolhash_mod &a) const\
    \ {\n        rolhash_mod cpy(*this);\n        return cpy *= a;\n    }\n    constexpr\
    \ bool operator==(const rolhash_mod &a) const {\n        return value == a.value;\n\
    \    }\n\n    // \u3079\u304D\u4E57\u306Emod(table\u3092\u7528\u610F\u305B\u305A\
    \u305D\u306E\u5834\u3067\u3084\u3063\u3066\u308B\u306E\u3067log(beki)\u304B\u304B\
    \u308B)\n    constexpr static u64 power(u64 base, u64 beki) {\n        rolhash_mod\
    \ curbekiMod(base);\n        rolhash_mod ret(1);\n        while (beki > 0) {\n\
    \            if (beki & 1) ret *= curbekiMod;\n            curbekiMod *= curbekiMod;\n\
    \            beki >>= 1;\n        }\n        return ret.val();\n    }\n\n   private:\n\
    \    u64 value;  // \u4E2D\u3067\u4FDD\u6301\u3057\u3066\u304A\u304Fmod\n    constexpr\
    \ static u64 MOD = (1ULL << 61) - 1;\n    constexpr static u64 calcMod(const u64\
    \ &x) {\n        u64 cur = x >> 61;\n        if ((cur += (x & MOD)) >= MOD) cur\
    \ -= MOD;\n        return cur;\n    }\n};\n\n// \u90E8\u5206\u6587\u5B57\u5217\
    [l,r)\u306Ehash\u5024\u3092\u8FD4\u3059query\u3092\u5B9A\u6570\u6642\u9593\u3067\
    \nstruct rolhash {\n    using u64 = uint64_t;\n\n   public:\n    template <class\
    \ T>\n    explicit rolhash(const std::vector<T> &input) : base(genBase()), N(input.size())\
    \ {\n        basebeki_table.resize(N + 1);\n        basebeki_table[0] = 1;\n \
    \       for (int i = 1; i <= N; i++) {\n            basebeki_table[i] = basebeki_table[i\
    \ - 1] * base;\n        }\n        front_table.resize(N + 1);\n        for (int\
    \ i = 1; i <= N; i++) {\n            front_table[i] = front_table[i - 1] * base\
    \ + input[i - 1];\n        }\n    }\n    explicit rolhash(const std::string &input_string)\n\
    \        : rolhash(std::vector<char>(input_string.begin(), input_string.end()))\
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
    \ randbase(2ULL, MOD - 2);\n        return randbase(mt);\n    }\n};\n#line 12\
    \ \"verify_tests/rollinghash/z_algorithm.test.cpp\"\nusing namespace std;\nusing\
    \ ll = long long;\n\n#define ALL(x) (x).begin(), (x).end()\ntemplate <class T>\
    \ using vec = vector<T>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    string S;\n    cin >> S;\n    rolhash rol(S);\n  \
    \  int N = S.size();\n    cout << N << \" \";\n    for(int i = 1; i < N; i++){\n\
    \        if(rol.query(i, N) == rol.query(0, N - i)){\n            cout << N -\
    \ i << \" \";\n            continue;\n        }\n        // S\u3068S[i, N)\u306E\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\n        int left = 0, right\
    \ = N - i;\n        while(right - left > 1){\n            // S[0, middle)\u3068\
    S[i, i + middle)\u3092\u6BD4\u3079\u308B\n            int middle = (left + right)\
    \ / 2;\n            if(rol.query(0, middle) == rol.query(i, i + middle)){\n  \
    \              left = middle;\n            } else {\n                right = middle;\n\
    \            }\n        }\n        cout << left << \" \";\n    }\n    cout <<\
    \ \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n// \u63D0\
    \u51FA\u6642\u306Bassert\u306F\u30AA\u30D5\n#ifndef DEBUG\n#ifndef NDEBUG\n#define\
    \ NDEBUG\n#endif\n#endif\n\n#include <bits/stdc++.h>\n#include \"myLibrary/rollinghash.hpp\"\
    \nusing namespace std;\nusing ll = long long;\n\n#define ALL(x) (x).begin(), (x).end()\n\
    template <class T> using vec = vector<T>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    string S;\n    cin >> S;\n    rolhash rol(S);\n  \
    \  int N = S.size();\n    cout << N << \" \";\n    for(int i = 1; i < N; i++){\n\
    \        if(rol.query(i, N) == rol.query(0, N - i)){\n            cout << N -\
    \ i << \" \";\n            continue;\n        }\n        // S\u3068S[i, N)\u306E\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\n        int left = 0, right\
    \ = N - i;\n        while(right - left > 1){\n            // S[0, middle)\u3068\
    S[i, i + middle)\u3092\u6BD4\u3079\u308B\n            int middle = (left + right)\
    \ / 2;\n            if(rol.query(0, middle) == rol.query(i, i + middle)){\n  \
    \              left = middle;\n            } else {\n                right = middle;\n\
    \            }\n        }\n        cout << left << \" \";\n    }\n    cout <<\
    \ \"\\n\";\n}"
  dependsOn:
  - myLibrary/rollinghash.hpp
  isVerificationFile: true
  path: verify_tests/rollinghash/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-03-03 02:37:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_tests/rollinghash/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/verify_tests/rollinghash/z_algorithm.test.cpp
- /verify/verify_tests/rollinghash/z_algorithm.test.cpp.html
title: verify_tests/rollinghash/z_algorithm.test.cpp
---
