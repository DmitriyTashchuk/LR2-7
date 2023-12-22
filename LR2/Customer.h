#pragma once
#include <string>
#include <vector>
#include "Human.h"
#include "Project.h"
#include "SoftProject.h"
using namespace std;
//клас Замовника
template <class Proj>
class Customer : virtual public Human {
public:
	Customer();
	Customer(string name, int human_salary) : Human(name, human_salary) {}
	Proj* get_project();
	void create_project();
	void add_cust_info(string company, string country);
	void set_proj_param(string name, int time);
	void set_proj_param(int price, int id);
	void set_proj_param(int emp);
	void show_info();
	~Customer(void);
private:
	string company;
	string country;
	Proj new_project;
};