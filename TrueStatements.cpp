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

class TrueStatements {
 public:
    int numberTrue(vector<int> vi) {
	int ret = -1;
	
	int N = vi.size();
	for(int n=0; n<=N; ++n) {
	    string store = string(N, 'x');
	    for(int i=0; i<N; ++i) {
		if(vi[i]==n) store[i] = 'T';
		else store[i] = 'F';
	    }
	    if(count(store.begin(), store.end(), 'T') == n) ret = max(ret, n);
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
    { { {0,1,2,3} }, {1} },
    { { {0} }, {-1} },
    { { {0,3,1,3,2,3} }, {3} },
    { { {1,1} }, {0} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;

        int run(TrueStatements* x) {
            return x->numberTrue(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<TrueStatements>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488010356, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
