/***************************************ͷ�ļ�******************************************/
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
/****************************************��*********************************************/
#define N 20 //���Ը������̴�С
/***************************************ȫ�ֱ���*****************************************/
char qipan[N][N];//ȫ�ֱ����������ļ��Ķ�������
int x,y;//����������̣�����)�±�Ϊx���� ��  �±�Ϊy�е�һ������
/***************************************��������*****************************************/
void initQipan();//���̵ĳ�ʼ��
void printQipan();//��ӡ����
void Pos(int x, int y);//���ù��λ��
void startGame();//��Ϸ��ʼ
int panduan(int x,int y);//�ж��Ƿ�������������
int remindgamer(int x,int y);//�ж�Σ���������ʾ
int showreminder();//���Σ�����
int showWhoWin();//���˭Ӯ��
void whitePlay();//�׷�����
void blackPlay();//�ڷ�����
void printShuzi();//��ӡ����ģ��
int step=0;//����
char qiju[N][N][1000];//����Ծ�


/*****************************************�Զ��庯��*************************************/
void Pos(int x, int y)//���ù��λ�ã������￪ʼ���
{
    COORD pos;//��ʾһ���ַ��ڿ���̨��Ļ�ϵ����꣬���Ͻ�(0,0)
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//���ر�׼�����롢����������豸�ľ����Ҳ���ǻ�����롢���/�������Ļ�������ľ��
    SetConsoleCursorPosition(hOutput, pos);
}

void printShuzi()
{
	int i;
	Pos(2,0);
	for(i=0;i<N;i++)
		printf("%2d",i);
	for(i=0;i<N;i++)
	{
		Pos(0,1+i);
		printf("%2d",i);
	}
}
void initQipan()
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			qipan[i][j]='+';
}
void printQipan()
{
	int i,j;
	printShuzi();
	for(i=0;i<N;i++)
	{
		Pos(2,1+i);//�Զ����е�����Ĺ��ܣ�����printf("\n");
		for(j=0;j<N;j++)
			printf(" %c",qipan[i][j]);
	}
}

int  panduan(int x,int y)
{
	char temp;//�������巽����ɫ,w  b
	int count=1;//ͳ�Ƹ���,��Ե�ͬһ���ߣ�ˮƽ�ߣ�
	int i=1;//��һ��
	int j=1;//��iͬʱ����������б��
	int whoWin=0;//1����׷���2����ڷ�
	temp=qipan[x][y];
	//ˮƽ�����
	while(temp==qipan[x][y-i]&&x>=0&&x<N&&y>=0&&y<N&&count<5)
	{
		i++;
		count++;
		if(count==5)//����count��5�������ж�˭Ӯ��
		{
			if(temp=='o')
				whoWin=1;

			else
				whoWin=2;
		}
	}
	//ˮƽ���ұ�
	i=1;
   while(temp==qipan[x][y+i]&&x>=0&&x<N&&y>=0&&y<N&&count<5)
	{
		i++;
		count++;
		if(count==5)//����count��5�������ж�˭Ӯ��
		{
			if(temp=='o')
				whoWin=1;

			else
				whoWin=2;
		}
	}

   //�����ֱ�ķ���
   //��ֱ�Ϸ�
   i=1;
   count=1;//�����֮ǰ������
   while(temp==qipan[x-i][y]&&x>=0&&x<N&&y>=0&&y<N&&count<5)
	{
		i++;
		count++;
		if(count==5)//����count��5�������ж�˭Ӯ��
		{
			if(temp=='o')
				whoWin=1;

			else
				whoWin=2;
		}
	}
   //��ֱ�·�
   i=1;
   while(temp==qipan[x+i][y]&&x>=0&&x<N&&y>=0&&y<N&&count<5)
	{
		i++;
		count++;
		if(count==5)//����count��5�������ж�˭Ӯ��
		{
			if(temp=='o')
				whoWin=1;

			else
				whoWin=2;
		}
	}
   //������ϵ�б��  �Ϸ�
	 i=1;
	 j=1;
	 count=1;
   while(temp==qipan[x-i][y-j]&&x>=0&&x<N&&y>=0&&y<N&&count<5)
	{
		i++;
		j++;
		count++;
		if(count==5)//����count��5�������ж�˭Ӯ��
		{
			if(temp=='o')
				whoWin=1;

			else
				whoWin=2;
		}
	}
   //������ϵ�б��  �·�
	 i=1;
	 j=1;
   while(temp==qipan[x+i][y+j]&&x>=0&&x<N&&y>=0&&y<N&&count<5)
	{
		i++;
		j++;
		count++;
		if(count==5)//����count��5�������ж�˭Ӯ��
		{
			if(temp=='o')
				whoWin=1;

			else
				whoWin=2;
		}
	}
   //������ϵ�б��  �Ϸ�
	 i=1;
	 j=1;
	 count=1;
   while(temp==qipan[x-i][y+j]&&x>=0&&x<N&&y>=0&&y<N&&count<5)
	{
		i++;
		j++;
		count++;
		if(count==5)//����count��5�������ж�˭Ӯ��
		{
			if(temp=='o')
				whoWin=1;

			else
				whoWin=2;
		}
	}
   //������ϵ�б��  �·�
	 i=1;
	 j=1;
   while(temp==qipan[x+i][y-j]&&x>=0&&x<N&&y>=0&&y<N&&count<5)
	{
		i++;
		j++;
		count++;
		if(count==5)//����count��5�������ж�˭Ӯ��
		{
			if(temp=='o')
				whoWin=1;

			else
				whoWin=2;
		}
	}
	return whoWin;
}
int remindgamer(int x,int y)
{
    char remind;
    int count = 1;
    int i = 1;
    int j = 1;
    int reminder = 0;
    remind = qipan[x][y];
    //ˮƽ����߳������������
    while(remind==qipan[x][y-1-i]&&x>=1&&x<N&&y>=0&&y<N&&count<3)
    {
        i++;
        count++;
        if(count = 3)
        {
            if (remind == 'o')
                reminder = 1;

            else
                reminder = 2;

        }
    }
    i = 1;
    while(remind==qipan[x][y+i]&&x>=1&&x<N&&y>=0&&y<N&&count<3)
    {
        i++;
        count++;
        if(count = 3)
        {
            if (remind == 'o')
                reminder = 3;

            else
                reminder = 4;

        }
    }
    return reminder;
}
int showreminder()
{
    int jumpnumber;
    jumpnumber = remindgamer(x,y);
    if(jumpnumber == 1)
    {
        system("cls");
        printQipan();
        printf("\n���ģ����Ӵ������Ѿ�������\n");
        system("pause");
    }
    if(jumpnumber==2)
    {
        system("cls");
        printQipan();
        printf("\n���ģ����Ӵ������Ѿ�������\n");
        system("pause");
    }
        if(jumpnumber==2)
    {
        system("cls");
        printQipan();
        printf("\n���ģ����Ӵ������Ѿ�������\n");
        system("pause");
    }
        if(jumpnumber==2)
    {
        system("cls");
        printQipan();
        printf("\n���ģ����Ӵ������Ѿ�������\n");
        system("pause");
    }

}
int showWhoWin()
{
	int overLeap=0;//1�������
	int leap;//��������˭Ӯ��
	leap=panduan(x,y);
	if(leap==1)
	{
	    overLeap=1;
		system("cls");
		printQipan();
		printf("\n�׷�ʤ��\n");
		system("pause");
	}
	if(leap==2)
	{
		overLeap=1;
		system("cls");
		printQipan();
		printf("\n�ڷ�ʤ��\n");
		system("pause");
	}
	return overLeap;
}

