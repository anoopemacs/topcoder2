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

class LameKnight {
 public:
    int maxCells(int h, int w) {
	if(h==1) return 1;
	if(h==2) return min((w+1)/2, 4);
	if(h>=3 && w<=6) return min(w, 4);
	return w-2;
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
    { { 100, 50 }, {48} },
    { { 1, 1 }, {1} },
    { { 17, 5 }, {4} },
    { { 2, 4 }, {2} },
    { { 20, 4 }, {4} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        int run(LameKnight* x) {
            return x->maxCells(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<LameKnight>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488034762, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
