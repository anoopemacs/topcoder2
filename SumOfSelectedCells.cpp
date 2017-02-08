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

class SumOfSelectedCells {
public:
    vector<string> mysplit(string s, char c) {
        vector<string> ret;
        int i=0;
        while(i<s.size()) {
            int j=s.find(c, i);
            if(j==-1) {
                ret.push_back(s.substr(i));
                break;
            } else {
                ret.push_back(s.substr(i, j-i));
            }
            i=j+1;
        }
        //    sort(s.begin(), s.end());
        return ret;
    }

    int mysti(string s) {
        stringstream ss;
        ss<<s;
        int ret;
        ss>>ret;
        return ret;
    }
    
    bool equalp(vector<int> vi) {
	for(int i=0; i<vi.size(); ++i)
	    if(vi[i]!=vi[0]) return false;
	return true;
    }
    
    string hypothesis(vector<string> table) {
	vector<vector<int>> t;
	
	for(int i=0; i<table.size(); ++i) {
	    vector<string> vs = mysplit(table[i], ' ');
	    vector<int> rowi;
	    for(int j=0; j<vs.size(); ++j)
		rowi.push_back(mysti(vs[j]));
	    t.push_back(rowi);
	}
	//debug(t);
	int nr = t.size(); //no of rows
	int nc = t[0].size();
	int sel = min(nr, nc); // no of selections by jesse

	if(nc==nr) {
	    for(int r=0; r<nr; ++r) {
		for(int c=0; c<nc; ++c) {
		    if(t[0][0] + t[r][c] != t[r][0]+t[0][c]) return "INCORRECT";
		}
	    }
	} else if (sel == nr){
	    for(int i=0; i<nr; ++i) {
		vector<int> vi = t[i];
		if(!equalp(vi)) return "INCORRECT";
	    }
	} else if (sel == nc) {
	    for(int c=0; c<nc; ++c) {
		int val_for_col_c = t[0][c];
		for(int r=0; r<nr; ++r) {
		    if(t[r][c] != val_for_col_c) return "INCORRECT";
		}
	    }
	}
	
	return "CORRECT";
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
	{ { {"5 6 6"} }, {"INCORRECT"} },
    { { {"11 12 13 14","21 22 23 24","31 32 33 34","41 42 43 44"} }, {"CORRECT"} },
    { { {"3 7","3 7","3 7"} }, {"CORRECT"} },
    { { {"1 2 3","4 5 6","9 8 7"} }, {"INCORRECT"} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        string run(SumOfSelectedCells* x) {
            return x->hypothesis(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<SumOfSelectedCells>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1486315833, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
