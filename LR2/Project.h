#pragma once
#include <string>
#include <vector>
using namespace std;
//клас Проекту
class Project {
public:
	Project();
	Project(const Project*& pattern);
	vector<string> get_info();
	void set_param(string name, int time);
	void set_param(int price, int id);
	void set_param(int emp);
	void write_to_file(string cust_name, int id);
private:
	string project_name;
	int time_to_complete;
	int price;
	int id;
	int number_of_emp;
};
void read_proj_from_file(int id);