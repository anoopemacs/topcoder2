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

class StrongPrimePower {
    long long mystl(string s) {
        stringstream ss;
        ss<<s;
        long long ret;
        ss>>ret;
        return ret;
    }
public:
    vector<int> baseAndExponent(string n) {
	vector<int> ret;
	int64 N = mystl(n);

	debug(N);
	for(int64 q=2; q<=59; ++q) {
	    long double pd = pow(N, 1.0/q);
	    int64 pdi = round(pd);

	    int64 nr=1L;
	    for(int z=0; z<q; ++z) nr = nr*pdi;
	    
	    if(nr == N) {
		//check if pdi is prime:
		bool isprime = true;
		for(int64 i=2; i*i<=pdi; ++i) {
		    if(pdi%i == 0) {
			isprime = false;
			break;
		    }
		}
		if(isprime==true) {
		    ret.push_back(pdi);
		    ret.push_back(q);
		    return ret;
		}
	    }
	    
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
	{ { "27" }, { {3,3} } },
	{ { "10" }, { {} } },
	{ { "7" }, { {} } },
	{ { "1296" }, { {} } },
	{ { "576460752303423488" }, { {2,59} } },
	{ { "999999874000003969" }, { {999999937,2} } },
	{ {"26293188972239280"}, { {} } },
	// Your custom test goes here:
	//{ { }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    string p0;

    vector<int> run(StrongPrimePower* x) {
	return x->baseAndExponent(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<StrongPrimePower>(
					      getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
					      500, 1488975022, CASE_TIME_OUT, Tester::COMPACT_REPORT
					      );
}
// CUT end
