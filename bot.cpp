#include<algorithm>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<chrono>
#include<functional>
#include<iomanip>
#include<iostream>
#include<random>
#include<sstream>
#include<vector>

// #define SimpleIO 1
#ifndef SimpleIO
  #include"jsoncpp/json.h"
  #define JsonIO 1
#endif

#ifdef RUNTIME_PY
  constexpr double TIME_LIMIT=5.96;
#else
  constexpr double TIME_LIMIT=0.96;
#endif

#define fir first
#define sec second
#define all(x) (x).begin(),(x).end()

typedef bool bit;
typedef int i32;
typedef long long i64;
typedef unsigned int u32;
typedef unsigned long long u64;


// Const Value
enum WAY{E,W,S,N,SW,NE,SE,NW};
constexpr int nxt[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};


// auto generated
namespace Judger{
  constexpr u64 corner=0x8100000000000081;
  constexpr u64 possibleMove[8]={0x7F7F7F7F7F7F7F7F,0xFEFEFEFEFEFEFEFE,0x00FFFFFFFFFFFFFF,0xFFFFFFFFFFFFFF00,0x007F7F7F7F7F7F7F,0xFEFEFEFEFEFEFE00,0x00FEFEFEFEFEFEFE,0x7F7F7F7F7F7F7F00};
  constexpr u64 stableEach[64]={0x81412111090503FF,0x02824222120A07FF,0x0404844424150EFF,0x08080888492A1CFF,0x10101011925438FF,0x2020212224A870FF,0x404142444850E0FF,0x8182848890A0C0FF,0x412111090503FF03,0x824222120A07FF07,0x04844424150EFF0E,0x080888492A1CFF1C,0x101011925438FF38,0x20212224A870FF70,0x4142444850E0FFE0,0x82848890A0C0FFC0,0x2111090503FF0305,0x4222120A07FF070A,0x844424150EFF0E15,0x0888492A1CFF1C2A,0x1011925438FF3854,0x212224A870FF70A8,0x42444850E0FFE050,0x848890A0C0FFC0A0,0x11090503FF030509,0x22120A07FF070A12,0x4424150EFF0E1524,0x88492A1CFF1C2A49,0x11925438FF385492,0x2224A870FF70A824,0x444850E0FFE05048,0x8890A0C0FFC0A090,0x090503FF03050911,0x120A07FF070A1222,0x24150EFF0E152444,0x492A1CFF1C2A4988,0x925438FF38549211,0x24A870FF70A82422,0x4850E0FFE0504844,0x90A0C0FFC0A09088,0x0503FF0305091121,0x0A07FF070A122242,0x150EFF0E15244484,0x2A1CFF1C2A498808,0x5438FF3854921110,0xA870FF70A8242221,0x50E0FFE050484442,0xA0C0FFC0A0908884,0x03FF030509112141,0x07FF070A12224282,0x0EFF0E1524448404,0x1CFF1C2A49880808,0x38FF385492111010,0x70FF70A824222120,0xE0FFE05048444241,0xC0FFC0A090888482,0xFF03050911214181,0xFF070A1222428202,0xFF0E152444840404,0xFF1C2A4988080808,0xFF38549211101010,0xFF70A82422212020,0xFFE0504844424140,0xFFC0A09088848281};
  constexpr u64 stableSide[64][4]={{0x0000000000000001,0x00000000000000FF,0x0101010101010101,0xFFFFFFFFFFFFFFFF},{0x0000000000000003,0x00000000000000FE,0x0303030303030303,0xFEFEFEFEFEFEFEFE},{0x0000000000000007,0x00000000000000FC,0x0707070707070707,0xFCFCFCFCFCFCFCFC},{0x000000000000000F,0x00000000000000F8,0x0F0F0F0F0F0F0F0F,0xF8F8F8F8F8F8F8F8},{0x000000000000001F,0x00000000000000F0,0x1F1F1F1F1F1F1F1F,0xF0F0F0F0F0F0F0F0},{0x000000000000003F,0x00000000000000E0,0x3F3F3F3F3F3F3F3F,0xE0E0E0E0E0E0E0E0},{0x000000000000007F,0x00000000000000C0,0x7F7F7F7F7F7F7F7F,0xC0C0C0C0C0C0C0C0},{0x00000000000000FF,0x0000000000000080,0xFFFFFFFFFFFFFFFF,0x8080808080808080},{0x0000000000000101,0x000000000000FFFF,0x0101010101010100,0xFFFFFFFFFFFFFF00},{0x0000000000000303,0x000000000000FEFE,0x0303030303030300,0xFEFEFEFEFEFEFE00},{0x0000000000000707,0x000000000000FCFC,0x0707070707070700,0xFCFCFCFCFCFCFC00},{0x0000000000000F0F,0x000000000000F8F8,0x0F0F0F0F0F0F0F00,0xF8F8F8F8F8F8F800},{0x0000000000001F1F,0x000000000000F0F0,0x1F1F1F1F1F1F1F00,0xF0F0F0F0F0F0F000},{0x0000000000003F3F,0x000000000000E0E0,0x3F3F3F3F3F3F3F00,0xE0E0E0E0E0E0E000},{0x0000000000007F7F,0x000000000000C0C0,0x7F7F7F7F7F7F7F00,0xC0C0C0C0C0C0C000},{0x000000000000FFFF,0x0000000000008080,0xFFFFFFFFFFFFFF00,0x8080808080808000},{0x0000000000010101,0x0000000000FFFFFF,0x0101010101010000,0xFFFFFFFFFFFF0000},{0x0000000000030303,0x0000000000FEFEFE,0x0303030303030000,0xFEFEFEFEFEFE0000},{0x0000000000070707,0x0000000000FCFCFC,0x0707070707070000,0xFCFCFCFCFCFC0000},{0x00000000000F0F0F,0x0000000000F8F8F8,0x0F0F0F0F0F0F0000,0xF8F8F8F8F8F80000},{0x00000000001F1F1F,0x0000000000F0F0F0,0x1F1F1F1F1F1F0000,0xF0F0F0F0F0F00000},{0x00000000003F3F3F,0x0000000000E0E0E0,0x3F3F3F3F3F3F0000,0xE0E0E0E0E0E00000},{0x00000000007F7F7F,0x0000000000C0C0C0,0x7F7F7F7F7F7F0000,0xC0C0C0C0C0C00000},{0x0000000000FFFFFF,0x0000000000808080,0xFFFFFFFFFFFF0000,0x8080808080800000},{0x0000000001010101,0x00000000FFFFFFFF,0x0101010101000000,0xFFFFFFFFFF000000},{0x0000000003030303,0x00000000FEFEFEFE,0x0303030303000000,0xFEFEFEFEFE000000},{0x0000000007070707,0x00000000FCFCFCFC,0x0707070707000000,0xFCFCFCFCFC000000},{0x000000000F0F0F0F,0x00000000F8F8F8F8,0x0F0F0F0F0F000000,0xF8F8F8F8F8000000},{0x000000001F1F1F1F,0x00000000F0F0F0F0,0x1F1F1F1F1F000000,0xF0F0F0F0F0000000},{0x000000003F3F3F3F,0x00000000E0E0E0E0,0x3F3F3F3F3F000000,0xE0E0E0E0E0000000},{0x000000007F7F7F7F,0x00000000C0C0C0C0,0x7F7F7F7F7F000000,0xC0C0C0C0C0000000},{0x00000000FFFFFFFF,0x0000000080808080,0xFFFFFFFFFF000000,0x8080808080000000},{0x0000000101010101,0x000000FFFFFFFFFF,0x0101010100000000,0xFFFFFFFF00000000},{0x0000000303030303,0x000000FEFEFEFEFE,0x0303030300000000,0xFEFEFEFE00000000},{0x0000000707070707,0x000000FCFCFCFCFC,0x0707070700000000,0xFCFCFCFC00000000},{0x0000000F0F0F0F0F,0x000000F8F8F8F8F8,0x0F0F0F0F00000000,0xF8F8F8F800000000},{0x0000001F1F1F1F1F,0x000000F0F0F0F0F0,0x1F1F1F1F00000000,0xF0F0F0F000000000},{0x0000003F3F3F3F3F,0x000000E0E0E0E0E0,0x3F3F3F3F00000000,0xE0E0E0E000000000},{0x0000007F7F7F7F7F,0x000000C0C0C0C0C0,0x7F7F7F7F00000000,0xC0C0C0C000000000},{0x000000FFFFFFFFFF,0x0000008080808080,0xFFFFFFFF00000000,0x8080808000000000},{0x0000010101010101,0x0000FFFFFFFFFFFF,0x0101010000000000,0xFFFFFF0000000000},{0x0000030303030303,0x0000FEFEFEFEFEFE,0x0303030000000000,0xFEFEFE0000000000},{0x0000070707070707,0x0000FCFCFCFCFCFC,0x0707070000000000,0xFCFCFC0000000000},{0x00000F0F0F0F0F0F,0x0000F8F8F8F8F8F8,0x0F0F0F0000000000,0xF8F8F80000000000},{0x00001F1F1F1F1F1F,0x0000F0F0F0F0F0F0,0x1F1F1F0000000000,0xF0F0F00000000000},{0x00003F3F3F3F3F3F,0x0000E0E0E0E0E0E0,0x3F3F3F0000000000,0xE0E0E00000000000},{0x00007F7F7F7F7F7F,0x0000C0C0C0C0C0C0,0x7F7F7F0000000000,0xC0C0C00000000000},{0x0000FFFFFFFFFFFF,0x0000808080808080,0xFFFFFF0000000000,0x8080800000000000},{0x0001010101010101,0x00FFFFFFFFFFFFFF,0x0101000000000000,0xFFFF000000000000},{0x0003030303030303,0x00FEFEFEFEFEFEFE,0x0303000000000000,0xFEFE000000000000},{0x0007070707070707,0x00FCFCFCFCFCFCFC,0x0707000000000000,0xFCFC000000000000},{0x000F0F0F0F0F0F0F,0x00F8F8F8F8F8F8F8,0x0F0F000000000000,0xF8F8000000000000},{0x001F1F1F1F1F1F1F,0x00F0F0F0F0F0F0F0,0x1F1F000000000000,0xF0F0000000000000},{0x003F3F3F3F3F3F3F,0x00E0E0E0E0E0E0E0,0x3F3F000000000000,0xE0E0000000000000},{0x007F7F7F7F7F7F7F,0x00C0C0C0C0C0C0C0,0x7F7F000000000000,0xC0C0000000000000},{0x00FFFFFFFFFFFFFF,0x0080808080808080,0xFFFF000000000000,0x8080000000000000},{0x0101010101010101,0xFFFFFFFFFFFFFFFF,0x0100000000000000,0xFF00000000000000},{0x0303030303030303,0xFEFEFEFEFEFEFEFE,0x0300000000000000,0xFE00000000000000},{0x0707070707070707,0xFCFCFCFCFCFCFCFC,0x0700000000000000,0xFC00000000000000},{0x0F0F0F0F0F0F0F0F,0xF8F8F8F8F8F8F8F8,0x0F00000000000000,0xF800000000000000},{0x1F1F1F1F1F1F1F1F,0xF0F0F0F0F0F0F0F0,0x1F00000000000000,0xF000000000000000},{0x3F3F3F3F3F3F3F3F,0xE0E0E0E0E0E0E0E0,0x3F00000000000000,0xE000000000000000},{0x7F7F7F7F7F7F7F7F,0xC0C0C0C0C0C0C0C0,0x7F00000000000000,0xC000000000000000},{0xFFFFFFFFFFFFFFFF,0x8080808080808080,0xFF00000000000000,0x8000000000000000}};
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
std::mt19937 rng(20040725^std::chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline T rand(T l,T r){return std::uniform_int_distribution<T>(l,r)(rng);}
inline u32 fakeRng(){
  static u32 seed=416;
  return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}


// Tools: Helper Libs
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::function;

template<class T> struct vector:std::vector<T>{
  using std::vector<T>::vector;
  
  inline vector<T> slice(int l,int r)const{return vector(this->begin()+l,this->begin()+r);}
  inline vector<T> concat(const vector<T> &rhs){this->insert(this->end(),rhs.begin(),rhs.end());}
  inline T random_item(){return this->operator[](rand(0,(int)this->size()-1));}
  inline bit includes(const T &x){return find(this->begin(),this->end(),x)!=this->end();}

  inline void forEach(const function<void(T)> &func){
    for(const auto &it:*this)func(it);
  }
  template<class TT> inline vector<TT> map(const function<TT(T)> &func)const{
    vector<TT> res;
    for(const auto &it:*this)res.push_back(func(it));
    return res;
  }

  inline static vector<int> from(u64 sta){
    vector<int> res;
    for(int i=0;i<64;i++)if((sta>>i)&1)res.push_back(i);
    return res;
  }
};

struct string:std::string{
  using std::string::string;
  string(const std::string &plain):std::string(plain){}

  inline string join(const vector<string> &vet)const{
    if(!vet.size())return "";
    string res=vet[0];
    for(int i=1;i<(int)vet.size();i++){
      res+=*this;
      res+=vet[i];
    }
    return res;
  }
  template<class T> inline string join(const vector<T> &vet)const{
    return this->join(vet.map((function<string(T)>)[](const T &x){return std::to_string(x);}));
  }
  template<class T> inline string join(const vector<T> &vet,function<string(T)> custom_to_string)const{
    return this->join(vet.map((function<string(T)>)[&](const T &x){return custom_to_string(x);}));
  }

  vector<string> split(const string &delim){
    if(this->empty())return {};
    cerr<<"split"<<delim<<endl;
    char *src=new char[this->length()+1];
    strcpy(src,this->c_str()); 
    char *tar=new char[delim.length()+1];
    strcpy(tar,delim.c_str());
    cerr<<"split"<<delim<<endl;
    vector<string> res;
    char *pos=strtok(src,tar);
    while(pos){
      res.push_back(string(pos));
      pos=strtok(nullptr,tar);
    }
    delete[] src;
    delete[] tar;
    return res;
  }

  template<class... Args> static string sprintf(const char* format,Args... args){
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
};

template<class T> string to_string(const vector<T> &v){
  return "{"+string(",").join(v)+"}";
}
template<class T> string to_string(const vector<T> &v,function<string(T)> custom_to_string){
  return "{"+string(",").join(v,custom_to_string)+"}";
}

template<class... Args> string string_sprintf(const char* format,Args... args){
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


// Tools: data & globaldata
struct Data{
  bool enabled;
  size_t limit;
  string name,plain;

  Data(string name,size_t limit):limit(limit),name(name){
    enabled=false;
  }
  inline void parse(const string &source){
    enabled=true;
    this->plain=source;
  }
  inline string toString(){
    if(!enabled)return "";
    return this->plain;
  }

  inline void print(const string &data){
    if(!enabled)return;
    plain=data+plain;
    if(plain.length()>limit){
      plain.erase(plain.begin()+limit,plain.end());
    }
    if(this->name=="globaldata"){
      log("\e[2m[%s]\e[0m %s",this->name.c_str(),data.c_str());
    }
  }
  template<class... Args> inline void printf(const char *format,Args... args){
    if(!enabled)return;
    this->print(string_sprintf(format,args...));
  }
};
Data data("data",100);
Data globaldata("globaldata",10000);


// Tools: Bit Operation
#define id(i,j) (((i)<<3)|(j))
#define idx(v) ((v)>>3)
#define idy(v) ((v)&7)
#define popcnt(v) __builtin_popcountll(v)
#define in(i,k) (((k)>>(i))&1)
#define subset(x,y) (((x)&(y))==(x))

inline string u64ToHex(u64 value){
  return string_sprintf("0x%08X%08X",value>>32,value&(-1u));
}
inline vector<int> u64ToVec(u64 source){
  vector<int> target;
  for(int i=0;i<64;i++)if((source>>i)&1)target.push_back(i);
  return target;
}


// Class: Map
struct Map{
  u64 plain;

  inline int count()const{return popcnt(plain);}
  inline int intersection(u64 rhs)const{return popcnt(plain&rhs);}

  inline void set(){plain=-1ull;}
  inline void reset(){plain=0;}
  inline void flip(){plain^=1ull;}

  inline bit get(int k)const{return in(k,plain);}
  inline void set(int k){plain|=1ull<<k;}
  inline void flip(int k){plain^=1ull<<k;}
  inline void reset(int k){plain&=-1ull^(1ull<<k);}
  inline void paint(int k,int x){x?this->set(k):this->reset(k);}

  inline bit get(int i,int j)const{return in(id(i,j),plain);}
  inline void set(int i,int j){plain|=1ull<<id(i,j);}
  inline void flip(int i,int j){plain^=1ull<<id(i,j);}
  inline void reset(int i,int j){plain&=-1ull^(1ull<<id(i,j));}
  inline void paint(int i,int j,int x){x?this->set(i,j):this->reset(i,j);}

  inline string to_string()const{
    string plain;
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++)
        plain+=get(i,j)?"*":".";
      plain+="\n";
    }
    return plain;
  }

  Map():plain(0ull){}
  Map(u64 plain):plain(plain){}
};


// Class: Board
struct Board{
  Map map[2];

  template<const bit c> inline u64 getMove()const;
  template<const bit c> inline u64 getMoveOld()const;
  template<const bit c> inline int getMoveSize()const;
  template<const bit c> inline bit checkMove(int)const;

  template<const bit c> inline u64 getStable()const;
  template<const bit c> inline u64 getStableOld()const;
  template<const bit c> inline int getStableSize()const;

  template<const bit c> inline u64 getFront()const;
  template<const bit c> inline int getFrontSize()const;

  template<const bit c> inline void move(int);
  template<const bit c> inline void move(int,int);

  template<const bit c> inline int judge()const;
  template<const bit c> inline int judgeSide(int)const;
  template<const bit c> inline int judgeFinal()const;

  inline void reverse(){std::swap(this->map[0],this->map[1]);}
  inline u64 rest()const{return -1ull^this->map[0].plain^this->map[1].plain;}

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
    log("===board %llu %llu===\n",map[0].plain,map[1].plain);
    log("%s",this->to_string().c_str());
#else
    log("[logger] Outputting a `Board` is disabled!");
#endif
  }
};


// Class: Movement
struct Movement{
  int move,value;

