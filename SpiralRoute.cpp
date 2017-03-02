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

class SpiralRoute {
public:
    vector<int> thronePosition(int w, int l) {
	vector<int> ret(2);
	int W=0, S=0, E=w-1, N=l-1;
	
	int count = w*l;
	int x=0, y=0;
	--count;
	
	while(count > 0) {
	    
	    while(x!=E && count>0) {
		++x;
		--count;
	    }
	    ++S;
	    
	    while(y!=N && count>0) {
		++y;
		--count;
	    }
	    --E;

	    //	    debug("x:", x, " and y:", y, count);
	    
	    while(x!=W && count>0) {
		--x;
		--count;
	    }
	    --N;

	    while(y!=S && count>0) {
		--y;
		--count;
	    }
	    ++W;

	    //debug("x:", x, " and y:", y, count);
        }
        ret[0]=x;
	ret[1]=y;
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
    { { 6, 4 }, { {1,2} } },
    { { 6, 5 }, { {3,2} } },
    { { 1, 11 }, { {0,10} } },
    { { 12, 50 }, { {5,6} } },
    { { 5000, 5000 }, { {2499,2500} } },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        vector<int> run(SpiralRoute* x) {
            return x->thronePosition(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SpiralRoute>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            500, 1487724832, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
