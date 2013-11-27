#include "iostream"
#include <cstring>
using namespace std;

struct student_info{
	char sname[20];
	long sid;
	long score;
}students[100];

int studentCount = 0;
void enterScore();
void showStuInfo();
void addStudent();
void delectStudent();
void input(struct student_info &student);
int search(char* sname,long sid);

int main()
{
	char action;
	do{
		cout<<"-----------菜单-----------"<<endl;
		cout<<"1)查看学生名单（含所有信息）"<<endl;
		cout<<"2)添加学生"<<endl;
		cout<<"3)删除学生"<<endl;
		cout<<"4)录入学生成绩"<<endl;
		cout<<"5)退出程序"<<endl;
		cin>>action;
		switch(action){
		case '1':
			showStuInfo();
			break;
		case '2':
			addStudent();
			break;
		case '3':
			delectStudent();
			break;
		case '5':
			return 0;
        case '4':
            enterScore();
            break;
		default:
			cout<<"您输入了错误的菜单项，请重新选择！";
		}
	}while(1);
}

void showStuInfo(){
	cout<<"-------学生信息-------"<<endl;
	cout<<"姓名\t"<<"学号"<<"\t成绩"<<endl;
	for(int i=0;i<studentCount;i++){
		cout<<students[i].sname<<"\t"<<students[i].sid<<"\t"<<students[i].score<<endl;
	}
}
void addStudent(){
	struct student_info student;
	input(student);

        int a = studentCount;
		strcpy(students[a].sname,student.sname);
		students[a].sid = student.sid;
		studentCount++;

}
void enterScore(){
	struct student_info student;
	input(student);
    int i = search(student.sname,student.sid);
	if (i<-1||i>studentCount) {
		cout<<"查找错误，不存在此同学！"<<endl;

	}else{

		cout<<"请输入获得的成绩："<<endl;
		cin>>students[i].score;
		cout<<"是否继续录入下个同学的成绩?"<<endl;
		cout<<"1.是的，继续录入。\t 2.否，返回上层。"<<endl;
		int action;
		cin>>action;
		switch(action){
        case 1:
            enterScore();
            break;
        case 2:
            break;
		default:

			cout<<"您输入了错误的菜单项，请重新选择！";

		}
	}

}
void delectStudent(){
	struct student_info student;
	input(student);
	int i = search(student.sname,student.sid);
	if (i<-1||i>studentCount) {
		cout<<"**************************"<<endl;
		cout<<"查找错误，不存在此同学！"<<endl;
	}else{
            for(int j=i;j<=studentCount;j++)
            {
            students[j]=students[j+1];/*删除元素...*/
            }
            studentCount--;
			cout<<"删除成功！"<<endl;
	}
}

void input(struct student_info &student){
	cout<<"姓名：";
	cin>>student.sname;

	cout<<"学号：";
	cin>>student.sid;
}

int search(char* sname,long sid){
	int i;
	for(i=0;i<=studentCount;i++){
		if(strcmp(students[i].sname,sname) == 0&&sid==students[i].sid){
			break;
		}
	}
	return i;
}
