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
int mymin(int a, int b) {
    return min(a,b);
}

class Hotel {
public:
    int marketCost(int minCustomers, vector<int> customers, vector<int> cost) {
	int N = cost.size();
	vector<int> dp(101+minCustomers);
	
	for(int mc=1; mc<=minCustomers; ++mc) {
	    int run = INT_MAX;
	    for(int i=0; i<N; ++i) {
		run = min(cost[i]+dp[100+mc-customers[i]], run);
	    }
	    dp[100+mc] = run;
	}
	return dp[100+minCustomers];
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
    { { 10, {1,2,3}, {3,2,1} }, {4} },
    { { 10, {1,2,3,4,5,6,7,8,9,10}, {1,2,3,4,5,6,7,8,9,10} }, {10} },
    { { 12, {5,1}, {3,1} }, {8} },
    { { 100, {9,11,4,7,2,8}, {4,9,3,8,1,9} }, {45} },
    // Your custom test goes here:
    //{ { , {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;vector<int> p1;vector<int> p2;

        int run(Hotel* x) {
            return x->marketCost(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<Hotel>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1486237358, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
