#include <iostream>
#include <vector>
#define elif else if
#define maks 100
#define cnum 48
using namespace std;
string dt_ch = "abcdefghijklmnopqrstuvwxyz";
int index = 0;

void inToPost(string str, int len);
int isOpr(char ch);
bool isNum(char ch);
void postEval(string str, int len);
int hitung(int a, int b, char opr);

struct enc{
	char ch;
	int num;
} edt[maks];

struct stack{
	char ch[maks];
	int index;
};

int main() {
	string infix, str = "";
    int len;
    
    getline(cin, infix);
    
    len = infix.size();
    
    for(int i=0; i<len; i++) {
    	if(isalnum(infix[i])) {
    		str += infix[i];
		}
		else if(infix[i]=='-') {
    		if(isalnum(infix[i+1])) {
    			str += infix[i];
			}
			else if(infix[i+1]=='(') {
				if(isalnum(infix[i-1])) {
					str += infix[i];
				}
				else {
					str += "-1*";
				}
			}
			else {
				if(infix[i+1]!=' ')
					str += "-1";
				else
					str += infix[i];
			}
		}
		else {
			if(infix[i]!=' ') {
				str += infix[i];
			}
		}
	}
	
//	cout << str;
	inToPost(str, str.size());
//	string infix;
//	int len;
//	
//	getline(cin, infix);
//	len = infix.size();
//	
//	inToPost(infix, len);
//	
//	cout << "\n\n";
//	index = 0;
//	main();
}

void inToPost(string str, int len) {
	struct stack stk;
	stk.index = 0; // intial index stack
	stk.ch[stk.index] = '#';
	stk.index++;
	string postfix = "";
	int jml=0, num, postLen;
	
	for(int i=0; i<len; i++) {
		if(isNum(str[i])) {
			num = str[i] - cnum;
			if(isNum(str[i+1])) {
				jml = (jml * 10) + (num * 10);
			}
			else {
				jml += num;
				edt[index].ch = dt_ch[index];
				edt[index].num = jml;
				postfix += edt[index].ch;
//				cout << edt[index].ch <<  edt[index].num << endl;
				index++;
				jml = 0;
			}
		}
		else {
			if(str[i]=='(') {
				stk.ch[stk.index] = str[i];
				stk.index++;
			}
			elif(str[i]==')') {
				while(stk.ch[stk.index-1]!='#' && stk.ch[stk.index-1]!='(') {
					postfix += stk.ch[stk.index-1];
					stk.index--;
				}
				stk.index--;
			}
			else {
				if(str[i]!=' ') {
					if(!(isNum(str[i-1])) && str[i]=='-' && isNum(str[i+1])) {
						edt[index].ch = dt_ch[index];
						edt[index].num = jml;
						postfix += edt[index].ch;
						index++;
					}
					else {
						while(stk.ch[stk.index-1]!='#' && isOpr(str[i]) <= isOpr(stk.ch[stk.index-1])) {
							postfix += stk.ch[stk.index-1];
							stk.index--;
						}
						stk.ch[stk.index] = str[i];
						stk.index++;
					}
				}
			}
		}
	}
	
	while(stk.ch[stk.index-1]!='#') {
		postfix += stk.ch[stk.index-1];
		stk.index--;
	}
	
	cout << postfix;
	postLen = postfix.size();
	postEval(postfix, postLen);
	delete &stk;
}

void postEval(string str, int len) {
	struct stack stk;
	stk.index = 0; // intial index stack
	int num[2], total;
	vector<char> temp;
	
	for(int i=0; i<len; i++) {
		if(isalnum(str[i])) {
			stk.ch[stk.index] = str[i];
			stk.index++;
		}
		else {
			for(int x=1; x>=0; x--) {
				for(int y=0; y<index; y++) {
					if(stk.ch[stk.index-1]==edt[y].ch) {
						num[x] = edt[y].num;
						temp.push_back(edt[y].ch);
						cout << edt[y].ch << " " << edt[y].num << endl;
					}
				}
				stk.index--;
			}
			
			total = hitung(num[0], num[1], str[i]);
			stk.ch[stk.index] = temp.back();
			stk.index++;
			for(int x=0; x<index; x++) {
				if(temp.back()==edt[x].ch) {
					edt[x].num = total;
					temp.pop_back();
					break;
				}
			}
			
			cout << "total : " << total << endl;
		}
	}
	
	cout << total;
	delete &stk;
}

int hitung(int a, int b, char opr) {
	if(opr=='+')
		return a + b;
	elif(opr=='-')
		return a - b;
	elif(opr=='*')
		return a * b;
	elif(opr=='/')
		return a / b;
	elif(opr=='%')
		return a % b;
	else
		return 0;
}

int isOpr(char ch) {
	if(ch=='+' || ch=='-')
		return 1;
	elif(ch=='*' || ch=='/' || ch=='%')
		return 2;
	else
		return 0;
}

bool isNum(char ch) {
	string idt = "0123456789";
	bool cek = false;
	
	for(int i=0; i<10; i++) {
		if(ch==idt[i]) {
			cek = true;
			break;
		}
	}
	
	return cek;
}
