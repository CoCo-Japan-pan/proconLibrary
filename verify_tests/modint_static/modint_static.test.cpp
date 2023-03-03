#define PROBLEM "https://yukicoder.me/problems/no/2007"

// 提出時にassertはオフ
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#endif

#include <bits/stdc++.h>
#include "myLibrary/modint_static.hpp"
using namespace std;
using mint = mint1000000007;
using ll = long long;

#define ALL(x) (x).begin(), (x).end()
template <class T> using vec = vector<T>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, n;
    cin >> a >> n;
    mint ans(a);
    ans = ans.pow(n);
    cout << 1000000007 << "\n"; 
    cout << ans.val() << "\n";
}