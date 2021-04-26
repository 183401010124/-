//头文件说明；
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<conio.h>
#include<string.h>

//定义全局变量；
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

//所得税计算
float suodeshui(float x);

//定义输入函数；
struct shu *Creatlist();

//定义显示函数；
void Printlist();

//定义修改函数；
void Modify(struct shu *x);

//定义查找函数；
void Listfind();

//定义添加函数；
void Insert();


//释放空间
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


//主函数结构如下：
int main()
{
   char i;
   struct shu *p,*head;
   head=(struct shu *)malloc(sizeof(struct shu));
   head=NULL;
   for( ; ;)     //循环执行功能菜单
  {
    clrscr();  //清屏幕
    printf("* * * * * *i菜单* * * * * * *\n");
    printf("*          a. 输入          *\n");
    printf("*          b. 显示          *\n");
    printf("*          c. 修改          *\n");
    printf("*          d. 查找          *\n");
    printf("*          e. 添加          *\n");
    printf("*          f. 退出          *\n");
    printf("*          输入a--f         *\n");
    printf("* * * * * * * * * * * * * * *\n");
    i=getch();
    if(i=='f') break;
    else switch(i)
    {
     case 'a': head=Creatlist();break;//调用输入函数
     case 'b': Printlist();system("pause");break;//调用显示函数
     case 'c': p=head;Modify(p);system("pause");break;//调用修改函数
     case 'd': Listfind();system("pause");break;//调用查找函数
     case 'e': Insert();system("pause");break;//调用添加函数
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

//编写输入函数：
struct shu *Creatlist()
{
	struct shu *p,*ha,*re;
	FILE *t1;
	int flag=2;
	t1=fopen("职工信息.txt","w");
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
		printf("请输入员工编号：");
		scanf("%s",p->num );
		printf("\n姓名：");
		scanf("%s",p->name );
		printf("\n基本工资：");
		scanf("%f",&p->base );
		p->salary +=p->base;
		printf("\n岗位津贴：");
		scanf("%f",&p->bonus );
		p->salary +=p->bonus ;
		printf("\n其他补贴：");
		scanf("%f",&p->qitabutie );
		p->salary +=p->qitabutie ;
		printf("\n奖金：");
		scanf("%f",&p->jiangjin);
		p->salary +=p->jiangjin ;
		printf("\n住房公基金：");
		scanf("%f",&p->house);
		p->kouchu +=p->house;
		printf("\n养老金：");
		scanf("%f",&p->yanglao);
		p->kouchu +=p->yanglao ;
		printf("\n医疗保险：");
		scanf("%f",&p->yiliaoxian );
		p->kouchu +=p->yiliaoxian ;
		printf("\n失业保险：");
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
		printf("是否结束职工信息的输入？ 1：是 2：否\n");
		scanf("%d",&flag);
	}
	fclose(t1);
	return ha;
}

//所得税计算：
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

//编写显示函数：
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
	t1=fopen("职工信息.txt","r");
	if(t1==NULL)
	{
		printf("未成功打开职工信息文件！\n");
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
	printf("编号：%s\n姓名：%s\n",num ,name);
	printf("应发工资：%.2f 实发工资：%.2f\n",salary,thsalary);
	printf("职务基本工资：%.2f 岗位津贴：%.2f 其他补贴：%.2f 奖金：%.2f\n",base,bonus ,qitabutie ,jiangjin);
	printf("扣除总共%.2f 包括：\n",kouchu );
	printf("所得税：%.2f 住房公基金：%.2f 养老金：%.2f 医疗保险：%.2f 失业保险 ： %.2f\n",shui ,house ,yanglao,yiliaoxian ,shiyexian );
	printf("\n");
	}
	fclose(t1);
	return ;
}

//编写修改函数：
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
	t1=fopen("职工信息.txt","a+");
	if(t1==NULL)
	{
		printf("未成功打开职工信息文件！\n");
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
	printf("请输入你要修改的职工姓名：");
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
		printf("该系统没有此姓名的职工，无法修改......\n");
		return ;
	}
	else
	{
		printf("--你现在可以修改此员工的信息了--\n");
		p->kouchu=0;
		p->thsalary =0;
		printf("请输入员工新编号：");
		scanf("%s",p->num );
		printf("\n请输入员工新姓名：");
		scanf("%s",p->name );
		printf("\n请输入员工基本工资：");
		scanf("%f",&p->base );
		p->salary +=p->base;
		printf("\n请输入员工岗位津贴：");
		scanf("%f",&p->bonus );
		p->salary +=p->bonus ;
		printf("\n请输入员工其他补贴：");
		scanf("%f",&p->qitabutie );
		p->salary +=p->qitabutie ;
		printf("\n请输入员工奖金：");
		scanf("%f",&p->jiangjin);
		p->salary +=p->jiangjin ;
		printf("\n请输入员工住房公基金：");
		scanf("%f",&p->house);
		p->kouchu +=p->house;
		printf("\n请输入员工养老金：");
		scanf("%f",&p->yanglao);
		p->kouchu +=p->yanglao ;
		printf("\n请输入员工医疗保险：");
		scanf("%f",&p->yiliaoxian );
		p->kouchu +=p->yiliaoxian ;
		printf("\n请输入员工失业保险：");
		scanf("%f",&p->shiyexian );
		p->kouchu +=p->shiyexian ;
		p->shui=suodeshui((p->base+p->jiangjin)-(p->kouchu ));
		p->kouchu +=p->shui ;
		p->thsalary =p->salary -p->kouchu;
		if(flag==0)
		    q=x->next;
		else
			q=ha->next;
		t1=fopen("职工信息.txt","w");
		if(t1==NULL)
		{
			printf("未能成功打开职工信息文件！\n");
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
		printf("信息修改成功！");
	}
	fclose(t1);
	return ;
}

//编写查找函数：
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
	t1=fopen("职工信息.txt","r");
	if(t1==NULL){
		printf("职工信息文件为空或未能成功打开职工信息文件！\n");
		return ;
	}
	else{
	printf("--------------------\n");
	printf("1.按编号查询\n2.按姓名查询\n");
	printf("请选择：");
	scanf("%d",&aa);
	if(aa==1)
	{
		printf("请输入要查找者的编号：");
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
			printf("姓名：%s 编号：%s\n",num ,name);
		    printf("应发工资：%.2f 实发工资：%.2f\n",salary,thsalary);
		    printf("职务基本工资：%.2f 岗位津贴：%.2f 其他补贴：%.2f 奖金：%.2f\n",base,bonus ,qitabutie ,jiangjin);
		    printf("扣除总共%.2f 包括：\n",kouchu );
		    printf("所得税：%.2f 住房公基金：%.2f 养老金：%.2f 医疗保险：%.2f 失业保险：%.2f\n",shui,house ,yanglao,yiliaoxian ,shiyexian );
		    flag=1;
			break;
		}
		}
		if(flag==0)
			printf("没有要查找的职工！\n");
	  }
	  else if(aa==2)
	  {
		  flag=0;
		printf("请输入要查找者的姓名：");
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
			printf("姓名：%s 编号：%s\n",num ,name);
		    printf("应发工资：%.2f 实发工资：%.2f\n",salary,thsalary);
		    printf("职务基本工资：%.2f 岗位津贴：%.2f 其他补贴：%.2f 奖金：%.2f\n",base,bonus ,qitabutie ,jiangjin);
		    printf("扣除总共%.2f 包括：\n",kouchu );
		    printf("所得税：%.2f 住房公基金：%.2f 养老金：%.2f 医疗保险：%.2f 失业保险：%.2f\n",shui,house ,yanglao,yiliaoxian ,shiyexian );
			flag=1;
		    break;
		}
		}
		if(flag==0)
			printf("没有要查找的职工！\n");
	}
	return ;
	}
}

