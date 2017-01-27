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

#include <cstring>
#include <ctime>
#include <set>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <iomanip>

using namespace std;

class XBallGame {
public:
    vector<string> newStatistics(vector<string> placeboard) {
	vector<string> ret;
	for (int i=0; i!=(int)placeboard.size(); ++i) {
	    string pi = placeboard[i];
	    int dash = pi.find("-");
	    string name = pi.substr(0, dash);
	    string position = pi.substr(dash+1, 2);
	    
            vector<string> positions;
	    for (int j=0; j!=(int)placeboard.size(); ++j) {
		string pj = placeboard[j];
		int dash2 = pj.find("-");
		string name2 = pj.substr(0, dash2);
		string position2 = pj.substr(dash2+1, 2);
		if (name2 == name) {
		    positions.push_back(position2);
		}
            }
	    sort(positions.begin(), positions.end());
	    
	    string tail = position;
	    for (int j=0; j!=(int)positions.size(); ++j) {
	    	if (positions[j] != position) {
		    tail = tail + "," + positions[j];
	    	}
	    }
	    string topush = name + "-" + tail;
	    ret.push_back(topush);
	}
	return ret;
    }
};

// CUT begin
ifstream data("XBallGame.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<string> placeboard, vector<string> __expected) {
    time_t startClock = clock();
    XBallGame *instance = new XBallGame();
    vector<string> __result = instance->newStatistics(placeboard);
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
        vector<string> placeboard;
        from_stream(placeboard);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(placeboard, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1482931245;
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
        cout << "XBallGame (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
