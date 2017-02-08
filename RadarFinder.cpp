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

class RadarFinder {
public:
    long sq(long d) {
        debug(pow(d,2), d*d);
	return d*d;
	//return pow(d,2); // pow is impresize due to its use of doubles
    }

    int possibleLocations(int X1, int Y1, int R1, int X2, int Y2, int R2) {
	long x1=X1,y1=Y1,r1=R1,x2=X2,y2=Y2,r2=R2;
	
	if(r1>r2) {
	    swap(r1, r2);
	    swap(x1, x2);
	    swap(y1, y2);
	}
	long ds = sq(x1-x2) + sq(y1-y2);
	if(ds==0 && r1==r2) return -1;
	
	long rs = sq(r1+r2);
	long rd = sq(r2-r1);
	debug("ds, rd, rs", rs, rd, rs);
	
	if(ds<rd) return 0;
	if(ds==rd) return 1;
	if(ds>rd && ds<rs) return 2;
	if(ds==rs) return 1;
	if(ds>rs) return 0;

	//never reached:
	return -69;
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
    { { 0, 0, 13, 40, 0, 37 }, {2} },
    { { 0, 0, 3, 0, 7, 4 }, {1} },
    { { 0, 0, 5, 10, 10, 3 }, {0} },
    { { 0, 0, 1, 0, 0, 1 }, {-1} },
    { {0, 0, 2, 499999999, 374999998, 625000000}, {2} },
    // Your custom test goes here:
    //{ { , , , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;int p4;int p5;

        int run(RadarFinder* x) {
            return x->possibleLocations(p0,p1,p2,p3,p4,p5);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3,p4,p5); }
    };
    
    int main() {
        return Tester::runTests<RadarFinder>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485965556, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
