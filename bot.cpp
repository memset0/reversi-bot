#include<algorithm>
#include<cassert>
#include<cstdio>
#include<chrono>
#include<functional>
#include<iomanip>
#include<iostream>
#include<random>
#include<sstream>
#include<vector>
#define fir first
#define sec second
#define all(x) (x).begin(),(x).end()

using namespace std;
using bit=bool;
using i32=int;
using i64=long long;
using u32=unsigned int;
using u64=unsigned long long;

// auto generated
namespace Judger{
  const u64 corner=0x8100000000000081;
  const u64 x_squares=0x0042000000004200;
  const u64 c_squares=0x4281000000008142;
  const u64 stable[64][5]={{0x81412111090503FF,0x0000000000000001,0x00000000000000FF,0x0101010101010101,0xFFFFFFFFFFFFFFFF},{0x02824222120A07FF,0x0000000000000003,0x00000000000000FE,0x0303030303030303,0xFEFEFEFEFEFEFEFE},{0x0404844424150EFF,0x0000000000000007,0x00000000000000FC,0x0707070707070707,0xFCFCFCFCFCFCFCFC},{0x08080888492A1CFF,0x000000000000000F,0x00000000000000F8,0x0F0F0F0F0F0F0F0F,0xF8F8F8F8F8F8F8F8},{0x10101011925438FF,0x000000000000001F,0x00000000000000F0,0x1F1F1F1F1F1F1F1F,0xF0F0F0F0F0F0F0F0},{0x2020212224A870FF,0x000000000000003F,0x00000000000000E0,0x3F3F3F3F3F3F3F3F,0xE0E0E0E0E0E0E0E0},{0x404142444850E0FF,0x000000000000007F,0x00000000000000C0,0x7F7F7F7F7F7F7F7F,0xC0C0C0C0C0C0C0C0},{0x8182848890A0C0FF,0x00000000000000FF,0x0000000000000080,0xFFFFFFFFFFFFFFFF,0x8080808080808080},{0x412111090503FF03,0x0000000000000101,0x000000000000FFFF,0x0101010101010100,0xFFFFFFFFFFFFFF00},{0x824222120A07FF07,0x0000000000000303,0x000000000000FEFE,0x0303030303030300,0xFEFEFEFEFEFEFE00},{0x04844424150EFF0E,0x0000000000000707,0x000000000000FCFC,0x0707070707070700,0xFCFCFCFCFCFCFC00},{0x080888492A1CFF1C,0x0000000000000F0F,0x000000000000F8F8,0x0F0F0F0F0F0F0F00,0xF8F8F8F8F8F8F800},{0x101011925438FF38,0x0000000000001F1F,0x000000000000F0F0,0x1F1F1F1F1F1F1F00,0xF0F0F0F0F0F0F000},{0x20212224A870FF70,0x0000000000003F3F,0x000000000000E0E0,0x3F3F3F3F3F3F3F00,0xE0E0E0E0E0E0E000},{0x4142444850E0FFE0,0x0000000000007F7F,0x000000000000C0C0,0x7F7F7F7F7F7F7F00,0xC0C0C0C0C0C0C000},{0x82848890A0C0FFC0,0x000000000000FFFF,0x0000000000008080,0xFFFFFFFFFFFFFF00,0x8080808080808000},{0x2111090503FF0305,0x0000000000010101,0x0000000000FFFFFF,0x0101010101010000,0xFFFFFFFFFFFF0000},{0x4222120A07FF070A,0x0000000000030303,0x0000000000FEFEFE,0x0303030303030000,0xFEFEFEFEFEFE0000},{0x844424150EFF0E15,0x0000000000070707,0x0000000000FCFCFC,0x0707070707070000,0xFCFCFCFCFCFC0000},{0x0888492A1CFF1C2A,0x00000000000F0F0F,0x0000000000F8F8F8,0x0F0F0F0F0F0F0000,0xF8F8F8F8F8F80000},{0x1011925438FF3854,0x00000000001F1F1F,0x0000000000F0F0F0,0x1F1F1F1F1F1F0000,0xF0F0F0F0F0F00000},{0x212224A870FF70A8,0x00000000003F3F3F,0x0000000000E0E0E0,0x3F3F3F3F3F3F0000,0xE0E0E0E0E0E00000},{0x42444850E0FFE050,0x00000000007F7F7F,0x0000000000C0C0C0,0x7F7F7F7F7F7F0000,0xC0C0C0C0C0C00000},{0x848890A0C0FFC0A0,0x0000000000FFFFFF,0x0000000000808080,0xFFFFFFFFFFFF0000,0x8080808080800000},{0x11090503FF030509,0x0000000001010101,0x00000000FFFFFFFF,0x0101010101000000,0xFFFFFFFFFF000000},{0x22120A07FF070A12,0x0000000003030303,0x00000000FEFEFEFE,0x0303030303000000,0xFEFEFEFEFE000000},{0x4424150EFF0E1524,0x0000000007070707,0x00000000FCFCFCFC,0x0707070707000000,0xFCFCFCFCFC000000},{0x88492A1CFF1C2A49,0x000000000F0F0F0F,0x00000000F8F8F8F8,0x0F0F0F0F0F000000,0xF8F8F8F8F8000000},{0x11925438FF385492,0x000000001F1F1F1F,0x00000000F0F0F0F0,0x1F1F1F1F1F000000,0xF0F0F0F0F0000000},{0x2224A870FF70A824,0x000000003F3F3F3F,0x00000000E0E0E0E0,0x3F3F3F3F3F000000,0xE0E0E0E0E0000000},{0x444850E0FFE05048,0x000000007F7F7F7F,0x00000000C0C0C0C0,0x7F7F7F7F7F000000,0xC0C0C0C0C0000000},{0x8890A0C0FFC0A090,0x00000000FFFFFFFF,0x0000000080808080,0xFFFFFFFFFF000000,0x8080808080000000},{0x090503FF03050911,0x0000000101010101,0x000000FFFFFFFFFF,0x0101010100000000,0xFFFFFFFF00000000},{0x120A07FF070A1222,0x0000000303030303,0x000000FEFEFEFEFE,0x0303030300000000,0xFEFEFEFE00000000},{0x24150EFF0E152444,0x0000000707070707,0x000000FCFCFCFCFC,0x0707070700000000,0xFCFCFCFC00000000},{0x492A1CFF1C2A4988,0x0000000F0F0F0F0F,0x000000F8F8F8F8F8,0x0F0F0F0F00000000,0xF8F8F8F800000000},{0x925438FF38549211,0x0000001F1F1F1F1F,0x000000F0F0F0F0F0,0x1F1F1F1F00000000,0xF0F0F0F000000000},{0x24A870FF70A82422,0x0000003F3F3F3F3F,0x000000E0E0E0E0E0,0x3F3F3F3F00000000,0xE0E0E0E000000000},{0x4850E0FFE0504844,0x0000007F7F7F7F7F,0x000000C0C0C0C0C0,0x7F7F7F7F00000000,0xC0C0C0C000000000},{0x90A0C0FFC0A09088,0x000000FFFFFFFFFF,0x0000008080808080,0xFFFFFFFF00000000,0x8080808000000000},{0x0503FF0305091121,0x0000010101010101,0x0000FFFFFFFFFFFF,0x0101010000000000,0xFFFFFF0000000000},{0x0A07FF070A122242,0x0000030303030303,0x0000FEFEFEFEFEFE,0x0303030000000000,0xFEFEFE0000000000},{0x150EFF0E15244484,0x0000070707070707,0x0000FCFCFCFCFCFC,0x0707070000000000,0xFCFCFC0000000000},{0x2A1CFF1C2A498808,0x00000F0F0F0F0F0F,0x0000F8F8F8F8F8F8,0x0F0F0F0000000000,0xF8F8F80000000000},{0x5438FF3854921110,0x00001F1F1F1F1F1F,0x0000F0F0F0F0F0F0,0x1F1F1F0000000000,0xF0F0F00000000000},{0xA870FF70A8242221,0x00003F3F3F3F3F3F,0x0000E0E0E0E0E0E0,0x3F3F3F0000000000,0xE0E0E00000000000},{0x50E0FFE050484442,0x00007F7F7F7F7F7F,0x0000C0C0C0C0C0C0,0x7F7F7F0000000000,0xC0C0C00000000000},{0xA0C0FFC0A0908884,0x0000FFFFFFFFFFFF,0x0000808080808080,0xFFFFFF0000000000,0x8080800000000000},{0x03FF030509112141,0x0001010101010101,0x00FFFFFFFFFFFFFF,0x0101000000000000,0xFFFF000000000000},{0x07FF070A12224282,0x0003030303030303,0x00FEFEFEFEFEFEFE,0x0303000000000000,0xFEFE000000000000},{0x0EFF0E1524448404,0x0007070707070707,0x00FCFCFCFCFCFCFC,0x0707000000000000,0xFCFC000000000000},{0x1CFF1C2A49880808,0x000F0F0F0F0F0F0F,0x00F8F8F8F8F8F8F8,0x0F0F000000000000,0xF8F8000000000000},{0x38FF385492111010,0x001F1F1F1F1F1F1F,0x00F0F0F0F0F0F0F0,0x1F1F000000000000,0xF0F0000000000000},{0x70FF70A824222120,0x003F3F3F3F3F3F3F,0x00E0E0E0E0E0E0E0,0x3F3F000000000000,0xE0E0000000000000},{0xE0FFE05048444241,0x007F7F7F7F7F7F7F,0x00C0C0C0C0C0C0C0,0x7F7F000000000000,0xC0C0000000000000},{0xC0FFC0A090888482,0x00FFFFFFFFFFFFFF,0x0080808080808080,0xFFFF000000000000,0x8080000000000000},{0xFF03050911214181,0x0101010101010101,0xFFFFFFFFFFFFFFFF,0x0100000000000000,0xFF00000000000000},{0xFF070A1222428202,0x0303030303030303,0xFEFEFEFEFEFEFEFE,0x0300000000000000,0xFE00000000000000},{0xFF0E152444840404,0x0707070707070707,0xFCFCFCFCFCFCFCFC,0x0700000000000000,0xFC00000000000000},{0xFF1C2A4988080808,0x0F0F0F0F0F0F0F0F,0xF8F8F8F8F8F8F8F8,0x0F00000000000000,0xF800000000000000},{0xFF38549211101010,0x1F1F1F1F1F1F1F1F,0xF0F0F0F0F0F0F0F0,0x1F00000000000000,0xF000000000000000},{0xFF70A82422212020,0x3F3F3F3F3F3F3F3F,0xE0E0E0E0E0E0E0E0,0x3F00000000000000,0xE000000000000000},{0xFFE0504844424140,0x7F7F7F7F7F7F7F7F,0xC0C0C0C0C0C0C0C0,0x7F00000000000000,0xC000000000000000},{0xFFC0A09088848281,0xFFFFFFFFFFFFFFFF,0x8080808080808080,0xFF00000000000000,0x8000000000000000}};
}

