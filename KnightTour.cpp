#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
using namespace std;

typedef long long llint;

// CUT begin
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

vector<string> all0 = {"A1", "A2", "A3", "A4", "A5", "A6", "B1", "B2", "B3", "B4", "B5", "B6", "C1", "C2", "C3", "C4", "C5", "C6",
		       "D1", "D2", "D3", "D4", "D5", "D6", "E1", "E2", "E3", "E4", "E5", "E6", "F1", "F2", "F3", "F4", "F5", "F6"};

class KnightTour {
public:
    string checkTour(vector<string> cells) {
	//string ret = "Valid";
	int N = cells.size();

	//check if all cells covered
	for(int i=0; i<all0.size(); ++i) {
	    if (find(cells.begin(), cells.end(), all0[i]) == cells.end()) return "Invalid";
	}
	
	//validp: fd=first diff, sd=second diff
	for(int i=1; i<N; ++i) {
	    string here0 = cells[i];
	    string before0 = cells[i-1];

	    int fd = abs(here0[0]-before0[0]);
	    int sd = abs(here0[1]-before0[1]);

	    if(!(((fd==1) && (sd==2)) ||
		 ((fd==2) && (sd==1)))) {
		return "Invalid";
	    }
	}

	//reentrant
	string here0 = cells[0];
        string before0 = cells[N-1];

        int fd = abs(here0[0]-before0[0]);
        int sd = abs(here0[1]-before0[1]);

        if(!(((fd==1) && (sd==2)) ||
             ((fd==2) && (sd==1)))) {
            return "Invalid";
        }

	return "Valid";
        
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
    { { {"A1","B3","A5","C6","E5","F3","D2","F1","E3","F5","D4","B5","A3","B1","C3","A2","C1","E2","F4","E6","C5","A6","B4","D5","F6","E4","D6","C4","B6","A4","B2","D1","F2","D3","E1","C2"} }, {"Valid"} },
    { { {"A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3"} }, {"Invalid"} },
    { { {"D4","F5","D6","B5","A3","B1","D2","F1","E3","D1","F2","E4","F6","D5","B6","A4","B2","C4","A5","C6","E5","F3","E1","C2","A1","B3","C5","E6","F4","E2","C3","A2","C1","D3","B4","A6"} }, {"Invalid"} },
    { { {"D4","F5","D6","B5","A3","B1","D2","F1","E3","D1","F2","E4","F6","D5","B6","A4","B2","C4","A5","C6","E5","F3","E1","C2","A1","B3","C5","A6","B4","A2","C3","E2","C1","D3","F4","E6"} }, {"Valid"} },
    { { {"C5","D3","F2","D1","B2","A4","B6","D5","C3","E4","F6","B3","A1","C2","E1","F3","E5","C6","A5","C4","A3","B1","D2","F1","E3","F5","D6","B5","D4","E6","F4","E2","C1","A2","B4","A6"} }, {"Invalid"} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        string run(KnightTour* x) {
            return x->checkTour(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<KnightTour>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1485692184, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
