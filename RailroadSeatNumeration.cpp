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
vector<int> dom;
vector<int> in;

class RailroadSeatNumeration {
    string myits(int i) {
	stringstream ss;
	ss<<i;
	string ret;
	ss>>ret;
	return ret;
    }
public:
    string getInternational(vector<int> t) {
	dom.push_back(-69);
	in.push_back(-69);
	for(int i=1;i<37;++i) dom.push_back(i);
	for(int i=1;i<37;++i) {
	    int com = (i-1)/4 + 1;
	    int num = (i-1)%4+1;
	    if(num==2) num=3;
	    else if(num==3) num=4;
	    else if(num==4) num=6;
	    in.push_back(com*10+num);
	}
	debug(dom);
	debug(in);
	
	int N=t.size();
	bool domestic=true;
	bool international=true;
	
	for(int i=0; i<N; ++i) {
	    int ti=t[i];
	    vector<int>::iterator domf, inf;
	    domf = find(dom.begin(),dom.end(),ti);
	    inf = find(in.begin(),in.end(),ti);
	    if(domf==dom.end()) domestic=false;
	    if(inf==in.end()) international=false;
        }
	if(!domestic && !international) return "BAD DATA";
	if(domestic && international) {
	    return "AMBIGUOUS";
	}
	string ret;
	
	if(domestic) {
	    for(int i=0; i<N; ++i) {
                int ti=t[i];
		//ti is domestic number
		int topush = in[ti];
		ret = ret + myits(topush) + " ";
            }
        } else {
	    for(int i=0; i<N; ++i) {
                int ti=t[i];
		//ti is international number
                ret = ret + myits(ti) + " ";
            }
        }
	
	ret=ret.substr(0,ret.size()-1);     
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
	{ { {1} }, {"11"} },
	{ { {11} }, {"AMBIGUOUS"} },
	{ { {45} }, {"BAD DATA"} },
	{ { {5,7,6} }, {"21 24 23"} },
	{ { {21,24,23} }, {"AMBIGUOUS"} },
	{ { {8,28} }, {"26 76"} },
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<int> p0;

    string run(RailroadSeatNumeration* x) {
	return x->getInternational(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<RailroadSeatNumeration>(
						    getTestCases<input, Tester::output<string>>(), disabledTest, 
						    500, 1484676595, CASE_TIME_OUT, Tester::COMPACT_REPORT
						    );
}
// CUT end
