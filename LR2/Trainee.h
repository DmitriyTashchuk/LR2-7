#pragma once
#include <string>
#include <vector>
#include "Human.h"
#include "Vacancy.h"
using namespace std;
//клас Стажера
class Trainee : virtual public Human, public Vacancy {
public:
	Trainee();
	Trainee(string name, int human_salary) : Human(name, human_salary) {}
	void set_internship_time(int time);
	void set_salary(int salary);
	virtual void show_info();
	Trainee& operator++();
	Trainee operator++(int);
	Trainee& operator--();
	Trainee operator--(int);
	int operator*(int n);
	~Trainee(void);
private:
	int internship_time;
};
