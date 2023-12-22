#include <string>
#include <vector>
#include "Customer.h"
#include "Trainee.h"
#include "Worker.h"
using namespace std;
//клас Менеджера
class Manager : virtual protected Human {
public:
	Manager();
	Manager(string name, int human_salary) : Human(name, human_salary){}
	template<class A> void set_emp_salary(A* emp, int salary) {
		emp->set_salary(salary);
	}
	void set_trainee_data(Trainee& emp, int id, int time);
	int get_num_of_emp(Customer<Project>& cust_name);
	void write_proj_to_file(Customer<Project>& cust_name);
	void set_proj_param(int price, int id, Customer<Project>& cust_name);
	void set_num_of_emp(int emp, Customer<Project>& cust_name);
	void show_project_info(Customer<Project>& cust_name);
	void add_manager_info(int exp, int id);
	void set_id(int id, Customer<Project>& cust_name);
	void set_id(int id, Worker& emp);
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
	~Manager(void);
private:
	int exp_in_job;
	vector<Customer<Project>*> customers;
	vector<vector<string>> tasks;
	vector<vector<Worker*>> workers;
	int* id_data;
};