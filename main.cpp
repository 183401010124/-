//ͷ�ļ�˵����
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<conio.h>
#include<string.h>

//����ȫ�ֱ�����
void clrscr();
struct shu{
	char num[20];
	char name[20];
	float base;
	float bonus;
	float qitabutie;
	float salary;
	float thsalary;
	float kouchu;
	float jiangjin;
	float shui;
	float house;
	float yanglao;
	float yiliaoxian;
	float shiyexian;
	struct shu *next;
};

//����˰����
float suodeshui(float x);

//�������뺯����
struct shu *Creatlist();

//������ʾ������
void Printlist();

//�����޸ĺ�����
void Modify(struct shu *x);

//������Һ�����
void Listfind();

//������Ӻ�����
void Insert();


//�ͷſռ�
void Free(struct shu *x)
{
	struct shu *p;
	while(x!=NULL)
	{
		p=x;
		x=x->next;
		free(p);
	}
}


//�������ṹ���£�
int main()
{
   char i;
   struct shu *p,*head;
   head=(struct shu *)malloc(sizeof(struct shu));
   head=NULL;
   for( ; ;)     //ѭ��ִ�й��ܲ˵�
  {
    clrscr();  //����Ļ
    printf("* * * * * *i�˵�* * * * * * *\n");
    printf("*          a. ����          *\n");
    printf("*          b. ��ʾ          *\n");
    printf("*          c. �޸�          *\n");
    printf("*          d. ����          *\n");
    printf("*          e. ���          *\n");
    printf("*          f. �˳�          *\n");
    printf("*          ����a--f         *\n");
    printf("* * * * * * * * * * * * * * *\n");
    i=getch();
    if(i=='f') break;
    else switch(i)
    {
     case 'a': head=Creatlist();break;//�������뺯��
     case 'b': Printlist();system("pause");break;//������ʾ����
     case 'c': p=head;Modify(p);system("pause");break;//�����޸ĺ���
     case 'd': Listfind();system("pause");break;//���ò��Һ���
     case 'e': Insert();system("pause");break;//������Ӻ���
    }
   }
   Free(head);
   system("pause");
   return 0;
}
void clrscr()
{
	system("cls");
}

//��д���뺯����
struct shu *Creatlist()
{
	struct shu *p,*ha,*re;
	FILE *t1;
	int flag=2;
	t1=fopen("ְ����Ϣ.txt","w");
	if(t1==NULL)
	{
		printf("file1");
		exit(-1);
	}
	ha=(struct shu *)malloc(sizeof(struct shu));
	if(ha==NULL)
	{
		printf("error");
		exit(-1);
	}
	ha->next=NULL;
	re=ha;
	while(flag==2)
	{
		p=(struct shu *)malloc(sizeof(struct shu));
		p->kouchu=0;
		p->salary =0;
		printf("������Ա����ţ�");
		scanf("%s",p->num );
		printf("\n������");
		scanf("%s",p->name );
		printf("\n�������ʣ�");
		scanf("%f",&p->base );
		p->salary +=p->base;
		printf("\n��λ������");
		scanf("%f",&p->bonus );
		p->salary +=p->bonus ;
		printf("\n����������");
		scanf("%f",&p->qitabutie );
		p->salary +=p->qitabutie ;
		printf("\n����");
		scanf("%f",&p->jiangjin);
		p->salary +=p->jiangjin ;
		printf("\nס��������");
		scanf("%f",&p->house);
		p->kouchu +=p->house;
		printf("\n���Ͻ�");
		scanf("%f",&p->yanglao);
		p->kouchu +=p->yanglao ;
		printf("\nҽ�Ʊ��գ�");
		scanf("%f",&p->yiliaoxian );
		p->kouchu +=p->yiliaoxian ;
		printf("\nʧҵ���գ�");
		scanf("%f",&p->shiyexian );
		p->kouchu +=p->shiyexian ;
		p->next=NULL;
		p->shui=suodeshui((p->base+p->jiangjin)-(p->kouchu ));
		p->kouchu +=p->shui ;
		p->thsalary =p->salary -p->kouchu ;
		re->next=p;
		re=p;
		fprintf(t1,"%s %s\n",p->num ,p->name);
		fprintf(t1,"%.2f %.2f\n",p->salary,p->thsalary);
		fprintf(t1,"%.2f %.2f %.2f %.2f\n",p->base,p->bonus ,p->qitabutie ,p->jiangjin);
		fprintf(t1,"%.2f\n",p->kouchu );
		fprintf(t1,"%.2f %.2f %.2f %.2f %.2f\n",p->shui,p->house ,p->yanglao,p->yiliaoxian ,p->shiyexian );
		printf("�Ƿ����ְ����Ϣ�����룿 1���� 2����\n");
		scanf("%d",&flag);
	}
	fclose(t1);
	return ha;
}

