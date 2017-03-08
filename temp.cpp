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

string myits(int i) {
    stringstream ss;
    ss<<i;
    string ret;
    ss>>ret;
    return ret;
}

int mysti(string s) {
    stringstream ss;
    ss<<s;
    int ret;
    ss>>ret;
    return ret;
}

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

#define M 32
int main() {
    // http://www.geeksforgeeks.org/c-bitset-and-its-application/
    bitset<M> bset1;
    bitset<M> bset2(-1);
    bitset<M> bset3(string("10"));
    debug(bset1, bset2, bset3);
    
    bitset<8> set8;
    debug(set8);
    debug(~set8);
    set8[1] = 1;
    set8[3] = 1;
    debug(set8);    
    
    int numberOf1 = set8.count();
    int numberOf0 = set8.size() - numberOf1;
    debug(numberOf1, numberOf0);
    for (int i=0; i<set8.size(); ++i)
        cout << set8.test(i) << endl;
    if(set8.any())
        cout << "set8 has some bit set" << endl;
    if(!bset1.any())
        cout << "bset1 has no bit set" << endl;
    if(!bset2.none())
        cout << "bset2 has all bits set" << endl;
    debug(set8.set());
    debug(set8.reset()); //destructive
    debug(set8.flip()); //destructive
    debug(set8.flip(1));
    
    //int num = 69;
    int num = -1;
    //long long num = -1;
    cout << num << " in binary = " << bitset<32>(num) << endl;
    
    int arr[99];
    memset(arr, 0, sizeof(arr));
    
    cout << (string("001") == "001") << endl;
    bitset<128> test128;
    test128.flip();
    cout << test128 << endl;
    
    bitset<8> b8;
    b8 = 1<<7;
    cout << b8 << endl;
    
    //bmerry: fun with bits
    cout << "bmerry fun with bits starts here" << endl;
    bitset<8> A(string("1010"));
    bitset<8> B(string("1100"));
    bitset<8> allbits("00001111"); // not 11111111 because for negation below to work
    
    debug("A=", A, " B=", B);
    debug("union:", A|B);
    debug("intersec:", A&B);
    debug("subtraction:", A&(~B));
    debug("negation:", allbits^A);
    A[2]=1;
    debug("set 2nd bit", A);
    
    bitset<32> n(16); // build n using the integer value = 16's bit representation
    debug("12345678123456781234567812345678");
    debug(n, "=n");
    int clz = __builtin_clz(16), ctz = __builtin_ctz(16), ones = __builtin_popcount(16);
    debug(clz, ctz, ones);
    debug(__builtin_ctz(0));

    cout << (1<<31) << "   " << bitset<32>(1<<31) << "  " << INT_MIN << endl;
    return 0;
    
    for(int i=0; i<20; ++i) {
        bitset<32> bi(i);
        int lowest_set_bit = (i & ~(i-1));
        cout << bi << "   " <<  bitset<32>(lowest_set_bit) << endl;
    }
    cout << endl;
    
    bitset<32> trivia = 1<<20;
    debug("trivia:", trivia);
    
    stringstream ss;
    ss << 0xaaaaaaaa;
    long i;
    ss >> i;
    cout << i << endl;
    
    //not so useful trick: reverse bits
    int x = 2;
    bitset<32>xbit(x);
    cout << xbit << endl;
    x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
    x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
    x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
    x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
    x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
    cout << bitset<32>(x) << endl;
    
    //subsets start
    //[0, N-1], k-element subsets
    //[0, 7], 3-element subsets
    int wht[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (int i=0; i<8; ++i)
        printf("%c ", wht[i]);
    cout << endl;
    
    int k = 3;
    int N = 8;
    
    int s = (1<<k) - 1;
    while(!(s & (1<<N))) {
        int lo = s & ~(s-1); // lowest one
        int lz = (s+lo) & (~s); // lowest zero after lo
        cout << bitset<8>(s) << "  " << bitset<8>(lo) << "  " << bitset<8>(lz) << endl;
        s = s | lz; // add lz to set
        s = s & ~(lz-1); // reset bits below lz
        int appropriate_number_of_ones = (lz/lo/2 - 1);
        s = s | appropriate_number_of_ones;
    }
    
    return 0;
}




















