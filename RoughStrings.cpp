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

class RoughStrings {
    int aux(vector<int> v, int n) {
        sort(v.begin(), v.end());
	int ret = v[v.size()-1] - v[0];

	int rmax = v[v.size()-1];
	int lmin = max(v[0]-n, 1);
	dump(lmin); dump(rmax);
	
	for(int l=lmin; l<=rmax; ++l) {
	    for(int r=l; r<=rmax; ++r) {
		int run = r-l;

		int cost = 0;
		for(int i=0; i<v.size(); ++i) {
		    if(v[i]<l) cost += v[i];
		    else if(v[i]>r) cost += (v[i]-r);
		}
		if(cost<=n) ret = min(ret, run);
		
	    }
	}
	
	return ret;
    }
    
 public:
    int minRoughness(string s, int n) {
	vector<pair<int, char>> vp;
	map<char,int> fq;
	for(int i=0; i<s.length(); ++i) {
	    fq[s[i]]++;
	    vp.push_back(make_pair(-1, s[i]));
	}
        //debug(fq);
	vector<int> v;
	for(map<char, int>::iterator iter = fq.begin(); iter != fq.end(); ++iter) {
	    //cout << iter->first << "  " << iter->second << endl;
	    v.push_back(iter->second);
	}

	//debug(v);
	//debug(r(s), r2(v));
	
	return aux(v, n);
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
    { { "aaaaabbc", 1 }, {3} },
    { { "aaaabbbbc", 5 }, {0} },
    { { "veryeviltestcase", 1 }, {2} },
    { { "gggggggooooooodddddddllllllluuuuuuuccckkk", 5 }, {3} },
    { { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", 17 }, {0} },
    { { "bbbccca", 2 }, {0} },
    { { "aaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbb", 49 }, {} },
    { {"jjtvjjjjjjjvjjvjjjvvjjkjvvvvvjj", 5}, {6}},
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;int p1;

        int run(RoughStrings* x) {
            return x->minRoughness(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<RoughStrings>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488811852, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
