#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//顺序表的最大容量
#define MAXSIZE 100

//操作状态 
#define OK 1
#define ERROR 0

//错误信息
#define ILLEGAL_INDEX "illegal index"  
#define OUTOFMEMORY "out of memory"

//数据类型
typedef int ElemType;

//状态信息
typedef struct {
	int status;
	string msg;
}Status;

typedef struct{
	ElemType *elem;
	int length;
}SqList;

Status InitList(SqList& L); //初始化顺序表
Status DestroyList(SqList& L); //销毁顺序表
Status ClearList(SqList& L); //清空顺序表
Status ListEmpty(SqList L); //表是否为空
Status GetElem(SqList L,int index, ElemType &elem); //获取元素
int LocateElem(SqList L,ElemType elem); //返回元素的位置，不存在返回-1
Status ListInsert(SqList& L,int index,ElemType elem); //插入元素
Status ListDelete(SqList& L,int index); //删除元素
void PrintList(SqList L); //打印元素


void CheckError(Status s);


bool auto_check = true;

int main(){
	SqList l;
	InitList(l);
	PrintList(l);
	for(int i=0;i<5;i++){
		ListInsert(l,i,i);
		PrintList(l);
	}
	ListInsert(l,3,55);
	PrintList(l);
	ListDelete(l,2);
	PrintList(l);
	ElemType e;
	GetElem(l,1,e);
	cout<<"e : "<<e<<endl;
	return 0;
}

void CheckError(Status s){
	cout<<"---> ";
	switch (s.status){
		case OK: cout<<s.msg<<" sucessful"<<endl;break;
		case ERROR: cout<<"ERROR! "<<s.msg<<endl;break;
	}
}

Status InitList(SqList& L){
	Status s;
	L.elem = new ElemType[MAXSIZE];
	if(!L.elem) s = {ERROR,OUTOFMEMORY};
	L.length = 0;
	s = {OK,"InitList"};
	if(auto_check)CheckError(s);
	return s;
}

Status ListInsert(SqList &L,int index,ElemType elem){
	Status s;
	if(index<0||index>L.length) s = {ERROR, ILLEGAL_INDEX};
	else if(L.length == MAXSIZE) s = {ERROR, OUTOFMEMORY};
	else {
		for (int i=L.length-1;i>=index;i--)	L.elem[i+1] = L.elem[i];
		L.elem[index] = elem;
		++L.length;
  		s = {OK,"Insert " + to_string(elem) + " at " + to_string(index)};
	}
	if(auto_check) CheckError(s);
	return s;
}

Status GetElem(SqList L,int index, ElemType &elem){
	Status s;
	if(index<0||index>=L.length) s = {ERROR,ILLEGAL_INDEX};
	else{
		elem = L.elem[index];
		s = {OK,"get "+to_string(elem)+" from index "+to_string(index)};
	}
	if(auto_check) CheckError(s);
	return s;
}

Status ListDelete(SqList& L,int index){
	Status s;
	if(index<0||index>=L.length) s = {ERROR,ILLEGAL_INDEX};
	else{
		s = {OK,"delete "+to_string(L.elem[index])+" from index "+to_string(index)};
		for(int i=index;i<L.length-1;i++) L.elem[i] = L.elem[i+1];
		--L.length;
	}
	if(auto_check) CheckError(s);
	return s;
}

void PrintList(SqList L){
	cout<<"List("<<L.length<<") :";
	for(int i = 0 ;i < L.length; i++){
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
}