  inline bool operator<(const Movement &rhs)const{return value<rhs.value;}
  inline bool operator==(const Movement &rhs)const{return value==rhs.value;}

  Movement(int move,int value):move(move),value(value){}
  Movement(int move,Board board,bit col):move(move){
    if(col){
      board.move<1>(move);
      value=board.judge<1>();
    }else{
      board.move<0>(move);
      value=board.judge<0>();
    }
  }
};


// Function: init
namespace Judger{
  struct MagicNumber{
    string name,type,plain;
    inline MagicNumber(string base,u64 value):type("u64"){
      name=base;
      plain=u64ToHex(value);
    }
    inline MagicNumber(string base,vector<u64> value):type("u64"){
      name=base+string_sprintf("[%lu]",value.size());
      plain=to_string(value,(function<string(u64)>)[](u64 x){return u64ToHex(x);});
    }
    inline MagicNumber(string base,vector<vector<u64>> value):type("u64"){
      name=base+string_sprintf("[%lu][%lu]",value.size(),value[0].size());
      plain=to_string(value,(function<string(vector<u64>)>)[](const vector<u64> &x){
        return to_string(x,(function<string(u64)>)[](u64 x){return u64ToHex(x);});
      });
    }
  };
  string to_string(const MagicNumber &x){
    return "constexpr "+x.type+" "+x.name+"="+x.plain+";";
  }

