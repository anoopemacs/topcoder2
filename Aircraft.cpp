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

class Aircraft {
public:
    double sq(double d) {
	return pow(d,2);
    }
    
    string nearMiss(vector<int> p1, vector<int> v1, vector<int> p2, vector<int> v2, int R) {
	//relative v&p:
	vector<int> v(3);
	vector<int> p(3);
	for(int i=0; i<3; ++i) {
	    v[i] = v2[i]-v1[i];
	    p[i] = p2[i]-p1[i];
	}

	// always minima at tmin as second derivative always positive
	double tmin = -(v[0]*p[0] + v[1]*p[1] + v[2]*p[2])/(sq(v[0]) + sq(v[1]) + sq(v[2]));
	double dmin = DBL_MAX;
	
	if(tmin>0) {
	    //dmin occurs at tmin
	    dmin = sqrt( sq(p[0] + v[0]*tmin) + sq(p[1] + v[1]*tmin) + sq(p[2] + v[2]*tmin));
	} else {
	    //dmin occurs at t=0
	    dmin = sqrt( sq(p[0]) + sq(p[1]) + sq(p[2]));
        }
	if(dmin <= (double)R) {
	    return "YES";
	} else {
	    return "NO";    
	}
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
    { { {15,50,5}, {25,1,0}, {161,102,9}, {-10,-10,-1}, 10 }, {"YES"} },
    { { {0,0,0}, {2,2,0}, {9,0,5}, {-2,2,0}, 5 }, {"YES"} },
    { { {0,0,0}, {-2,2,0}, {9,0,5}, {2,2,0}, 5 }, {"NO"} },
    { { {-2838,-7940,-2936}, {1,1,-2}, {532,3850,9590}, {1,0,-3}, 3410 }, {"YES"} },
    { { {-8509,9560,345}, {-89,-33,62}, {-5185,-1417,2846}, {-58,24,26}, 8344 }, {"YES"} },
    { { {-7163,-371,-2459}, {-59,-41,-14}, {-2398,-426,-5487}, {-43,27,67}, 5410 }, {"NO"} },
    { { {1774,-4491,7810}, {-12,19,-24}, {2322,3793,9897}, {-12,19,-24}, 10000 }, {"YES"} },
    { { {3731,8537,5661}, {-70,71,32}, {8701,-1886,-5115}, {28,-13,7}, 9766 }, {"NO"} },
    // Your custom test goes here:
    //{ { {}, {}, {}, {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;vector<int> p2;vector<int> p3;int p4;

        string run(Aircraft* x) {
            return x->nearMiss(p0,p1,p2,p3,p4);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3,p4); }
    };
    
    int main() {
        return Tester::runTests<Aircraft>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1485949546, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
