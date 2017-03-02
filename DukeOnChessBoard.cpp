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

string maxSimplePath = "";      

class DukeOnChessBoard {
public:
    bool insidep_and_notTraversedp(int n, string pos) {
	//also checks if the position is already traversed
	
	if(maxSimplePath.find(pos, 0) != -1) return false;
	
	char maxChar = 'a' - 1 + n;
        char maxDigit = '0' + n;

        char posChar = pos[0];
        char posDigit = pos[1];

	if(posChar <= maxChar && posChar >= 'a' && posDigit <= maxDigit && posDigit >= '1')
	    return true;
	return false;
    }
    
    string mynext(int n, string pos) {
	char posChar = pos[0];
	char posDigit = pos[1];
	
	string east=pos, west=pos, north=pos, south=pos;
	
	east[0] = (char) (posChar+1);
	north[1] = (char) (posDigit+1);
	south[1] = (char) (posDigit-1);
	west[0] = (char) (posChar-1);

	//debug(posChar, (char) (posDigit+1));
	//debug(east, north, south, west);
	
        if(insidep_and_notTraversedp(n, east)) return east;  
        if(insidep_and_notTraversedp(n, north)) return north;  
        if(insidep_and_notTraversedp(n, south)) return south;  
        if(insidep_and_notTraversedp(n, west)) return west;
	
	return "none";
    }
    
    string dukePath(int n, string initPosition) {
	maxSimplePath = initPosition;
	
	for(string np = mynext(n, initPosition); np != "none"; np = mynext(n, np)) {
	    maxSimplePath = maxSimplePath + "-" + np;
	}

        int N = maxSimplePath.length();	
	if(N <= 40) return maxSimplePath;
	return maxSimplePath.substr(0, 20) + "..." + maxSimplePath.substr(N-20, 20);
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
    { { 3, "b2" }, {"b2-c2-c3-b3-a3-a2-a1-b1-c1"} },
    { { 4, "d4" }, {"d4-d3-d2-d1-c1-c2-c3...b3-b2-b1-a1-a2-a3-a4"} },
    { { 3, "a2" }, {"a2-b2-c2-c3-b3-a3"} },
    { { 4, "d3" }, {"d3-d4-c4-c3-c2-d2-d1...b2-b3-b4-a4-a3-a2-a1"} },
    { { 8, "a8" }, {"a8-b8-c8-d8-e8-f8-g8...a1-a2-a3-a4-a5-a6-a7"} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;string p1;

        string run(DukeOnChessBoard* x) {
            return x->dukePath(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DukeOnChessBoard>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            550, 1487993630, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
