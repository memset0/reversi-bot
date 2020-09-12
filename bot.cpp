#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) (x).begin(),(x).end()

using namespace std;
using bit=bool;
using u64=unsigned long long;

// Tools: Debug
#define log(...) fprintf(stderr,__VA_ARGS__)

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
};

// Class: Map
struct Map{
	u64 a;
	inline bit get(int k){return in(k,a);}
	inline void set(int k){a|=1ull<<k;}
	inline void flip(int k){a^=1ull<<k;}
	inline void reset(int k){a&=-1ull^(1ull<<k);}
	inline void paint(int k,int x){x?this->set(k):this->reset(k);}
	inline bit get(int i,int j){return in(id(i,j),a);}
	inline void set(int i,int j){a|=1ull<<id(i,j);}
	inline void flip(int i,int j){a^=1ull<<id(i,j);}
	inline void reset(int i,int j){a&=-1ull^(1ull<<id(i,j));}
	inline void paint(int i,int j,int x){x?this->set(i,j):this->reset(i,j);}
};

// Class: Board
struct Board{
	Map map[2];
	void reverse(){swap(map[0],map[1]);}
	inline vec<int> getMoves(bit);
	inline void move(bit,int);
	inline void move(bit,int,int);
	inline string to_string(){
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
	inline void output(){log("%s",this->to_string().c_str());}
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
inline vec<int> Board::getMoves(bit c){
	log("Board::getMoves(%d)\n",c);
	this->output();
	vec<int> res;
	// for(int i=0;i<64;i++)log("%d %d\n",map[c].get(i),map[c^1].get(i));
	for(int i=0;i<64;i++)
		if(!map[c].get(i)&&!map[c^1].get(i)){
			// log("check %d\n",i);
			bit fl=0;
			for(int w=0;w<8&&!fl;w++)
				if(walk[i][w].size()&&map[c^1].get(walk[i][w].front())){
					for(int j:walk[i][w]){
						if(map[c].get(j)){fl=1; break;}
						if(!map[c^1].get(j))break;
					}
				}
			// log("  -> %d\n",fl);
			if(fl)res.push_back(i);
		}
	return res;
}

// Function: play a movement
inline void Board::move(bit c,int i,int j){this->move(c,id(i,j));}
inline void Board::move(bit c,int u){
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
	log("Board::move(%d,%d)\n",idx(u),idy(u));
	this->output();
}

// main
Board board;
bit col;

int main(){
#ifdef memset0
	freopen("testinput.in","r",stdin);
#endif
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
	vec<int> moves=board.getMoves(col);
	if(moves.size()){
		int choosed=moves.random_item();
		for(int move:moves)log(">> %d %d\n",idx(move),idy(move));
		printf("%d %d\n",idx(choosed),idy(choosed));
	}else{
		printf("-1 -1\n");
	}
	return fflush(stdout),0;
}