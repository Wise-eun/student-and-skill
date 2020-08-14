#include<iostream>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;


///////////////////////Student(�л�) Ŭ������ �ۼ��϶��϶�
class Student {
protected:
	string name;
	int kor, eng, math;
public:

	Student();
	Student(string name) {
		this->name = name;
		kor = rand() % 31;
		math = rand() % 31;	eng = rand() % 31;
		// �̸��� name�� �ʱ�ȭ, ������ �ɷ�ġ�� 0~30������ ������÷.
	}
	Student(string name, int kor, int eng, int math) {
		this->eng = eng; this->kor = kor;
		this->math = math;	this->name = name;
	}
	friend bool compare(Student* a, Student* b);
	void study();
	void virtual info();
};

void Student::study() {

	this->kor += 2;
	this->eng += 2;
	this->math += 2;

	if (this->kor > 100)
		this->kor = 100;
	if (this->eng > 100)
		this->eng = 100;
	if (this->math > 100)
		this->math = 100;

}


void Student::info() {
	cout << "�̸� :" << name << "  ����:" << this->kor << "  ����� :" << this->eng << "  ���з� :" << this->math << endl;
}


//////////////////////Student�� ��ӹ޾� CollegeStudent(���л�) Ŭ������ �ۼ��϶�
class CollegeStudent :public Student {
protected:
	int general, major, hp;

public:

	CollegeStudent();
	CollegeStudent(string name) :Student(name) {
		this->name = name;
		general = rand() % 31; major = rand() % 31; hp = rand() % 31;
		// �̸��� name�� �ʱ�ȭ, ������ �ɷ�ġ�� 0~30������ ������÷.
	}

	CollegeStudent(string name, int kor, int eng, int math) :Student(name, kor, eng, math) {
		general = rand() % 31; major = rand() % 31; hp = rand() % 31;
	}//���޵� �Ű������� ����ʱ�ȭ. ������ �ɷ�ġ�� 0~30������ ������÷.

	CollegeStudent(string name, int kor, int eng, int math, int general, int major, int hp) :Student(name, kor, eng, math) {

		this->general = general; this->major = major; this->hp = hp;
	}//���޵� �Ű������� ��� ����ʱ�ȭ


	void study();
	void report();
	void rest();
	void info();
};
void CollegeStudent::study() {
	this->general += 2;
	this->major += 2;

	if (this->general > 100)
		this->general = 100;
	if (this->major > 100)
		this->major = 100;
}


void CollegeStudent::report() {
	if (this->hp < 5) {
		cout << this->name << " ü�¾�� report ����Ұ�" << endl;
		return;
	}

	this->general += 5;
	this->major += 5;
	this->hp -= 5;
	if (this->general > 100)
		this->general = 100;
	if (this->major > 100)
		this->major = 100;
	if (this->hp <= 0)
		this->hp = 0;
}

void CollegeStudent::rest() {
	this->general -= 1;
	this->major -= 1;
	this->hp += 5;

	if (this->general <= 0)
		this->general = 0;
	if (this->major <= 0)
		this->major = 0;
	if (this->hp > 100)
		this->hp = 100;
}

void  CollegeStudent::info() {
	cout << "�̸� :" << name << "  ����:" << this->kor << "  ����� :" << this->eng << "  ���з� :" << this->math << "  ���� : " << general << "  �������� : " << major << "  ü�� :" << hp << endl;
}


///////////CollegeStudent�� ��ӹ޾� GraduateStudent(���п���) Ŭ������ �ۼ��϶�

class GraduatedStudent :public CollegeStudent {
	int present;
public:
	GraduatedStudent();
	GraduatedStudent(string name) :CollegeStudent(name) {
		this->name = name;
		present = rand() % 31;
		//�̸��� name�� �ʱ�ȭ, ������ �ɷ�ġ�� 0~30������ ������÷.
	}

	GraduatedStudent(string name, int kor, int eng, int math) :CollegeStudent(name, kor, eng, math) {
		present = rand() % 31;
	}

	GraduatedStudent(string name, int kor, int eng, int math, int general, int major, int hp) :CollegeStudent(name, kor, eng, math, general, major, hp) {
		present = rand() % 31;
	}
	GraduatedStudent(string name, int kor, int eng, int math, int general, int major, int hp, int present) :CollegeStudent(name, kor, eng, math, general, major, hp) {
		this->present = present;
	}



	void presentation();
	void research();
	void info();
};

void  GraduatedStudent::presentation() {
	if (this->hp < 5) {
		cout << this->name << " ü�¾�� presentation ����Ұ�" << endl;
		return;
	}

	this->present += 5;
	this->hp -= 5;
	if (this->present > 100)
		this->present = 100;
	if (this->hp <= 0)
		this->hp = 0;

}
void  GraduatedStudent::research() {
	if (this->hp < 10) {
		cout << this->name << " ü�¾�� research ����Ұ�" << endl;
		return;
	}

	this->major += 10;
	this->hp -= 10;
	if (this->major > 100)
		this->major = 100;
	if (this->hp <= 0)
		this->hp = 0;

}
void GraduatedStudent::info() {
	cout << "�̸� :" << name << "  ����:" << this->kor << "  ����� :" << this->eng << "  ���з� :" << this->math << "  ���� : " << general << "  �������� : " << major << "  ü�� :" << hp << "  ��ǥ�� : " << present << endl;
}

///////////////////////////////////////////////////////////////////////

bool compare(Student* a, Student* b) {
	if ((*a).name > (*b).name)
		return 0;
	else
		return 1;
}
int main() {
	srand((unsigned int)time(NULL));

	vector< Student*> v;
	vector< CollegeStudent*> vp;
	vector< GraduatedStudent*> p;

	//1�� �۾�
	v.push_back(new Student("4�л�"));
	v.push_back(new Student("3�л�"));
	v.push_back(new Student("2�л�", 50, 20, 10));
	v.push_back(new Student("1�л�", 30, 40, 80));

	vp.push_back(new CollegeStudent("b���л�"));
	vp.push_back(new CollegeStudent("c���л�", 70, 90, 60));
	vp.push_back(new CollegeStudent("a���л�", 50, 60, 70, 80, 90, 85));

	p.push_back(new GraduatedStudent("b���п���"));
	p.push_back(new GraduatedStudent("c���п���", 40, 80, 90, 76, 20, 98));
	p.push_back(new GraduatedStudent("a���п���", 15, 25, 35, 45, 55, 65, 75));

	vector<Student*>::iterator it;
	vector<CollegeStudent*>::iterator it1;
	vector<GraduatedStudent*>::iterator it2;

	for (it1 = vp.begin(); it1 < vp.end(); it1++)
		v.push_back(*it1);
	for (it2 = p.begin(); it2 < p.end(); it2++)
		v.push_back(*it2);

	//2�� �۾�
	for (it = v.begin(); it < v.end(); it++)
		(*it)->info();

	//3���۾�
	for (it = v.begin(); it < v.end(); it++)
		(*it)->study();

	//4���۾�
	for (it1 = vp.begin(); it1 < vp.end(); it1++) {
		(*it1)->report();
		(*it1)->rest();
	}
	for (it2 = p.begin(); it2 < p.end(); it2++) {
		(*it2)->report();
		(*it2)->rest();
	}

	//5���۾�
	for (it2 = p.begin(); it2 < p.end(); it2++) {
		(*it2)->presentation();
		(*it2)->research();
	}

	//6���۾�
	sort(v.begin(), v.end(), compare);

	cout << endl << endl;

	//7���۾�
	for (it = v.begin(); it < v.end(); it++)
		(*it)->info();


	return 0;
}
