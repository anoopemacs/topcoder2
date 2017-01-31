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

class KLastNonZeroDigits {
public:
    string mylts(long l) {
        stringstream ss;
        ss<<l;
        string ret;
        ss>>ret;
        return ret;
    }

    string getKDigits(int N, int K) {
	long n=N;
	long fact=1;
	while(n>0) {
	    fact=fact*n;
	    --n;
	}
	string factString = mylts(fact);
	int ns=factString.size();
	for(int i=ns-1; factString[i]=='0'; --i) {
	    factString[i]='a';
	}
	string::iterator iter = remove(factString.begin(),factString.end(), 'a');
	string factStringMod = string(factString.begin(), iter);

	int fsn = factStringMod.size();
	
	string ret;
	for(int i=fsn-1, k=0; (i>=0) && (k<K); --i, ++k) {
	    ret = factStringMod[i]+ret;
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
    { { 10, 3 }, {"288"} },
    { { 6, 1 }, {"2"} },
    { { 6, 3 }, {"72"} },
    { { 7, 2 }, {"04"} },
    { { 20, 9 }, {"200817664"} },
    { { 1, 1 }, {"1"} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        string run(KLastNonZeroDigits* x) {
            return x->getKDigits(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<KLastNonZeroDigits>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1485848502, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
