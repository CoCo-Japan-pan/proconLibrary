#define PROBLEM = "https://yukicoder.me/problems/no/1092"
// 提出時にassertはオフ
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#endif

#include <bits/stdc++.h>
#include "myLibrary/modint_dynamic.hpp"
using namespace std;
using ll = long long;

#define ALL(x) (x).begin(), (x).end()
template <class T> using vec = vector<T>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int P, N;
    cin >> P >> N;
    vec<int> A(N);
    for(int &a : A) cin >> a;
    string S;
    cin >> S;
    modint_dynamic::set_mod(P);
    // cout << modint_dynamic::get_mod() << "\n";
    modint_dynamic ans(A[0]);
    for(int i = 1; i < N; i++){
        if(S[i - 1] == '+') {
            ans += A[i];
        } else if(S[i - 1] == '-') {
            ans -= A[i];
        } else if(S[i - 1] == '*') {
            ans *= A[i];
        } else {
            ans /= A[i];
        }
    }
    cout << ans.val() << "\n";
}