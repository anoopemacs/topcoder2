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

int mymax(int a, int b) {
    if(b>a) return b;
    return a;
}

class DNAString {
public:
    int minChanges(int maxPeriod, vector<string> dna) {
	string d = "";
	for(int i=0; i<dna.size(); ++i) d += dna[i];
	if(maxPeriod == d.size()) return 0;

	int ret = d.size(); // replace all chars
	for(int p=1; p<=maxPeriod; ++p) {
	    vector<string> atp;
	    for(int b=0; b<p; ++b) {
		string runb = "";
		for(int r=b; r<d.size(); r=r+p) {
		    runb = runb + d[r];
		}
		atp.push_back(runb);
	    }
	    int retp = 0;
	    for(int i=0; i<atp.size(); ++i) {
		string s = atp[i];
		vector<int> ct = vector<int>(s.size(), 0);
		for(int j=0; j<s.size(); ++j) {
		    ct[j] = count(s.begin(), s.end(), s[j]);
		}
		int maxExisting = accumulate(ct.begin(), ct.end(), 0, mymax);
		retp = retp + (s.length() - maxExisting);
	    }
	    ret = min(retp, ret);
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
    { { 3, {"ATAGATA"} }, {1} },
    { { 2, {"ACGTGCA"} }, {3} },
    { { 13, {"ACGCTGACAGATA"} }, {0} },
    { { 1, {"AAAATTTCCG"} }, {6} },
    { { 12, {"ACGTATAGCATGACA","ACAGATATTATG","ACAGATGTAGCAGTA","ACCA","GAC"} }, {20} },
    // Your custom test goes here:
    //{ { , {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;vector<string> p1;

        int run(DNAString* x) {
            return x->minChanges(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DNAString>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488950659, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
