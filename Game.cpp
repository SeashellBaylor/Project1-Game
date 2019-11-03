#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

const int N=10010;

string s[N]={"###############################################################",
			 "#@#######O### O$###****$****####O*P*O##O*O*O*O*####O####O**O  #",
			 "# ##O####OOO#-#########-########*O*O*#OOO ##### $####P##### #P#",
			 "#    OOO     OOOO O O O O O OPO O O  P  OO O O OOO **** OOOO ##",
			 "###-###########################################################",
			 "#O# #O####  OO  O *$*OOO## # O #********* P*** OOP$  **PO** OO#",
			 "#  OO ####************* *   OOOOOO  **  OPO* *  ###   * PPPO  #",
			 "#  #OOO  O OO**OOO  OOO   # * OOO***#-#-#-#-#-#-#-#-#  #  OOOO#",
			 "#  ##################################-#-#-#-#-#-#-#-###########",
			 "#  OO  ***PPP  OO ####  #PPPPPPP### OOOO  **###P OOO#POOP###OO#",
			 "#    ** O ###OO$####    #-------#   ##OOOOOOO  **** #*O**#P##O#",
			 "# ** OOOOOO   ## ***OOOOO  *   PP   * ####OOO OOO #       POOO#",
			 "#############################################################-#"};//64*13
int x=1,y=1,life=3,key,coin;
int tar1=12,tar2=62;
bool Cam;

inline void build(int xx,int yy,int type) {
	if(type==1) {
		s[xx][yy]=' ';
		s[xx-1][yy]='@';
		return;
	}
	if(type==2) {
		s[xx][yy]=' ';
		s[xx][yy-1]='@';
		return;
	}
	if(type==3) {
		s[xx][yy]=' ';
		s[xx+1][yy]='@';
		return;
	}
	if(type==4) {
		s[xx][yy]=' ';
		s[xx][yy+1]='@';
		return;
	}
}

inline void Klprint(string s) {
	for(register int i=0;i<s.size();i++) cout<<s[i],Sleep(30);
}

int main() {
	system("color 1B");
	while(x<tar1&&y<=tar2) {
		for(register int i=0;i<13;i++) {
			for(register int j=0;j<64;j++) cout<<s[i][j];
			cout<<endl;
		}
		cout<<"Coin:"<<coin<<endl<<"Life:"<<life<<endl<<"Key:"<<key;
		bool flag=true;
		char c=getch();
		if(c=='w') {
			if(s[x-1][y]^'#') {
				if(s[x-1][y]=='*') life--;
				if(s[x-1][y]=='$') key++;
				if(s[x-1][y]=='P') life++;
				if(s[x-1][y]=='O') coin++;
				if(s[x-1][y]=='-') {
					if(key) {
						int uuu=MessageBox(NULL,"你真的要花费一把钥匙打开一扇门吗？请慎重决定！","提示",MB_YESNO);
						if(uuu==6)
							build(x,y,1),key--,x--;
					}
					flag=false;
				}
				if(flag) build(x,y,1),x--;
			}
		}
		if(c=='a') {
			if(s[x][y-1]^'#') {
				if(s[x][y-1]=='*') life--;
				if(s[x][y-1]=='$') key++;
				if(s[x][y-1]=='P') life++;
				if(s[x][y-1]=='O') coin++;
				if(s[x][y-1]=='-') {
					if(key) {
						int uuu=MessageBox(NULL,"你真的要花费一把钥匙打开一扇门吗？请慎重决定！","提示",MB_YESNO);
						if(uuu==6)
							build(x,y,2),key--,y--;
					}
					flag=false;
				}
				if(flag) build(x,y,2),y--;
			}
		}
		if(c=='s') {
			if(s[x+1][y]^'#') {
				if(s[x+1][y]=='*') life--;
				if(s[x+1][y]=='$') key++;
				if(s[x+1][y]=='P') life++;
				if(s[x+1][y]=='O') coin++;
				if(s[x+1][y]=='-') {
					if(key) {
						int uuu=MessageBox(NULL,"你真的要花费一把钥匙打开一扇门吗？请慎重决定！","提示",MB_YESNO);
						if(uuu==6)
							build(x,y,3),key--,x++;
					}
					flag=false;
				}
				if(flag) build(x,y,3),x++;
			}
		}
		if(c=='d') {
			if(s[x][y+1]^'#') {
				if(s[x][y+1]=='*') life--;
				if(s[x][y+1]=='$') key++;
				if(s[x][y+1]=='P') life++;
				if(s[x][y+1]=='O') coin++;
				if(s[x][y+1]=='-') {
					if(key) {
						int uuu=MessageBox(NULL,"你真的要花费一把钥匙打开一扇门吗？请慎重决定！","提示",MB_YESNO);
						if(uuu==6)
							build(x,y,4),key--,y++;
					}
					flag=false;
				}
				if(flag) build(x,y,4),y++;
			}
		}
		if(c==27) Sleep(100),system("cls"),exit(0);
		system("cls");
		if(life==0) {
			Cam=true;
			break;
		}
	}
	if(Cam==true) {
		Klprint("Sorry, you lose the game!");
		Sleep(1000);
	}
	else {
		Klprint("Wow! You won the game! You have: ");
		cout<<coin;
		Klprint(" coins!");
		Sleep(1000);
	}
	return 0;
}
