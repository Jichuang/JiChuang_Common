

#include<stdio.h>
#include<stdlib.h>
int v,len=0,j,q,u,g,x,n=0,t,a[100],i,s;
char b;
void shuchu()
{printf("��ǰ����Ϊ��\n");
	for(j=1;j<=len;j++)
printf("%d\t",a[j]);                            //���
printf("\n");printf("��ѡ��˵����ܣ�");	
}
void shuru()
{
printf("������һ�����飬����'#'����\n");
for(i=0;i<len+1;i++)                            //��̬����
    {
	scanf("%d",&a[i]);
    b=getchar();
    if(b=='#'){break;}
    len=len+1;
    }
printf("������%d����\n",len);
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
a[i]=0;                                    //������� 
len=0;
printf("��������գ�\n");
printf("\n");printf("��ѡ��˵����ܣ�");	

}

void charu()
{shuchu();
	printf("��������Ҫ�������\n");
scanf("%d",&v);
if(v>a[len]){a[len+1]=v;}
else{
for(i=0;i<len;i++)
if(a[i]<v){n=i;}
for(j=len;j>n;j--)                              //����
{a[j+1]=a[j];}
a[n+1]=v;}len=len+1;
shuchu();	
}

void sb()
{
printf("\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
printf("\t&                                  &\n");
printf("\t&        <1>¼������               &\n");
printf("\t&        <2>�����ǰ����           &\n");
printf("\t&        <3>ɾ��һ������           &\n");
printf("\t&        <4>����һ������           &\n");
printf("\t&        <5>�����������           &\n");
printf("\t&        <6>�˳�                   &\n");
printf("\t&                                  &\n");
printf("\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
}
void shanchu()
{      printf("��ǰ����Ϊ��\n");
	for(j=1;j<=len;j++)
printf("%d\t",a[j]);                          
printf("\n");                               //���

printf("��ѡ����Ҫɾ�������֣�");
scanf("%d",&x);


q=0;
for(j=0;j<=len;j++)
if(a[j]==x){q=1;}

if(q==0)printf("Not find!\n");                        //ɾ������

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
printf("��ѡ��˵����ܣ�");	}
}

int main()
{
sb();
printf("��ѡ��˵����ܣ�");	
scanf("%d",&u);
q=u;                                       //������ 
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
printf("��лʹ�ã�\n");
return 0;
}




