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

double mem[1000006];

class TheDiceGame {
 public:
    double expectedThrows(int candies) {
	memset(mem, 0, sizeof(mem));    

	mem[0] = 0.0;
	mem[1] = 1.0;
	
	for(int c=2; c<=candies; ++c) {
	    double ret = 1.0 + (1/6.0*mem[max(c-1, 0)]) + (1/6.0*mem[max(c-2, 0)]) + (1/6.0*mem[max(c-3, 0)])
		+ (1/6.0*mem[max(c-4, 0)]) + (1/6.0*mem[max(c-5, 0)]) + (1/6.0*mem[max(c-6, 0)]);
	    mem[c] = ret;
	}
	
	return mem[candies];
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
    { { 1 }, {1.0} },
    { { 2 }, {1.1666666666666667} },
    { { 7 }, {2.5216263717421126} },
    { { 47 }, {13.90476189046144} },
    //{ { 757158}, {} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;

        double run(TheDiceGame* x) {
            return x->expectedThrows(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<TheDiceGame>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            500, 1488047809, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
