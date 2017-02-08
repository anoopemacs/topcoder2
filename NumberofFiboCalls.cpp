#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
using namespace std;

// CUT begin
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

vector<vector<int>> dp;

class NumberofFiboCalls {
public:
    vector<int> fiboCallsMade(int n) {
	vector<int> zero(2);
	vector<int> one(2);
	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;
	dp.push_back(zero);
	dp.push_back(one);

	for(int i=2; i<=n; ++i) {
	    int z,o;
	    z = dp[i-1][0] + dp[i-2][0];
	    o = dp[i-1][1] + dp[i-2][1];
	    vector<int> tp(2);
	    tp[0]=z;
	    tp[1]=o;
	    dp.push_back(tp);
	}
	
	return dp[n];
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
    { { 0 }, { {1,0} } },
    { { 3 }, { {1,2} } },
    { { 6 }, { {5,8} } },
    { { 22 }, { {10946,17711} } },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;

        vector<int> run(NumberofFiboCalls* x) {
            return x->fiboCallsMade(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<NumberofFiboCalls>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            500, 1486026602, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
