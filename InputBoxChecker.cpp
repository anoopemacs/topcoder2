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

#define dbg(x) cout << #x << ": " << x << endl

class InputBoxChecker {
public:
    vector<string> checkPrefix(int s, int l, vector<int> n) {
	cout << endl;
	vector<string> ret;
	int N = n.size();
	for(int i=0; i<N; ++i) {
	    int x=n[i];
	    if(x>l) {
		ret.push_back("INVALID");
		continue;
	    } else if (x>=s && x<=l) {
		ret.push_back("VALID");
		continue;
	    } else { // x<s
		
		long multiplier_left=1;
		while((multiplier_left*x+multiplier_left-1)<s) multiplier_left=10*multiplier_left;
		long xs_left=multiplier_left*x;
		long xl_left=multiplier_left*x+multiplier_left-1;
		
		// dbg(x);
		// dbg(multiplier_left);           
        	// dbg(x*multiplier_left);
		
        	long left=(xs_left<s)? s:xs_left;
		
		
		long multiplier_right=1;
		while(x*multiplier_right<=l) multiplier_right=10*multiplier_right;
		multiplier_right=multiplier_right/10;
		
		long xs_right=multiplier_right*x;
		long xl_right=multiplier_right*x+multiplier_right-1;
		long right= (xl_right>l)? l : xl_right;
		
		
		if(left<=l || right>=s) {
		    ret.push_back("VALID");
		} else {
		    ret.push_back("INVALID");
		}
	    }
	}
	
	return ret;
    }
};

// CUT begin
ifstream data("InputBoxChecker.sample");

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

bool do_test(int smallest, int largest, vector<int> numbers, vector<string> __expected) {
    time_t startClock = clock();
    InputBoxChecker *instance = new InputBoxChecker();
    vector<string> __result = instance->checkPrefix(smallest, largest, numbers);
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
        int smallest;
        from_stream(smallest);
        int largest;
        from_stream(largest);
        vector<int> numbers;
        from_stream(numbers);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(smallest, largest, numbers, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1484368580;
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
        cout << "InputBoxChecker (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
