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

class CandidateKeys {
    void sub0() {
	int n = (1<<3);
	n = n-1;
	while(n!=0) {
	    cout << bitset<8>(n) << endl;
	    n=n-1;
	}
    }

    bool uniquep(vector<string> vs) {
	sort(vs.begin(), vs.end());
	return (unique(vs.begin(), vs.end()) == vs.end());
    }
    
public:
    vector<int> getKeys(vector<string> table) {
	vector<int> ret;
	//sub0();
	int Nr = table.size();
	int Nc = table[0].length();
	int all_bits = (1<<Nc) - 1;
	//cout << bitset<32>(all_bits) << endl;
	
	vector<bitset<32>> all_subsets;
	
	int n = all_bits;
	//int n = all_bits - 1; // because proper subset ////$$$$$$$$$
	while(n!=0) {
	    all_subsets.push_back(bitset<32>(n));
	    n=n-1;
	}
	reverse(all_subsets.begin(), all_subsets.end());

	vector<int> csl; // candidate superkey length

	vector<bitset<32>> skipThis;
	
	for(int i=0; i<all_subsets.size(); ++i) {
	    bitset<32> s = all_subsets[i];
	    if(find(skipThis.begin(), skipThis.end(), s) != skipThis.end()) continue;

	    vector<string> modi;
	    for(int r=0; r<Nr; ++r) {
		string tp = "";
		for(int c=0; c<Nc; ++c) {
		    if(s[c]==1) {
			tp = tp+table[r][c];
		    }
		}
		modi.push_back(tp);
	    }

	    debug(modi);

	    if(uniquep(modi)) {
		csl.push_back(modi[0].length());

		for(int j=0; j<all_subsets.size(); ++j) {
		    bitset<32> testme = all_subsets[j];
		    if((s & (~testme)) == 0) {
			skipThis.push_back(testme);
		    }
		}
	    }
	    
	}

	int small=INT_MAX;
	int large=INT_MIN;

	for(int i=0; i<csl.size(); ++i) {
	    small = min(small,csl[i]);
	    large = max(large,csl[i]);
	}
	
	if(small!=INT_MAX && large!=INT_MIN) {
	    ret.push_back(small);
	    ret.push_back(large);
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
	{ { {"ABC","ABC","ABC"} }, { {} } },
	{ { {"ABC","ABD","ABE"} }, { {1,1} } },
	{ { {"ABC","ACD","BBE"} }, { {1,2} } },
   { { {"A","B"} }, { {1,1} } },
   { { {"AABB","BABA","CAAB","DAAA","EBBB","FBBA","GBAB","HBAA"} }, { {1,3} } },

   { {{"AAABBABAA", "BBAAABBBB", "BABAABAAA", "ABAABBBAA", "BBBBAAABA", "ABABBABAA"}},  {{3, 4}} },

   
   
   // Your custom test goes here:
   //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        vector<int> run(CandidateKeys* x) {
            return x->getKeys(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<CandidateKeys>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            500, 1488469483, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
