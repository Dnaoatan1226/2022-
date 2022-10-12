#include<bits/stdc++.h>
using namespace std;
string itos(int i)//将整形转为字符串 
{
	stringstream s;
	s<<i;
	return s.str();
}
class Student
{
	public:
	char studentNum[50];
	double gradePoint;
	map <int,int> courseTime;	
	map <int,int> callTheRoll;
};
class Course
{
	public:
	Student student[91];
	void readIn();
	void writeCall();
};
FILE *fp;
Course course[5];
void Course::readIn()//读取课程数据 
{
	for(int j=1;j<91;j++)
	{
		fscanf(fp,"%s ",&student[j].studentNum);
		fscanf(fp,"%lf ",&student[j].gradePoint);
		for(int k=1;k<21;k++)
		{
			fscanf(fp,"%d ",&student[j].courseTime[k]);
		}
	}
}
void Course::writeCall()//输出点名方案的.xls文件 
{
	fprintf(fp,"%s\t%s","学号","绩点");
	for(int j=1;j<21;j++)
	{
		fprintf(fp,"\t%s",("第"+itos(j)+"节").c_str());
	} 
	fprintf(fp,"\n");
	for(int j=1;j<91;j++)
	{
		fprintf(fp,"%s\t%lf",student[j].studentNum,student[j].gradePoint);
		for(int k=1;k<21;k++)
		{
			fprintf(fp,"\t%d",student[j].callTheRoll[k]);
		}
		fprintf(fp,"\n");
	}
}
double getE()
{
	int requestCount=0,goodRequestCount=0,count;
	int truancyNum[20][50];
	map<int,int> wrongPeople; 
	for(int i=0;i<5;i++)
	{
		count=0;
		for(int j=1;j<21;j++)
		{
			if(j==1)
			{
				for(int k=1;k<91;k++)
				{
					if(course[i].student[k].gradePoint<2.0)
					{
						requestCount++;
						course[i].student[k].callTheRoll[j]=1;
						if(course[i].student[k].courseTime[j]==1)
						{
							goodRequestCount++;
							truancyNum[i][count++]=k;
						}
					}
				
				}
			}
			else 
			{
				for(int k=0;k<count;k++)
				{
					if(truancyNum[i][k]!=-1)
					{
						requestCount++;
						course[i].student[truancyNum[i][k]].callTheRoll[j]=1;
						if(course[i].student[truancyNum[i][k]].courseTime[j]==1)
						{
							goodRequestCount++;
						}
						else if(course[i].student[truancyNum[i][k]].courseTime[j]==0)
						{
							wrongPeople[truancyNum[i][k]]++;
							if(wrongPeople[truancyNum[i][k]]>4)
							{
								truancyNum[i][k]=-1;
							}
						}
					}
					
				}
			}
		}
		wrongPeople.clear();		
	}
	return goodRequestCount*1.0/requestCount;
}
int main()
{
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\课程1.txt","r+");
	course[0].readIn();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\课程2.txt","r+");
	course[1].readIn();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\课程3.txt","r+");
	course[2].readIn();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\课程4.txt","r+");
	course[3].readIn();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\课程5.txt","r+");
	course[4].readIn();
	cout<<getE();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\callTheRoll_Course1.xls","w+");
	course[0].writeCall();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\callTheRoll_Course2.xls","w+");
	course[1].writeCall();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\callTheRoll_Course3.xls","w+");
	course[2].writeCall();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\callTheRoll_Course4.xls","w+");
	course[3].writeCall();
	fp=fopen("C:\\Users\\81980\\Desktop\\软工\\callTheRoll_Course5.xls","w+");
	course[4].writeCall();
}
