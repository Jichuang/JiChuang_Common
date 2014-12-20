

#include<stdio.h>
#include<stdlib.h>
int v,len=0,j,q,u,g,x,n=0,t,a[100],i,s;
char b;
void shuchu()
{printf("当前数据为：\n");
	for(j=1;j<=len;j++)
printf("%d\t",a[j]);                            //输出
printf("\n");printf("请选择菜单功能：");	
}
void shuru()
{
printf("请输入一组数组，并以'#'结束\n");
for(i=0;i<len+1;i++)                            //动态输入
    {
	scanf("%d",&a[i]);
    b=getchar();
    if(b=='#'){break;}
    len=len+1;
    }
printf("共输入%d个数\n",len);
     for(j=0;j<len;j++)
     for(i=0;i<len;i++)
       {
	   if(a[i+1]<a[i])
         {
		 t=a[i];a[i]=a[i+1];a[i+1]=t;}}
     shuchu();	
}
void qingkong()
{
for(i=0;i<len;i++)
a[i]=0;                                    //清空数据 
len=0;
printf("数据已清空！\n");
printf("\n");printf("请选择菜单功能：");	

}

void charu()
{shuchu();
	printf("请输入需要插入的数\n");
scanf("%d",&v);
if(v>a[len]){a[len+1]=v;}
else{
for(i=0;i<len;i++)
if(a[i]<v){n=i;}
for(j=len;j>n;j--)                              //插入
{a[j+1]=a[j];}
a[n+1]=v;}len=len+1;
shuchu();	
}

void sb()
{
printf("\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
printf("\t&                                  &\n");
printf("\t&        <1>录入数据               &\n");
printf("\t&        <2>浏览当前数据           &\n");
printf("\t&        <3>删除一个数据           &\n");
printf("\t&        <4>插入一个数据           &\n");
printf("\t&        <5>清空所有数据           &\n");
printf("\t&        <6>退出                   &\n");
printf("\t&                                  &\n");
printf("\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
}
void shanchu()
{      printf("当前数据为：\n");
	for(j=1;j<=len;j++)
printf("%d\t",a[j]);                          
printf("\n");                               //输出

printf("请选择需要删除的数字：");
scanf("%d",&x);


q=0;
for(j=0;j<=len;j++)
if(a[j]==x){q=1;}

if(q==0)printf("Not find!\n");                        //删除数字

else
{
if(a[len]==x)
{a[len]=0;
len=len-1;
shuchu();  }
else{	for(i=0;i<len;i++)
if(a[i]==x){t=i-1;t=t+1;}
for(s=t;s<=len;s++)
a[s]=a[s+1];len=len-1;
shuchu();
}
printf("请选择菜单功能：");	}
}

int main()
{
sb();
printf("请选择菜单功能：");	
scanf("%d",&u);
q=u;                                       //主函数 
while(q!=6)
{
	if(q==1){shuru();}
	if(q==2){shuchu();}
	if(q==3){shanchu();}
	if(q==4){charu();}
	if(q==5){qingkong();}           
	scanf("%d",&q);
	system("cls");
	sb();
}
printf("感谢使用！\n");
return 0;
}




