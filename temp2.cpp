#include <bits/stdc++.h>

using namespace std;

#define dbg(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {
    cerr << str << " : " << t << endl;
}
template <class T, class... S> void dbs(string str, T t, S... s) {
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}

int main() {
    cout << "hello" << endl;
    vector<int> v = {1,2,3,5};
    int i=2;
    int j=3;
    dbg(i, j, v[3]);
}
