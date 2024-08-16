#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"

using namespace std;

bool readFile(const char *, BST *);
int menu();

int main() {
	//###################code for testing
	char filename[100];
	BST* t1 = new BST();
	BST* t2 = new BST();
	cout << "Enter the filename: ";
	cin >> filename;
	Student s1;
	s1.id = 255;

	readFile(filename, t1);
	//t1->display(1, 1);
	t2->CloneSubtree(*t1, s1);
	

	system("pause");
	return 0;
}

bool readFile(const char* filename, BST* t1) {

	ifstream input;
	input.open(filename);

	Student* stu = new Student();;
	
	char c;
	bool read = false;
	string value;
	int count = 1;

	if (!input.is_open())return false;

	while (input.get(c)) {
		if (c == '=') read = true;
		else if (c == '\n') {
			//To get rid of a space, for example " "hello"", there is a space in front of hello. After get rid of the space it becomes ""hello""
			read = false;
			if (value.length() != 0) {
				value = value.substr(1, value.length());
			}
			//Save students' informations
			if (count % 8 == 1) {
				stu->id = atoi(value.c_str());
			}
			else if (count % 8 == 2) {
				strcpy(stu->name, value.c_str());
			}
			else if (count % 8 == 3) {
				strcpy(stu->address, value.c_str());
			}
			else if (count % 8 == 4) {
				strcpy(stu->DOB, value.c_str());
			}
			else if (count % 8 == 5) {
				strcpy(stu->phone_no, value.c_str());
			}
			else if (count % 8 == 6) {
				strcpy(stu->course, value.c_str());
			}
			else if (count % 8 == 7) {
				stu->cgpa = atof(value.c_str());
				t1->insert(*stu);
			}
			else if (count % 8 == 0) {}
			else cout << "Input error!" << endl;

			value = "";
			count++;
		}
		else if (read) {
			value += c;
		}
	}
	//Last line of the txt file is not endline, so we need this to save the data into the tree.
	if (!value.empty()) {
		stu->cgpa = atof(value.c_str());
		t1->insert(*stu);
	}

	input.close();
	return true;
}

