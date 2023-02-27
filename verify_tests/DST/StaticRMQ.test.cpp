#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

// 提出時にassertはオフ
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "proconLibrary/DST.hpp"

#define ALL(x) (x).begin(), (x).end()
template <class T> using vec = vector<T>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vec<int> A(N);
    for(int &a : A) cin >> a;
    DisjointSparseTable<int> dst(A, [](int a, int b){return min(a, b);});
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        cout << dst.query(l ,r) << "\n";
    }
}