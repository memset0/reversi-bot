#include<bits/stdc++.h>
typedef unsigned long long u64;

std::string to_string(u64 x){
	std::string plain;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)
			plain+=(x>>(i<<3|j))&1?"*":".";
		plain+="\n";
	}
	return plain;
}

int main(){
	std::cout<<to_string(0x8080808080808080)<<std::endl;
	std::cout<<to_string(0xc0c0c0c0c0c0c0c0)<<std::endl;
	std::cout<<to_string(0xf0f0f0f0f0f0f0f0)<<std::endl;
	std::cout<<to_string(0x7E7E7E7E7E7E7E7Eu)<<std::endl;
}