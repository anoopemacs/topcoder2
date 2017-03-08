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

class ConcatenateNumber {
    string myits(int i) {
        stringstream ss;
        ss<<i;
        string ret;
        ss>>ret;
        return ret;
    }
    
public:
    int getSmallest(int number, int k) {
	string ns = myits(number);
	int64 L = ns.length();
	int64 num = number;
	int64 rem = num%k;
	if(rem==0) return 1;
	debug(rem, L);
	
	int64 ret = 1;
	//npk = n%k

	set<int> remset;
	//remset.insert(rem);
	
	for(int64 npk = rem; npk != 0; npk = ((npk*((int64)pow(10,L)))%k + rem)%k ) {
	    //debug("npk, k, rem, L", npk, k, rem, L);
	    debug("npk", npk);
	    
	    if(remset.find(npk) != remset.end()) return -1;         
            remset.insert(npk);
	    
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
    { { 2, 9 }, {9} },
    { { 121, 11 }, {1} },
    { { 1, 2 }, {-1} },
    //{ { 35, 98765 }, {9876} },
    { { 1000000000, 3 }, {3} },
    { {96927, 146}, {-1}},
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        int run(ConcatenateNumber* x) {
            return x->getSmallest(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<ConcatenateNumber>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488734818, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