  vector<MagicNumber> out;
  void build(){
    auto buildMap=[](const std::initializer_list<std::pair<int,int>> &source){
      u64 target=0;
      for(const auto &pr:source){
        target|=1ull<<id(pr.fir,pr.sec);
      }
      return target;
    };
    out.push_back(MagicNumber("corner",buildMap({{0,0},{0,7},{7,0},{7,7}})));
    out.push_back(MagicNumber("x_squares",buildMap({{1,1},{1,6},{6,1},{6,6}})));
    out.push_back(MagicNumber("c_squares",buildMap({{0,1},{1,0},{1,7},{0,6},{7,1},{6,0},{7,6},{6,7}})));
    auto possibleMove=vector<u64>(8);
    for(int w=0;w<8;w++){
      for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
          int ti=i+nxt[w][0],tj=j+nxt[w][1];
          if(ti<0||tj<0||ti>=8||tj>=8)continue;
          possibleMove[w]|=1ull<<id(i,j);
        }
    }
    out.push_back(MagicNumber("possibleMove",possibleMove));
    auto stableEach=vector<u64>(64);
    auto stableSide=vector<vector<u64>>(64);
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
        stableEach[id(x,y)]=now.plain,now.reset();
        for(int i=0;i<=x;i++)
          for(int j=0;j<=y;j++)
            now.set(i,j);
        stableSide[id(x,y)].push_back(now.plain),now.reset();
        for(int i=0;i<=x;i++)
          for(int j=y;j<8;j++)
            now.set(i,j);
        stableSide[id(x,y)].push_back(now.plain),now.reset();
        for(int i=x;i<8;i++)
          for(int j=0;j<=y;j++)
            now.set(i,j);
        stableSide[id(x,y)].push_back(now.plain),now.reset();
        for(int i=x;i<8;i++)
          for(int j=y;j<8;j++)
            now.set(i,j);
        stableSide[id(x,y)].push_back(now.plain),now.reset();
      }
    out.push_back(MagicNumber("stableEach",stableEach));
    out.push_back(MagicNumber("stableSide",stableSide));
    for(const auto &num:out)log("%s\n",to_string(num).c_str());
  }
}

