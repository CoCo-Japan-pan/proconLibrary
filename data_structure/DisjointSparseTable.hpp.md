---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_tests/DST/StaticRMQ.test.cpp
    title: verify_tests/DST/StaticRMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/DisjointSparseTable.hpp\"\n\n#ifdef NOBUNDLE\n\
    #include<bits/stdc++.h>\nusing namespace std;\n#endif\n\n// \u9759\u7684\u306A\
    \u534A\u7FA4\u5217\u306E\u533A\u9593\u548C\u3092\u9AD8\u901F\u306B\u8A08\u7B97\
    \u3059\u308B\n// \u534A\u7FA4: \u4E8C\u9805\u6F14\u7B97\u304C\u5B9A\u7FA9\u3055\
    \u308C\u3066\u3001\u7D50\u5408\u6CD5\u5247\u3092\u6E80\u305F\u3059\u3001\u5358\
    \u4F4D\u5143\u3082\u9006\u5143\u3082\u4E0D\u8981 (min, max, \u548C, \u7A4D, gcd)\n\
    // \u66F4\u65B0\u306F\u3067\u304D\u306A\u3044\u304C\u3001\u30AF\u30A8\u30EA\u306F\
    O(1)!!! (\u524D\u8A08\u7B97\u306BO(nlogn))\n\ntemplate <class T>\nstruct DST {\n\
    \    using OperatorType = function<T(T, T)>;\n\n   public:\n    DST(const vector<T>\
    \ &vec, const OperatorType &op_) : size(vec.size()), op(op_) {\n        int depth\
    \ = 1;\n        while((1 << depth) <= size) depth++;\n        data.assign(depth,\
    \ vector<T>(size));\n        MSSBTable.resize((1 << depth), 0);\n        for(int\
    \ i = 0; i < size; i++) {\n            data[0][i] = vec[i];\n        }\n     \
    \   for(int i = 2; i < (1 << depth); i++){\n            MSSBTable[i] = MSSBTable[i\
    \ >> 1] + 1;\n        }\n\n        for(int a = 1; a < depth; a++) {\n        \
    \    int maxLen = 1 << a;\n            for(int b = 0; b < size; b += (maxLen <<\
    \ 1)){\n                // [l, middle)\n                int middle = min(b + maxLen,\
    \ size);\n                data[a][middle - 1] = vec[middle - 1];\n           \
    \     for(int l = middle - 2; l >= b; l--){\n                    data[a][l] =\
    \ op_(vec[l], data[a][l + 1]);\n                }\n                if(middle ==\
    \ size) break;\n                // [middle, r]\n                data[a][middle]\
    \ = vec[middle];\n                for(int r = middle + 1; r < min(middle + maxLen,\
    \ size); r++){\n                    data[a][r] = op_(data[a][r - 1], vec[r]);\n\
    \                }\n            }   \n        }\n    }\n\n    // [l, r)\u306E\u533A\
    \u9593\u3067\u306E\u8A08\u7B97\u7D50\u679C\u3092O(1)\u3067\u53D6\u5F97\n    T\
    \ query(int l, int r) const {\n        assert(l < r);\n        assert(0 <= l &&\
    \ r <= size);\n        if(l >= --r) return data[0][l];\n        return op(data[MSSBTable[l\
    \ ^ r]][l], data[MSSBTable[l ^ r]][r]);\n    }\n\n   private:\n    const int size;\n\
    \    const OperatorType op;\n    vector<vector<T>> data; // data[i][j]\u3067\u3001\
    [j, MSSB) \u307E\u305F\u306F [MSSB, j]\n    vector<int> MSSBTable;  // most significant\
    \ set bit\n};\n"
  code: "#pragma once\n\n#ifdef NOBUNDLE\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n// \u9759\u7684\u306A\u534A\u7FA4\u5217\u306E\u533A\u9593\u548C\
    \u3092\u9AD8\u901F\u306B\u8A08\u7B97\u3059\u308B\n// \u534A\u7FA4: \u4E8C\u9805\
    \u6F14\u7B97\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3001\u7D50\u5408\u6CD5\u5247\
    \u3092\u6E80\u305F\u3059\u3001\u5358\u4F4D\u5143\u3082\u9006\u5143\u3082\u4E0D\
    \u8981 (min, max, \u548C, \u7A4D, gcd)\n// \u66F4\u65B0\u306F\u3067\u304D\u306A\
    \u3044\u304C\u3001\u30AF\u30A8\u30EA\u306FO(1)!!! (\u524D\u8A08\u7B97\u306BO(nlogn))\n\
    \ntemplate <class T>\nstruct DST {\n    using OperatorType = function<T(T, T)>;\n\
    \n   public:\n    DST(const vector<T> &vec, const OperatorType &op_) : size(vec.size()),\
    \ op(op_) {\n        int depth = 1;\n        while((1 << depth) <= size) depth++;\n\
    \        data.assign(depth, vector<T>(size));\n        MSSBTable.resize((1 <<\
    \ depth), 0);\n        for(int i = 0; i < size; i++) {\n            data[0][i]\
    \ = vec[i];\n        }\n        for(int i = 2; i < (1 << depth); i++){\n     \
    \       MSSBTable[i] = MSSBTable[i >> 1] + 1;\n        }\n\n        for(int a\
    \ = 1; a < depth; a++) {\n            int maxLen = 1 << a;\n            for(int\
    \ b = 0; b < size; b += (maxLen << 1)){\n                // [l, middle)\n    \
    \            int middle = min(b + maxLen, size);\n                data[a][middle\
    \ - 1] = vec[middle - 1];\n                for(int l = middle - 2; l >= b; l--){\n\
    \                    data[a][l] = op_(vec[l], data[a][l + 1]);\n             \
    \   }\n                if(middle == size) break;\n                // [middle,\
    \ r]\n                data[a][middle] = vec[middle];\n                for(int\
    \ r = middle + 1; r < min(middle + maxLen, size); r++){\n                    data[a][r]\
    \ = op_(data[a][r - 1], vec[r]);\n                }\n            }   \n      \
    \  }\n    }\n\n    // [l, r)\u306E\u533A\u9593\u3067\u306E\u8A08\u7B97\u7D50\u679C\
    \u3092O(1)\u3067\u53D6\u5F97\n    T query(int l, int r) const {\n        assert(l\
    \ < r);\n        assert(0 <= l && r <= size);\n        if(l >= --r) return data[0][l];\n\
    \        return op(data[MSSBTable[l ^ r]][l], data[MSSBTable[l ^ r]][r]);\n  \
    \  }\n\n   private:\n    const int size;\n    const OperatorType op;\n    vector<vector<T>>\
    \ data; // data[i][j]\u3067\u3001[j, MSSB) \u307E\u305F\u306F [MSSB, j]\n    vector<int>\
    \ MSSBTable;  // most significant set bit\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2023-02-28 16:41:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_tests/DST/StaticRMQ.test.cpp
documentation_of: data_structure/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/data_structure/DisjointSparseTable.hpp
- /library/data_structure/DisjointSparseTable.hpp.html
title: data_structure/DisjointSparseTable.hpp
---
