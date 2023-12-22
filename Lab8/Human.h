#pragma once
#include <string>
#include <vector>
using namespace std;
//клас Людини
class Human {
public:
	Human();
	Human(string name, int human_salary) : name(name), salary(human_salary) {}
	string get_name();
	void set_id(int id);
	int get_id();
	int get_salary();
	void show_message();
	virtual void show_info(void) = 0;
	virtual ~Human(void);
protected:
	string name;
	int salary;
	int id;
};