vector<int> walk[64][8];
vector<u64> walkpath[64][8];
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
template<const bit c> inline u64 Board::getMoveOld()const{
  u64 res=0;
  for(int i=0;i<64;i++)
    if(!map[c].get(i)&&!map[!c].get(i)){
      bit fl=0;
      for(int w=0;w<8&&!fl;w++)
        if(walk[i][w].size()&&map[!c].get(walk[i][w].front())){
          for(int j:walk[i][w]){
            if(map[c].get(j)){fl=1; break;}
            if(!map[!c].get(j))break;
          }
        }
      if(fl)res|=1ull<<i;
    }
  return res;
}
template<const bit c> inline u64 Board::getMove()const{
  const u64 &board_u=this->map[c].plain;
  const u64 &board_v=this->map[!c].plain;
  u64 moves,board_v_inner,board_flip,board_v_adj;
  board_v_inner=board_v&(u64)0x7E7E7E7E7E7E7E7E;
  //E
  board_flip=(board_u>>1)&board_v_inner;
  board_flip|=(board_flip>>1)&board_v_inner;
  board_v_adj=board_v_inner&(board_v_inner>>1);
  board_flip|=(board_flip>>2)&board_v_adj;
  board_flip|=(board_flip>>2)&board_v_adj;
  moves=board_flip>>1;
  //W
  board_flip=(board_u<<1)&board_v_inner;
  board_flip|=(board_flip<<1)&board_v_inner;
  board_v_adj=board_v_inner&(board_v_inner<<1);
  board_flip|=(board_flip<<2)&board_v_adj;
  board_flip|=(board_flip<<2)&board_v_adj;
  moves|=board_flip<<1;
  //S
  board_flip=(board_u>>8)&board_v;
  board_flip|=(board_flip>>8)&board_v;
  board_v_adj=board_v&(board_v>>8);
  board_flip|=(board_flip>>16)&board_v_adj;
  board_flip|=(board_flip>>16)&board_v_adj;
  moves|=board_flip>>8;
  //N
  board_flip=(board_u<<8)&board_v;
  board_flip|=(board_flip<<8)&board_v;
  board_v_adj=board_v&(board_v<<8);
  board_flip|=(board_flip<<16)&board_v_adj;
  board_flip|=(board_flip<<16)&board_v_adj;
  moves|=board_flip<<8;
  //SW
  board_flip=(board_u>>7)&board_v_inner;
  board_flip|=(board_flip>>7)&board_v_inner;
  board_v_adj=board_v_inner&(board_v_inner>>7);
  board_flip|=(board_flip>>14)&board_v_adj;
  board_flip|=(board_flip>>14)&board_v_adj;
  moves|=board_flip>>7;
  //NE
  board_flip=(board_u<<7)&board_v_inner;
  board_flip|=(board_flip<<7)&board_v_inner;
  board_v_adj=board_v_inner&(board_v_inner<<7);
  board_flip|=(board_flip<<14)&board_v_adj;
  board_flip|=(board_flip<<14)&board_v_adj;
  moves|=board_flip<<7;
  //SE
  board_flip=(board_u>>9)&board_v_inner;
  board_flip|=(board_flip>>9)&board_v_inner;
  board_v_adj=board_v_inner&(board_v_inner>>9);
  board_flip|=(board_flip>>18)&board_v_adj;
  board_flip|=(board_flip>>18)&board_v_adj;
  moves|=board_flip>>9;
  //NW
  board_flip=(board_u<<9)&board_v_inner;
  board_flip|=(board_flip<<9)&board_v_inner;
  board_v_adj=board_v_inner&(board_v_inner<<9);
  board_flip|=(board_flip<<18)&board_v_adj;
  board_flip|=(board_flip<<18)&board_v_adj;
  moves|=board_flip<<9;
  moves&=~(board_u|board_v);
  // assert(moves==this->getMoveOld<c>());
  return moves;
}
template<const bit c> inline int Board::getMoveSize()const{
  return popcnt(this->getMove<c>());
}
template<const bit c> inline bit Board::checkMove(int now)const{
  u64 moves=this->getMove<c>();
  if(!moves){
    return now==-1;
  }else{
    return (moves>>now)&1;
  }
}


