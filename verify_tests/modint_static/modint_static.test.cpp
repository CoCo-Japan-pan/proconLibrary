#define PROBLEM "https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ad"

// 提出時にassertはオフ
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#endif

#include <bits/stdc++.h>
#include "myLibrary/modint_static.hpp"
using namespace std;
using ll = long long;
using mint = mint1000000007;

#define ALL(x) (x).begin(), (x).end()
template <class T> using vec = vector<T>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    mint ans_numer = 1, ans_denom = 1;
    for(int i = 1; i <= n; i++){
        ans_numer *= i;
        if(i == r) ans_denom *= ans_numer;
        if(i == n - r) ans_denom *= ans_numer; 
    }
    mint ans = ans_numer / ans_denom;
    cout << ans.val() << "\n";
}