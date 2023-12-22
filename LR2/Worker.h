#pragma once
#include <string>
#include <vector>
#include "Trainee.h"
using namespace std;
//клас Працівника
class Worker : public Trainee {
public:
	Worker();
	Worker(string name, int human_salary, string dep) : Trainee(name, human_salary), department(dep) {}		//конструктор з параметрами
	Worker(Trainee& trainee, string dep);
	void add_worker_info(string name, string dep);
	void show_task();
	void set_task(string task);
	void set_premium(int prem);
	bool get_busy();
	string get_department();
	void show_info();
	void show_salary();
	using Human::show_message;
	string operator+=(string dep);
	~Worker(void);
private:
	int premium = 0;
	string department;
	string task;
	bool has_a_task = false;;
};
void count_salary_for_year(Worker* emp);
void count_salary_for_year(Worker emp);