//编写添加函数：
void Insert()
{
	struct shu *p;
	FILE *t1;
	p=(struct shu *)malloc(sizeof(struct shu));
	p->kouchu=0;
	p->salary =0;
	printf("请输入要添加的员工编号：");
	scanf("%s",p->num );
	printf("\n姓名：");
	scanf("%s",p->name );
	printf("\n基本工资：");
	scanf("%f",&p->base );
	p->salary +=p->base;
	printf("\n岗位津贴：");
	scanf("%f",&p->bonus );
	p->salary +=p->bonus ;
	printf("\n其他补贴：");
	scanf("%f",&p->qitabutie );
	p->salary +=p->qitabutie ;
	printf("\n奖金：");
	scanf("%f",&p->jiangjin);
	p->salary +=p->jiangjin ;
	printf("\n住房公基金：");
	scanf("%f",&p->house);
	p->kouchu +=p->house;
	printf("\n养老金：");
	scanf("%f",&p->yanglao);
	p->kouchu +=p->yanglao ;
	printf("\n医疗保险：");
	scanf("%f",&p->yiliaoxian );
	p->kouchu +=p->yiliaoxian ;
	printf("\n失业保险：");
	scanf("%f",&p->shiyexian );
	p->kouchu +=p->shiyexian ;
	p->shui=suodeshui((p->base)-(p->kouchu ));
	p->kouchu +=p->shui ;
	p->thsalary =p->salary -p->kouchu ;
	t1=fopen("职工信息.txt","a");
	if(t1==NULL)
	{
		printf("未能成功打开职工信息文件！\n");
	}
		fprintf(t1,"%s %s\n",p->num ,p->name);
		fprintf(t1,"%.2f %.2f\n",p->salary,p->thsalary);
		fprintf(t1,"%.2f %.2f %.2f %.2f\n",p->base,p->bonus ,p->qitabutie ,p->jiangjin);
		fprintf(t1,"%.2f\n",p->kouchu );
		fprintf(t1,"%.2f %.2f %.2f %.2f %.2f\n",p->shui,p->house ,p->yanglao,p->yiliaoxian ,p->shiyexian );
	    printf("信息添加成功！");
	fclose(t1);
	return ;
}
