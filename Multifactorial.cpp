#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
using namespace std;

typedef long long llint;

// CUT begin
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

long biggest = 1e18;

class Multifactorial {
public:
    string mylts(long l) {
	stringstream ss;
	ss<<l;
	string ret;
	ss>>ret;
	return ret;
    }

    string calcMultiFact(int n, int k) {
	//n-x*k, xmax:
	long m=n;
	while((m-k)>0) m=m-k;
	long ret=1;

	for(long i=m; i<=n; i=i+k) {
	    if(ret > biggest/i*1.0) return "overflow";
            ret = ret * i;
	    
	}
	//debug(m, ret/1e18);

	return mylts(ret);
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
    { { 14, 3 }, {"12320"} },
    { { 5, 4 }, {"5"} },
    { { 1000, 2 }, {"overflow"} },
    { { 2000000000, 1900000000 }, {"200000000000000000"} },
    { { 1000, 256 }, {"84232704000"} },
    { { 2000000000, 1 }, {"overflow"} },
    {{423332300, 165035639}, {"overflow"}},
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
	int p0;int p1;

	string run(Multifactorial* x) {
	    return x->calcMultiFact(p0,p1);
	}
	void print() { Tester::printArgs(p0,p1); }
    };

    int main() {
	return Tester::runTests<Multifactorial>(
	    getTestCases<input, Tester::output<string>>(), disabledTest,
	    500, 1485696294, CASE_TIME_OUT, Tester::COMPACT_REPORT
	);
    }
// CUT end
