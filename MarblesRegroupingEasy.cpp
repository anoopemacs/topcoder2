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

class MarblesRegroupingEasy {
    int nt(string s) {
	int ret = 0;
	for(int i=0; i<s.length(); ++i) {
	    if(s[i] != '0') ++ret;
	}
	return ret;
    }
  
public:
    int minMoves(vector<string> boxes) {
	int Nb = boxes.size(); // no. of boxes
	//int Nr = Nb;
	int Nc = boxes[0].length(); // no. of colors = columns

	int ret_max = Nb - 1; // move all to joker

	int joker_index = 0;
	for(int i=1; i<boxes.size(); ++i) {
	    if(nt(boxes[i]) > nt(boxes[joker_index])) {
		joker_index = i;
	    }
	}
	if(nt(boxes[joker_index]) == 1) {
	    map<string, int> freq;
	    for(int i=0; i<Nb; ++i) {
		freq[boxes[i]]++;
	    }
	    debug(freq);

	    string max_freq_string = "initial69";
	    int max_freq = INT_MIN;
	    for(map<string, int>::iterator iter = freq.begin(); iter != freq.end(); ++iter) {
		if(iter->second > max_freq) {
		    max_freq = iter->second;
		    max_freq_string = iter->first;
		}
	    }

	    for(int i=0; i<Nb; ++i) {
		if(boxes[i] == max_freq_string) {
		    joker_index = i;
		    break;
		}
	    }
	    
	}
	
	vector<int> alreadyUsed(Nc, 0);

	debug(joker_index);
	
	int ret=0;
	for(int i=0; i<Nb; ++i) {
	    if(i != joker_index) {
		if(nt(boxes[i])>1) {
		    ret = ret+1;
		} else if(nt(boxes[i])==1) {
		    string s = boxes[i];
		    int c = 0;
		    while(s[c]=='0') ++c;
		    if(alreadyUsed[c]==0) {
			alreadyUsed[c]=1;
		    } else if(alreadyUsed[c]==1) {
			ret = ret+1;
		    }
		}
	    }
	}

	return min(ret_max, ret);
	
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
	{ { {"20","11"} }, {0} },
	{ { {"11","11","10"} }, {1} },
	{ { {"10","10","01","01"} }, {1} },
	{ { {"11","11","11","10","10","01"} }, {3} },
	{ { {"020008000070","000004000000","060000600000","006000000362","000720000000","000040000000","004009003000","000800000000","020030003000","000500200000","000000300000"} }, {6} },
	{ {{"10", "01", "01", "01", "01"}}, {2} },
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<string> p0;

    int run(MarblesRegroupingEasy* x) {
	return x->minMoves(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<MarblesRegroupingEasy>(
						   getTestCases<input, Tester::output<int>>(), disabledTest, 
						   600, 1488718981, CASE_TIME_OUT, Tester::COMPACT_REPORT
						   );
}
// CUT end
