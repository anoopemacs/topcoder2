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

vector<string> reachable;

class Trainyard {
public:
    void mytraverse(vector<string> vs, int fuel, int ir, int ic) {
	debug(reachable, fuel);
	
	if(fuel <= 0) return;
	int Nr = vs.size();
	int Nc = vs[0].length();

	//debug(vs, ir, ic);
	
	//east:	
	if((ic+1) < Nc &&
	   //	   reachable[ir][ic+1] != 'R' &&
	   (vs[ir][ic]=='+' || vs[ir][ic]=='-') &&
	   (vs[ir][ic+1]=='+' || vs[ir][ic+1]=='-')) {
	    reachable[ir][ic+1] = 'R';
	    mytraverse(vs, fuel-1, ir, ic+1);
	}

	//north:
	if((ir-1) >= 0 &&
	   //reachable[ir-1][ic] != 'R' &&     
	   (vs[ir][ic]=='+' || vs[ir][ic]=='|') &&
           (vs[ir-1][ic]=='+' || vs[ir-1][ic]=='|')) {
            reachable[ir-1][ic] = 'R';
            mytraverse(vs, fuel-1, ir-1, ic);
        }

	//west:
	if((ic-1) >= 0 &&
	   //reachable[ir][ic-1] != 'R' &&     
	   (vs[ir][ic]=='+' || vs[ir][ic]=='-') &&
           (vs[ir][ic-1]=='+' || vs[ir][ic-1]=='-')) {
            reachable[ir][ic-1] = 'R';
            mytraverse(vs, fuel-1, ir, ic-1);
        }

	//south:
	if((ir+1) < Nr &&
	   //reachable[ir+1][ic] != 'R' &&     
	   (vs[ir][ic]=='+' || vs[ir][ic]=='|') &&
           (vs[ir+1][ic]=='+' || vs[ir+1][ic]=='|')) {
            reachable[ir+1][ic] = 'R';
            mytraverse(vs, fuel-1, ir+1, ic);
        }
    }
    
    int reachableSquares(vector<string> layout, int fuel) {
	reachable = layout;

	
	int initRow=-1, initCol=-1;
	for(int i=0; i<layout.size(); ++i)
	    for(int j=0; j<layout[i].size(); ++j)
		if(layout[i][j] == 'S') {
		    initRow = i;
		    initCol = j;
		}
	reachable[initRow][initCol] = 'R';

	/*
        for(int i=0; i<reachable.size(); ++i) {
            cout << reachable[i] << endl;
        }
	cout << "************************************************************************************************************************************" << endl; 
        */
	
        layout[initRow][initCol] = '+';
	
	mytraverse(layout, fuel, initRow, initCol);
	
	int ret = 0;
	for(int i=0; i<reachable.size(); ++i) {
	    ret += count(reachable[i].begin(), reachable[i].end(), 'R');
	}

	/*
	cout << "************************************************************************************************************************************" << endl;
	for(int i=0; i<reachable.size(); ++i) {
	    cout << reachable[i] << endl;
	}
	*/
	
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
    { { {".-....","-S---.","......"}, 2 }, {4} },
    { { {"..+-+.","..|.|.","S-+-+."}, 10 }, {10} },
    { { {"-....-","|....+","+-S++|","|.|..|","..+-++"}, 8 }, {15} },
    { { {".|...","-+S+|",".|..."}, 5 }, {6} },
    { {{"++++++++++", "++++++++++", "++++++++++", "++++++++++", "++++++++++", "++++S+++++", "++++++++++", "++++++++++", "++++++++++", "++++++++++"}, 3}, {25}},
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;int p1;

        int run(Trainyard* x) {
            return x->reachableSquares(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<Trainyard>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1487996606, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
