#include<algorithm>
#include<cstdio>
#include<chrono>
#include<functional>
#include<iostream>
#include<random>
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

// Tools: Debug
#ifdef memset0
  #define log(...) fprintf(stderr,__VA_ARGS__)
#else
  #define log(...) void(0)
#endif

// Tools: rng
mt19937 rng(20040725^chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline T rand(T l,T r){return uniform_int_distribution<T>(l,r)(rng);}

// Tools: Bit Operation
#define id(i,j) (((i)<<3)|(j))
#define idx(v) ((v)>>3)
#define idy(v) ((v)&7)
#define popcnt __builtin_popcountll
#define in(i,k) (((k)>>(i))&1)
#define subset(x,y) (((x)&(y))==(x))

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
};

// Class: Map
struct Map{
  u64 a;

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

  inline u64 source()const{return a;}

  Map():a(0ull){}
};

// Class: Board
struct Board{
  Map map[2];

  inline vec<int> getMoves(bit)const;
  inline bit checkMove(bit,int)const;
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

// Class: Movement
struct Movement{
  int move,value;

  inline int judge(Board,bit);

  inline bool operator<(const Movement &rhs)const{return value<rhs.value;}
  inline bool operator==(const Movement &rhs)const{return value==rhs.value;}

  Movement(int move):move(move){}
  Movement(int move,int value):move(move),value(value){}
  Movement(int move,Board board,bit col):move(move){board.move(col,move),judge(board,col);}
};

// Function: init
const int nxt[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
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
inline vec<int> Board::getMoves(bit c)const{
  // log("Board::getMoves(%d)\n",c);
  // this->output();
  vec<int> res;
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
      if(fl)res.push_back(i);
    }
  return res;
}
inline bit Board::checkMove(bit c,int now)const{
  vec<int> moves=this->getMoves(c);
  if(!moves.size()){
    return now==-1;
  }else{
    return moves.includes(now);
  }
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
        u64 path=walkpath[u][w][t];
        this->map[c].a^=path;
        this->map[c^1].a^=path;
        break;
      }
      if(!this->map[c^1].get(v))break;
    }
  // log("Board::move(%d,%d)\n",idx(u),idy(u));
  // this->output();
}

// Function: Judge
const int mapWeightTable[8][8]={
  {1000,-25,10,5,5,10,-25,1000},
  {-25,-50,1,1,1,1,-50,-25},
  {10,1,3,2,2,3,1,10},
  {5,1,2,1,1,2,1,5},
  {5,1,2,1,1,2,1,5},
  {10,1,3,2,2,3,1,10},
  {-25,-50,1,1,1,1,-50,-25},
  {1000,-25,10,5,5,10,-25,1000}
};
int judgeByMapWeight(const Board &board,bit c){
  int res=0;
  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      if(board.map[c].get(i,j)){
        res+=mapWeightTable[i][j];
      }else if(board.map[c^1].get(i,j)){
        res-=mapWeightTable[i][j];
      }
  return res;
}
int judge(const Board &board,bit c){
  int res=0;
  res+=judgeByMapWeight(board,c)*100;
  return res;
}

inline int Board::judge(bit col)const{
  return ::judge(*this,col);
}
inline int Movement::judge(Board board,bit col){
  board.move(col,this->move);
  return this->value=::judge(board,col);
}

// Function: Alpha-Beta Search
namespace AlphaBetaSearch{
  const int DepthLimit=50;
  const int WeightInf=1e9;
  Board board;
  bit col;
  int maxDepth;
  u32 tickCounter;
  function<void(int)> callback;

  pair<int,int> ans;
  vec<int> stack[DepthLimit];

  int bruteForce(){
    vec<Movement> moves=board.getMoves(col).map((function<Movement(int)>)[&](int move){
      return Movement(move,board,col);
    });
    if(!moves.size()){
      return -1;
    }else{
      sort(all(moves));
      return moves.back().move;
    }
  }

  void finishSearch(int ans){
    if(board.checkMove(col,ans)){
      callback(ans);
    }else{
      callback(bruteForce());
    }
    exit(0);
  }

  int alphaBetaSearch(const Board &board,int step,int alpha,int beta){
    bit mycol=col^(step&1);
    if((++tickCounter&1023)==0&&1.0*clock()/CLOCKS_PER_SEC>0.95){
      return finishSearch(ans.fir),0;
    }
    if(step>maxDepth){
      return judge(board,mycol);
    }

    pair<int,int> best(-1,-WeightInf);
    vec<pair<Movement,Board>> data=board.getMoves(mycol)
      .map((function<pair<Movement,Board>(int)>)[&](int move){
        Board nextBoard=board;
        nextBoard.move(mycol,move);
        int value=nextBoard.judge(mycol);
        return make_pair(Movement(move,value),nextBoard);
      });
    sort(all(data),[](const auto &a,const auto &b){
      return a.fir.value>b.fir.value;
    });
    stack[step]=data
      .map((function<int(pair<Movement,Board>)>)[&](const pair<Movement,Board> &data){
        return data.fir.move;
      });

    bool havePossibleMove=false;
    for(const auto &it:data){
      const Board &next=it.sec;
      int val;
      if(havePossibleMove){
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
        best=make_pair(it.fir.move,val);
      }
    }
    if(data.empty()){
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

    if(!board.getMoves(col).size()){
      log("[alpha-beta] no moves at all!");
      return finishSearch(-1);
    }

    ans=make_pair(-1,-WeightInf);
    for(maxDepth=2;maxDepth<DepthLimit;maxDepth++){
      alphaBetaSearch(board,0,-WeightInf,WeightInf);
      Movement ansMovement(ans.fir,board,col);
      log("ans=[%d %d] : x=%d y=%d value=%d\n",ans.fir,ans.sec,idx(ans.fir),idy(ans.fir),ansMovement.value);
    }

    finishSearch(ans.fir);
  }
}

// main

int main(){
#ifdef memset0
  freopen("testinput.in","r",stdin);
#endif
  Board board;
  bit col=0;
  init();
  board.map[0].set(3,3),board.map[0].set(4,4);
  board.map[1].set(3,4),board.map[1].set(4,3);

  int n;
  vec<pair<int,int>> go;  
  cin>>n;
  go.resize((n<<1)-1);
  for(int i=0;i<(int)go.size();i++){
    cin>>go[i].fir>>go[i].sec;
    if(!i)col=go.front().fir==-1&&go.front().sec==-1;
    if(~go[i].fir&&~go[i].sec){
      board.move((i&1)^col^1,go[i].fir,go[i].sec);
    }
  }
  log("color=%d\n",col);
  AlphaBetaSearch::solve(board,col,[&](int movement){
    log("[bot] `callback` has been called!\n");
    if(~movement){
      cout<<idx(movement)<<" "<<idy(movement)<<endl;
    }else{
      cout<<"-1 -1"<<endl;
    }
  });

  return -1;
}