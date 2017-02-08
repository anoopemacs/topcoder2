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

class SimpleRotationDecoder {
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
    
    bool myvalidate(string s) {
	int N = s.size();
	//no leaading or ending spaces in sentence
	if(s[0]==' ' || s[N-1]==' ') return false;
	
	vector<string> vs = mysplit(s, ' ');
	for(int i=0; i<vs.size(); ++i) {
	    string word = vs[i];
	    if(word.size() < 2 || word.size() > 8) return false;
	    if((word.find('a') == -1) && (word.find('e') == -1) && (word.find('i') == -1) && (word.find('o') == -1) && (word.find('u') == -1)) return false;
	}
	return true;
    }
    
    string decode(string ct) {
	string ref = " abcdefghijklmnopqrstuvwxyz";
	
	vector<string> pv;
	for(int i=1; i<27; ++i) {
	    for(int j=1; j<27; ++j) {
		for(int k=1; k<27; ++k) {
		    string topush;
		    topush.push_back(ref[i]);
		    topush.push_back(ref[j]);
		    topush.push_back(ref[k]);
                    pv.push_back(topush);
		}
	    }
	}
	//pv is possible passwords vector
	//debug(pv);

	for(int i=0; i<pv.size(); ++i) {
	    string pass = pv[i];
	    vector<string> cref;
	    string cref0, cref1, cref2;
	    for(int j=0; j<ref.size(); ++j) {
		char c = ref[j];
		int cal0 = (ref.find(c)+ref.find(pass[0])) % 27;
		int cal1 = (ref.find(c)+ref.find(pass[1])) % 27;
		int cal2 = (ref.find(c)+ref.find(pass[2])) % 27;

		cref0.push_back(ref[cal0]);
		cref1.push_back(ref[cal1]);
		cref2.push_back(ref[cal2]);
            }
	    cref.push_back(cref0);
	    cref.push_back(cref1);
	    cref.push_back(cref2);
            
	    int N = ct.size();
	    //for each in ct:
	    
	    //use the property that there is one-one relation between cipher & original for a given password
	    string original;
	    for(int j=0; j<N; ++j) {
		int fi = j%3; //first index
		string crefi = cref[fi];
		
		int calcj = crefi.find(ct[j]);
		char originalChar = ref[calcj];
		original.push_back(originalChar);
	    }

	    if(myvalidate(original)) {
		return original;
	    }
        }
        
	return "error0";
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
    { { "mmbtvrbhhtgohaktklqegnrmlelojotyeyeiudvtil ey ffg" }, {"the quick brown fox jumps over the lazy dog again"} },
    { { "ntgntgntgntofwlfwlfwlnookookook" }, {"he he he heh he he heh he he he"} },
    { { "f sgnzslhzquq ydyuinmqiwfyrtdvn" }, {"abkbprnn usmlbqz mdpelkoa jofni"} },
    { { "shxnaaeqjlofhhsuurbhpdgt z" }, {"naeiui jrghnca pnzxaxz avs"} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;

        string run(SimpleRotationDecoder* x) {
            return x->decode(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<SimpleRotationDecoder>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1485871250, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
