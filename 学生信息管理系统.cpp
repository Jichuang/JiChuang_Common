#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu
{
	char name[50];
	char ruxue[20];
	char banji[20];
	char phone[20];
	char dress[100];
}t[500];
int renshu;
int xuanze();
void shanchu();
void chazhao();
void tianjia();
void chakan();
void xiugai();
void tongji();
void paixu();
int duqu();
void baocun();
int main()
{
	int x;
	printf("\t\t\t********学生信息管理********\n");
	printf("\t\t\t*      1.添加学生信息.     *\n");
	printf("\t\t\t*      2.查看学生信息.     *\n");
	printf("\t\t\t*      3.查找学生信息.     *\n");
	printf("\t\t\t*      4.修改学生信息.     *\n");
	printf("\t\t\t*      5.删除学生信息.     *\n");
	printf("\t\t\t*      6.统计学生信息.     *\n");
	printf("\t\t\t*      7.排序学生信息.     *\n");
	printf("\t\t\t*      8.保存学生信息.     *\n");
	printf("\t\t\t*      9.读取学生信息.     *\n");
	printf("\t\t\t*      10.退出.             *\n");
	printf("\t\t\t****************************\n");                //菜单
	do
	{
	    printf("请输入您的选择(1-10):\n");
	    x=xuanze();
	    while(x<1||x>10)
		{
			printf("输入错误,请重新输入:\n");
	        x=xuanze();
		}
		switch(x)
		{
		case 1:tianjia();break;
		case 2:chakan();break;
		case 3:chazhao();break;
		case 4:xiugai();break;
		case 5:shanchu();break;
        case 6:tongji();break;
		case 7:paixu();break;
		case 8:baocun();break;
		case 9:renshu=duqu();break;
		case 10:printf("\t\t\t\t谢谢使用\n");exit(0);break;
		}
		system("cls");
		main();
	}while(x!=10);
	return 0;
}



int xuanze()
{
    int n;
	scanf("%d",&n);
	return n;
}


void tianjia()                                    //添加学生
{
	int i,n;
	system("cls");
    printf("请输入要添加学生信息的个数:");
	scanf("%d",&n);	
	printf("!!!!!请您将未知信息填写为“无（wu）”,否则会造成文件混乱!!!!!");
	for(i=renshu;i<renshu+n;i++)
	{
		printf("\n");
		if(i==renshu)
			getchar();
		printf("请输入第%d名学生信息:\n",i+1-renshu);
		printf("请输入学生姓名:");
        gets(t[i].name);
	    printf("请输入学生入学时间:");
    	gets(t[i].ruxue);
        printf("请输入学生班级:");
        gets(t[i].banji);
		printf("请输入学生电话:");
        gets(t[i].phone);
		printf("请输入学生家庭地址:");
        gets(t[i].dress);
	}
	system("pause");
	renshu=renshu+n;
}

void chakan()                            //查看所有学生
{
	int i;
	system("cls");
	printf("共有%d名学生:\n",renshu);
	if(renshu!=0)
		for(i=0;i<renshu;i++)
		{
			printf("第%d名学生:\n\t\t姓名:%s\n\t\t入学时间:%s\n\t\t班级:%s\n\t\t电话:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
	        printf("\n");
		}
	else
		printf("无学生信息!\n");
	system("pause");
}

void shanchu()                           //删除学生信息
{
	system("cls");
	if(renshu!=0)
	{
		printf("请输入要删除的学生姓名:");
	    int h,j,i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("找到学生:\n");
			    printf("\t第%d名学生:\n\t\t姓名:%s\n\t\t入学时间:%s\n\t\t班级:%s\n\t\t电话:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
                printf("是否删除此联系人:\n\t\t1.删除\t\t2.不删除\n请选择:");
			    scanf("%d",&h);
			    while(h!=1&&h!=2)
				{
					printf("输入错误,请重新输入!");
				    scanf("%d",&h);
				};
			    if(h==1)
				{
			        for(j=i;j<renshu;j++)
				    t[j]=t[j+1];
			        renshu=renshu-1;
				    printf("学生信息已删除\n");
				    printf("继续删除?\n\t\t1.是\t\t2.否\n请选择:");
				    scanf("%d",&m);
			        while(m!=1&&m!=2)
					{
						printf("输入错误,请重新输入!");
				        scanf("%d",&m);
					};
			        if(m==1)
						shanchu();
				}
			    break;
			}
		    if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("没有找到学生!\n");
			    printf("1.重新输入学生姓名.\n2.回到主菜单\n请选择:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("输入错误,请重新输入!");
				    scanf("%d",&m);
				};
			    if(m==1)
					shanchu();
				system("pause");
			}
		}
	}
	else
	{
		printf("无学生信息!\n");
        system("pause");
	}
}

