#include<iostream>
#include<string>

using namespace std;

void replace(char rs[],char a[],char s1[],const char s2[]){
	string str_a=""; str_a+=a;
	string str_s1=""; str_s1+=s1;
	string str_s2=""; str_s2+=s2;
	int size_a=str_a.size(),size_s1=str_s1.size(),size_s2=str_s2.size();
	//�����str_a��ƥ�� str_s1������str_s2�滻 
	for(int i=0;i<=size_a-size_s1;i++){
		bool isok=true;
		for(int j=0;j<size_s1;j++){
			if(str_a[i+j]!=str_s1[j]){
				isok=false;
				break;
			}
		}
		if(isok){
			//ƥ�䵽str_s1����str_s2�滻
			//�滻�꣬��str_a�ĳ��ȸı䣬��Ҫ�����α�i��str_a�ĳ���size_a��ֵ 
			str_a=str_a.substr(0,i)+str_s2+str_a.substr(i+size_s1);
			i=i+size_s2-1;
			size_a=str_a.size();
		}
	}
	for(int i=0;i<size_a;i++){
		rs[i]=str_a[i];
	}
	rs[size_a]='\0';
}

int main(){
	char rs[100],a[100]="ksidjabcjufabcd",s1[100]="abc",s2[100]="xxxxxxxx";
	replace(rs,a,s1,s2);
	puts(rs);
	return 0;
}
