
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len=0,j,q,u, x,n=0,i=0,s;
int b;
int c;
void sb()
{
printf("\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
printf("\t&                                  &\n");
printf("\t&    通  讯  录  管  理  系  统    &\n");
printf("\t&                                  &\n");
printf("\t&             主菜单               &\n");
printf("\t&                                  &\n");
printf("\t&        <1>添加联系人             &\n");
printf("\t&        <2>浏览已有联系人         &\n");
printf("\t&        <3>修改联系人信息         &\n");                    //菜单界面
printf("\t&        <4>删除联系人             &\n");
printf("\t&        <5>查询联系人             &\n");
printf("\t&        <6>退出                   &\n");
printf("\t&                                  &\n");
printf("\t&                                  &\n");
printf("\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
}


struct person
{int num[100];
char name[30];
char jiguan[20];
char phone1[30];
char phone2[30];
char e_mail[40];
}a[100];


void shuru()
{
printf("请输入联系人信息，输入'#'返回\n");
while(1)        
{system("cls");
sb();
printf("请输入联系人姓名：\n");
scanf("%s",&a[i].name);
printf("请输入籍贯：\n");
scanf("%s",&a[i].jiguan);
printf("请输入号码1:\n");
scanf("%s",&a[i].phone1);
printf("请输入号码2:\n");
scanf("%s",&a[i].phone2);
printf("请输入邮箱:\n");                                
scanf("%s",&a[i].e_mail);
a[i].num[i]=i+1;
len=len+1;                                                               //添加联系人
i=i+1;
system("cls");
sb();
printf("\n");
printf("添加成功!\n输入'1'继续添加，输入'0'返回主菜单\n");
scanf("%d",&b);
if(b==0){system("cls");
sb();break;}
}
printf("已添加%d个联系人\n",len);
printf("请选择菜单功能：");	
}

void ss()
{
jixu:
system("cls");
sb();
printf("\n");
printf("已有联系人：\n");
for(j=0;j<len;j++)
printf("%d\t%s\t%s\n",j+1,a[j].name,a[j].phone1);                        //浏览联系人
printf("\n");
printf("输入对应编号查看详细信息，输入'0'返回主菜单\n");
scanf("%d",&i);
if(i==0){system("cls");
sb();printf("请选择菜单功能:\n");return ;}
system("cls");
sb();
printf("\t姓名:\t%s\n\t籍贯：\t%s\n\tphone1:\t%s\n\tphone2:\t%s\n\te-mail:\t%s\n",a[i-1].name,a[i-1].jiguan,a[i-1].phone1,a[i-1].phone2,a[i-1].e_mail);
printf("\n输入'9'返回上一页，输入'0'返回主菜单，\n");
scanf("%d",&c);
if(c==9){goto jixu;}
else{
	system("cls");
	sb();
	printf("请选择菜单功能:\n");}
}

void shanchu()
{	system("cls");
	sb();
printf("已有联系人：\n");
for(j=0;j<len;j++)
printf("%d\t%s\t%s\n",j+1,a[j].name,a[j].phone1);                    //删除联系人
printf("\n");
	printf("请选择需要删除的联系人编号：");
scanf("%d",&x);
for(s=x;s<=len;s++)
a[s-1]=a[s];
len=len-1;
system("cls");
	sb();
printf("删除成功!\n");
printf("请选择菜单功能:\n");

}



void xiugai()
{
	system("cls");
	sb();
printf("已有联系人：\n");
for(j=0;j<len;j++)
printf("%d\t%s\t%s\n",j+1,a[j].name,a[j].phone1);                    //修改联系人
printf("\n");
	printf("请选择需要修改的联系人编号：");
scanf("%d",&x);
system("cls");
sb();
printf("\n(1)\t%s\n(2)\t%s\n(3)\t%s\n(4)\t%s\n(5)\t%s\n",a[x-1].name,a[x-1].jiguan,a[x-1].phone1,a[x-1].phone2,a[x-1].e_mail);
printf("\n请输入需要修改的信息编号：\n");
scanf("%d",&c);
if(c==1){printf("请输入新姓名:\n");scanf("%s",a[x-1].name);}
if(c==2){printf("请输入新籍贯:\n");scanf("%s",a[x-1].jiguan);}
if(c==3){printf("请输入新号码:\n");scanf("%s",a[x-1].phone1);}
if(c==4){printf("请输入新号码:\n");scanf("%s",a[x-1].phone2);}
if(c==5){printf("请输入新邮箱:\n");scanf("%s",a[x-1].e_mail);}
system("cls");
sb();
printf("修改成功!\n");
printf("请选择菜单功能:\n");

}






void chaxun()
{int v,p;
char t[20];hehe:
system("cls");
sb();
printf("请选择查询方式:\n");
printf("\n");
printf("1.通过姓名查询\t2.通过号码查询\n\n9.返回主菜单\n");
scanf("%d",&v);
p=v;                                                              //查询联系人
if(p==1)
{system("cls");
sb();
printf("请输入查询的姓名:\n");
scanf("%s",t);

for(i=0;i<len;i++)
if(strcmp(t,a[i].name)==0)
{system("cls");sb();
printf("\t姓名:\t%s\n\t籍贯：\t%s\n\tphone1:\t%s\n\tphone2:\t%s\n\te-mail:\t%s\n",a[i].name,a[i].jiguan,a[i].phone1,a[i].phone2,a[i].e_mail);
printf("\n输入'9'返回上一页，输入'0'返回主菜单，\n");
scanf("%d",&c);
if(c==9){goto hehe;}
else{
	system("cls");
	sb();
	printf("请选择菜单功能:\n"); return;}
}
}

if(p==2)
{system("cls");
sb();printf("请输入查询的号码:\n");
scanf("%s",t);

for(i=0;i<len;i++)
if(strcmp(t,a[i].phone1)==0)
{system("cls");sb();
printf("姓名:\t%s\n籍贯：\t%s\nphone1:\t%s\nphone2:\t%s\ne-mail:\t%s\n",a[i].name,a[i].jiguan,a[i].phone1,a[i].phone2,a[i].e_mail);
printf("\n输入'9'返回上一页，输入'0'返回主菜单，\n");
scanf("%d",&c);
if(c==9){goto hehe;}
else{system("cls");sb();printf("请选择菜单功能:\n");return;}}

for(i=0;i<len;i++)
if(strcmp(t,a[i].phone2)==0)
{system("cls");sb();
printf("姓名:\t%s\n籍贯：\t%s\nphone1:\t%s\nphone2:\t%s\ne-mail:\t%s\n",a[i].name,a[i].jiguan,a[i].phone1,a[i].phone2,a[i].e_mail);
printf("\n输入'9'返回上一页，输入'0'返回主菜单，\n");
scanf("%d",&c);
if(c==9){goto hehe;}
else{system("cls");sb();printf("请选择菜单功能:\n");return;}}
}


if(p==9){system("cls");sb();printf("请选择菜单功能:\n");return;}
else{printf("输入错误!\n请重新输入，或输入9返回主菜单\n");goto hehe;}



}










int main()
{system("cls");
sb();
printf("请选择菜单功能：");	
scanf("%d",&u);
q=u;
while(q!=6)                                                          //主函数
{
if(q==1)    {   system("cls");  sb();   shuru();}
if(q==2)	{   ss();        }
if(q==3)    {   xiugai();  }
if(q==4)    {   shanchu();             }
if(q==5)    {   chaxun();      }
scanf("%d",&q);
}

	system("cls");
	sb();
printf("感谢使用！\n");
return 0;
}