void chazhao()                             //查找学生
{
	system("cls");
	int v,h=0;
	if(renshu!=0)
	{
		printf("\t1.按姓名查找.\t\t2.按入学时间查找\n请选择:");
		scanf("%d",&v);
	    while(v!=1&&v!=2)
		{
			printf("输入错误,请重新输入!");
		    scanf("%d",&v);
		};
	    if(v==1)
		{
		  printf("请输入要查找的学生姓名:");
	      int i,m;
	      getchar();
          gets(t[renshu].name);
	      for(i=0;i<renshu;i++)
		  {
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("找到学生:\n");
			    printf("\t第%d名学生:\n\t\t姓名:%s\n\t\t入学时间:%s\n\t\t班级:%s\n\t\t电话:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);			
			    h=1;
			}
            if(i==(renshu-1)&&h==0)
			{
				printf("没有找到学生!\n");
			    printf("1.重新查找.\n2.回到主菜单\n请选择:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("输入错误,请重新输入!");
				    scanf("%d",&m);
				};
			    if(m==1)
					chazhao();
			}
		  }
		}
		if(v==2)
		{
		  printf("请输入要查找的学生入学时间:");
	      int i,m;
	      getchar();
          gets(t[renshu].ruxue);
	      for(i=0;i<renshu;i++)
		  {
			if(strcmp(t[renshu].ruxue,t[i].ruxue)==0)
			{
				printf("找到学生:\n");
			    printf("\t第%d名学生:\n\t\t姓名:%s\n\t\t入学时间:%s\n\t\t班级:%s\n\t\t电话:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);			
			    h=1;
			}
            if(i==(renshu-1)&&h==0)
			{
				printf("没有找到学生!\n");
			    printf("1.重新查找.\n2.回到主菜单\n请选择:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("输入错误,请重新输入!");
				    scanf("%d",&m);
				};
			    if(m==1)
					chazhao();
			}
		  }
		}
	}
	else
		printf("无学生信息!\n");
	system("pause");
}


void xiugai()                               //修改学生信息
{
	system("cls");
	if(renshu!=0)
	{
		printf("请输入要修改的学生姓名:");
	    int j,i,m;
	    getchar();
        gets(t[renshu].name);
	    for(i=0;i<renshu;i++)
		{
			if(strcmp(t[renshu].name,t[i].name)==0)
			{
				printf("找到学生:\n");
			    printf("\t第%d名学生:\n\t\t姓名:%s\n\t\t入学时间:%s\n\t\t班级:%s\n\t\t电话:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
                j=i;
				break;			
			}
            if(i==(renshu-1)&&strcmp(t[renshu].name,t[i].name)!=0)
			{
				printf("没有找到学生!\n");
			    printf("1.重新查找.\n2.回到主菜单\n请选择:");
			    scanf("%d",&m);
			    while(m!=1&&m!=2)
				{
					printf("输入错误,请重新输入!");
				    scanf("%d",&m);
				};
			    if(m==1)
					xiugai();
			}
		}
		int k;
	printf("请选择要修改的信息:\n\t1.姓名\t2.入学时间\t3.班级\t4.电话\t5.家庭地址\n请选择:");
	scanf("%d",&k);
	while(k<1||k>5)
	{
		printf("输入错误,请重新输入!");
		scanf("%d",&k);
	}
	printf("请输入新的信息:");
	switch(k)
	{
	case 1:getchar();gets(t[j].name);break;
	case 2:getchar();gets(t[j].ruxue);break;
	case 3:getchar();gets(t[j].banji);break;
	case 4:getchar();gets(t[j].phone);break;
	case 5:getchar();gets(t[j].dress);break;
	}
	printf("修改成功!\n");
	}
	else
		printf("无学生信息!\n");
	system("pause");
}
void tongji()
{
	system("cls");
	printf("请输入学生入学时间:");
	int i,m,h=0;
	getchar();
    gets(t[renshu].ruxue);
	for(i=0;i<renshu;i++)
	{
	    if(strcmp(t[renshu].ruxue,t[i].ruxue)==0)
		{
		    printf("\t第%d名学生:\n\t\t姓名:%s\n\t\t入学时间:%s\n\t\t班级:%s\n\t\t电话:%s\n\t\t家庭地址:%s\n",i+1,t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);			
			h=1;
		}
        if(i==(renshu-1)&&h==0)
		{
			printf("没有找到学生!\n");
			printf("1.重新查找.\n2.回到主菜单\n请选择:");
			scanf("%d",&m);
			while(m!=1&&m!=2)
			{
		      	printf("输入错误,请重新输入!");
				scanf("%d",&m);
			};
			if(m==1)
			tongji();
		}
	}
	system("pause");
}

void paixu()
{
    system("cls");
	int i,n,j;
	for(i=0;i<renshu;i++)
	{
	strcpy(t[renshu+1+i].name,t[i].name);
	strcpy(t[renshu+1+i].banji,t[i].banji);
	strcpy(t[renshu+1+i].ruxue,t[i].ruxue);
	strcpy(t[renshu+1+i].phone,t[i].phone);
	strcpy(t[renshu+1+i].dress,t[i].dress);
	}
	for(n=1;n<renshu+1;n++)
	{
		strcpy(t[renshu].name,t[renshu+n].name);
	    strcpy(t[renshu].banji,t[renshu+n].banji);
        strcpy(t[renshu].ruxue,t[renshu+n].ruxue);
	    strcpy(t[renshu].phone,t[renshu+n].phone);
        strcpy(t[renshu].dress,t[renshu+n].dress);
	    for(i=renshu+n;i<renshu*2+1;i++)
		{
	
		    if(strcmp(t[i].banji,t[renshu].banji)<0||(strcmp(t[i].banji,t[renshu].banji)==0&&strcmp(t[i].name,t[renshu].name)<0))
			{
			    strcpy(t[renshu].name,t[i].name);
           	    strcpy(t[renshu].banji,t[i].banji);
			    strcpy(t[renshu].ruxue,t[i].ruxue);
	            strcpy(t[renshu].phone,t[i].phone);
			    strcpy(t[renshu].dress,t[i].dress);
			    j=i;
			}
		}
		printf("\t班级:%s\t姓名:%s\t入学时间:%s\t电话:%s\t家庭地址:%s\n",t[renshu].banji,t[renshu].name,t[renshu].ruxue,t[renshu].phone,t[renshu].dress);
	    strcpy(t[j].name,t[renshu+n].name);
        strcpy(t[j].banji,t[renshu+n].banji);
	    strcpy(t[j].ruxue,t[renshu+n].ruxue);
	    strcpy(t[j].phone,t[renshu+n].phone);
        strcpy(t[j].dress,t[renshu+n].dress);
	}

	
	system("pause");
}

int duqu()
{
	FILE *x=NULL;
	int i=0,renshu=0;
	if((x=fopen("t.txt","r+"))==NULL)
	{
		printf("不能打开文件:t.txt\n");
		system("pause");
		exit(0);
	}
	fscanf(x,"%d",&renshu);
	printf("\n\t\t\t******开始读取文件******\n");
	for(i=0;i<renshu;i++)
		fscanf(x,"%s\n%s\n%s\n%s\n%s\n",t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
    fclose(x);
	printf("\t\t\t********读取成功********\n");
	system("pause");
	return renshu;
}


void baocun()
{
	FILE *x;
	int i;
    x=fopen("t.txt","w");
	printf("\t\t\t******开始保存文件******\n");
	fprintf(x,"%d",renshu);
	fprintf(x,"\r\n");
	for(i=0;i<renshu;i++)
	{
		fprintf(x,"%s\n%s\n%s\n%s\n%s\n",t[i].name,t[i].ruxue,t[i].banji,t[i].phone,t[i].dress);
        fprintf(x,"\r\n");
	}
	fclose(x);
	printf("\t\t\t********保存成功********\n");
	system("pause");


}
