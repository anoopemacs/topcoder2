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

class NoEights {
public:
    string myits(int i) {
        stringstream ss;
        ss<<i;
        string ret;
        ss>>ret;
	while (ret.size()<10)
	    ret = "0"+ret;
        return ret;
    }

    int smallestAmount(int low, int high) {
	string l = myits(low);
	string h = myits(high);
	string common = "";
	for (int i=0; i<10 && l[i]==h[i]; ++i) {
	    common = common + l[i];
	}
	return count(common.begin(), common.end(), '8');
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
    { { 1, 10 }, {0} },
    { { 88, 88 }, {2} },
    { { 800, 899 }, {1} },
    { { 8808, 8880 }, {2} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        int run(NoEights* x) {
            return x->smallestAmount(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<NoEights>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            550, 1486222072, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
