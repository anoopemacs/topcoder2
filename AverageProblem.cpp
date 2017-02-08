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

class AverageProblem {
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
    
    int numberOfParticipants(vector<string> marks) {
	string sm;
	for(int i=0; i<marks.size(); ++i)
	    sm = sm + marks[i] + " ";
	
	vector<string> vs = mysplit(sm, ' ');
	vector<int> vi;
	for(int i=0; i<vs.size(); ++i) {
	    string si = vs[i];
	    string::iterator it = remove(si.begin(), si.end(), '.');
	    string smod = string(si.begin(), it);
	    vi.push_back(mysti(smod));
	}
	debug(vi);
	
	for(int ret=1; ret<1000; ++ret) {
	    bool retValid = true;
	    
	    for(int i=0; i<vi.size(); ++i) {
		int n = vi[i];
		int low = n*ret;
		int high = (n+1)*ret;
		//[low,high)
		debug(low, high);
		
		int a = floor(low/1000)*1000;
		int b = (floor(low/1000) + 1)*1000;
		if(!((a>=low && a<high) || (b>=low && b<high))) retValid = false;
	    }
	    if(retValid) return ret;
	}
	
	return 1000;
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
	{ { {"0.000"} }, {1} },
	{ { {"0.500 0.250","0.125"} }, {8} },
	{ { {"0.500","0.300"} }, {10} },
	{ { {"0.500","0.301"} }, {106} },
	{ { {"0.001","0.002"} }, {667} },
	{ {{"5.500 5.125 5.650 6.777"}}, {360} },
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<string> p0;

    int run(AverageProblem* x) {
	return x->numberOfParticipants(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<AverageProblem>(
					    getTestCases<input, Tester::output<int>>(), disabledTest, 
					    500, 1486224864, CASE_TIME_OUT, Tester::COMPACT_REPORT
					    );
}
// CUT end
