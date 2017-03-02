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

class TurningLightOn {
public:
    char toggle(char c) {
	if(c=='0') return '1';
	else return '0';
    }
    
    void flip(vector<string>& board, int R, int C) {
	//params are 0-based
	for(int r=0; r<=R; ++r) {
	    for(int c=0; c<=C; ++c) {
		board[r][c] = toggle(board[r][c]);
	    }
	}
    }
    
    int minFlips(vector<string> board) {
	int R = board.size();
	int C = board[0].length();
	int ret = 0;
	
	for(int r=R-1; r>=0; --r) {
	    for(int c=C-1; c>=0; --c) {
		if(board[r][c] == '0') {
		    flip(board, r, c);
		    ++ret;
		}
		
	    }
	}
	debug(board);
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
    { { {"0001111","0001111","1111111"} }, {1} },
    { { {"1111111","1111111","1111111"} }, {0} },
    { { {"01001"} }, {3} },
    { { {"0101","1010","0101","1010"} }, {7} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        int run(TurningLightOn* x) {
            return x->minFlips(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<TurningLightOn>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1487720952, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
