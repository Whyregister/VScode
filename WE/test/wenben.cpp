#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"conio.h" 
#define Link_Size 80 
int NUM,N,C,ROW;
typedef struct list
{
    char data[80];
    int length;
	int row;
    struct list *next;
    struct list *pre;
} LinkList;
LinkList *head;
LinkList *CreatWord()
{
	ROW=0;
    LinkList *temp;
    char ch;
    int i,j;
    head->next=(LinkList *)malloc(sizeof(LinkList));
    head->pre=NULL;
    temp=head->next;
    temp->pre=NULL;
    temp->length=0;
    for(i=0;i<80;i++)
    temp->data[i]='\0';
printf("开始创建文本，请输入文章（输入#号结束）:\n");
for(j=0;j<Link_Size;j++)
{
     for(i=0;i<80;i++)
     {
        ch=getchar();
        temp->data[i]=ch;
        temp->length++;
        if(temp->data[i] =='\n')
              ROW++;
        if(ch=='#')
           {
             NUM=j;
             break;
           }
     }
     if(ch=='#')
     {
        temp->length=i;
        temp->next=NULL;
        break;
     }
     temp->next=(LinkList *)malloc(sizeof(LinkList));
     temp->next->pre=temp;
     temp=temp->next;
     for(i=0;i<80;i++)
     temp->data[i]='\0';
}
temp->row=NUM+1;
system("cls");
return temp;
}
LinkList *open()
{
	FILE *fp;
    ROW=0;
    LinkList *temp;
    char ch;
    int i;
	char filename[20];
	system("cls");
	printf("输入文件名(例如：d:\\\\text.txt)\n");
	scanf("%s",filename);
	fp=fopen("filename","r+");
	if(!fp)
		return NULL;
		while(fp!=EOF){
     for(i=0;i<80;i++)
     {
        ch=fgetc(fp);
        temp->data[i]=ch;
        temp->length++;
        if(temp->data[i] =='\n')
              ROW++;
     }
     temp->next=(LinkList *)malloc(sizeof(LinkList));
     temp->next->pre=temp;
     temp=temp->next;
     for(i=0;i<80;i++)
     temp->data[i]='\0';
}   temp->row=NUM+1;
    printf("打开成功\n");
	printf("\n请按回车键继续");	
    fclose(fp);
    return temp;
}
void filemenu(temp)
{
	int t,i; 
	FILE *fp;
	LinkList *p; 
	while(1)
  {
  printf("\n");
  system("cls");   
  printf("                   文本编辑器           \n");
  printf("              文本操作菜单              \n");
  printf("         1、另存为            \n");
  printf("         2、打开文件        \n");
  printf("         3、保存文件                \n");
  printf("         4、返回主菜单           \n");
  printf("请选择操作:");
  scanf("%d",&t);
  switch(t)
  {
  case 1:   saves(temp);
			getch(); 
	        break;
  case 2:   temp=open();
            printf("请按任意键继续");
            getch();
			break;
  case 3:   save(temp);
			break;
  case 4:break;
  default:printf("请输入正确选项\n");
          printf("请按任意键继续");
            getch();
            break; 
 }
  if(t==4)   
  {system("cls");  break;}
}}
void PrintWord()
{
	int i,j;
	LinkList *p;
	p=head->next;
	system("cls"); 
	printf("\n当前文章的内容是:");
	for(j=0;j<=NUM&&p!=NULL;j++)
	{
		for(i=0;(i<80)&&(p->data[i])!='#';i++)
			printf("%c",p->data[i]);
		p=p->next;
	}
	printf("\n当前文章的行数是:%d",ROW);
}
void CountWord()
{
  LinkList *temp;
  char ch;
  int i,j,t;
  int WORD=0,word=0,space=0,num=0,punct=0,sum=0;
  temp=head->next;
  for(j=0;j<=NUM;j++)
  {
	 for(i=0;(i<80)&&(temp->data[i])!='#';i++)
	 {
		 ch=temp->data[i];
		 if((ch>='A')&&(ch<='Z'))
			 WORD++;
		 else if((ch>='a')&&(ch<='z'))
			 word++;
		 else if((ch>='0')&&(ch<='9'))
			 num++;
		 else if(ch==' ')
			 space++;
		 else if(ch==33||ch==34||ch==39||ch==44||ch==46||ch==58||ch==59||ch==63)
		     punct++;
     }
	 sum=WORD+word+num;
	 }
  while(1)
  {
  printf("\n");
  system("cls");   
  printf("                   文本编辑器           \n");
  printf("              文章内容统计菜单              \n");
  printf("         1、文章中大写字母的个数            \n");
  printf("         2、文章中小写字母的个数            \n");
  printf("         3、文章中数字的个数                \n");
  printf("         4、文章中标点符号的个数            \n");
  printf("         5、文章中空格的个数                \n");
  printf("         6、文章中所有字数                  \n");
  printf("         7、退出返回主菜单                  \n");
  printf("请选择需统计项目:");
  scanf("%d",&t);
  switch(t)
  {
  case 1:
	  system("cls"); 
	  printf("\n\t\t文章中大写字母的个数:%d\n",WORD);
	  printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
	  break;
  case 2:
	  system("cls"); 
	  printf("\n\t\t文章中小写字母的个数:%d\n",word);
	  printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
			break;
  case 3:
	  system("cls"); 
	  printf("\n\t\t文章中数字的个数:%d\n",num);
	  printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
			break;
  case 4:
	  system("cls"); 
	  printf("\n\t\t文章中标点符号的个数:%d\n",punct);
	  printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
	  break;
  case 5:
	  system("cls"); 
	  printf("\n\t\t文章中空格的个数:%d\n",space);
	  printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
	  break;
  case 6:
	  system("cls"); 
	  printf("\n\t\t文章中所有字数:%d\n",sum);
	  printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
	  break;
  }
  if(t==7)   
  {system("cls");  break;}
  }
}
void SearchWord(char *str1,LinkList* temp)          
{ 
    char Data[20] ; 
    int i,j,k=0,sum=0,C;
	int l=1;
    temp=head->next; 
    strcpy(Data,str1);
    for(i=0;i<=NUM;i++) 
    { 
        for(j=0;j<80;j++) 
        { 
            if((temp->data[j])==Data[k]) k++;
            else if(Data[k]!='\0')
			{
				j=j-k;
				k=0;
			} 
            if(Data[k]=='\0') 
			{
			sum++;
			j=j-k+1;
			printf("\t\t第%d次出现在第%d行第%d列\n",l,i+1,j+1);
			l++;
			k=0;
			continue;} 
        } 
        temp=temp->next; 
    } 
    printf("\t\t\t字符串总共出现次数为:%d\n\n",sum); 
    C=sum;	
	N=i*80+j;
} 
void DeleteWord(char *str2)                    
{	char Data[20];
    LinkList *temp,*term; 
int i,j,k,m,y,num;
     strcpy(Data,str2);
    for(y=0;y<C;y++) 
    { 
		num=80;
		k=0,m=0; 
		temp=head; 
		for(i=0;i<=NUM;i++) 
		{ 
			term=temp; 
			temp=temp->next; 
			for(j=0;j<80;j++) 
			{ 
				if((temp->data[j])==Data[k]) k++; 
				else if(Data[k]!='\0') {j=j-k;k=0;} 
				if(Data[k]=='\0') 
				{
					num=j;
					break;
				} 
			} 
			if(num<80) break; 
		} 
		for(;i<=NUM;i++) 
		{ 
			for(;j<80;j++) 
			{ 
				if(j+1<k) 
					term->data[80-k+num]=temp->data[j+1]; 
				else
					temp->data[j-k+1]=temp->data[j+1]; 
			} 
			term=temp; 
               temp=temp->next;
		         j=0; 
		} 
    } 
}
char *strrpc(char *str,char *oldstr,char *newstr,int *count){
	int i;
    char bstr[strlen(str)];//转换缓冲区
    memset(bstr,0,sizeof(bstr));
    for(i = 0;i < strlen(str);i++){
        if(!strncmp(str+i,oldstr,strlen(oldstr))){//查找目标字符串
            strcat(bstr,newstr);
            i += strlen(oldstr) - 1;
            (*count)++;
        }else
          	strncat(bstr,str + i,1);//保存一字节进缓冲区
    }
    strcpy(str,bstr);
    return str;
}
LinkList * Replaceword(LinkList *temp)
{
	char *sour=(char *)malloc(sizeof(char)*80);
	char *des=(char *)malloc(sizeof(char)*80);
	int *count=(int *)malloc(sizeof(int)) ;
	*count=0;
	LinkList *head=temp;
	fflush(stdin);
	printf("请输入源字符串:");
	scanf("%s",sour);
    printf("\n请输入目的字符串:");
    scanf("%s",des);
    while(temp)
    {
    	strcpy(temp->data,strrpc(temp->data,sour,des,count));
    	temp=temp->next;
	}
	head->length-=(*count)*(strlen(sour)-strlen(des));	
	temp=head;
	while(temp->data==NULL)
	{
		(head->row)--;
		head=head->next;
		temp=temp->next;
	}
		temp=head;
		while(temp)
		{
			if(temp->next&&temp->next->data==NULL)
				temp->next=temp->next->next;
			else
				temp=temp->next;
		}
	return head;	
}
LinkList * MoveWord(LinkList *temp)
{
	int row,pos,i;
	char *s=(char *)malloc(sizeof(char)*80);
	LinkList *h=temp;
	printf("请输入要移动的字符串,其所在行,要移动到的位置，用空格隔开\n"); 
	fflush(stdin);
	scanf("%s %d %d",s,&row,&pos);
	if(row<0||row>temp->length)
	{
		printf("行号有误！");
		return temp; 
	}
	while(--row>0)
		h=h->next;
	if(strstr(h->data,s)==NULL)
	{
			printf("该行不含此字符串！");
			return temp; 
	}
	else
	{
		if(strlen(h->data)<strlen(s)+pos-1||pos<1)
		{
			printf("输入位置有误！");
			return temp;
		}
		else
		{
			char *tem=strstr(h->data,s);
			int p=-((&(h->data[0]))-(&(*tem)));
			if(p==pos)
				return temp;
			else if(p>pos)
			{
				char tem[p-pos];
				for( i=0;i<p-pos;i++)
					tem[i]=h->data[pos+i];
				tem[p-pos]='\0';
				for(i=0;i<=strlen(s);i++)
					h->data[pos+i]=s[i];
				for(i=0;i<p-pos;i++)
					h->data[pos+strlen(s)+i]=tem[i];
				return temp;
			}
		}
	}
 } 
