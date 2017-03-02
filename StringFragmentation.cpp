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

class StringFragmentation {
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
        //    sort(s.begin(), s.end());
        return ret;
    }

    
    
    int largestFontSize(string text, int width, int height) {
	const int minFont = 8;
	vector<string> vs = mysplit(text, ' ');
	int largest_word_length = 0;
	for(int i=0; i<vs.size(); ++i)
	    if(vs[i].length() > largest_word_length) largest_word_length = vs[i].length();
	
	int maxFont1 = 10000/2;
	int maxFont2 = 10000/largest_word_length - 2;
	int maxFont = min(maxFont1, maxFont2);

	int ret = -1;
	
	for(int f=minFont; f<=maxFont; ++f) {
	    //debug("f=", f);
	    int font_width = width/(f+2);
	    int font_height = height/(2*f);

	    if(font_width == 0 || font_height == 0) continue;
	    
	    vector<string> display;

	    for(int i=0; i<vs.size(); ) {

		string topush = vs[i];

		int j;
		
		for(j=i+1; j<vs.size() ; ++j) {
		    string temp = topush + " " + vs[j];
		    if (temp.length() > font_width) {
			break;
		    }
		    
		    if (temp.length()<=font_width) {
			topush = temp;
		    }
		}
		i = j;

		display.push_back(topush);
		
	    }

	    if(display.size() <= font_height) {
		string longestDisplayLine = "";
		for(int k=0; k<display.size(); ++k)
		    if(display[k].length() > longestDisplayLine.length()) longestDisplayLine = display[k];
		
		
		if(longestDisplayLine.length() <= font_width) {
		    debug(display, f, longestDisplayLine, font_width);
		    
		    ret = f;
		}
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
    { { "ONE TWO THREE FOUR FIVE", 150, 40 }, {9} },
    { { "ONE TWO THREE FOUR FIVE", 150, 60 }, {10} },
    { { "ONE TWO THREE FOUR FIVE", 150, 10000 }, {28} },
    { { "ONE TWO THREE FOUR FIVE", 10000, 10000 }, {1250} },
    { { "ONE TWO THREE FOUR FIVE", 50, 50 }, {-1} },
    { { "A", 9, 14 }, {-1} },
    // Your custom test goes here:
    //{ { , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;int p1;int p2;

        int run(StringFragmentation* x) {
            return x->largestFontSize(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<StringFragmentation>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1487954146, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
