#include<iostream>

using namespace std;

#define M 100

//�ж��Ƿ�Ϊ���� 
bool isSu(int n){
	if(n<=1) return false;
	for(int i=2;i<n;i++){
		if(n%i==0) return false;
	}
	return true;
}

//����n�ĸ�λ��֮�� 
int calSum(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n=n/10;
	}
	return sum;
}

//�ݹ�ؽ�n������������stack�� 
void getSuChild(int stack[M],int &top,int n){
	if(isSu(n)){
		stack[++top]=n;
		return;
	} 
	for(int i=2;i<n;i++){
		if(isSu(i)&&n%i==0){
			stack[++top]=i;
			getSuChild(stack,top,n/i);
			break;
		}
	}
}

int main(){
	cout<<"Smith����"<<endl;
	int stack[M],top=-1;
	for(int i=1;i<=100;i++){
		if(isSu(i)) continue;
		int a=calSum(i);
		int b=0;
		top=-1;
		getSuChild(stack,top,i);
		for(int i=0;i<=top;i++){
			b+=calSum(stack[i]);
		}
		if(a==b){
			cout<<i<<endl;
		}
	}
	return 0;
} 
