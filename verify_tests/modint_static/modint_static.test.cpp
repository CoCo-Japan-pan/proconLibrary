#define PROBLEM "https://yukicoder.me/problems/no/2235"

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
    int N;
    cin >> N;
    vec<ll> x(N);
    for(ll &num : x) cin >> num;
    // ((Σx)^2 - Σx^2) / Σx + 1
    mint sum = 0, sum_square = 0;
    for(int i = 0; i < N; i++){
        sum += x[i];
        sum_square += x[i] * x[i];
    }
    mint ans = sum.pow(2) - sum_square;
    ans /= sum;
    ans++;
    cout << ans.val() << "\n";
}