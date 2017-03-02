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

class BuildingStrings {
public:
    int myval(string s) {
	int N = s.size();
	sort(s.begin(), s.end());
	string::iterator iter = unique(s.begin(), s.end());
	return N * (int) (iter - s.begin());
    }
    
    int myval(vector<string> vs) {
	int ret = 0;
	for(int i=0; i<vs.size(); ++i) {
	    ret += myval(vs[i]);
	}
	return ret;
    }
    
    vector<string> findAny(int K) {
	string L = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"; // 1300

	string run = "";
	vector<string> ret;

	while(myval(ret) + myval(L) <= K)
	    ret.push_back(L);

	string s676 = "abcdefghijklmnopqrstuvwxyz";
        while(myval(ret) + myval(s676) <= K)
            ret.push_back(s676);
        
	// now (K - myval(ret)) belongs to [0, 675]
	
	string s625 = "abcdefghijklmnopqrstuvwxy";
        while(myval(ret) + myval(s625) <= K)
            ret.push_back(s625);
	
	// now (K - myval(ret)) belongs to [0, 624], 10 more strings
	
	string s441 = "abcdefghijklmnopqrstu";
        while(myval(ret) + myval(s441) <= K)
            ret.push_back(s441);
        
        // now (K - myval(ret)) belongs to [0, 440], 9 more strings
        
	string s50 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        while(myval(ret) + myval(s50) <= K)
            ret.push_back(s50);
        
        // now (K - myval(ret)) belongs to [0, 49], 8 more strings

	int req = K - myval(ret);
	string last = "";
	for (int i=0; i<req; ++i)
	    last.push_back('a');

	if(last.length() != 0)
	    ret.push_back(last);
	
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
    { { 49 }, { {"little","limak"} } },
    { { 15 }, { {"azz","xyz"} } },
    { { 704 }, { {"aaaaaaaaaa","abcdefghijklmnopqrstuvwxyz","aabbcc"} } },
    { { 37521 }, { {"aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy","abcd","aa","a","a","a"} } },
    { { 1 }, { {"a"} } },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;

        vector<string> run(BuildingStrings* x) {
            return x->findAny(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<BuildingStrings>(
            getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
            500, 1487688012, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
