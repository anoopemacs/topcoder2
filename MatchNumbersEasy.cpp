#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl

string dp[51]; // n=[1,50] 1-based index, n=no. of matches

class MatchNumbersEasy {
public:
    string maxNumber(vector<int> matches, int n) {
	for(int i=0; i<51; ++i) dp[i]="";
	int N = matches.size();
	
	for(int i=0; i<N; ++i) {
	    dp[matches[i]] = (char)('0'+i);
	}
	
	for(int i=2; i<=n; ++i) {
	    for(int j=0; j<=i/2; ++j) {
		string run = dp[j]+dp[i-j];
		sort(run.begin(), run.end());
		reverse(run.begin(), run.end());
		if((run.size()>dp[i].size() &&   run[0]!='0') || (run.size()==dp[i].size() && run>dp[i]))
		    dp[i]=run;
	    }
	}
	string ret = dp[n];
	if(count(ret.begin(), ret.end(), '0')==ret.size()) return "0";
	return ret;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
	{ { {6,7,8}, 21 }, {"210"} },
	{ { {5,23,24}, 30 }, {"20"} },
	{ { {1,5,3,2}, 1 }, {"0"} },
	{ { {1,1,1,1,1,1,1,1,1,1}, 50 }, {"99999999999999999999999999999999999999999999999999"} },
	// Your custom test goes here:
	//{ { {}, }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<int> p0;int p1;
    
    string run(MatchNumbersEasy* x) {
	return x->maxNumber(p0,p1);
    }
    void print() { Tester::printArgs(p0,p1); }
};

int main() {
    return Tester::runTests<MatchNumbersEasy>(
					      getTestCases<input, Tester::output<string>>(), disabledTest, 
					      500, 1484476403, CASE_TIME_OUT, Tester::COMPACT_REPORT
					      );
}
// CUT end
