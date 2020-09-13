#include<algorithm>
#include<cassert>
#include<cstdio>
#include<fstream>
#include<functional>
#include<iostream>
#include<sstream>
#include<vector>
#define fir first
#define sec second
using namespace std;
using bit=bool;
using i32=int;
using i64=long long;
using u32=unsigned int;
using u64=unsigned long long;

const string mode="replay";
const string player[2]={
  /*white*/"/Users/memset0/Git/reversi-bot/bot.cpp",
  /*black*/"/Users/memset0/Git/reversi-bot/others-example/xay5421.cpp",
};
// const string player[2]={
// 	/*white*/"",
// 	/*black*/"",
// };

// Tools: Debug
#ifdef memset0
  #define log(...) fprintf(stderr,__VA_ARGS__)
  #define debug(...) fprintf(stderr,__VA_ARGS__)
#else
  #define log(...) void(0)
  #define debug(...) fprintf(stderr,__VA_ARGS__)
#endif

// Tools: Bit Operation
#define id(i,j) (((i)<<3)|(j))
#define idx(v) ((v)>>3)
#define idy(v) ((v)&7)
#define popcnt __builtin_popcountll
#define in(i,k) (((k)>>(i))&1)
#define subset(x,y) (((x)&(y))==(x))

// Tools: Helper Libs
template<typename... Args> string string_sprintf(const char* format,Args... args){
  int length=snprintf(nullptr,0,format,args...);
#ifdef memset0
  assert(length>=0);
#endif
  char* buf=new char[length+1];
  snprintf(buf,length+1,format,args...);
  string str(buf);
  delete[] buf;
  return str;
}

// Class: Vector
template<class T> struct vec:vector<T>{
  using vector<T>::vector;
  
  inline vec<T> slice(int l,int r)const{return vec(this->begin()+l,this->begin()+r);}
  inline vec<T> concat(const vec<T> &rhs){this->insert(this->end(),rhs.begin(),rhs.end());}
  inline bit includes(const T &x){return find(this->begin(),this->end(),x)!=this->end();}

  inline void forEach(const function<void(T)> &func){
    for(const auto &it:*this)func(it);
  }
  template<class TT> inline vec<TT> map(const function<TT(T)> &func){
    vec<TT> res;
    for(const auto &it:*this)res.push_back(func(it));
    return res;
  }
};
template<class T> string to_string(const vec<T> &v){
  string res;
  if(v.size()){
    res+=to_string(v[0]);
    for(size_t i=1;i<v.size();i++)res+=","+to_string(v[i]);
  }
  return "{"+res+"}";
}
template<class T> string to_string(const vec<T> &v,function<string(T)> custom){
  string res;
  if(v.size()){
    res+=custom(v[0]);
    for(size_t i=1;i<v.size();i++)res+=","+custom(v[i]);
  }
  return "{"+res+"}";
}

// Class: Map
struct Map{
  u64 a;

  inline u64 source()const{return a;}
  inline int count()const{return popcnt(a);}
  inline int intersection(u64 rhs)const{return popcnt(a^rhs);}

  inline void set(){a=-1ull;}
  inline void reset(){a=0;}
  inline void flip(){a^=1ull;}

  inline bit get(int k)const{return in(k,a);}
  inline void set(int k){a|=1ull<<k;}
  inline void flip(int k){a^=1ull<<k;}
  inline void reset(int k){a&=-1ull^(1ull<<k);}
  inline void paint(int k,int x){x?this->set(k):this->reset(k);}

  inline bit get(int i,int j)const{return in(id(i,j),a);}
  inline void set(int i,int j){a|=1ull<<id(i,j);}
  inline void flip(int i,int j){a^=1ull<<id(i,j);}
  inline void reset(int i,int j){a&=-1ull^(1ull<<id(i,j));}
  inline void paint(int i,int j,int x){x?this->set(i,j):this->reset(i,j);}

  Map():a(0ull){}
  Map(u64 a):a(a){}
};

// Class: Board
struct Board{
  Map map[2];

  inline vec<int> getMove(bit)const;
  inline int getMoveSize(bit)const;
  inline bit checkMove(bit,int)const;

  inline vec<int> getStable(bit)const;
  inline int getStableSize(bit)const;

  inline void move(bit,int);
  inline void move(bit,int,int);

  inline int judge(bit)const;

  inline void reverse(){swap(map[0],map[1]);}