void whitePlay()
{
	printf("\n��׷����ӣ����������е�����:");
	scanf("%d%d",&x,&y);//�����ֵ
	while(1)//���һֱ�´��ӵ�����
	{
		if(qipan[x][y]=='+')//���ӵĵط�û��������
		{
		     qipan[x][y]='o';
			 //���while(1)
			 break;
		}
		else
		{
			printf("�����Ӵ���\n");
		    printf("��׷����ӣ����������е�����:");
			scanf("%d%d",&x,&y);//�����ֵ
		}

	}
	printQipan();

}
void blackPlay()
{

	printQipan();
	printf("\n��ڷ����ӣ����������е�����:");
	scanf("%d%d",&x,&y);//�����ֵ
		while(1)//���һֱ�´��ӵ�����
	{
		if(qipan[x][y]=='+')//���ӵĵط�û��������
		{
		     qipan[x][y]='*';
			 //���while(1)
			 break;
		}
		else
		{
			printf("�����Ӵ���\n");
		    printf("��ڷ����ӣ����������е�����:");
		}
		scanf("%d%d",&x,&y);//�����ֵ

	}
	printQipan();

}
void chucun(s)
{
    int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			qiju[i][j][s]=qipan[i][j];
}

void duqu(s)
{
    int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			qipan[i][j]=qiju[i][j][s];
}

void startGame()
{
	initQipan();
	printQipan();

	while(1)
	{
        chucun(step);
        whitePlay();
        step++;
        chucun(step);
        showreminder();//system("pause");
		if(showWhoWin()==1)//system("pause");
		     break;
	    system("cls");//������Ļ,����Ļ�ϵ��ֲ��ظ�
		blackPlay();
        step++;
        showreminder();//system("pause");
		if(showWhoWin()==1)//system("pause");
		     break;
		system("cls");
	    printQipan();

	}
	printf("���Ƿ�������Ϸ:y  or n");
    Tag:
        if(getch()=='n')
        {
            system("cls");
            printf("��Ϸ����\n");
            //exit(0);//��Ϊ������ֹ
        }
        if(getch()=='y')
        {
            system("cls");
            startGame();
        }
        printf("�Ƿ��ȡ���:y  or  n");
        if(getch()=='n')
        {
            system("cls");
            printf("��Ϸ����\n");
            exit(0);//��Ϊ������ֹ
        }
        if(getch()=='y')
        {
            int s;
            system("cls");
            printf("�������ȡ����:");
            scanf("%d",&s);
            duqu(s);
            printQipan();
            goto Tag;
        }

}

/*********************************************������************************************/
int main()
{
	startGame();

	return 0;
}












