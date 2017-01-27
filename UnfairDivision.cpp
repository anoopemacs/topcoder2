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

class UnfairDivision {
public:
    int albertsShare(vector<int> ass) {
	cout << endl;
	int N = ass.size();
	
	int bestAlbert = 0;
        for (int i=1; i<=N-1; ++i) {
	    
	    int albert = 0;
	    int bestBetty = 0;
	    for(int j=1; j<=N-1; ++j) {
		if (i==j) continue;
		int p=min(i,j); int q=max(i,j);
		
		// 3 parts:
		int p1 = sum(0, p, ass);
		int p2 = sum(p, q, ass);
		int p3 = sum(q, N, ass);
		
		if(p1>p2) swap(p1, p2);
		if(p2>p3) swap(p2, p3);
		if(p1>p2) swap(p1, p2);
		
		if(p2>bestBetty || (p2==bestBetty && p1<albert)) {
		    albert = p1;                    
		    bestBetty = p2;
		}
	    }
	    
	    
	    bestAlbert = max(albert, bestAlbert);
	}
	
	return bestAlbert;
    }
    
    int sum(int b, int e, vector<int> ass) {
	
	int ret = 0;
	for (int i=b; i!=e; ++i) {
	    ret += ass[i];
	}
	return ret;
    }
};

// CUT begin
ifstream data("UnfairDivision.sample");

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

bool do_test(vector<int> assets, int __expected) {
    time_t startClock = clock();
    UnfairDivision *instance = new UnfairDivision();
    int __result = instance->albertsShare(assets);
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
        vector<int> assets;
        from_stream(assets);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(assets, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1483029444;
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
        cout << "UnfairDivision (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
