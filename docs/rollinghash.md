---
title: rollinghash
documentation_of: ../myLibrary/rollinghash.hpp
---

### 概要
文字列を数字とみなすことで文字列一致判定を高速に行う

### 使い方
- `rolhash(vector<T> &vec)` または `rolhash-(string &str)` : $O(n)$ で構築  
- `query(int l, int r)` :  $O(1)$ で連続する部分列 $[l, r)$ にあたるhash値(rolhash_mod型)を返す  
- `get_basebeki(int beki)` : $O(1)$ で内部でランダムに生成しているbaseのbeki乗を返す  
- `get_front(int i)` : $O(1)$ で連続する部分列 $[0, i)$ にあたるhash値を返す

[参照したサイト](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)