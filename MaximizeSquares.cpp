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

class MaximizeSquares {
public:
    int F(int M) {
	if(M==0 || M==1) return 0;
	return F(M-1) + (M-1)*(M-1);
    }
    
    int squareCount(int N) {	
	int M = (int)sqrt(N);
	int extra = N-M*M;
	//todo: learn master method
	int fromBlock = F(M);
	debug("M, F(M):", M, F(M));
	
	int points_used = 0;
	int fromExtra = 0;

	debug("extra", extra);

	for(int i=1; i<(M+1) && points_used<extra; ++i) {
	    fromExtra = fromExtra + (i-1);
	    ++points_used;
	    //cout << "*" << i << "*" << endl;
	}
	debug("points_used", points_used);
	++points_used;
	debug("points_used", points_used);
	
	if(points_used < extra) {
	    for(int i=0; i<(extra-points_used); ++i) {
		fromExtra = fromExtra + (i+1);
	    }
	}
	debug(fromBlock, fromExtra);
	
	return fromBlock + fromExtra;
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
    { { 4 }, {1} },
    { { 5 }, {1} },
    { { 6 }, {2} },
    { { 16 }, {14} },
    { { 115 }, {340} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;

        int run(MaximizeSquares* x) {
            return x->squareCount(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<MaximizeSquares>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1486366452, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
