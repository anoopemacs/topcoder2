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

class Library {
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
public:
    int documentAccess(vector<string> records, vector<string> userGroups, vector<string> roomRights) {
	int ret = 0;
	map<string, bool> docs;
	for(int i=0; i<records.size(); ++i) {
            vector<string> doc = mysplit(records[i], ' ');
            docs[doc[0]] = false;
	}
	
	for(int i=0; i<records.size(); ++i) {
	    vector<string> doc = mysplit(records[i], ' ');
	    if (find(roomRights.begin(), roomRights.end(), doc[1]) != roomRights.end() &&
		find(userGroups.begin(), userGroups.end(), doc[2]) != userGroups.end() &&
		docs[doc[0]] != true) {
		docs[doc[0]] = true;
		++ret;
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
    { { {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}, {"employee","editor","author"}, {"history","cars","computers"} }, {2} },
    { { {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}, {"employee","editor","author","librarian"}, {"history","cars","computers"} }, {2} },
    { { {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}, {"employee","editor","author","librarian"}, {} }, {0} },
    { { {"a b c","a b d","b b c","b b d","e c d","e c b","e c c","t d e"}, {"c","d","x"}, {"a","b","c"} }, {3} },
    // Your custom test goes here:
    //{ { {}, {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;vector<string> p1;vector<string> p2;

        int run(Library* x) {
            return x->documentAccess(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<Library>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488460935, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
