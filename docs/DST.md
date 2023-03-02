---
title: Disjoint Sparse Table
documentation_of: ../myLibrary/DisjointSparseTable
---

## Disjoint Sparse Table
#### 概要
静的な半群列、すなわち二項演算が定義されていて結合則が成立する(単位元や逆元は不要)、に対する区間クエリを高速に行う  
#### 使い方
`DST(vector<T> &vec)` $O(nlogn)$ で構築  
`query(int l, int r)` $O(1)$ で区間 $[l, r)$ の演算結果を返す
#### 参照したサイト 
https://noshi91.hatenablog.com/entry/2018/05/08/183946