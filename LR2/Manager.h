#include <string>
#include <vector>
#include "Customer.h"
#include "Trainee.h"
#include "Worker.h"
#include <iostream>
using namespace std;
//клас Менеджера
class Manager : virtual public Human {
public:
	Manager();
	Manager(string name, int human_salary) : Human(name, human_salary){}
	template<class A> void set_emp_salary(A* emp, int salary) {
		emp->set_salary(salary);
	}
	void set_trainee_data(Trainee& emp, int id, int time);
	int get_num_of_emp(Customer<Project>& cust_name);
	void write_proj_to_file(Customer<Project>& cust_name);
	template<class Proj>
	void set_proj_param(int price, int id, Customer<Proj>& cust_name) {
		cust_name.set_proj_param(price, id);
	}
	template<class Proj>
	void set_num_of_emp(int emp, Customer<Proj>& cust_name) {
		cust_name.set_proj_param(emp);
	}
	template<class Proj>
	void show_project_info(Customer<Proj>& cust_name) {
		vector<string> info = cust_name.get_project()->get_info();
		cout << "Назва проекту: " << info[0] << endl;
		cout << "Терміни виконання(у днях): " << info[1] << endl;
		cout << "Вартість проекту: " << info[2] << endl;
		cout << "ID проекту: " << info[3] << endl;
		cout << "Працівників закріплено за проектом: " << info[4] << endl;
	}
	void add_manager_info(int exp, int id);
	template<class Proj>
	void set_id(int id, Customer<Proj>& cust_name) {
		cust_name.set_id(id);
	}
	void set_id(int id, Worker& emp);
	void show_salary();
	void set_premium(int prem);
	void set_worker_premium(Worker& worker, int prem);
	void set_tasks(vector<string> param, int num_of_proj);
	void show_tasks(int num_of_proj);
	void add_worker(Worker* emp, int num_of_proj, Customer<Project>& cust_name);
	void set_worker_task(int num_of_proj);
	Worker* get_worker(int ind, int num_of_proj);
	void search_by_id(int worker_id);
	void add_and_sort_id();
	void delete_by_id(int worker_id);
	void show_info();
	vector<string>::iterator operator[](string task);
	~Manager(void);
private:
	int premium = 0;
	int exp_in_job;
	vector<string> task_arr;
	vector<vector<string>> tasks;
	vector<vector<Worker*>> workers;
	int* id_data;
};
void printElement(int id);