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

#define DEBUG(x) cout << #x << ": " << x << "\n"

class PartSorting {
public:
    vector<int> process(vector<int> data, int nSwaps) {
	cout << endl;
	int N = data.size();
	
	int l=0;
	
	while(nSwaps>0 && l<N) {
	    
	    int big=data[l]; int r=l;
	    int swapCount=0;
	    
	    for(int i=l+1; swapCount<nSwaps && i<N; ++i, ++swapCount) {
		if(data[i]>big) {
		    big=data[i];
		    r=i;
		}
	    }
	    
	    for(int i=r; i>l; --i) {
		data[i] = data[i-1];
	    }
	    data[l] = big;
	    
	    nSwaps=nSwaps-(r-l);
	    ++l;            
	}

	return data;
    }
};

// CUT begin
ifstream data("PartSorting.sample");

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

bool do_test(vector<int> data, int nSwaps, vector<int> __expected) {
    time_t startClock = clock();
    PartSorting *instance = new PartSorting();
    vector<int> __result = instance->process(data, nSwaps);
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
	vector<int> data;
	from_stream(data);
	int nSwaps;
	from_stream(nSwaps);
	next_line();
	vector<int> __answer;
	from_stream(__answer);

	cases++;
	if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
	    continue;

	cout << "  Testcase #" << cases - 1 << " ... ";
	if ( do_test(data, nSwaps, __answer)) {
	    passed++;
	}
    }
    if (mainProcess) {
	cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
	int T = time(NULL) - 1484284729;
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
	cout << "PartSorting (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
