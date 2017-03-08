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

class IsomorphicWords {
    bool isomorphicp(string a, string b) {
	map<char, char> modi;
	for(int i=0; i<a.length(); ++i) {

	    //a letter mapping to 2 different letters
	    if(modi.find(a[i]) != modi.end()) {
		map<char, char>::iterator iter = modi.find(a[i]);
		if(iter->second != b[i]) return false;
	    }
	    
	    modi[a[i]] = b[i];
	}

	//2 different letters mapping to the same letter
	map<char, bool> done;
	for(char c='a'; c<='z'; ++c) 
	    done[c] = false;

	for(map<char, char>::iterator it = modi.begin(); it!=modi.end(); ++it) {
	    //char f = it->first;
	    char s = it->second;

	    if(done[s] == true) return false;
	    else {
		done[s] = true;
	    }
	}
	
	
	string expected_b = "";
	for(int i=0; i<a.length(); ++i) {
	    expected_b += modi[a[i]];
        }
	if(expected_b == b) return true;

	// never reached:
	return false;
    }
 public:
    int countPairs(vector<string> words) {
	int Nr = words.size();
	//int Nc = words[0].length();
	
	int ret = 0;
	for(int f=0; f<Nr; ++f) {
	    for(int s=f+1; s<Nr; ++s) {
		string fir = words[f];
		string sec = words[s];
		debug(fir, sec);
		if(isomorphicp(fir, sec)) ++ret;
	    }
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
    { { {"abca","zbxz","opqr"} }, {1} },
    { { {"aa","ab","bb","cc","cd"} }, {4} },
    { { {"cacccdaabc","cdcccaddbc","dcdddbccad","bdbbbaddcb","bdbcadbbdc","abaadcbbda","babcdabbac","cacdbaccad","dcddabccad","cacccbaadb","bbcdcbcbdd","bcbadcbbca"} }, {13} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        int run(IsomorphicWords* x) {
            return x->countPairs(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<IsomorphicWords>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488772109, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
