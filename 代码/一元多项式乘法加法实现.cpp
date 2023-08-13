#include <iostream>
using namespace std;

struct PolyNode{//节点
int coef;//系数
int expon;//指数
PolyNode* link;
};
typedef PolyNode* List;

void attach(int c,int e,List* Rear){//二级指针实现对Rear操作，attach函数实现添加项
List l=(List)malloc(sizeof(struct PolyNode));
l->coef=c;
l->expon=e;
l->link=NULL;
(*Rear)->link=l;
*Rear=l;
}

List Readlist(){//读取，存入多项式
List p=(List)malloc(sizeof(struct PolyNode));
List Rear=p;
int num;
cin>>num;
while(num--){
int c,e;
cin>>c>>e;
attach(c,e,&Rear);
}
List temp=p;
p=p->link;
free(temp);
return p;
}

List addlist(List p1,List p2){
List p=(List)malloc(sizeof(struct PolyNode));
p->link=NULL;
List Rear=p;
while(p1&&p2){//三种相加情况，大于等于小于
    if(p1->expon>p2->expon){
        attach(p1->coef,p1->expon,&Rear);
        p1=p1->link;
    }
    else if(p1->expon<p2->expon){
        attach(p2->coef,p2->expon,&Rear);
        p2=p2->link;
    }
    else if(p1->expon==p2->expon){
        if(p1->coef+p2->coef)//不为0
            attach(p1->coef+p2->coef,p2->expon,&Rear);
        p1=p1->link;
        p2=p2->link;
    }
}
while(p1){
    attach(p1->coef,p1->expon,&Rear);
    p1=p1->link;
}
while(p2){
    attach(p2->coef,p2->expon,&Rear);
    p2=p2->link;
}
List temp=p;
p=p->link;
free(temp);
return p;
}

List multlist(List p1,List p2){
if(!p1||!p2){//其中一个为空返回NULL
    return NULL;
}
List p=(List)malloc(sizeof(struct PolyNode));
p->link=NULL;//申请一个空节点
List Rear=p,t1=p1,t2=p2,te;
int c,e;
while(t2){
    attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
    t2=t2->link;
}//先将t1第一项乘以t2所有项得到的项存入p再逐项相加进行操作
t1=t1->link;
while(t1){//t1,t2循环逐项相乘加入p
    Rear=p;
    t2=p2;
    while(t2){
        c=t1->coef*t2->coef;
        e=t1->expon+t2->expon;
        while(Rear->link&&Rear->link->expon>e)
            Rear=Rear->link;
        if(Rear->link&&Rear->link->expon==e){//只有两种情况，小于和等于
            if(Rear->link->coef+c)//相加不为0
                Rear->link->coef+=c;
            else{//相加为0删除节点
                te=Rear->link;
                Rear->link=te->link;
                free(te);
            }
        }else{//放在rear下一项前面，小于的情况
            te=(List)malloc(sizeof(struct PolyNode));
            te->coef=c;
            te->expon=e;
            te->link=Rear->link;
            Rear->link=te;
            Rear=Rear->link;
        }
            t2=t2->link;
    }
    t1=t1->link;
}
List temp=p;//删除空表头，得到完整项
p=p->link;
free(temp);
return p;
}

void printlist(List p){
    int num=0;
    if(!p)
        cout<<"0 0";//若为空表输出0 0
    while(p){//用num实现第一个不加空格，后面都是空格系数空格指数的形式
        if(!num)
            num=1;
        else
            cout<<" ";
        cout<<p->coef<<" "<<p->expon;
        p=p->link;
    }
    cout<<endl;
}
int main(){
    List l1,l2,l3,l4;//功能调用实现
    l1=Readlist();
    l2=Readlist();
    l3=addlist(l1,l2);
    l4=multlist(l1,l2);
    printlist(l4);
    printlist(l3);
    return 0;
}