// Function: get stable chess
template<const bit c> inline u64 Board::getStableOld()const{
  u64 res=0;
  for(int i=0;i<64;i++)
    if(subset(Judger::stableEach[i],(this->map[0].plain|this->map[1].plain))|| 
       subset(Judger::stableSide[i][0],this->map[c].plain)||
       subset(Judger::stableSide[i][1],this->map[c].plain)||
       subset(Judger::stableSide[i][2],this->map[c].plain)||
       subset(Judger::stableSide[i][3],this->map[c].plain)){  
      res|=1ull<<i;
    }
  return res;
}
template<const bit c> inline u64 Board::getStable()const{
  u64 stable=-1ull;
  u64 moveSideA,moveSideB;
#define evalutionStable(step,key0,key1,key2,key3,key4,key5) \
      moveSideA=this->map[c].plain,                         \
      moveSideA&=(moveSideA>>(step))|key0,                  \
      moveSideA&=(moveSideA>>(step<<1))|key1,               \
      moveSideA&=(moveSideA>>(step<<2))|key2,               \
      moveSideB=this->map[c].plain,                         \
      moveSideB&=(moveSideB<<(step))|key3,                  \
      moveSideB&=(moveSideB<<(step<<1))|key4,               \
      moveSideB&=(moveSideB<<(step<<2))|key5,               \
      stable&=moveSideA|moveSideB
  evalutionStable(1,0x8080808080808080,0xC0C0C0C0C0C0C0C0,0xF0F0F0F0F0F0F0F0,0x0101010101010101,0x0303030303030303,0x0F0F0F0F0F0F0F0F);
  evalutionStable(8,0xFF00000000000000,0xFFFF000000000000,0xFFFFFFFF00000000,0x00000000000000FF,0x000000000000FFFF,0x00000000FFFFFFFF);
  evalutionStable(7,0xFF01010101010101,0xFFFF030303030303,0xFFFFFFFF0F0F0F0F,0x80808080808080FF,0xC0C0C0C0C0C0FFFF,0xF0F0F0F0FFFFFFFF);
  evalutionStable(9,0xFF80808080808080,0xFFFFC0C0C0C0C0C0,0xFFFFFFFFF0F0F0F0,0x01010101010101FF,0x030303030303FFFF,0x0F0F0F0FFFFFFFFF);
#undef evalutionStable
  return stable;
}
template<const bit c> inline int Board::getStableSize()const{
  return popcnt(this->getStable<c>());
}


