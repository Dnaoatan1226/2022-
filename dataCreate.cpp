#include<bits/stdc++.h>
using namespace std;
FILE *fp = NULL;
string itos(int i)//������תΪ�ַ��� 
{
	stringstream s;
	s<<i;
	return s.str();
}
class Student
{
	public:
	string studentNum;
	double gradePoint;
	map <int,int> courseTime;	
};
class Course
{
	public:
	Student student[91];
	map <int,int> oftenTruancy;
};
Course course[5];
void writeData(int i,int flag)//����������xsl��txt�ļ� 
{
	if(flag==1)
	{
		fprintf(fp,"%s\t%s","ѧ��","����");
		for(int j=1;j<21;j++)
		{
			fprintf(fp,"\t%s",("��"+itos(j)+"��").c_str());
		} 
		fprintf(fp,"\n");
	}
	for(int j=1;j<91;j++)
	{
		fprintf(fp,"%s\t%lf",(course[i].student[j].studentNum).c_str(),course[i].student[j].gradePoint);
		for(int k=1;k<21;k++)
		{
			fprintf(fp,"\t%d",course[i].student[j].courseTime[k]);
		}
		fprintf(fp,"\n");
	}
}
int main()
{
	srand((unsigned)time(NULL));
	map<int,int> numRepeat1[5];
	map<int,int> numRepeat2[5][91];
	map<int,int> numRepeat3[5][30];
	for(int i=0;i<5;i++)
	{
		for(int j=1;j<91;j++)
		{
			double g=rand()*1.0/RAND_MAX;
			course[i].student[j].gradePoint=1+(4-1)*g;
			course[i].oftenTruancy[j]=0;
			for(int k=1;k<21;k++)
			{
				course[i].student[j].courseTime[k]=0;
			}
			if(j<10)  course[i].student[j].studentNum="032002"+itos(i+1)+"0"+itos(j);
			else  course[i].student[j].studentNum="032002"+itos(i+1)+itos(j);
		}
		int truancyCount=5+rand()%4;
		for(int j=0;j<truancyCount;)// 5-8λ�̶�����û����ѧ�� 
		{
			int tNum;
			tNum=1+rand()%90;
			if(numRepeat1[i][tNum]==0&&course[i].student[tNum].gradePoint<2.0)
			{
				numRepeat1[i][tNum]=1;
				course[i].oftenTruancy[tNum]=1;
				for(int k=0;k<16;)// ȱ����16�ο�
				{
					int t;
					t=1+rand()%20;
					if(numRepeat2[i][tNum][t]==0)
					{
						numRepeat2[i][tNum][t]=1;
						course[i].student[tNum].courseTime[t]=1;
						k++;
					}
				}
				j++;
			}
		}
		for(int j=1;j<21;j++)//ÿ�ſγ̵�ÿ�ολ���0-3λͬѧû�� 
		{
			for(int k=0;k<(0+rand()%4);k++)
			{
				int sn=1+rand()%90;
				if(numRepeat3[i][j][sn]==0)
				{
					if(course[i].oftenTruancy[sn]==0)
					{
						numRepeat3[i][j][sn]=1;
						course[i].student[sn].courseTime[j]=1;
					}
				}
			
			}
		}
	}
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�1.xls","w+");
	writeData(0,1);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�2.xls","w+");
	writeData(1,1);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�3.xls","w+");
	writeData(2,1);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�4.xls","w+");
	writeData(3,1);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�5.xls","w+");
	writeData(4,1);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�1.txt","w+");
	writeData(0,0);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�2.txt","w+");
	writeData(1,0);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�3.txt","w+");
	writeData(2,0);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�4.txt","w+");
	writeData(3,0);
	fp = fopen("C:\\Users\\81980\\Desktop\\��\\�γ�5.txt","w+");
	writeData(4,0);
}
