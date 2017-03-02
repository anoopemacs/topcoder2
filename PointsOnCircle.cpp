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

class PointsOnCircle {
public:
    long long count(int R) {
	long long r = R;
	vector<long long> divisors;
	
	long long run = r;
	
	for(long long d=1; d*d<=run; ++d)
	    if(run%d == 0) {
		divisors.push_back(d);
		if(d != run/d) divisors.push_back(run/d);
	    }
	

	int sz = divisors.size();

	for(int i=0; i<sz; ++i) {
	    for(int j=i; j<sz; ++j) {
		long long prod = divisors[i]*divisors[j];
		divisors.push_back(prod);
	    }
	}

	sort(divisors.begin(), divisors.end());
	vector<long long>::iterator iter = unique(divisors.begin(), divisors.end());
	vector<long long> divs = vector<long long>(divisors.begin(), iter);
	
	debug(divs);

	long long D1 = 0;
        long long D3 = 0;

	for(int i=0; i<divs.size(); ++i) {
	    if(divs[i]%4 == 1) ++D1;
	    else if (divs[i]%4 == 3) ++D3;
	}
	
	
	return 4*(D1-D3);
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
    { { 1 }, {4LL} },
    { { 2000000000 }, {76LL} },
    { { 3 }, {4LL} },
    { { 1053 }, {12LL} },
    { {36664725}, {60}},
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;

        long long run(PointsOnCircle* x) {
            return x->count(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<PointsOnCircle>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            600, 1487701742, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
