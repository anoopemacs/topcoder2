#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
#define dump(x) // Just strip off all dump tokens
using namespace std;
typedef long long int64;

// CUT begin
#undef dump
#define dump(x) cerr << #x << " = " << (x) << endl;
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

class ApproximateDivision {
 public:
    double quotient(int a, int b, int terms) {
	int t=1;
	while(t<b) t=2*t;
	int c = t-b;
	debug("b,t,c", b, t, c);

	double ret = 0;

	for(int i=0; i<terms; ++i) {
	    double num = pow(c, i);
	    double den = pow(t, i+1);
	    ret = ret + (double)num/(double)den;
	}
	
	return ret*a;
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
    { { 2, 5, 2 }, {0.34375} },
    { { 7, 8, 5 }, {0.875} },
    { { 1, 3, 10 }, {0.33333301544189453} },
    { { 1, 10000, 2 }, {8.481740951538086E-5} },
    { { 1, 7, 20 }, {0.14285714285714285} },
    { { 0, 4, 3 }, {0.0} },
    { { 50, 50, 1 }, {0.78125} },
    // Your custom test goes here:
    //{ { , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;int p2;

        double run(ApproximateDivision* x) {
            return x->quotient(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<ApproximateDivision>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            500, 1488733420, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
