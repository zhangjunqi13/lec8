#include <string>
#include <sstream>
#include <iomanip
#define NUM 128   //页数目
#define CON 32   //页大小（byte数目）
#define BEGIN 17  //页目录表的物理地址
using namespace std;
short mem[NUM][CON];   //物理内存
void search(short VAddress){   //VAddress为虚地址
	int pde_index = (VAddress >> 10) & 0x1f;   
	int pte_index = (VAddress >> 5) & 0x1f;

	short page_index = mem[BEGIN][pde_index];    //页表所对应的页号
	short thing = mem[page_index][pte_index];    //物理地址所对应的内容

	cout<<thing<<endl;
}

int main(){
	search(6);
	search(45621);

	return 0;
}
