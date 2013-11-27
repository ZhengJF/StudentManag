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
		cout<<"-----------�˵�-----------"<<endl;
		cout<<"1)�鿴ѧ����������������Ϣ��"<<endl;
		cout<<"2)���ѧ��"<<endl;
		cout<<"3)ɾ��ѧ��"<<endl;
		cout<<"4)¼��ѧ���ɼ�"<<endl;
		cout<<"5)�˳�����"<<endl;
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
			cout<<"�������˴���Ĳ˵��������ѡ��";
		}
	}while(1);
}

void showStuInfo(){
	cout<<"-------ѧ����Ϣ-------"<<endl;
	cout<<"����\t"<<"ѧ��"<<"\t�ɼ�"<<endl;
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
		cout<<"���Ҵ��󣬲����ڴ�ͬѧ��"<<endl;

	}else{

		cout<<"�������õĳɼ���"<<endl;
		cin>>students[i].score;
		cout<<"�Ƿ����¼���¸�ͬѧ�ĳɼ�?"<<endl;
		cout<<"1.�ǵģ�����¼�롣\t 2.�񣬷����ϲ㡣"<<endl;
		int action;
		cin>>action;
		switch(action){
        case 1:
            enterScore();
            break;
        case 2:
            break;
		default:

			cout<<"�������˴���Ĳ˵��������ѡ��";

		}
	}

}
void delectStudent(){
	struct student_info student;
	input(student);
	int i = search(student.sname,student.sid);
	if (i<-1||i>studentCount) {
		cout<<"**************************"<<endl;
		cout<<"���Ҵ��󣬲����ڴ�ͬѧ��"<<endl;
	}else{
            for(int j=i;j<=studentCount;j++)
            {
            students[j]=students[j+1];/*ɾ��Ԫ��...*/
            }
            studentCount--;
			cout<<"ɾ���ɹ���"<<endl;
	}
}

void input(struct student_info &student){
	cout<<"������";
	cin>>student.sname;

	cout<<"ѧ�ţ�";
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