// Function: get chess in front
template<const bit c> inline u64 Board::getFront()const{
  u64 self=this->map[c].plain;
  u64 rest=this->rest();
  u64 front=0;
  front|=self&((rest&Judger::possibleMove[E])>>1);
  front|=self&((rest&Judger::possibleMove[W])<<1);
  front|=self&((rest)>>8);
  front|=self&((rest)<<8);
  front|=self&((rest&Judger::possibleMove[SW])>>7);
  front|=self&((rest&Judger::possibleMove[NE])<<7);
  front|=self&((rest&Judger::possibleMove[SE])>>9);
  front|=self&((rest&Judger::possibleMove[NW])<<9);
  return front;
}
template<const bit c> inline int Board::getFrontSize()const{
  return popcnt(this->getFront<c>());
}


// Function: play a movement
template<const bit c> inline void Board::move(int i,int j){this->move<c>(id(i,j));}
template<const bit c> inline void Board::move(int u){
  if(!~u)return;
  this->map[c].set(u);
#define moveSide(w) \
      for(int t=0;t<(int)walk[u][w].size();t++){ \
        int v=walk[u][w][t]; \
        if(this->map[c].get(v)){ \
          this->map[c].plain^=walkpath[u][w][t]; \
          this->map[!c].plain^=walkpath[u][w][t]; \
          break; \
        } \
        if(!this->map[!c].get(v))break; \
      }
  moveSide(E);
  moveSide(W);
  moveSide(S);
  moveSide(N);
  moveSide(SW);
  moveSide(NE);
  moveSide(SE);
  moveSide(NW);
#undef moveSide
}


