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

bool isVowel(char c) {
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

bool isConsonant(char c) {
    return !isVowel(c);
}

struct myword {
    string wd;
    string sy;
};
typedef struct myword myword;

bool mysort1(myword w1, myword w2) {
    return w1.wd <= w2.wd;
}

bool mysort2(myword w1, myword w2) {
    return w1.sy <= w2.sy;
}

class SyllableSorting {
public:

    //problem statement ambiguious : skip for now
    string myprocess(string s) {
	vector<string> vs;
	//split as syllables, sort and join
	string::iterator A=s.begin(),B=s.begin(),C=s.begin();
	
	while(C != s.end()) {
	    B=find_if(A, s.end(), isVowel);
	    C=find_if(B, s.end(), isConsonant);
	    string syllable = string(A, C);
	    //debug(syllable);
	    vs.push_back(syllable);
	    
	    if(C != s.end()) A = C;
	}

	sort(vs.begin(), vs.end());
	string ret = "";
	for(int i=0; i<vs.size(); ++i) {
	    ret = ret + vs[i];
	}
	return ret;
    }
    
    void myprint(vector<myword> vw) {
	for(int i=0; i<vw.size(); ++i) {
	    cout << "(" << vw[i].wd << ": " << vw[i].sy << "),   ";
	}
	cout << endl;
    }
    
    vector<string> sortWords(vector<string> words) {
	vector<string> ret;
	
	vector<myword> vw;
	for(int i=0; i<words.size(); ++i) {
	    string sylle = myprocess(words[i]);
	    myword w0;
	    w0.wd = words[i];
	    w0.sy = sylle;
	    vw.push_back(w0);
	}

	myprint(vw);
	
	sort(vw.begin(), vw.end(), mysort1);
	stable_sort(vw.begin(), vw.end(), mysort2);
	
	for(int i=0; i<vw.size(); ++i) {
	    myword wrd = vw[i];
	    ret.push_back(wrd.wd);
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
    { { {"xiaoxiao","yamagawa","gawayama"} }, { {"gawayama","yamagawa","xiaoxiao"} } },
    { { {"bcedba","dbabce","zyuxxo"} }, { {"bcedba","dbabce","zyuxxo"} } },
    { { {"hgnibqqaxeiuteuuvksi","jxbuzui","zrotyqeruiydozui","ywuuzkto","lmopbookoagyco","vredfvavvexliu"} }, { {"hgnibqqaxeiuteuuvksi","vredfvavvexliu","lmopbookoagyco","jxbuzui","zrotyqeruiydozui","ywuuzkto"} } },
    { { {"crazgo","cwsoygiokiuo","yueoseeu","tuadiojvugeoe","naumxditui","sgukkelyoi","nrohjuasoia","mgabmo"} }, { {"mgabmo","crazgo","cwsoygiokiuo","tuadiojvugeoe","nrohjuasoia","sgukkelyoi","naumxditui","yueoseeu"} } },
    { { {"wheewjuguoi","coutcu","hqivaa","sgiibgwi","ypaqpki","bgyikouapae","wqakeu","skolfo","pzesaa","ypivhi"} }, { {"sgiibgwi","bgyikouapae","coutcu","wheewjuguoi","hqivaa","wqakeu","skolfo","pzesaa","ypaqpki","ypivhi"} } },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        vector<string> run(SyllableSorting* x) {
            return x->sortWords(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<SyllableSorting>(
            getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
            500, 1487961916, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
