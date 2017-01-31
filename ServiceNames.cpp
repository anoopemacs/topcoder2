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

class ServiceNames {
public:
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
        sort(s.begin(), s.end());
        return ret;
    }
    
    vector<string> makeList(vector<string> s) {
	vector<string> allinputs;
	vector<string> allservices;
	map<string, vector<string>> mymap;
	
	for(int i=0; i<s.size(); ++i) {
	    string si = s[i];
	    vector<string> words = mysplit(si, ' ');
	    copy(words.begin()+1, words.end(), back_inserter(allinputs));
	    allservices.push_back(words[0]);

	    string serviceName = words[0];

	    for(int i=1; i<words.size(); ++i) {
		string inp = words[i];
		vector<string> prev = mymap[inp];
		prev.push_back(serviceName);
		mymap[inp] = prev;
	    }
	    
	}

	debug(mymap);
	
	sort(allservices.begin(), allservices.end());
	sort(allinputs.begin(), allinputs.end());
	
	vector<string>::iterator iter = unique(allinputs.begin(), allinputs.end());
	vector<string> alli = vector<string>(allinputs.begin(), iter);
	//debug(allinputs);       
	//debug(alli);
	
	vector<string> ret;
	
	for(int i=0; i<alli.size(); ++i) {
	    string inp = alli[i];
	    if(mymap[inp].size() != 0) {
		string topush = inp + " ==> ";
		vector<string> vec0 = mymap[inp];
		sort(vec0.begin(), vec0.end());
		
		for(int j=0; j<vec0.size()-1; ++j) {
		    topush = topush + vec0[j] + ", ";
		}
		int N = vec0.size();
		topush = topush + vec0[N-1];
		ret.push_back(topush);
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
    { { {"BLAST Genome Annotation Sensitivity","PING","X Annotation"} }, { {"Annotation ==> BLAST, X","Genome ==> BLAST","Sensitivity ==> BLAST"} } },
    { { {"PING"} }, { {} } },
    { { {"BLAST Genome annotation Sensitivity","PING","X Annotation","Apple X ample"} }, { {"Annotation ==> X","Genome ==> BLAST","Sensitivity ==> BLAST","X ==> Apple","ample ==> Apple","annotation ==> BLAST"} } },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        vector<string> run(ServiceNames* x) {
            return x->makeList(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<ServiceNames>(
            getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
            500, 1485703830, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