// Function: Judge
int JudgeStatus=1;
template<const bit c> inline int Board::judgeSide(int mov)const{
  int res=0;
  int cnt=this->map[c].count();
  if(!cnt)return -20040725;
  Map rest=this->rest();

  //边角定权
  res+=this->map[c].intersection(Judger::corner)*1800;
#define evalutionCorner(thisX,thisY,deltaX,deltaY)               \
      if(rest.get(thisX,thisY)){                                 \
        if(this->map[c].get(thisX+deltaX,thisY))res-=200;        \
        if(this->map[c].get(thisX,thisY+deltaY))res-=200;        \
        if(this->map[c].get(thisX+deltaX,thisY+deltaY))res-=600; \
      }
  evalutionCorner(0,0,1,1);
  evalutionCorner(0,7,1,-1);
  evalutionCorner(7,0,-1,1);
  evalutionCorner(7,7,-1,-1);
#undef evalutionCorner

  //行动力
  res+=mov*30;
  switch(mov){
    case 0:res-=1000;break;
    case 1:res-=300;break;
    case 2:res-=100;break;
  }

  //稳定子
  int sta=this->getStableSize<c>();
  res+=sta*50;
  if(sta>=32)return 20040725;

  //占子策略
  switch(JudgeStatus){
    case 1:
      res-=this->getFrontSize<c>()*20;
      res-=cnt*10;
      break;
    case 2:
      res-=this->getFrontSize<c>()*5;
      res+=cnt*25+sta*25;
      break;
  }
  return res;
}
template<const bit c> inline int Board::judgeFinal()const{
  int cnt[]={this->map[0].count(),this->map[1].count()};
  return cnt[0]==cnt[1]?0:2*(cnt[c]>cnt[!c]?20040725:-20040725);
}
template<const bit c> inline int Board::judge()const{
  int movU=this->getMoveSize<c>();
  int movV=this->getMoveSize<!c>();
  if(!movU&&!movV){
    return this->judgeFinal<c>();
  }
  return this->judgeSide<c>(movU)-this->judgeSide<!c>(movV)+(fakeRng()%5-2);
}


// Main: Alpha-Beta Search
namespace AlphaBetaSearch{
  const int INFW=1e9;
  bit col;
  u32 tick;
  int ans,maxd,stackValue[64][64];
  Board board,stackBoard[64][64];
  function<int(int)> callback;

  int bruteForce(){
    vector<Movement> moves=u64ToVec(col?board.getMove<1>():board.getMove<0>())
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
    vector<int> moves=u64ToVec(col?board.getMove<1>():board.getMove<0>());
    if(!moves.size()){
      return -1;
    }else{
      return moves[rand(0,(int)moves.size()-1)];
    }
  }

  void finishSearch(int movement){
    string debug_message=string().sprintf("maxd=%d\n",maxd);
    log("\e[32m%s\e[0m",debug_message.c_str());
    data.print(debug_message);
    globaldata.print(debug_message);
    if(col?board.checkMove<1>(movement):board.checkMove<0>(movement)){
      exit(callback(movement));
    }else{
      globaldata.printf("[error] Illegal moves!!! (%d,%d)\n",idx(movement),idy(movement));
      exit(callback(rand(0,2)?bruteForce():randomChoose()));
    }
  }