LinkList * InsertWord(char *str1,LinkList *temp)
{   
    int h,q;
	printf("\n\t\t当前文章内容为:");
	PrintWord();
	printf("\n\t\t请输入要插入的行:");
	scanf("%d",&h);
	printf("\n\t\t请输入要插入的列:");
	scanf("%d",&q);
    int i=(h-1)*80+q;
    LinkList *a;
	int n=strlen(str1);
	int m ;
	int insertRow=i/80+1;
	int row=temp->row;
	int j;
	if(insertRow==row)
	{	
		for(m=temp->length-1;m>=(i%80)&&n>0;m--)
			temp->data[m+n]=temp->data[m];	
		for(m=(i%80),j=0;m<n+(i%80);m++,j++)
			temp->data[m]=str1[j];		
	} 
	else
	{	
		int r=0,p;
		for(p=insertRow; p<row;p++)
		{
			if(p == insertRow) 
			   r=0;
			 else
				r=n;
			for(m=temp->length-1-r;m>=0&&n>0;m--)
			temp->data[m+n]=temp->data[m];
			a=temp;	
			temp = temp->pre;
			temp->length = 80;
			for(m = temp->length-n,j=0;m<temp->length;m++,j++)
				a->data[j]=temp->data[m];
		}
		for(m=temp->length-n-1;m>=(i%80);m--) 
			temp->data[m+n]=temp->data[m];
		for(m=(i%80),j=0;m<(i%80)+n;m++,j++) 
			temp->data[m] =str1[j];
		}
	return temp;
}
void menu(LinkList *temp)
{
    char str1[20], str2[20], str3[20], str4[20];
	int a,t;
do{
system("cls"); 
printf("               文本编辑器           \n");
printf("\n");
printf("                 主菜单                     \n");
printf("        0、文件操作菜单                        \n");
printf("        1、文章内容输入                     \n");
printf("        2、显示当前文章                 \n");
printf("        3、进入文章内容统计菜单             \n");
printf("        4、查找字符串           \n");
printf("        5、删除字符串           \n");
printf("        6、插入字符串           \n");
printf("        7、替换字符串           \n");
printf("        8、移动字符串           \n");
printf("        9、结束\n");
printf("    请选择:");
scanf("%d",&t);
if((t>8)&&(t<1))  
	printf("无此功能，请输入正确的功能序号!\n");
else
switch(t)
{  
    case 0:
	         system("cls"); 
	         filemenu(temp);
	         break;
    case 1:  
		     system("cls"); 
		     temp=CreatWord();
             break;
    case 2:  
		     system("cls"); 
             PrintWord();
			 printf("\n");
			 printf("按回车键继续");
			 getchar();
			 getchar();
			 system("cls");
			 break;
	case 3:
		     system("cls");
		     CountWord();
			 break;
	case 4:
			system("cls"); 
	        printf("\t\t\t请输入您需要查找的字符或字符串:");
            getchar();
            gets(str1);
            SearchWord(str1,temp);
		    printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
		    break;
	case 5:
	       system("cls"); 
	       printf("\t\t\t请输入您需要删除的字符或字符串:");
           getchar();
           gets(str2);
           SearchWord(str2,temp);
           DeleteWord(str2);
           printf("\t\t\t删除 %s 后的文章为:",str2);
           PrintWord();
		   printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
		   break;
	case 6:
	       system("cls"); 
	       printf("\n\t\t请输入要插入的字符或字符串:");
	       getchar();
	       gets(str1);
           InsertWord(str1,temp);
           printf("\t\t\t插入字符或字符串后文章为:");
           PrintWord();
		   printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
		   break;
	case 7:
	        system("cls"); 
	        temp=  Replaceword(temp);
		    printf("\t\t\t替换字符或字符串后文章为:");
            PrintWord();
		    printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
		   break;
    case 8:
    	 system("cls"); 
	       MoveWord(temp);
	        fflush(stdin); 
	        getchar();
	        printf("\t\t\t移动后的文章为:");
            PrintWord();
		    printf("\n按回车键继续");
			getchar();
			getchar();
			system("cls");
		   break;
}
if(t==9) exit(0);
}while(1);
}
void save(LinkList *temp)
{
	FILE *fp;
	LinkList *q;
	char filename[20];
	q=temp;
	system("cls");
	printf("输入文件名(例如：d:\\\\text.txt)\n");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	if(!fp)
	{
		printf("\n打开文件错误\n");
		getchar();
		return ;
	}
	do{
	fputs(q->data,fp);
	q=q->next;		
	}while(q);
	printf("保存成功\n");
	printf("\n按回车键继续");
	getchar();
	getchar();
	fclose(fp);
}
void saves(LinkList *temp)
{
	FILE *fp;
	LinkList *q;
	char filename[20];
	q=temp;
	system("cls");
	printf("输入文件名(例如：d:\\\\text.txt)\n");
	scanf("%s",filename);
	fp=fopen(filename,"w+");
		if(!fp)
	{
		printf("\n打开文件错误\n");
		getchar();
		return ;
	}
	do{
	fputs(q->data,fp);
	q=q->next;		
	}while(q);
	printf("保存成功\n");
	printf("\n按回车键继续");
	getchar();
	getchar();
	fclose(fp);
}

int main()
{
head=(LinkList *)malloc(sizeof(LinkList));
LinkList *temp;
menu(temp);
return  0;
}