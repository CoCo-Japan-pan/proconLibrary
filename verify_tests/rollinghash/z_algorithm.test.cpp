#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

// 提出時にassertはオフ
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#endif

#include <bits/stdc++.h>
#include "string/rollinghash.hpp"
using namespace std;
using ll = long long;

#define ALL(x) (x).begin(), (x).end()
template <class T> using vec = vector<T>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    rolhash rol(S);
    int N = S.size();
    cout << N << " ";
    for(int i = 1; i < N; i++){
        if(rol.query(i, N) == rol.query(0, N - i)){
            cout << N - i << " ";
            continue;
        }
        // SとS[i, N)の共通接頭辞の長さ
        int left = 0, right = N - i;
        while(right - left > 1){
            // S[0, middle)とS[i, i + middle)を比べる
            int middle = (left + right) / 2;
            if(rol.query(0, middle) == rol.query(i, i + middle)){
                left = middle;
            } else {
                right = middle;
            }
        }
        cout << left << " ";
    }
    cout << "\n";
}