  template<const bit c> int search(const Board &board,int step,int alpha,int beta){
    if(!(++tick&1023)&&clock()/(double)CLOCKS_PER_SEC>TIME_LIMIT){
      return finishSearch(ans),0;
    }
    if(step>maxd){
      return board.judge<c>();
    }

    vector<int> ord;
    int best=-1;
    u64 moves=board.getMove<c>();
    for(int i=0;i<64;i++)if((moves>>i)&1){
      ord.push_back(i);
      stackBoard[step][i]=board;
      stackBoard[step][i].move<c>(i);
      stackValue[step][i]=stackBoard[step][i].judge<c>();
    }
    sort(ord.begin(),ord.end(),[&](int x,int y){
      return stackValue[step][x]>stackValue[step][y];
    });

    bool flagPVS=false; // Principal Variation Search
    for(int i:ord){
      const Board &next=stackBoard[step][i];
      int val;
      if(flagPVS){
        val=-search<!c>(next,step+1,-alpha-1,-alpha);
        if(val>alpha&&val<beta){
          val=-search<!c>(next,step+1,-beta,-alpha);
        }
      }else{
        val=-search<!c>(next,step+1,-beta,-alpha);
      }
      if(val>=beta)return val;
      if(val>alpha){
        alpha=val;
        best=i;
        flagPVS=true;
      }
    }
    if(!moves){
      int val=-search<!c>(board,step+1,-beta,-alpha);
      if(val>=beta)return val;
      if(val>alpha){
        alpha=val;
        best=-1;
      }
    }

    if(!step)ans=best;
    return alpha;
  }
  int search(bit c,const Board &board,int alpha,int beta){
    if(c){
      return search<1>(board,0,alpha,beta);
    }else{
      return search<0>(board,0,alpha,beta);
    }
  }

  void solve(const Board &_board,bit _col,function<int(int)> _callback){
    board=_board,col=_col,callback=_callback;

    if(!(col?board.getMove<1>():board.getMove<0>())){
      log("[alpha-beta] no moves at all!");
      return finishSearch(-1);
    }
    // if(board.map[col].count()<=3&&board.map[col^1].count()<=3){
    //   return finishSearch(randomChoose());
    // }

    ans=-1;
    static constexpr int window=100;
    int val=-1,alpha,beta;
    for(maxd=6;maxd<64;maxd++){
      if(~val){
        alpha=val-window;
        beta=val+window;
        val=search(col,board,alpha,beta);
        if(val<=alpha||val>=beta){
          val=search(col,board,-INFW,INFW);
        }
      }else{
        val=search(col,board,-INFW,INFW);
      }

      Movement ansMovement(ans,board,col);
      string debugMessage(string_sprintf("val=%d mov=%d(%d,%d)\n",val,ans,idx(ans),idy(ans)));
      log("\e[36m%s\e[0m",debugMessage.c_str());
      data.print(debugMessage);
      if(maxd<16){
        globaldata.print(debugMessage);
      }
    }
    finishSearch(ans);
  }
}


// Main: init & IO
int main(){
#ifdef memset0
#ifdef SimpleIO
  freopen("testinput.in","r",stdin);
#endif
#ifdef JsonIO
  freopen("testinput.json","r",stdin);
#endif
  // Judger::build();
#endif
  log("[bot] start!\n");
  for(int t=rand(0,233);t--;)fakeRng();
  init();

  Board board;
  board.map[0].set(3,3),board.map[0].set(4,4);
  board.map[1].set(3,4),board.map[1].set(4,3);

  int n;
  vector<std::pair<int,int>> go;

#ifdef SimpleIO
  cin>>n;
  go.resize((n<<1)-1);
  for(int i=0;i<(int)go.size();i++){
    cin>>go[i].fir>>go[i].sec;
  }
#endif

#ifdef JsonIO
  string str;
  std::getline(cin,str);
  Json::Reader reader;
  Json::Value input;
  reader.parse(str,input);
  n=input["requests"].size();
  for(int i=0;i<n-1;i++){
    go.push_back(std::make_pair(input["requests"][i]["x"].asInt(),input["requests"][i]["y"].asInt()));
    go.push_back(std::make_pair(input["responses"][i]["x"].asInt(),input["responses"][i]["y"].asInt()));
  }
  go.push_back(std::make_pair(input["requests"][n-1]["x"].asInt(),input["requests"][n-1]["y"].asInt()));
  data.parse(input.isMember("data")?input["data"].asString():"");
  globaldata.parse(input.isMember("globaldata")?input["globaldata"].asString():"");
#endif

  globaldata.printf("=== Round: %d ===\n",n);
  if(n>16){
    JudgeStatus=2;
  }
  bit col=go.front().fir==-1&&go.front().sec==-1;

  for(int i=0;i<(int)go.size();i++)
    if(~go[i].fir&&~go[i].sec){
      if((i&1)^col){
        board.move<0>(go[i].fir,go[i].sec);
      }else{
        board.move<1>(go[i].fir,go[i].sec);
      }
    }
  log("[bot] color=%d\n",col);

  AlphaBetaSearch::solve(board,col,[&](int movement){
    debug("[bot] finished. (clock=%.6lf)\n",clock()/(double)CLOCKS_PER_SEC);
    int resultX=~movement?idx(movement):-1;
    int resultY=~movement?idy(movement):-1;

#ifdef SimpleIO
    cout<<resultX<<" "<<resultY<<endl;
#endif

#ifdef JsonIO
    Json::Value ret;
    ret["response"]["x"]=resultX;
    ret["response"]["y"]=resultY;
    ret["data"]=data.toString();
    ret["globaldata"]=globaldata.toString();
    Json::FastWriter writer;
    cout<<writer.write(ret)<<endl;
#endif
    return 0;
  });

  return -1;
}