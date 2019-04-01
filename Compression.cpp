#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Compression of a vector containing a large range of numbers.
 *
 * (NOTE) Instead of supporting a large range of numbers,
 *        the size of the vector should be modest.
 *
 * @param rawData : a vector you want to compress.
 * @return res : a map that maps the values of a given vector to compressed values.
 **/

// CUT begin
template<class T>
map<T, int> Compression(vector<T> rawData) {
    sort(rawData.begin(), rawData.end());
    rawData.erase(unique(rawData.begin(), rawData.end()), rawData.end());
    map<T, int> res;
    for (size_t i = 0; i < rawData.size(); ++i) res[rawData[i]] = i;
    return res;
}
//CUT end


int main() {
    // An example of the output method of all the compressed values is shown below.
    int N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)cin >> A[i];

    auto res = Compression(A);

    for (int i = 0; i < N; i++)cout << res[A[i]] << " ";
    cout << endl;

    return 0;
}
