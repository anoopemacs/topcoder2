// changed the symlink

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

class IndicatorMotionReverse {
public:
    string syms = "-N|/";
    string ops = "RLFS";
    char get_op (char before, char after) {
        int dif = syms.find(after) - syms.find(before);
        switch(dif) {
        case 1:
        case -3:
            return 'R';
        case -1:
        case 3:
            return 'L';
        case -2:
        case 2:
            return 'F';
        case 0:
            return 'S';
        default:
            printf("error in switch0");
        }
        return 'z';
    }
    string getMinProgram(vector<string> actions) {
        string ret;
        string in;
        for (int i=0; i!=actions.size(); ++i) {
            in += actions[i];
        }
        if (in.size() <= 1) return "";
	
        string verbose;
        for (int i=1; i!=in.size(); ++i) {
            verbose += get_op(in[i-1], in[i]);
        }
	
        //        cout << verbose << endl;
        int i = 0;
        while(i<(int)verbose.size()) {
            int j = i;
            int count = 0;
            char key = verbose[i];
	    
            while(verbose[j] == verbose[i] && j < verbose.size()) {
                ++j;
                ++count;
            }
	    int q = count / 99;
            int r = count % 99;
            if (r != 0) {
                ret = ret + key;
                ret += (char)r/10 + '0';
                ret += (char)r%10 + '0';
            }
            for (int i=0; i!=q; ++i) {
                ret = ret + key + "99";
            }
            i = j;
        }
	
        if (ret.size() > 100) {
            ret = ret.substr(0, 97) + "...";
        }
        return ret;
    }
};

// CUT begin
ifstream data("IndicatorMotionReverse.sample");

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

bool do_test(vector<string> actions, string __expected) {
    time_t startClock = clock();
    IndicatorMotionReverse *instance = new IndicatorMotionReverse();
    string __result = instance->getMinProgram(actions);
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
        vector<string> actions;
        from_stream(actions);
        next_line();
        string __answer;
        from_stream(__answer);
        
        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;
        
        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(actions, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1482925436;
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
        cout << "IndicatorMotionReverse (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
