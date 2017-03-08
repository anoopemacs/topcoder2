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

class UnderscoreJustification {
 public:
    string justifyLine(vector<string> words, int width) {
	string ret = words[0];
	
	int N = words.size();
	int len = 0;
	for(int i=0; i<words.size(); ++i) {
	    len = len + words[i].length();
	}
	int gap = width-len;
	int ngaps = N-1;
	//gap = w*a + (w+1)*b // w, w+1 is width of each gap

	int w=1;
	while(ngaps*w < gap) ++w;
	
	if(gap%w == 0 && gap/w == ngaps) {
	    for(int i=1; i<words.size(); ++i) {
		ret = ret + string(w, '_') + words[i];
	    }
	} else {
	    w = w-1;
	    int b = gap%ngaps;
	    int a = ngaps-b;
	    for(int i=1; i<words.size(); ++i) {
		if(islower(words[i][0]) && b>0) {
		    words[i] = string(w+1, '_') + words[i];
		    --b;
		}
	    }
	    if(b>0) {
	        for(int i=words.size()-1; i>=1; --i) {
                    if(isupper(words[i][0]) && b>0) {
                        words[i] = string(w+1, '_') + words[i];
                        --b;
                    }
                }	
	    }
	    
	    for(int i=1; i<words.size(); ++i) {
                if(words[i][0] != '_') {
                    words[i] = string(w, '_') + words[i];
		    --a;
                }
            }
	    debug("assert a=0, a=", a);

	    for(int i=1; i<words.size(); ++i) {
		ret = ret + words[i];
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
    { { {"A","quick","brown","fox","jumps","over","the","lazy","dog"}, 50 }, {"A___quick__brown__fox__jumps__over__the__lazy__dog"} },
    { { {"Alpha","Beta","Gamma","Delta","Epsilon"}, 32 }, {"Alpha_Beta_Gamma__Delta__Epsilon"} },
    { { {"Hello","world","John","said"}, 29 }, {"Hello____world___John____said"} },
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;int p1;

        string run(UnderscoreJustification* x) {
            return x->justifyLine(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<UnderscoreJustification>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1488466541, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
