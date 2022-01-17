#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct student {
	char *name;
	int score;

};

struct student*  initstudent(int len)
{
	int i;
	//      struct student stu0[5];
        struct student *stu=(struct student *)malloc(len*sizeof(struct student));
//      stu=stu0;
//      stu=(struct student *)malloc(len*sizeof(struct student));

        for(i=0;i<len;i++)
//      for(i=0;i<sizeof(stu0)/sizeof(stu0[0]);i++)
        {
                printf("请输入名字\n");
                stu->name=(char*)malloc(128);
                memset(stu->name,"\0",128);
                scanf("%s",(stu->name));
//                gets(stu->name);
//              getchar();
                printf("请输分数：\n");
                scanf("%d",&(stu->score));
                stu++;
        }
 
	return stu-len;
}

void printMes(struct student* stu,int len)
{   	
	int i;
//	stu=stu-len;
        for(i=0;i<len;i++)
        {
               printf("第%d名字：%s,分数：%d\n",i+1,stu->name,stu->score);
               stu++;
        }

}

struct student* maxstudents(struct student* stu,int len)
{      
        struct student* maxstudent;
	int i;
	maxstudent=stu;
	for(i=0;i<len;i++)
        {
               if(stu->score>maxstudent->score){
			maxstudent=stu;

		}
               stu++;
        }
        return maxstudent;


}

struct student* minstudents(struct student* stu,int len)
{
	struct student* minstudent;
        int i;
        minstudent=stu;
        for(i=0;i<len;i++)
        {
               if(stu->score<minstudent->score){
                        minstudent=stu;

                }
               stu++;
        }
        return minstudent;
}

float pingjun(struct student* stu,int len)
{
	int total=0;
        int i;
        for(i=0;i<len;i++)
        {
               total=total+stu->score;
               stu++;
        }
        return (float)total/len;


}

int findname(struct student* stu,int len,char *name)
{
     int i;
     for(i=0;i<len;i++)
     {
               if(strcmp(name,stu->name)==0){
			return 1;
		}
               stu++;
      }
      return -1;

}

int main()
{
	int i;
	int len;
	struct student* stu=NULL;
	struct student* maxstudent=NULL;
	struct student* minstudent=NULL;
	float  average;
	char *name="张清华";
	printf("请输入比较学生的个数：\n");
	scanf("%d",&len);
        stu=initstudent(len);
	printMes(stu,len);
	maxstudent=maxstudents(stu,len);
	minstudent=minstudents(stu,len);
        average=pingjun(stu,len);
	printf("最大学生名字：%s,分数：%d\n",maxstudent->name,maxstudent->score);
	printf("最小学生名字：%s,分数：%d\n",minstudent->name,minstudent->score);
        printf("平均分为：%f\n",average);
        if(findname(stu,len,name)==1){
		printf("找到了\n");
	}else{
		printf("算了吧\n");
	}
	return 0;
}
