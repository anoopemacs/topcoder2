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

class BeautifulString {
public:
    int maximumLength(int countAA, int countBB, int maxAA, int maxBB) {
	long long countA=countAA, countB=countBB, maxA=maxAA, maxB=maxBB;
	
	if(maxA==0 || countA==0) return min(countB, maxB);
	if(maxB==0 || countB==0) return min(countA, maxA);
	
	debug((countB+1)*maxA + countB, (countA+1)*maxB + countA, countA+countB);
	
	if((countB+1)*maxA < countA) {
	    return (countB+1)*maxA + countB;
	} 
	
	if((countA+1)*maxB < countB) {
	    return (countA+1)*maxB + countA;
	}
	
	return countA+countB;
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
    { { 0, 0, 10, 10 }, {0} },
    { { 10, 10, 0, 0 }, {0} },
    { { 3, 5, 1, 1 }, {7} },
    { { 677578, 502524, 989951, 504698 }, {1180102} },
    { {387085, 185394, 4184, 336687}, {572479}},
    // Your custom test goes here:
    //{ { , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;

        int run(BeautifulString* x) {
            return x->maximumLength(p0,p1,p2,p3);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3); }
    };
    
    int main() {
        return Tester::runTests<BeautifulString>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1487716894, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
