/*
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
const int maxNameLenghth = 20;
const int markCount = 3;

struct Student {

	char name[maxNameLenghth];
	int marks[markCount];
};

void initstudent(Student& student, const char* name, const int marks[]) {

	strcpy_s(student.name, maxNameLenghth, name);
	for (int i = 0; i < markCount; i++) {
		student.marks[i] = marks[i];
	}
}

double avermark(Student student) {
	double sum = 0;
	for (int i = 0; i < markCount; i++) {
		sum += student.marks[i];
	}
	return sum / markCount;
}

void printstudent(Student student) {
	cout << student.name << endl;
	cout << "оценки";
	for (int i = 0; i < markCount; i++) {
		cout << setw(4) << student.marks[i];
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "");
		cout << "успеваемость студента";
		Student student;
		const char* studentName{ " " "ЛЕГЕНДА С.В.О" };
		 int studentMark[]{  666, 1337, 1488 };
		initstudent(student, studentName, studentMark);
		printstudent(student);
		cout << "средняя оценка:" << fixed << setprecision(2) << avermark(student) << endl;

}
*/
/*
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
const int maxNameLenghth = 20;
const int markCount = 3;

class Student 
{
	char name[maxNameLenghth];
	int marks[markCount];
public:
	
	Student(const char* name, const int* marks) {
		strcpy_s(Student::name, maxNameLenghth, name);
		for (int i = 0; i < markCount; i++) {
			Student::marks[i] = marks[i];
		}
	}
	double getaver() {
		double sum = 0;
		for (int i = 0; i < markCount; i++) {
			sum += marks[i];
		}
		return sum / markCount;
	}
	void printstudent() {
		cout << name << endl;
		cout << "оценки";
		for (int i = 0; i < markCount; i++) {
			cout << setw(4) << marks[i];
		}
		cout << endl;
	}
	void printaver() {
		cout << "средняя оценка:" << fixed << setprecision(2) << getaver() << endl;
	}
};

int main() {
	setlocale(LC_ALL, "");
	cout << "успеваемость студента" <<endl;
	int a;
	int b;
	int c;
	cout << "первая оценка" << endl;
	cin >> a;
	cout << "вторая оценка" << endl;
	cin >> b;
	cout << "третья оценка" << endl;
	cin >> c;
	Student student{"легенда С.В.О" , new int[3]{a,b,c} };
	student.printstudent();
	student.printaver();
	
}*/
/*#include <iostream>
#include <conio.h>
using namespace std;
class Student {



public:
	char name[20];
	int marks[3];
	double getaver() {
		double sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += marks[i];
		}
		return sum / 3;
	}
};
int main() {
	setlocale(LC_ALL, "");
	cout << "успеваемость студента" << endl;
	Student student;
	strcpy_s(student.name, 20, " Иванов И.И");
		student.marks[0] = 10;
		cout << student.name << " : " << student.marks[0];
	_getch();
}*/
	

#include <iostream>
#include <conio.h>
using namespace std;
class Auto{
public:
	char mark[50];
	char model[50];
	int power;
};

int main() {
	setlocale(LC_ALL, "");
	cout << "автомобиль:" << endl;
	Auto AUto; 
	strcpy_s(AUto.mark, 50, "toyota");
	strcpy_s(AUto.model, 50, "mark2 stolb edition");
	AUto.power = 1500;
	cout << AUto.mark << " : " << AUto.model << endl;
	cout << AUto.power << "hp" << endl;
	cout << "бип-бип";
	_getch();

}