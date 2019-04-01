#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Radix conversion of a certain decimal integer.
 *
 * You can choose any integer, including negative integers, as a decimal integer and a radix.
 * (NOTE) It do not support too big or small integers.
 *
 * @param N, B : N to be converted to radix, B is a radix.
 * @return A vector containing the value of each digit of the converted integer.
 **/

// CUT begin
template<typename T>
vector<T> radixConvertion(T N, T B) {
    vector<T> convertedNum;
    T n = 1, b = abs(B);
    while (N) {
        convertedNum.emplace_back((N * n) % b);
        if (convertedNum.back() < 0) convertedNum.back() += b;
        N -= convertedNum.back() * n;
        N /= b;
        n *= (B / b);
    }
    if (convertedNum.empty()) convertedNum.emplace_back(0);
    reverse(convertedNum.begin(), convertedNum.end());
    return convertedNum;
}
//CUT end


int main() {
    // As an example, convert 4 in decimal notation to -2 base number.
    ll N = 4, B = -2;
    auto res = radixConvertion(N, B);
    for (auto d : res)cout << d;
    cout << endl;
    
    return 0;
}