// Tools: Debug
#ifdef memset0
  #define log(...) fprintf(stderr,__VA_ARGS__)
  #define debug(...) fprintf(stderr,__VA_ARGS__)
#else
  #define log(...) void(0)
  #define debug(...) fprintf(stderr,__VA_ARGS__)
#endif

// Tools: rng
mt19937 rng(20040725^chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline T rand(T l,T r){return uniform_int_distribution<T>(l,r)(rng);}
inline u32 fakeRng(){
  static u32 seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}

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
  inline T random_item(){return this->operator[](rand(0,(int)this->size()-1));}
  inline bit includes(const T &x){return find(this->begin(),this->end(),x)!=this->end();}

  inline void forEach(const function<void(T)> &func){
    for(const auto &it:*this)func(it);
  }
  template<class TT> inline vec<TT> map(const function<TT(T)> &func){
    vec<TT> res;
    for(const auto &it:*this)res.push_back(func(it));
    return res;
  }

  inline static vec<int> from(u64 sta){
    vec<int> res;
    for(int i=0;i<64;i++)if((sta>>i)&1)res.push_back(i);
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

// Lib
inline string u64ToHex(u64 value){
  return string_sprintf("0x%08X%08X",value>>32,value&(-1u));
}
inline vec<int> u64ToVec(u64 source){
  vec<int> target;
  for(int i=0;i<64;i++)if((source>>i)&1)target.push_back(i);
  return target;
}

// Class: Map
struct Map{
  u64 a;

  inline u64 source()const{return a;}
  inline int count()const{return popcnt(a);}
  inline int intersection(u64 rhs)const{return popcnt(a&rhs);}

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

  inline u64 getMove(bit)const;
  inline int getMoveSize(bit)const;
  inline bit checkMove(bit,int)const;

  inline u64 getStable(bit)const;
  inline int getStableSize(bit)const;

  inline void move(bit,int);
  inline void move(bit,int,int);

  inline int judge(bit)const;
  inline int judgeSide(bit)const;

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

// Class: Movement
struct Movement{
  int move,value;

  inline int judge(Board,bit);

  inline bool operator<(const Movement &rhs)const{return value<rhs.value;}
  inline bool operator==(const Movement &rhs)const{return value==rhs.value;}

  Movement(int move,int value):move(move),value(value){}
  Movement(int move,Board board,bit col):move(move){board.move(col,move),value=board.judge(col);}
};

// Function: init
namespace Judger{
  constexpr int nxt[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

  struct MagicNumber{
    string name,type,plain;
    inline MagicNumber(string base,u64 value):type("u64"){
      name=base;
      plain=u64ToHex(value);
    }
    inline MagicNumber(string base,vec<u64> value):type("u64"){
      name=base+string_sprintf("[%lu]",value.size());
      plain=to_string(value,(function<string(u64)>)[](u64 x){return u64ToHex(x);});
    }
    inline MagicNumber(string base,vec<vec<u64>> value):type("u64"){
      name=base+string_sprintf("[%lu][%lu]",value.size(),value[0].size());
      plain=to_string(value,(function<string(vec<u64>)>)[](const vec<u64> &x){
        return to_string(x,(function<string(u64)>)[](u64 x){return u64ToHex(x);});
      });
    }
  };
  string to_string(const MagicNumber &x){
    return "const "+x.type+" "+x.name+"="+x.plain+";";
  }

  vec<MagicNumber> out;
  void build(){
    auto buildMap=[](const initializer_list<pair<int,int>> &source){
      u64 target=0;
      for(const auto &pr:source){
        target|=1ull<<id(pr.fir,pr.sec);
      }
      return target;
    };

    out.push_back(MagicNumber("corner",buildMap({{0,0},{0,7},{7,0},{7,7}})));
    out.push_back(MagicNumber("x_squares",buildMap({{1,1},{1,6},{6,1},{6,6}})));
    out.push_back(MagicNumber("c_squares",buildMap({{0,1},{1,0},{1,7},{0,6},{7,1},{6,0},{7,6},{6,7}})));

    auto stable=vec<vec<u64>>(64);
    for(int x=0;x<8;x++)
      for(int y=0;y<8;y++){
        Map now;
        now.set(x,y);
        for(int i=0;i<8;i++){
          int u=x,v=y;
          while(true){
            u+=nxt[i][0],v+=nxt[i][1];
            if(u<0||v<0||u>=8||v>=8)break;
            now.set(u,v);
          }
        }
        stable[id(x,y)].push_back(now.source()),now.reset();
        for(int i=0;i<=x;i++)
          for(int j=0;j<=y;j++)
            now.set(i,j);
        stable[id(x,y)].push_back(now.source()),now.reset();
        for(int i=0;i<=x;i++)
          for(int j=y;j<8;j++)
            now.set(i,j);
        stable[id(x,y)].push_back(now.source()),now.reset();
        for(int i=x;i<8;i++)
          for(int j=0;j<=y;j++)
            now.set(i,j);
        stable[id(x,y)].push_back(now.source()),now.reset();
        for(int i=x;i<8;i++)
          for(int j=y;j<8;j++)
            now.set(i,j);
        stable[id(x,y)].push_back(now.source()),now.reset();
      }
    out.push_back(MagicNumber("stable",stable));

    for(const auto &num:out)log("%s\n",to_string(num).c_str());
  }
}

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

// Function: get all moves
inline u64 Board::getMove(bit c)const{
  u64 res=0;
  for(int i=0;i<64;i++)
    if(!map[c].get(i)&&!map[c^1].get(i)){
      bit fl=0;
      for(int w=0;w<8&&!fl;w++)
        if(walk[i][w].size()&&map[c^1].get(walk[i][w].front())){
          for(int j:walk[i][w]){
            if(map[c].get(j)){fl=1; break;}
            if(!map[c^1].get(j))break;
          }
        }
      if(fl)res|=1ull<<i;
    }
  return res;
}
inline int Board::getMoveSize(bit c)const{
  return popcnt(this->getMove(c));
}
inline bit Board::checkMove(bit c,int now)const{
  u64 moves=this->getMove(c);
  if(!moves){
    return now==-1;
  }else{
    return u64ToVec(moves).includes(now);
  }
}

// Function: get stable chess
inline u64 Board::getStable(bit c)const{
  u64 res=0;
  for(int i=0;i<64;i++)
    if(subset(Judger::stable[i][0],this->map[c].a)|| 
       subset(Judger::stable[i][1],this->map[c].a)||
       subset(Judger::stable[i][2],this->map[c].a)||
       subset(Judger::stable[i][3],this->map[c].a)||
       subset(Judger::stable[i][4],this->map[c].a)){
      res|=1ull<<i;
    }
  return res;
}
inline int Board::getStableSize(bit c)const{
  int cnt=0;
  for(int i=0;i<64;i++)
    if(subset(Judger::stable[i][0],(this->map[0].a|this->map[1].a))|| 
       subset(Judger::stable[i][1],this->map[c].a)||
       subset(Judger::stable[i][2],this->map[c].a)||
       subset(Judger::stable[i][3],this->map[c].a)||
       subset(Judger::stable[i][4],this->map[c].a)){
      ++cnt;
    }
  return cnt;
}

// Function: play a movement
inline void Board::move(bit c,int i,int j){this->move(c,id(i,j));}
inline void Board::move(bit c,int u){
  if(!~u)return;
  this->map[c].set(u);
  for(int w=0;w<8;w++)
    for(int t=0;t<(int)walk[u][w].size();t++){
      int v=walk[u][w][t];
      if(this->map[c].get(v)){
        this->map[c].a^=walkpath[u][w][t];
        this->map[c^1].a^=walkpath[u][w][t];
        break;
      }
      if(!this->map[c^1].get(v))break;
    }
}

// Function: Judge
int JudgeStatus=1;
inline int Board::judgeSide(bit c)const{
  int res=0;
  int cnt=this->map[c].count();
  if(!cnt)return -20040725;
  //边角定权
  res+=this->map[c].intersection(Judger::corner)*600;
  res-=this->map[c].intersection(Judger::x_squares)*200;
  res-=this->map[c].intersection(Judger::c_squares)*50;
  //行动力
  int mov=this->getMoveSize(c);
  res+=mov*20;
  if(!mov)res-=800;
  //稳定子
  int sta=this->getStableSize(c);
  res+=sta*40;
  if(sta>=32)return 20040725;
  //占子策略
  if(JudgeStatus==1){
    res-=cnt*10;
  }else if(JudgeStatus==2){
    res+=cnt*30+sta*20;
  }
  return res;
}
inline int Board::judge(bit c)const{
  return this->judgeSide(c)-this->judgeSide(c^1)+(fakeRng()%9-4);
}
inline int Movement::judge(Board board,bit col){
  board.move(col,this->move);
  return this->value=board.judge(col);
}

// Function: Alpha-Beta Search
namespace AlphaBetaSearch{
  const int WeightInf=1e9;
  Board board;
  bit col;
  int maxDepth;
  u32 tick;
  function<void(int)> callback;

  pair<int,int> ans;
  int stackValue[64][64];
  Board stackBoard[64][64];

  int bruteForce(){
    vec<Movement> moves=u64ToVec(board.getMove(col))
      .map((function<Movement(int)>)[&](int move){
        return Movement(move,board,col);
      });
    if(!moves.size()){
      return -1;
    }else{
      sort(all(moves));
      return moves.back().move;
    }
  }
  
  int randomChoose(){
    vec<int> moves=u64ToVec(board.getMove(col));
    if(!moves.size()){
      return -1;
    }else{
      return moves[rand(0,(int)moves.size()-1)];
    }
  }

  void finishSearch(int movement){
    debug("[alpha-beta] maxDepth=%d answerWeight=%d\n",maxDepth,ans.sec);
    if(board.checkMove(col,movement)){
      callback(movement);
    }else{
      debug("[error] Illegal moves!!! (move=%d)",movement);
      callback(rand(0,2)?bruteForce():randomChoose());
    }
    exit(0);
  }

  int alphaBetaSearch(const Board &board,int step,int alpha,int beta){
    bit mycol=col^(step&1);
    if(!(++tick&1023)&&1.0*clock()/CLOCKS_PER_SEC>0.95){
      return finishSearch(ans.fir),0;
    }
    if(step>maxDepth){
      return board.judge(mycol);
    }

    vec<int> ord;
    pair<int,int> best(-1,-WeightInf);

    u64 moves=board.getMove(mycol);
    for(int i=0;i<64;i++)if((moves>>i)&1){
      ord.push_back(i);
      stackBoard[step][i]=board;
      stackBoard[step][i].move(mycol,i);
      stackValue[step][i]=stackBoard[step][i].judge(mycol);
    }
    sort(ord.begin(),ord.end(),[&](int x,int y){
      return stackValue[step][x]>stackValue[step][y];
    });

    bool slideWindowFlag=false;
    for(int i:ord){
      const Board &next=stackBoard[step][i];
      int val;
      if(slideWindowFlag){
        val=-alphaBetaSearch(next,step+1,-alpha-1,-alpha);
        if(val>alpha&&val<beta){
          val=-alphaBetaSearch(next,step+1,-beta,-alpha);
        }
      }else{
        val=-alphaBetaSearch(next,step+1,-beta,-alpha);
      }
      if(val>=beta)return val;
      if(val>alpha){
        alpha=val;
        best=make_pair(i,val);
        slideWindowFlag=true;
      }
    }
    if(!moves){
      int val=-alphaBetaSearch(board,step+1,-beta,-alpha);
      if(val>=beta)return val;
      if(val>alpha){
        alpha=val;
        best=make_pair(-1,val);
      }
    }

    if(!step)ans=best;
    return alpha;
  }

  void solve(const Board &_board,bit _col,function<void(int)> _callback){
    board=_board,col=_col,callback=_callback;

    if(!board.getMove(col)){
      log("[alpha-beta] no moves at all!");
      return finishSearch(-1);
    }
    if(board.map[col].count()<=3&&board.map[col^1].count()<=5){
      return finishSearch(randomChoose());
    }

    ans=make_pair(-1,-WeightInf);
    for(maxDepth=3;maxDepth<16;maxDepth++){
      alphaBetaSearch(board,0,-WeightInf,WeightInf);
      Movement ansMovement(ans.fir,board,col);
      debug("ans=[%d %d] : x=%d y=%d value=%d\n",ans.fir,ans.sec,idx(ans.fir),idy(ans.fir),ansMovement.value);
    }
    finishSearch(ans.fir);
  }
}


// main

int main(){
#ifdef memset0
  freopen("testinput.in","r",stdin);
  // Judger::build();
#endif
  log("[bot] start!\n");
  for(int t=rand(0,233);t--;)fakeRng();
  init();

  Board board;
  board.map[0].set(3,3),board.map[0].set(4,4);
  board.map[1].set(3,4),board.map[1].set(4,3);

  int n;
  vec<pair<int,int>> go;  
  cin>>n;
  if(n>16){
    JudgeStatus=2;
  }

  go.resize((n<<1)-1);
  for(int i=0;i<(int)go.size();i++){
    cin>>go[i].fir>>go[i].sec;
  }
  bit col=go.front().fir==-1&&go.front().sec==-1;
  for(int i=0;i<(int)go.size();i++)
    if(~go[i].fir&&~go[i].sec){
      board.move((i&1)^col^1,go[i].fir,go[i].sec);
    }
  log("[bot] color=%d\n",col);

  AlphaBetaSearch::solve(board,col,[&](int movement){
    log("[bot] finished.\n");
    if(~movement){
      cout<<idx(movement)<<" "<<idy(movement)<<endl;
    }else{
      cout<<"-1 -1"<<endl;
    }
  });

  return -1;
}