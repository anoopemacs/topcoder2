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

class StreetWalking {
 public:
    long long minTime(int X, int Y, int walkTime, int sneakTime) {
	int64 x=X, y=Y, w=walkTime, s=sneakTime, m=min(s, 2*w);
	int64 walkOnly = (x+y)*w; // walk only
	if(s>2*w) return walkOnly;

	//below onwards sneak is prefered to 2walks
	
	//sneakOnly:
	int64 sneakOnly = LLONG_MAX;
	bool sneakOnlyPossible = (x%2==0 && y%2==0) || (x%2==1 && y%2==1); //both are even OR both are odd
	if(sneakOnlyPossible == true) {
	    sneakOnly = max(x,y) * s;
	}
	
	//walk and sneak:
	int64 walkAndSneak = LLONG_MAX;
	int64 A, B;         

        //path = (0,0) -> (A,B) as sneak; then (A,B) -> (X,Y) as walk   
        if(w<s) {
	    A = B = min(x,y);
	    walkAndSneak = A*s + (max(x,y) - A)*w;
	} else {
	    int64 sneak = max(x-1, y-1) * s;
	    walkAndSneak = sneak+w;
        }
        
	return min(walkAndSneak, sneakOnly);
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
    { { 4, 2, 3, 10 }, {18LL} },
    { { 4, 2, 3, 5 }, {16LL} },
    { { 2, 0, 12, 10 }, {20LL} },
    { { 25, 18, 7, 11 }, {247LL} },
    { { 24, 16, 12, 10 }, {240LL} },
    { { 10000000, 50000000, 800, 901 }, {41010000000LL} },
    { { 135, 122, 43, 29 }, {3929LL} },
    // Your custom test goes here:
    //{ { , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;

        long long run(StreetWalking* x) {
            return x->minTime(p0,p1,p2,p3);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3); }
    };
    
    int main() {
        return Tester::runTests<StreetWalking>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            500, 1488945146, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
