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

class ReturnToHome {
public:
    double goHome(int X, int Y, int D, int T) {
	double ret=0;
	double Z=sqrt(pow(X,2) + pow(Y,2));
	
	//only walk:
	double t1=Z;

	//only jump:
	double t2=DBL_MAX;
	double dj=D;//total jump dist
	while(dj<Z) dj+=D;
	debug("dj", dj);
	t2=(dj/D)*T;
	if(dj<2*D) t2=t2+T;
	
	//walk & jump:
	double t3=0;
	double r=Z;
	while(r>D) {
	    r=r-D;
	    t3=t3+T;
	}
	t3 = t3 + min(r, T + D-r);
	
	debug(t1, t2, t3);
	ret=min(t1, t2);
	ret=min(ret, t3);
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
	{ { 6, 8, 5, 3 }, {6.0} },
	{ { 3, 4, 6, 3 }, {4.0} },
	{ { 400, 300, 150, 10 }, {40.0} },
	{ { 318, 445, 1200, 800 }, {546.9451526432975} },
	{ { 6, 8, 3, 2 }, {7.0} },
	{ { 10, 10, 1000, 5 }, {10.0} },
	// Your custom test goes here:
	//{ { , , , }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    int p0;int p1;int p2;int p3;

    double run(ReturnToHome* x) {
	return x->goHome(p0,p1,p2,p3);
    }
    void print() { Tester::printArgs(p0,p1,p2,p3); }
};

int main() {
    return Tester::runTests<ReturnToHome>(
					  getTestCases<input, Tester::output<double>>(), disabledTest,
					  500, 1484560450, CASE_TIME_OUT, Tester::COMPACT_REPORT
					  );
}
// CUT end
