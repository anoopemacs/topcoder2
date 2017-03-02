#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
using namespace std;
typedef long long int64;

// CUT begin
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

#define ff first
#define ss second
#define mpa make_pair

class CollectingRiders {
public:
    vector<int> dx = {1,1,2,2,-1,-1,-2,-2};
    vector<int> dy = {2,-2,1,-1,2,-2,1,-1};
    
    int knight_dist(int x1, int y1, int x2, int y2, int Nc, int Nr) {
        //debug( x1,  y1,  x2,  y2,  Nc,  Nr);
	
        queue<int> Q;
        Q.push(x1);
        Q.push(y1);
        Q.push(0);
        
        int solved[10][10];
        memset(solved, 0, sizeof(solved));
        
        while(!Q.empty()) {
            int xq = Q.front(); Q.pop();
            int yq = Q.front(); Q.pop();
            int distq = Q.front(); Q.pop();
        
            // cout << endl;   
            // debug("xq,yq,distq", xq,yq,distq);
        
            if(xq==x2 && yq==y2)
                return distq;
            solved[xq][yq] = 1;     
    
            for(int i=0; i<8; ++i) {
                int x3 = xq+dx[i];
                int y3 = yq+dy[i];
            
                if(x3>=0 && x3<Nc && y3>=0 && y3<Nr && solved[x3][y3] == 0) {
                    //debug(x3,y3,"*******", "i=", i, "d[]", dx[i], dy[i]);
                
                    Q.push(x3);
                    Q.push(y3);
                    Q.push(distq+1);
                    //debug("x3,y3,distq_plus_one", xq,yq,distq+1);
                }
            }
        }
        return 10000;
    }
    
    int minimalMoves(vector<string> board) {
	int Nr = board.size();
	int Nc = board[0].length();
	
        int memo[10][10];
        memset(memo, 0, sizeof(memo));

	int dist[10][10][10][10];
	memset(dist, 0, sizeof(dist));
	
	for(int x1=0; x1<Nc; ++x1) for(int y1=0; y1<Nr; ++y1) for(int x2=0; x2<Nc; ++x2) for(int y2=0; y2<Nr; ++y2) {
			if(!(x1==x2 && y1==y2)) {
			    dist[x1][y1][x2][y2] = knight_dist(x1,y1,x2,y2,Nc,Nr);
			}
                    } 
	
        for(int x2=0; x2<Nc; ++x2) {
            for(int y2=0; y2<Nr; ++y2) {
		int running_dist_sum = 0;
		
		for(int x1=0; x1<Nc; ++x1) {
		    for(int y1=0; y1<Nr; ++y1) {
			int board_row = y1;
			int board_column = x1;
			if(board[board_row][board_column] != '.') {
			    int distance = dist[x1][y1][x2][y2];
			    if(distance >= 10000)
				running_dist_sum = running_dist_sum + 10000;
			    else
				running_dist_sum = running_dist_sum + ceil ((double)distance/(double)(board[board_row][board_column] - '0')); //integer division
			}
		    }
		}
		memo[x2][y2] = running_dist_sum;
	    }
	}

        for(int py=0;py<Nr;++py) {          
	    for(int px=0;px<Nc;++px) {
		cout << memo[px][py] << ", ";
	    }
	    cout << endl;
	}
	
	int ret = INT_MAX;
	for(int x2=0; x2<Nc; ++x2) {
            for(int y2=0; y2<Nr; ++y2) {
		if(memo[x2][y2] < ret) {
		    ret = memo[x2][y2];
		}
	    }
	}
	
	for(int x1=0; x1<Nc; ++x1) for(int y1=0; y1<Nr; ++y1) for(int x2=0; x2<Nc; ++x2) for(int y2=0; y2<Nr; ++y2) {
			cout << "(" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ") = "
			     << dist[x1][y1][x2][y2] << endl;
		    }
	
	if(ret>=10000) return -1;
	    
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
    // { { {"...1","....","2..."} }, {2} },
    // { { {"........",".1......","........","....3...","........","........",".7......","........"} }, {2} },
    // { { {"..","2.",".."} }, {0} },
    // { { {".1....1."} }, {-1} },
    // { { {"9133632343","5286698232","8329333369","5425579782","4465864375","8192124686","3191624314","5198496853","1638163997","6457337215"} }, {121} },
    { {{"1...1", "....."}}, {2}},
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        int run(CollectingRiders* x) {
            return x->minimalMoves(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<CollectingRiders>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488054131, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
