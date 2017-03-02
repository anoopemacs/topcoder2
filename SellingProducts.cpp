#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
using namespace std;
typedef long long int64;

// CUT begin
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end
int mymax(int a, int b) {
    return max(a, b);
}

class SellingProducts {
 public:
    int optimalPrice(vector<int> price, vector<int> cost) {
	//map[price] = profit
	map<int, int> pp;
	int maxPrice = accumulate(price.begin(), price.end(), 0, mymax);
	
	int maxProfit = INT_MIN;
	for(int p=0; p<=maxPrice; ++p) {
	    int runProfit = 0;	
	    for(int i=0; i<cost.size(); ++i) {
		if(p <= price[i])
		    runProfit += max(0, p-cost[i]);
	    }
	    pp[p] = runProfit;
	    maxProfit = max(maxProfit, runProfit);
	}
	debug(pp);
	
	for(int p=0; p<=maxPrice; ++p) {
	    if(pp[p] == maxProfit) return p;
	}
	return -69; //never reached
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
    { { {13,22,35}, {0,0,0} }, {22} },
    { { {13,22,35}, {5,15,30} }, {13} },
    { { {13,22,35}, {15,30,40} }, {0} },
    { { {10,10,20,20,5}, {1,5,11,15,0} }, {10} },
    { { {13,17,14,30,19,17,55,16}, {12,1,5,10,3,2,40,19} }, {17} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        int run(SellingProducts* x) {
            return x->optimalPrice(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SellingProducts>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488033553, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
