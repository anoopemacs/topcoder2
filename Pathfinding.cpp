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

class Pathfinding {
public:
    int manh(int x1, int y1, int x2, int y2) {
	return abs(x1-x2)+abs(y1-y2);
    }
    
    int getDirections(int x, int y) {
	if(x==0 && y==0) return 0;

	int X=x, Y=y;
	int ret=-69;
	
	if(x>=0 && y>=0) {
	    //I
	    if(x%2 != 0) ++x;
	    if(y%2 != 0) ++y;
	    ret = manh(x, y, 0, 0);
	    if((X%2 != 0) != (Y%2 != 0)) {
		--ret;
	    }

	} else if(x<0 && y>0) {
	    //II
	    if(x%2!=0) --x;
	    if(y%2==0) ++y;
	    ret = manh(x, y, 0, 0);
	    if((X%2 == 0) == (Y%2 == 0)) {
                --ret;
            }
	    
	} else if(x<=0 && y<=0) {
	    //III
	    if(x%2==0) --x;
            if(y%2==0) --y;
            ret = 1 + manh(x, y, 1, 0);
            if((X%2 != 0) != (Y%2 != 0)) {
                --ret;
            }
	    
	} else if(x>0 && y<0) {
	    //IV
	    if(x%2 == 0) ++x;
	    if(y%2 != 0) --y;
	    ret = manh(x, y, 0, 0);
	    if((X%2 == 0) == (Y%2 == 0)) {
                --ret;
            }
	    
	} else {
	    cout << "all cases not covered error!#################################" << endl;
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
    { { 0, -4 }, {8} },
    { { 5, -4 }, {9} },
    { { 5, 4 }, {9} },
    { { -1, -4 }, {7} },
    { { 0, 0 }, {0} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        int run(Pathfinding* x) {
            return x->getDirections(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<Pathfinding>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485887736, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
