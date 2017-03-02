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

int mem[51][51];
int indx[51][3];
string ans = "";
vector<string> cl;

class RoadConstruction {
public:
    void myset(int nL) {
	int i = 0;
	for(; i<nL; ++i) {
	    if((indx[i][1] < indx[i][2]) && (mem[i][indx[i][1]] == 1)) {
		ans = ans + cl[i][indx[i][1]];
		++indx[i][1];

		//set others
		for(int j=0; j<i; ++j) {
		    //yielding occurs for below lanes
		    mem[j][indx[j][1]] = 1;
		}
		
		break;
	    }
	}
	if(i == nL) { // all are zero
	    for(int j=nL-1; j>=0; --j) {
		if((indx[j][1] < indx[j][2]) && (mem[j][indx[j][1]] == 0)) {
		    mem[j][indx[j][1]] = 1;
		    break;
		}
	    }
	}
    }
    
    int getExitTime(vector<string> currentLanes) {
	cl = currentLanes;
	int nL = currentLanes.size();
	memset(mem, 0, sizeof(mem));
	memset(indx, 0, sizeof(indx));
	for(int i=0; i<currentLanes.size(); ++i)
	    indx[i][2] = currentLanes[i].length();
	//indx[i][1] = currentIndex, indx[i][2] = maxlength
	myset(nL);

	int totalCars = 0;
	for(int i=0; i<nL; ++i)
	    totalCars += currentLanes[i].length();

	while(ans[ans.length()-1] != 'D' && ans.length() <= totalCars) {
	    myset(nL);
	    debug(ans);
	}

	int ret=0;
	while(ans[ret] != 'D') ++ret;
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
    { { {"AB","CD","E"} }, {4} },
    { { {"AH","D","BCG","E","F"} }, {2} },
    { { {"AAA","A","AAA","A","AAD","A","AAB"} }, {13} },
    { { {"DEFGHIJK"} }, {0} },
    { { {"I","WANT","TO","DRINK","SOME","COFFEE"} }, {5} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        int run(RoadConstruction* x) {
            return x->getExitTime(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<RoadConstruction>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1487726979, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
