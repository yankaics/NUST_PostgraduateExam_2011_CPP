#include<iostream>
#include<cstdio>

using namespace std;

#define M 100

int countNum(string str,int integers[M]){
	int top=-1;
	for(int i=0,size=str.size();i<size;i++){
		if(str[i]>='0'&&str[i]<='9'){
			int j=i+1;
			while(str[j]>='0'&&str[j]<='9') j++;	//ƥ���������� 
			string buf=str.substr(i,j-i);
			int a;
			sscanf(buf.c_str(),"%d",&a);	//���ַ���ת��Ϊint 
			integers[++top]=a;		 //�����ַ��������� 
			i=j-1;	//�����α�i 
		}
	} 
	return top;
}

int main(){
	string str;
	cin>>str;
	int integers[M];
	int top=countNum(str,integers);
	cout<<"������"<<top+1<<endl;
	cout<<"�ֱ�Ϊ��";
	for(int i=0;i<=top;i++){
		cout<<integers[i];
		if(i<top) cout<<" ";
	}
	cout<<endl;
	return 0;
} 