//����˰���㣺
float suodeshui(float x)
{
	float a,b;
	a=x-3500;
	if(a>=0){
	if(a<=1500)
		b=a*0.03;
	if(a>1500&&a<=4500)
		b=a*0.1;
	if(a>4500&&a<=9000)
		b=a*0.2;
	if(a>9000&&a<=35000)
		b=a*0.25;
	if(a>35000&&a<=55000)
		b=a*0.3;
	if(a>55000&&a<=80000)
		b=a*0.35;
	if(a>80000)
		b=a*0.45;
	}
	else
		b=0;
	return b;
}

//��д��ʾ������
void Printlist()
{
	char num[20];
	char name[20];
	float base;
	float bonus;
	float qitabutie;
	float salary;
	float thsalary;
	float kouchu;
	float jiangjin;
	float shui;
	float house;
	float yanglao;
	float yiliaoxian;
	float shiyexian;
	struct shu *next;
	FILE *t1;
	t1=fopen("ְ����Ϣ.txt","r");
	if(t1==NULL)
	{
		printf("δ�ɹ���ְ����Ϣ�ļ���\n");
		exit(-1);
	}
	while(fscanf(t1,"%s",num )!=EOF)
	{
	fscanf(t1,"%s",name );
	fscanf(t1,"%f",&salary );
	fscanf(t1,"%f",&thsalary );
    fscanf(t1,"%f",&base);
	fscanf(t1,"%f",&bonus);
	fscanf(t1,"%f",&qitabutie );
	fscanf(t1,"%f",&jiangjin);
	fscanf(t1,"%f",&kouchu);
	fscanf(t1,"%f",&shui);
	fscanf(t1,"%f",&house);
	fscanf(t1,"%f",&yanglao);
	fscanf(t1,"%f",&yiliaoxian );
	fscanf(t1,"%f",&shiyexian );
	printf("��ţ�%s\n������%s\n",num ,name);
	printf("Ӧ�����ʣ�%.2f ʵ�����ʣ�%.2f\n",salary,thsalary);
	printf("ְ��������ʣ�%.2f ��λ������%.2f ����������%.2f ����%.2f\n",base,bonus ,qitabutie ,jiangjin);
	printf("�۳��ܹ�%.2f ������\n",kouchu );
	printf("����˰��%.2f ס��������%.2f ���Ͻ�%.2f ҽ�Ʊ��գ�%.2f ʧҵ���� �� %.2f\n",shui ,house ,yanglao,yiliaoxian ,shiyexian );
	printf("\n");
	}
	fclose(t1);
	return ;
}

