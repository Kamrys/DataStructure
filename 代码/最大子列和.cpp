#include <iostream>
using namespace std;
void maxsum(int p[],int numb){
int i;
int thissum=0,maxsum1=0;
for(i=0;i<numb;i++){
thissum+=p[i];
if(thissum>maxsum1)
maxsum1=thissum;
else if(thissum<0)
thissum=0;
}
cout<<maxsum1;
}
int main(){
int num;
cin>>num;
int *p=new int[num];
int number=num;
while(num){
cin>>p[num-1];
num--;
}
maxsum(p,number);
delete p;
return 0;
}
