
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
printf("\t&    ͨ  Ѷ  ¼  ��  ��  ϵ  ͳ    &\n");
printf("\t&                                  &\n");
printf("\t&             ���˵�               &\n");
printf("\t&                                  &\n");
printf("\t&        <1>�����ϵ��             &\n");
printf("\t&        <2>���������ϵ��         &\n");
printf("\t&        <3>�޸���ϵ����Ϣ         &\n");                    //�˵�����
printf("\t&        <4>ɾ����ϵ��             &\n");
printf("\t&        <5>��ѯ��ϵ��             &\n");
printf("\t&        <6>�˳�                   &\n");
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
printf("��������ϵ����Ϣ������'#'����\n");
while(1)        
{system("cls");
sb();
printf("��������ϵ��������\n");
scanf("%s",&a[i].name);
printf("�����뼮�᣺\n");
scanf("%s",&a[i].jiguan);
printf("���������1:\n");
scanf("%s",&a[i].phone1);
printf("���������2:\n");
scanf("%s",&a[i].phone2);
printf("����������:\n");                                
scanf("%s",&a[i].e_mail);
a[i].num[i]=i+1;
len=len+1;                                                               //�����ϵ��
i=i+1;
system("cls");
sb();
printf("\n");
printf("��ӳɹ�!\n����'1'������ӣ�����'0'�������˵�\n");
scanf("%d",&b);
if(b==0){system("cls");
sb();break;}
}
printf("�����%d����ϵ��\n",len);
printf("��ѡ��˵����ܣ�");	
}

void ss()
{
jixu:
system("cls");
sb();
printf("\n");
printf("������ϵ�ˣ�\n");
for(j=0;j<len;j++)
printf("%d\t%s\t%s\n",j+1,a[j].name,a[j].phone1);                        //�����ϵ��
printf("\n");
printf("�����Ӧ��Ų鿴��ϸ��Ϣ������'0'�������˵�\n");
scanf("%d",&i);
if(i==0){system("cls");
sb();printf("��ѡ��˵�����:\n");return ;}
system("cls");
sb();
printf("\t����:\t%s\n\t���᣺\t%s\n\tphone1:\t%s\n\tphone2:\t%s\n\te-mail:\t%s\n",a[i-1].name,a[i-1].jiguan,a[i-1].phone1,a[i-1].phone2,a[i-1].e_mail);
printf("\n����'9'������һҳ������'0'�������˵���\n");
scanf("%d",&c);
if(c==9){goto jixu;}
else{
	system("cls");
	sb();
	printf("��ѡ��˵�����:\n");}
}

void shanchu()
{	system("cls");
	sb();
printf("������ϵ�ˣ�\n");
for(j=0;j<len;j++)
printf("%d\t%s\t%s\n",j+1,a[j].name,a[j].phone1);                    //ɾ����ϵ��
printf("\n");
	printf("��ѡ����Ҫɾ������ϵ�˱�ţ�");
scanf("%d",&x);
for(s=x;s<=len;s++)
a[s-1]=a[s];
len=len-1;
system("cls");
	sb();
printf("ɾ���ɹ�!\n");
printf("��ѡ��˵�����:\n");

}



void xiugai()
{
	system("cls");
	sb();
printf("������ϵ�ˣ�\n");
for(j=0;j<len;j++)
printf("%d\t%s\t%s\n",j+1,a[j].name,a[j].phone1);                    //�޸���ϵ��
printf("\n");
	printf("��ѡ����Ҫ�޸ĵ���ϵ�˱�ţ�");
scanf("%d",&x);
system("cls");
sb();
printf("\n(1)\t%s\n(2)\t%s\n(3)\t%s\n(4)\t%s\n(5)\t%s\n",a[x-1].name,a[x-1].jiguan,a[x-1].phone1,a[x-1].phone2,a[x-1].e_mail);
printf("\n��������Ҫ�޸ĵ���Ϣ��ţ�\n");
scanf("%d",&c);
if(c==1){printf("������������:\n");scanf("%s",a[x-1].name);}
if(c==2){printf("�������¼���:\n");scanf("%s",a[x-1].jiguan);}
if(c==3){printf("�������º���:\n");scanf("%s",a[x-1].phone1);}
if(c==4){printf("�������º���:\n");scanf("%s",a[x-1].phone2);}
if(c==5){printf("������������:\n");scanf("%s",a[x-1].e_mail);}
system("cls");
sb();
printf("�޸ĳɹ�!\n");
printf("��ѡ��˵�����:\n");

}






void chaxun()
{int v,p;
char t[20];hehe:
system("cls");
sb();
printf("��ѡ���ѯ��ʽ:\n");
printf("\n");
printf("1.ͨ��������ѯ\t2.ͨ�������ѯ\n\n9.�������˵�\n");
scanf("%d",&v);
p=v;                                                              //��ѯ��ϵ��
if(p==1)
{system("cls");
sb();
printf("�������ѯ������:\n");
scanf("%s",t);

for(i=0;i<len;i++)
if(strcmp(t,a[i].name)==0)
{system("cls");sb();
printf("\t����:\t%s\n\t���᣺\t%s\n\tphone1:\t%s\n\tphone2:\t%s\n\te-mail:\t%s\n",a[i].name,a[i].jiguan,a[i].phone1,a[i].phone2,a[i].e_mail);
printf("\n����'9'������һҳ������'0'�������˵���\n");
scanf("%d",&c);
if(c==9){goto hehe;}
else{
	system("cls");
	sb();
	printf("��ѡ��˵�����:\n"); return;}
}
}

if(p==2)
{system("cls");
sb();printf("�������ѯ�ĺ���:\n");
scanf("%s",t);

for(i=0;i<len;i++)
if(strcmp(t,a[i].phone1)==0)
{system("cls");sb();
printf("����:\t%s\n���᣺\t%s\nphone1:\t%s\nphone2:\t%s\ne-mail:\t%s\n",a[i].name,a[i].jiguan,a[i].phone1,a[i].phone2,a[i].e_mail);
printf("\n����'9'������һҳ������'0'�������˵���\n");
scanf("%d",&c);
if(c==9){goto hehe;}
else{system("cls");sb();printf("��ѡ��˵�����:\n");return;}}

for(i=0;i<len;i++)
if(strcmp(t,a[i].phone2)==0)
{system("cls");sb();
printf("����:\t%s\n���᣺\t%s\nphone1:\t%s\nphone2:\t%s\ne-mail:\t%s\n",a[i].name,a[i].jiguan,a[i].phone1,a[i].phone2,a[i].e_mail);
printf("\n����'9'������һҳ������'0'�������˵���\n");
scanf("%d",&c);
if(c==9){goto hehe;}
else{system("cls");sb();printf("��ѡ��˵�����:\n");return;}}
}


if(p==9){system("cls");sb();printf("��ѡ��˵�����:\n");return;}
else{printf("�������!\n���������룬������9�������˵�\n");goto hehe;}



}










int main()
{system("cls");
sb();
printf("��ѡ��˵����ܣ�");	
scanf("%d",&u);
q=u;
while(q!=6)                                                          //������
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
printf("��лʹ�ã�\n");
return 0;
}

