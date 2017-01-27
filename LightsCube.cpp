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

class LightsCube {
    string its(int i) {
	stringstream ss;
	ss<<i;
	string ret;
	ss>>ret;
	return ret;
    }
    
    string myits(int x, int y, int z) {
	//convert to zero based index
	return its(x-1) + " " + its(y-1) + " " + its(z-1);
    }
    
public:
    vector<int> count(int N, vector<string> lights) {
	vector<int> ret;
        //int cube[N+2][N+2][N+2];
	vector<vector<vector<int>>> cube;
	
	for(int x=0;x<N+2; ++x) {
	    vector<vector<int>> surface;
            for(int y=0;y<N+2; ++y){
		vector<int> zline;
                for(int z=0;z<N+2; ++z) {
		    zline.push_back(-1);
		}
		surface.push_back(zline);
	    }
	    cube.push_back(surface);
	}
	
	int cN=lights.size();
	for(int i=0; i<cN; ++i)
	    ret.push_back(0);
	
	int count=N*N*N;
	
	for(int x=1;x<=N; ++x) {
            for(int y=1;y<=N; ++y) {
                for(int z=1;z<=N; ++z) {
                    string xyz=myits(x,y,z);
                    vector<string>::iterator iter = find(lights.begin(), lights.end(), xyz);
                    if (iter != lights.end()) { //found=>already on
                        int color = (int) (iter-lights.begin());
                        cube[x][y][z]=color;
                        --count;
                    }
                }
            }
        }
	
        while(count > 0) {// each while loop = 1second
	    vector<vector<vector<int>>> next_cube=cube;
	    
            for(int x=1;x<=N; ++x) {
                for(int y=1;y<=N; ++y) {
		    for(int z=1;z<=N; ++z) {
			if (cube[x][y][z]==-1) { //if off
			    vector<int> adj;
			    //adj contains neighbour colors that are on
			    int nei[6]; //6 neighbours
			    nei[0]=cube[x-1][y][z];
			    nei[1]=cube[x+1][y][z];
			    nei[2]=cube[x][y-1][z];                        
			    nei[3]=cube[x][y+1][z];                        
			    nei[4]=cube[x][y][z-1];                        
			    nei[5]=cube[x][y][z+1];
			    for(int i=0; i<6; ++i) {
				if(nei[i]!=-1) adj.push_back(nei[i]);
                            }
			    if(adj.size()!=0) {
				sort(adj.begin(), adj.end());
				next_cube[x][y][z] = adj[0];
			        --count;                            
			    }
			}
		    }
		}
	    }
	    cube=next_cube;
	}
	
	for(int x=1;x<=N; ++x) {
            for(int y=1;y<=N; ++y) {
                for(int z=1;z<=N; ++z) {
		    int color=cube[x][y][z];
		    ++ret[color];
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
	{ { 2, {"0 0 0","0 0 1","0 1 0","0 1 1","1 0 0","1 0 1","1 1 0","1 1 1"} }, { {1,1,1,1,1,1,1,1} } },
	{ { 3, {"1 1 1"} }, { {27} } },
	{ { 4, {"0 0 0","3 3 3"} }, { {32,32} } },
	{ { 5, {"0 2 4","2 0 0","3 4 4","4 1 2"} }, { {38,28,32,27} } },
	{ { 12, {"4 7 6","8 0 0","3 2 3","7 7 2","7 5 1","10 11 5","4 9 7","6 1 0","10 1 1","9 7 11","11 3 11","9 0 3","10 2 0"} }, { {264,18,303,236,105,124,216,44,53,146,126,80,13} } },
	{ { 40, {"29 13 9","4 10 34","11 26 16","2 33 22","27 31 14","36 20 8"} }, { {14657,12834,12364,5902,12678,5565} } },
	// Your custom test goes here:
	//{ { , {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    int p0;vector<string> p1;

    vector<int> run(LightsCube* x) {
	return x->count(p0,p1);
    }
    void print() { Tester::printArgs(p0,p1); }
};
    
int main() {
    return Tester::runTests<LightsCube>(
					getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
					500, 1484668631, CASE_TIME_OUT, Tester::COMPACT_REPORT
					);
}
// CUT end