//��д�޸ĺ�����
void Modify(struct shu *x)
{
	FILE *t1;
	int flag=0;
	struct shu *p,*ha,*re,*q;
	if(x==NULL)
        {
		flag=1;
	char num[20];
	char name[20];
	float base;
	float bonus;
	float qitabutie;
	float salary;
	float thsalary;
	float kouchu;
	float jiangjin;
	float shui;
	float house;
	float yanglao;
	float yiliaoxian;
	float shiyexian;
	struct shu *next;
	ha=(struct shu *)malloc(sizeof(struct shu));
	if(ha==NULL)
	{
		printf("error");
		exit(-1);
	}
	ha->next=NULL;
	re=ha;
	FILE *t1;
	t1=fopen("ְ����Ϣ.txt","a+");
	if(t1==NULL)
	{
		printf("δ�ɹ���ְ����Ϣ�ļ���\n");
		exit(-1);
	}
	while(fscanf(t1,"%s",num )!=EOF)
	{
	fscanf(t1,"%s",name );
	fscanf(t1,"%f",&salary );
	fscanf(t1,"%f",&thsalary );
    fscanf(t1,"%f",&base);
	fscanf(t1,"%f",&bonus);
	fscanf(t1,"%f",&qitabutie );
	fscanf(t1,"%f",&jiangjin);
	fscanf(t1,"%f",&kouchu);
	fscanf(t1,"%f",&shui);
	fscanf(t1,"%f",&house);
	fscanf(t1,"%f",&yanglao);
	fscanf(t1,"%f",&yiliaoxian );
	fscanf(t1,"%f",&shiyexian );
	p=(struct shu *)malloc(sizeof(struct shu));
	p->salary=salary;
	strcpy(p->num,num);
	strcpy(p->name ,name);
	p->thsalary =thsalary;
	p->base=base;
	p->bonus =bonus;
	p->qitabutie =qitabutie;
	p->jiangjin =jiangjin;
	p->kouchu =kouchu;
	p->shui =shui;
	p->house =house;
	p->yanglao =yanglao;
	p->yiliaoxian =yiliaoxian;
	p->shiyexian =shiyexian;
	p->next=NULL;
	re->next =p;
	re=p;
	}
	p=ha;
    fclose(t1);
	}
	else
	{	p=x->next ;}
	char nam[20];
	printf("��������Ҫ�޸ĵ�ְ��������");
	scanf("%s",nam);
	while(p!=NULL)
	{
		if(strcmp(p->name,nam)==0)
			break;
		else{
			p=p->next ;
		}
	}
	if(p==NULL){
		printf("��ϵͳû�д�������ְ�����޷��޸�......\n");
		return ;
	}
	else
	{
		printf("--�����ڿ����޸Ĵ�Ա������Ϣ��--\n");
		p->kouchu=0;
		p->thsalary =0;
		printf("������Ա���±�ţ�");
		scanf("%s",p->num );
		printf("\n������Ա����������");
		scanf("%s",p->name );
		printf("\n������Ա���������ʣ�");
		scanf("%f",&p->base );
		p->salary +=p->base;
		printf("\n������Ա����λ������");
		scanf("%f",&p->bonus );
		p->salary +=p->bonus ;
		printf("\n������Ա������������");
		scanf("%f",&p->qitabutie );
		p->salary +=p->qitabutie ;
		printf("\n������Ա������");
		scanf("%f",&p->jiangjin);
		p->salary +=p->jiangjin ;
		printf("\n������Ա��ס��������");
		scanf("%f",&p->house);
		p->kouchu +=p->house;
		printf("\n������Ա�����Ͻ�");
		scanf("%f",&p->yanglao);
		p->kouchu +=p->yanglao ;
		printf("\n������Ա��ҽ�Ʊ��գ�");
		scanf("%f",&p->yiliaoxian );
		p->kouchu +=p->yiliaoxian ;
		printf("\n������Ա��ʧҵ���գ�");
		scanf("%f",&p->shiyexian );
		p->kouchu +=p->shiyexian ;
		p->shui=suodeshui((p->base+p->jiangjin)-(p->kouchu ));
		p->kouchu +=p->shui ;
		p->thsalary =p->salary -p->kouchu;
		if(flag==0)
		    q=x->next;
		else
			q=ha->next;
		t1=fopen("ְ����Ϣ.txt","w");
		if(t1==NULL)
		{
			printf("δ�ܳɹ���ְ����Ϣ�ļ���\n");
		}
		while(q!=NULL)
		{
			fprintf(t1,"%s %s\n",q->num ,q->name);
			fprintf(t1,"%.2f %.2f\n",q->salary,q->thsalary);
			fprintf(t1,"%.2f %.2f %.2f %.2f\n",q->base,q->bonus ,q->qitabutie ,q->jiangjin);
			fprintf(t1,"%.2f\n",q->kouchu );
			fprintf(t1,"%.2f %.2f %.2f %.2f %.2f\n",q->shui,q->house ,q->yanglao,q->yiliaoxian ,q->shiyexian );
			q=q->next ;
		}
		printf("��Ϣ�޸ĳɹ���");
	}
	fclose(t1);
	return ;
}

