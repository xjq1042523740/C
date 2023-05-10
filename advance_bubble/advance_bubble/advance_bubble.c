#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef struct Stu
{
	char name[20];
	int age;
}Stu;

int cmp_int(void* p1,void* p2)
{
	return *((int*)p1)-*((int*)p2);
}
int cmp_Stu_age(void* p1,void* p2)
{
	return ((Stu*)p1)->age-((Stu*)p2)->age;
}

void Swap(char* p1,char* p2,int width)
{
	int i=0;
	for(i=0;i<width;i++)
	{
		char temp=*p1;
		*p1=*p2;
		*p2=temp;
		p1++;
		p2++;
	}
}

void Ad_bubble(void* arr,int sz,int width,int(*cmp)(void* a,void* b))
{
	int i=0;
	//趟数
	for(i=0;i<sz-1;i++)
	{
		int j=0;
		//每一趟的比较次数
		for(j=0;j<sz-1-i;j++)
		{
			int flag=0;
			flag=cmp((char*)arr+j*width,(char*)arr+(j+1)*width);
			if(flag>0)
			{
				Swap((char*)arr+j*width,(char*)arr+(j+1)*width,width);
			}
		}
	}
}
int main()
{
	int arr[]={2,4,8,3,1,9,5,7,6};
	Stu a[]={{"zhangsan",22},{"lisi",19},{"wangwu",32}};
	int j=0;
	int sz=sizeof(arr)/sizeof(arr[0]);
	int sz1=sizeof(a)/sizeof(a[0]);
	Ad_bubble(arr,sz,sizeof(arr[0]),cmp_int);
	Ad_bubble(a,sz1,sizeof(a[0]),cmp_Stu_age);
	for(j=0;j<sz;j++)
	{
		printf("%d ",arr[j]);
	}
	printf("\n");
	for(j=0;j<sz1;j++)
	{
		printf("%d ",a[j].age);
	}
	return 0;
}