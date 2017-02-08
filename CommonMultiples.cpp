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

class CommonMultiples {
public:
    static long gcd(long a, long b) {
	for(;;) {
	    if(a==0) return b;
	    b=b%a;
	    if(b==0) return a;
	    a=a%b;
	}
    }

    static long lcm(long a, long b) {
	// lcm*gcd = a*b
	long temp = gcd(a,b);
	return temp? (a/temp*b) : 0;
    }
    
    int countCommMult(vector<int> a, int lower, int upper) {
	long L = 1;
	for(int i=0; i<a.size(); ++i) {
	    L = lcm(a[i], L);
	    if(L>upper) return 0;
	    debug(L);
	}
	
	int ret = 0;
	long run = L;
	while(run < lower) run = run+L;
	while(run <= upper) {
	    run = run+L;
	    ++ret;
	}
	
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
    { { {1,2,3}, 5, 15 }, {2} },
    { { {1,2,4,8,16,32,64}, 128, 128 }, {1} },
    { { {2,3,5,7,11,13,17,19,23,29,31,37,41,43,49}, 1, 2000000000 }, {0} },
    { { {1,1,1}, 1, 2000000000 }, {2000000000} },
    // Your custom test goes here:
    //{ { {}, , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;int p1;int p2;

        int run(CommonMultiples* x) {
            return x->countCommMult(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<CommonMultiples>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485944496, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
