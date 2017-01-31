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

class TagalogDictionary {
public:
    static bool mycompare(string A, string B) {
	//ng is z, $ has the greatest sentinel, - is the smallest sentinel
	vector<char> alphas = {'-', 'a', 'b', 'k', 'd', 'e', 'g', 'h', 'i', 'l', 'm', 'n', 'z', 'o', 'p', 'r', 's', 't', 'u', 'w', 'y', '$'};
	map<char, int> vals;
	for(int i=0; i<alphas.size(); ++i) {
	    vals[alphas[i]] = i;
	}
	//debug(vals);
	
	int diff = abs((int) A.size() - (int) B.size());
	//debug(A.size(), B.size(), diff, "***************************************************************************************************");

	/*
	if(A.size() < B.size()) {
	    A = A + string(diff, '-');
	} else if (B.size() < A.size()) {
	    B = B + string(diff, '$');
        }
	*/
	
	//debug(A.size(), B.size(), A, B);
	
	//now A.size() = B.size()

	int sn = min(A.size(), B.size());
	
	int retInt = -69;
	int i=0;
	for(; i<sn; ++i) {
	    //debug("i, A[i], vals[A[i]], B[i], vals[B[i], A, B",i, A[i], vals[A[i]], B[i], vals[B[i]], A, B);
	    if(vals[A[i]] > vals[B[i]]) {
		debug("vals[A[i]] > vals[B[i]]", A[i], vals[A[i]], B[i], vals[B[i]], "###################################");
		debug("assert A>B", A, B);
		retInt = 0;
		break;
	    } else if (vals[A[i]] == vals[B[i]]) {
		continue;
	    } else if (vals[A[i]] < vals[B[i]]) {
		retInt = 1;
		break;
	    }
	    //cout << "---------------------------------------------------------------------------------------------------" << endl;
	}
	
	if(retInt==1) {
	    return true;
	} else if (retInt==0) {
	    return false;
	} else {
	    debug("assert retInt=-69", retInt);
	    return (A.size() < B.size());
	}
    }
    
    string mytransform (string A) {
	for(;;) {
	    string ng = "ng";
	    string::iterator iter = search(A.begin(), A.end(), ng.begin(), ng.end());
	    if(iter == A.end()) break;
	    string nextA = string(A.begin(), iter) + "z" + string(iter+2, A.end());
	    A=nextA;
	}
	
	return A;
    }
    
    vector<string> sortWords(vector<string> words) {
	int N = words.size();   
	int max_word_size=0;
	for(int i=0; i<N; ++i) {
	    if(words[i].size() > max_word_size)
		max_word_size = words[i].size();
	}
	
	map<string, string> trans;
	vector<string> ret;
	
	for(int i=0; i<N; ++i) {
	    ret.push_back(mytransform(words[i]));
	    trans[mytransform(words[i])] = words[i];
	}
	debug(trans);
	//debug(mytransform("rng"), mytransform("nganoop"), mytransform("ngngng"), mytransform("ngnng"));
	
	debug("ret unsorted:", ret);
	sort(ret.begin(), ret.end(), mycompare);
	debug("ret sorted before transform:", ret);
	
	vector<string> ret_backup = ret;
	for(int i=0; i<N; ++i) {
	    ret[i] = trans[ret_backup[i]];
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
    { { {"abakada","alpabet","tagalog","ako"} }, { {"abakada","ako","alpabet","tagalog"} } },
    { { {"ang","ano","anim","alak","alam","alab"} }, { {"alab","alak","alam","anim","ano","ang"} } },
    { { {"siya","niya","kaniya","ikaw","ito","iyon"} }, { {"kaniya","ikaw","ito","iyon","niya","siya"} } },
    { { {"kaba","baka","naba","ngipin","nipin"} }, { {"baka","kaba","naba","nipin","ngipin"} } },
    { { {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"} }, { {"kingkong","knilngiggnngginggn","dindong","dingdont","dingdong","ingkblot","ingkigningg"} } },
    { { {"silangang","baka","bada","silang"} }, { {"baka","bada","silang","silangang"} } },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        vector<string> run(TagalogDictionary* x) {
            return x->sortWords(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<TagalogDictionary>(
            getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
            500, 1485851261, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
