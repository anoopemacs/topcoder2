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

class MysticAndCandiesEasy {
public:
    int minBoxes(int C, int X, vector<int> high) {
	int N = high.size();
	vector<int> h = high;
	sort(h.begin(), h.end());
	int rsum = C;

	int ret = N;
	for(int i=0; (rsum-h[i])>= X; ++i) {
	    rsum = rsum-h[i];
	    --ret;
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
    { { 10, 10, {20} }, {1} },
    { { 10, 7, {3,3,3,3,3} }, {4} },
    { { 100, 63, {12,34,23,45,34} }, {3} },
    { { 19, 12, {12,9,15,1,6,4,9,10,10,10,14,14,1,1,12,10,9,2,3,6,1,7,3,4,10,3,14} }, {22} },
    { { 326, 109, {9,13,6,6,6,16,16,16,10,16,4,3,10,8,11,17,12,5,7,8,7,4,15,7,14,2,2,1,17,1,7,7,12,17,2,9,7,1,8,16,7,4,16,2,13,3,13,1,17,6} }, {15} },
    // Your custom test goes here:
    //{ { , , {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;vector<int> p2;

        int run(MysticAndCandiesEasy* x) {
            return x->minBoxes(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<MysticAndCandiesEasy>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1487684962, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
