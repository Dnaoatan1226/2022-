#include<bits/stdc++.h>
using namespace std;
FILE *fp = NULL;
string itos(int i)//将整形转为字符串 
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
void writeData(int i,int flag)//将数据生成xsl和txt文件 
{
	if(flag==1)
	{
		fprintf(fp,"%s\t%s","学号","绩点");
		for(int j=1;j<21;j++)
		{
			fprintf(fp,"\t%s",("第"+itos(j)+"节").c_str());
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
		for(int j=0;j<truancyCount;)// 5-8位固定经常没来的学生 
		{
			int tNum;
			tNum=1+rand()%90;
			if(numRepeat1[i][tNum]==0&&course[i].student[tNum].gradePoint<2.0)
			{
				numRepeat1[i][tNum]=1;
				course[i].oftenTruancy[tNum]=1;
				for(int k=0;k<16;)// 缺了哪16次课
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
		for(int j=1;j<21;j++)//每门课程的每次课还有0-3位同学没来 
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
	fp = fopen("filepath\\课程1.xls","w+");//输入想要文件生成的位置，例：C:\\Users\\81980\\Desktop\\软工\\课程1.xls
	writeData(0,1);
	fp = fopen("filepath\\课程2.xls","w+");
	writeData(1,1);
	fp = fopen("filepath\\课程3.xls","w+");
	writeData(2,1);
	fp = fopen("filepath\\课程4.xls","w+");
	writeData(3,1);
	fp = fopen("filepath\\课程5.xls","w+");
	writeData(4,1);
	fp = fopen("filepath\\课程1.txt","w+");
	writeData(0,0);
	fp = fopen("filepath\\课程2.txt","w+");
	writeData(1,0);
	fp = fopen("filepath\\课程3.txt","w+");
	writeData(2,0);
	fp = fopen("filepath\\课程4.txt","w+");
	writeData(3,0);
	fp = fopen("filepath\\课程5.txt","w+");
	writeData(4,0);
}
