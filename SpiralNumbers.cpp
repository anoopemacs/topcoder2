#include <cstdio>
#include <string>
#include <cctype>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <climits>

#include <cstring>
#include <ctime>
#include <set>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <iomanip>
#include <utility>

using namespace std;

class SpiralNumbers {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    string getPosition(int N) {
	if (N == 0) return "(0,0)";
	pair<int, int> ret = make_pair(0, 0);
	int d = 0;
	long long cur = 1;
	for(int i=1;;++i) {
	    if (cur+i >= N) return convert(ret.first + (N-cur)*dx[d], ret.second + (N-cur)*dy[d]);
	    ret.first += i*dx[d];
	    ret.second += i*dy[d];
	    cur += i;
	    d = (d+1) % 4;
	    
	    if (cur+i >= N) return convert(ret.first + (N-cur)*dx[d], ret.second + (N-cur)*dy[d]);
            ret.first += i*dx[d];
            ret.second += i*dy[d];
            cur += i;
            d = (d+1) % 4;
        }
    }
    string convert(int x, int y) {
	return "(" + tostr(x) + "," + tostr(y) + ")";
    }
    string tostr(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
    }
};

// CUT begin
ifstream data("SpiralNumbers.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int N, string __expected) {
    time_t startClock = clock();
    SpiralNumbers *instance = new SpiralNumbers();
    string __result = instance->getPosition(N);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int N;
        from_stream(N);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1482941916;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "SpiralNumbers (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