  inline string to_string()const{
    string text;
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        if(map[0].get(i,j))text+='0';
        else if(map[1].get(i,j))text+='1';
        else text+='.';
      }
      text+='\n';
    }
    return text;
  }
  inline void output()const{
#ifdef memset0
    log("===board %llu %llu===\n",map[0].source(),map[1].source());
    log("%s",this->to_string().c_str());
#else
    log("[logger] Outputting a `Board` is disabled!");
#endif
  }
};
constexpr int nxt[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
vec<int> walk[64][8];
vec<u64> walkpath[64][8];
void init(){
  for(int sx=0;sx<8;sx++)
    for(int sy=0;sy<8;sy++)
      for(int w=0;w<8;w++){
        int x=sx,y=sy;
        u64 path=0;
        while(true){
          x+=nxt[w][0];
          y+=nxt[w][1];
          if(x<0||x>=8||y<0||y>=8)break;
          walk[id(sx,sy)][w].push_back(id(x,y));
          walkpath[id(sx,sy)][w].push_back(path);
          path|=1ull<<id(x,y);
        }
      }
}

// Lib
inline void shell(string command,bool quiet=false){
  if(!quiet)printf("\e[31m[shell] %s\e[0m\n",command.c_str());
	system(command.c_str());
}
string readFile(string path){
  ifstream fileStream(path);
  string line,text;
  while(getline(fileStream,line)){
    text+=line+"\n";
  }
  return text;
}
void writeFile(string path,const string &text){
  ofstream fileStream(path);
  fileStream<<text;
  fileStream.close();
}

// Mode: Replay
int replayMain(){
	int n;
	vec<pair<int,int>> go,data[2];
	ifstream replayData("judger/replay.in");
	replayData>>n;
  go.resize((n<<1)-1);
  for(int i=0;i<(int)go.size();i++){
    replayData>>go[i].fir>>go[i].sec;
  }
  printf("n=%d\n",n);

	data[0]=data[1]=go;
	if(~go.front().fir&&~go.front().sec){ //当前是白棋
		data[1].insert(data[1].begin(),make_pair(-1,-1));
	}else{ //当前是黑棋
		data[0].erase(data[0].begin());
	}

	auto filterData=[](int n,const vec<pair<int,int>> &data){
    string plain=to_string(n)+"\n";
		for(int i=0;i<(n<<1)-1;i++){
      plain+=to_string(data[i].fir)+" "+to_string(data[i].sec)+"\n";
		}
    return plain;
	};
  printf(">> %lu %lu\n",data[0].size(),data[1].size());
	for(int n=1;(n<<1)-1<=data[1].size()||(n<<1)-1<=data[0].size();n++){
    log("\e[33m\n=== Round %d ===\e[0m\n",n);
		if((n<<1)-1<=data[1].size()){
			writeFile("judger/input1.in",filterData(n,data[1]));
			shell("judger/player1.exe < judger/input1.in > judger/output1.out",1);
			writeFile("judger/input0.in",filterData(n,data[1]));
			shell("judger/player0.exe < judger/input1.in > judger/output0.out",1);
      log("\e[32mchoose => %soppo choose => %s\e[0m",readFile("judger/output1.out").c_str(),readFile("judger/output0.out").c_str());
		}
    pair<int,int> mov1=(n<<1)<=data[1].size()?data[1][(n<<1)-1]:make_pair(-1,-1);
    log("\e[31mBLACK: %d %d\e[0m\n",mov1.fir,mov1.sec);
		if((n<<1)-1<=data[0].size()){
      writeFile("judger/input0.in",filterData(n,data[0]));
      shell("judger/player0.exe < judger/input0.in > judger/output0.out",1);
			writeFile("judger/input1.in",filterData(n,data[1]));
			shell("judger/player1.exe < judger/input0.in > judger/output1.out",1);
      log("\e[32mchoose => %soppo choose => %s\e[0m",readFile("judger/output0.out").c_str(),readFile("judger/output1.out").c_str());
		}
    pair<int,int> mov0=(n<<1)<=data[0].size()?data[0][(n<<1)-1]:make_pair(-1,-1);
    log("\e[31mWHITE: %d %d\e[0m\n",mov0.fir,mov0.sec);
    if(n==4)break;
	}

	return 0;
}

// main
int main(){
	for(int c=0;c<2;c++)
		if(player[c].length()){
      log("\e[2m[log] Complie program of `Player%d`\e[0m\n",c);
			shell("g++ -O2 -std=c++17 "+player[c]+" -o judger/player"+to_string(c)+".exe");
		}
	if(mode=="replay")return replayMain();
}