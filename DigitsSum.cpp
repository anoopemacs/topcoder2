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

class DigitsSum {
public:
    int lastDigit(int n) {
	int ret = 0;
	while(n!=0) {
	    ret += n%10;
	    n/=10;
	}
	while(ret>9) {
	    ret=lastDigit(ret);
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
	{ { 12345 }, {6} },
	{ { 6 }, {6} },
	{ { 999999999 }, {9} },
	{ { 213413512 }, {4} },
	{ { 314 }, {8} },
	{ { 2147483647 }, {1} },
	// Your custom test goes here:
	//{ { }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    int p0;

    int run(DigitsSum* x) {
	return x->lastDigit(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<DigitsSum>(
				       getTestCases<input, Tester::output<int>>(), disabledTest, 
				       500, 1484551352, CASE_TIME_OUT, Tester::COMPACT_REPORT
				       );
}
// CUT end
