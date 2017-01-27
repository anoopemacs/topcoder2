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
#include <cstdlib> // malloc
#include <climits>
#include <utility> // pair

#include <cstring>
#include <ctime>
#include <set>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <iomanip>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << "n"

class ScoreRecomposition {
public:
    int mod(int x) {
	if(x<0) return x*(-1);
	return x;
    }
    
    int error(vector<int> v) {
	int ret = INT_MIN;
	for(int i=1; i<=v.size(); ++i) {
	    ret = max(ret, mod(i-v[i-1]));
	}
	return ret;
    }
    
    int minError(string q, int score) {
	cout << endl;
	int N = q.size();
	
	vector<int> p;
	for(int i=1; i<=N; ++i) p.push_back(i);
	int rerror=INT_MAX;
	
	do {
	    int rscore = 0;
	    for(int i=0; i<N; ++i) {
		if(q[i]=='C') rscore+=p[i];
	    }
	    if(rscore==score) {
		rerror = min(rerror, error(p));
	    }
	} while(next_permutation(p.begin(), p.end()));
	
	if(rerror != INT_MAX) return rerror;
	return -1;
    }
};

// CUT begin
ifstream data("ScoreRecomposition.sample");

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

bool do_test(string questions, int score, int __expected) {
    time_t startClock = clock();
    ScoreRecomposition *instance = new ScoreRecomposition();
    int __result = instance->minError(questions, score);
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
        string questions;
        from_stream(questions);
        int score;
        from_stream(score);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(questions, score, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1484308078;
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
        cout << "ScoreRecomposition (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
