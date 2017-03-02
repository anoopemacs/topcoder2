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

typedef long long int64;

class SquaresInsideLattice {
public:
    //I read editorial before solving
    int64 type1(int64 w, int64 h) {
	int64 ret = 0;
	for(int i=0; i<min(w, h); ++i) {
            ret = ret + (w-i)*(h-i)*(i+1);
        }
        return ret;
    }
    
    int64 howMany(int width, int height) {
	int64 w = width, h = height;
	int64 t1 = type1(w, h);
	
	return t1;
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
    { { 1, 1 }, {1LL} },
    { { 2, 3 }, {10LL} },
    { { 3, 3 }, {20LL} },
    { { 27, 19 }, {23940LL} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        long long run(SquaresInsideLattice* x) {
            return x->howMany(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SquaresInsideLattice>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            500, 1487999847, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