//��д���Һ�����
void Listfind()
{
	char num[20];
	char name[20];
	float base;
	float bonus;
	float qitabutie;
	float salary;
	float thsalary;
	float kouchu;
	float jiangjin;
	float shui;
	float house;
	float yanglao;
	float yiliaoxian;
	float shiyexian;
	char nu[20],nam[20];
	int aa,flag=0;
	struct shu *p,*q;
	FILE *t1;
	t1=fopen("ְ����Ϣ.txt","r");
	if(t1==NULL){
		printf("ְ����Ϣ�ļ�Ϊ�ջ�δ�ܳɹ���ְ����Ϣ�ļ���\n");
		return ;
	}
	else{
	printf("--------------------\n");
	printf("1.����Ų�ѯ\n2.��������ѯ\n");
	printf("��ѡ��");
	scanf("%d",&aa);
	if(aa==1)
	{
		printf("������Ҫ�����ߵı�ţ�");
		scanf("%s",nu);
		while(fscanf(t1,"%s",num )!=EOF)
	  {
	    fscanf(t1,"%s",name );
	    fscanf(t1,"%f",&salary );
	    fscanf(t1,"%f",&thsalary );
        fscanf(t1,"%f",&base);
	    fscanf(t1,"%f",&bonus);
	    fscanf(t1,"%f",&qitabutie );
	    fscanf(t1,"%f",&jiangjin);
    	fscanf(t1,"%f",&kouchu);
	    fscanf(t1,"%f",&shui);
	    fscanf(t1,"%f",&house);
	    fscanf(t1,"%f",&yanglao);
	    fscanf(t1,"%f",&yiliaoxian );
	    fscanf(t1,"%f",&shiyexian );
		if(strcmp(num ,nu)==0)
		{
			printf("������%s ��ţ�%s\n",num ,name);
		    printf("Ӧ�����ʣ�%.2f ʵ�����ʣ�%.2f\n",salary,thsalary);
		    printf("ְ��������ʣ�%.2f ��λ������%.2f ����������%.2f ����%.2f\n",base,bonus ,qitabutie ,jiangjin);
		    printf("�۳��ܹ�%.2f ������\n",kouchu );
		    printf("����˰��%.2f ס��������%.2f ���Ͻ�%.2f ҽ�Ʊ��գ�%.2f ʧҵ���գ�%.2f\n",shui,house ,yanglao,yiliaoxian ,shiyexian );
		    flag=1;
			break;
		}
		}
		if(flag==0)
			printf("û��Ҫ���ҵ�ְ����\n");
	  }
	  else if(aa==2)
	  {
		  flag=0;
		printf("������Ҫ�����ߵ�������");
		scanf("%s",nam);
		while(fscanf(t1,"%s",num )!=EOF)
	  {
		fscanf(t1,"%s",name );
		fscanf(t1,"%f",&salary );
		fscanf(t1,"%f",&thsalary );
		fscanf(t1,"%f",&base);
		fscanf(t1,"%f",&bonus);
		fscanf(t1,"%f",&qitabutie );
		fscanf(t1,"%f",&jiangjin);
		fscanf(t1,"%f",&kouchu);
		fscanf(t1,"%f",&shui);
		fscanf(t1,"%f",&house);
		fscanf(t1,"%f",&yanglao);
		fscanf(t1,"%f",&yiliaoxian );
		fscanf(t1,"%f",&shiyexian );
		if(strcmp(name ,nam)==0)
		{
			printf("������%s ��ţ�%s\n",num ,name);
		    printf("Ӧ�����ʣ�%.2f ʵ�����ʣ�%.2f\n",salary,thsalary);
		    printf("ְ��������ʣ�%.2f ��λ������%.2f ����������%.2f ����%.2f\n",base,bonus ,qitabutie ,jiangjin);
		    printf("�۳��ܹ�%.2f ������\n",kouchu );
		    printf("����˰��%.2f ס��������%.2f ���Ͻ�%.2f ҽ�Ʊ��գ�%.2f ʧҵ���գ�%.2f\n",shui,house ,yanglao,yiliaoxian ,shiyexian );
			flag=1;
		    break;
		}
		}
		if(flag==0)
			printf("û��Ҫ���ҵ�ְ����\n");
	}
	return ;
	}
}

//��д��Ӻ�����
void Insert()
{
	struct shu *p;
	FILE *t1;
	p=(struct shu *)malloc(sizeof(struct shu));
	p->kouchu=0;
	p->salary =0;
	printf("������Ҫ��ӵ�Ա����ţ�");
	scanf("%s",p->num );
	printf("\n������");
	scanf("%s",p->name );
	printf("\n�������ʣ�");
	scanf("%f",&p->base );
	p->salary +=p->base;
	printf("\n��λ������");
	scanf("%f",&p->bonus );
	p->salary +=p->bonus ;
	printf("\n����������");
	scanf("%f",&p->qitabutie );
	p->salary +=p->qitabutie ;
	printf("\n����");
	scanf("%f",&p->jiangjin);
	p->salary +=p->jiangjin ;
	printf("\nס��������");
	scanf("%f",&p->house);
	p->kouchu +=p->house;
	printf("\n���Ͻ�");
	scanf("%f",&p->yanglao);
	p->kouchu +=p->yanglao ;
	printf("\nҽ�Ʊ��գ�");
	scanf("%f",&p->yiliaoxian );
	p->kouchu +=p->yiliaoxian ;
	printf("\nʧҵ���գ�");
	scanf("%f",&p->shiyexian );
	p->kouchu +=p->shiyexian ;
	p->shui=suodeshui((p->base)-(p->kouchu ));
	p->kouchu +=p->shui ;
	p->thsalary =p->salary -p->kouchu ;
	t1=fopen("ְ����Ϣ.txt","a");
	if(t1==NULL)
	{
		printf("δ�ܳɹ���ְ����Ϣ�ļ���\n");
	}
		fprintf(t1,"%s %s\n",p->num ,p->name);
		fprintf(t1,"%.2f %.2f\n",p->salary,p->thsalary);
		fprintf(t1,"%.2f %.2f %.2f %.2f\n",p->base,p->bonus ,p->qitabutie ,p->jiangjin);
		fprintf(t1,"%.2f\n",p->kouchu );
		fprintf(t1,"%.2f %.2f %.2f %.2f %.2f\n",p->shui,p->house ,p->yanglao,p->yiliaoxian ,p->shiyexian );
	    printf("��Ϣ��ӳɹ���");
	fclose(t1);
	return ;
}
