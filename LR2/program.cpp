using namespace std;
#include "Manager.h"
#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include "MyException.h"
#include <algorithm>
#include <functional>
int main() {
	setlocale(LC_ALL, "ukrainian");
	read_proj_from_file(14);

	cin.get();

	Customer<Project> customer1("vasya", 100000);
	Customer<SoftwareProject>* customer2 = new Customer<SoftwareProject>("denis", 2000000);
	try {																//перевірка на помилки при виділенні пам'яті
		if (customer2 == nullptr) {
			throw bad_alloc();
		}
	}
	catch (bad_alloc &e) {
		cerr << "Помилка виділення пам'яті: " << e.what() << endl;
	}
	Manager taras("taras", 25000);
	//працівники
	Worker worker7;			//простий спосіб використання конструктора
	Worker worker8;
	//стажери
	Trainee tr1("diana", 0);
	Trainee* tr2 = new Trainee("dasha", 0);      //створення за допомогою конструкторів
	Trainee* tr3 = new Trainee("taras", 0);
	Trainee* tr4 = new Trainee("ivan", 0);
	Trainee* tr5 = new Trainee("jenya", 0);
	Trainee* tr6 = new Trainee("dima", 0);
	try {
		stack <Trainee*> memory_check;
		memory_check.push(tr2);
		memory_check.push(tr3);
		memory_check.push(tr4);
		memory_check.push(tr5);
		memory_check.push(tr6);
		while (!memory_check.empty()) {
			if (memory_check.top() == nullptr) {
				throw bad_alloc();
			}
			memory_check.pop();
		}
	}
	catch (bad_alloc& e) {
		cerr << "Помилка виділення пам'яті: " << e.what() << endl;
	}
	
	//встановлення даних стажерів
	taras.set_trainee_data(tr1, 978, 30);
	taras.set_trainee_data(*tr2, 3512, 30);
	taras.set_trainee_data(*tr3, 3142, 30);
	taras.set_trainee_data(*tr4, 3142, 30);
	taras.set_trainee_data(*tr5, 3132, 30);
	taras.set_trainee_data(*tr6, 3112, 30);
	taras.set_emp_salary(&tr1, 3000);
	taras.set_emp_salary(tr2, 4000);
	taras.set_emp_salary(tr3, 2700);
	taras.set_emp_salary(tr4, 5600);
	taras.set_emp_salary(tr5, 3455);
	taras.set_emp_salary(tr6, 3255);


	//використання поліморфних викликів
	Human* ptr;
	ptr = new Trainee;
	ptr->show_salary();
	delete ptr;
	ptr = new Customer<Project>;
	ptr->show_salary();
	delete ptr;
	ptr = new Manager;
	ptr->show_salary();
	delete ptr;
	///
	Manager manager1;
	Manager manager2;
	ptr = &manager1;
	ptr->show_salary();
	ptr = &manager2;
	ptr->show_salary();
	///
	ptr = (Human*) &taras;
	ptr->show_salary();
	ptr = (Human*) tr2;
	ptr->show_salary();
	ptr = (Human*) &customer1;
	ptr->show_salary();


	//створення працівників на основі стажерів
	Worker* worker1 = new Worker(tr1, "materials");
	Worker* worker2 = new Worker(*tr2, "measure");
	Worker* worker3 = new Worker(*tr3, "layout");
	Worker* worker4 = new Worker(*tr4, "materials");
	Worker* worker5 = new Worker(*tr5, "layout");
	Worker*  worker6 = new Worker(*tr6, "measure");

	Trainee* temp = &tr1;
	temp->show_info();
	temp = worker1;
	temp->show_info();
	cin.get();
	//видалення об'єктів стажерів
	try {
		queue <Trainee*> delete_check;
		delete_check.push(tr2);
		delete_check.push(tr3);
		delete_check.push(tr4);
		delete_check.push(tr5);
		delete_check.push(tr6);
		while (!delete_check.empty()) {
			if (delete_check.front() == nullptr) {
				throw MyException("Спроба видалити пустий об'єкт");
			}
			delete_check.pop();
		}
		delete tr2;
		delete tr3;
		delete tr4;
		delete tr5;
		delete tr6;
	}
	catch (MyException& e) {
		cerr << "Знайдена помилка: " << e.what() << endl;
	}

	//Worker worker7("diana", 0, "measure");		//явний спосіб використання конструктора
	//Worker worker8{"dasha", 0, "materials"};		//скорочений спосіб використання конструктора

	//встановлення даних замовників та менеджера
	customer2->add_cust_info("pepsi", "ukraine");
	customer1.add_cust_info("nivea", "usa");
	taras.add_manager_info(10, 29);
	taras.set_id(15, customer1);
	taras.set_id(14, *customer2);

	//створення проектів
	customer1.create_project();
	customer1.set_proj_param("burger", 30);
	customer2->create_project();
	customer2->set_proj_param("cafe", 60);

	//встановлення даних проектів
	taras.set_proj_param(100000, 42, *customer2);
	taras.set_num_of_emp(4, *customer2);
	taras.set_proj_param(50000, 40, customer1);
	taras.set_num_of_emp(4, customer1);

	taras.show_project_info(*customer2);
	taras.show_project_info(customer1);
	cin.get();

	taras.set_tasks({ "develop a layout", "describe the materials", "take measurements", "check the calculations"}, 1);
	/*taras.set_tasks({ "describe the materials", "take measurements", "develop a layout", "check the calculations"}, 2);*/
	/*taras.show_tasks(2);*/
	//встановлення даних працівників
	worker7.add_worker_info("vlad", "materials");
	worker8.add_worker_info("danya", "measure");
	
	taras.set_id(19, worker7);
	taras.set_id(22, worker8);
	
	taras.set_emp_salary(worker1, 10000);
	taras.set_emp_salary(worker2, 12000);
	taras.set_emp_salary(worker3, 11000);
	taras.set_emp_salary(worker4, 15000);
	taras.set_emp_salary(worker5, 20000);
	taras.set_emp_salary(worker6, 9000);
	taras.set_emp_salary(&worker7, 17000);
	taras.set_emp_salary(&worker8, 19000);

	taras.set_worker_premium(*worker2, 1000);
	taras.set_worker_premium(*worker4, 10000);
	taras.set_worker_premium(*worker6, 5000);

	//додавання працівників на проекти
	taras.add_worker(worker1, 1, customer1);
	taras.add_worker(worker2, 1, customer1);
	taras.add_worker(worker3, 1, customer1);
	/*taras.add_worker(worker4, 2, *customer2);
	taras.add_worker(worker5, 2, *customer2);
	taras.add_worker(worker6, 2, *customer2);*/
	taras.add_worker(&worker7, 1, customer1);
	/*taras.add_worker(&worker8, 2, *customer2);*/

	taras.set_worker_task(1);
	/*taras.set_worker_task(2);*/
	/*taras.search_by_id(54);
	taras.search_by_id(10);*/
	/*taras.write_proj_to_file(customer1);
	taras.write_proj_to_file(*customer2);*/

	taras.add_and_sort_id();
	
	count_salary_for_year(worker3);
	count_salary_for_year(worker7);

	/*worker6->show_job();
	worker6->show_company();
	cin.get();*/

	/*taras.show_info();
	customer1.show_info();*/

	/*worker1->show_info();
	worker2->show_info();
	worker3->show_info();
	worker4->show_info();
	worker5->show_info();
	worker6->show_info();
	worker7.show_info();
	worker8.show_info();*/

	//дані про зарплату та премії
	ptr = worker1;
	ptr->show_salary();

	worker2->show_salary();
	worker3->show_salary();
	worker4->show_salary();
	worker5->show_salary();
	worker6->show_salary();
	worker7.show_salary();
	worker8.show_salary();

	//зміна зарплати
	++(*worker1);
	++(*worker2);
	(*worker3)--;
	--(*worker4);
	//повторна перевірка
	worker1->show_salary();
	worker2->show_salary();
	worker3->show_salary();
	worker4->show_salary();

	static int salary[6] = { 3323, 13213, 5433, 433432, 54353, 12331 };
	list<int> pricesList(salary, salary + sizeof(salary) / sizeof(salary[0]));

	plus<int> addition;
	addition(salary[3], salary[5]);

	multiplies<int> multiplication;
	multiplication(salary[1], 2);

	divides<int> division;
	division(salary[1], 2);

	greater<int> greater_than;
	greater_than(salary[2], salary[5]);

	less<int> less_than;
	less_than(salary[5], salary[6]);

	logical_and<bool> logical_and_Object;
	bool greater_than_25000 = true;
	for (int i = 0; i < 6; i++) {
		greater_than_25000 = logical_and_Object(greater_than_25000, salary[i] > 25000);
	}

	logical_or<bool> logical_or_Object;
	bool less_than_1500 = false;
	for (int i = 0; i < 6; i++) {
		less_than_1500 = logical_or_Object(less_than_1500, salary[i] < 1500);
	}

	//зарплата за рік
	/*count_salary_for_year(worker2);*/

	//видалення по id
	taras.delete_by_id(3512);

	cin.get();
	try {
		queue <Worker*> delete_check;
		delete_check.push(worker1);
		delete_check.push(worker3);
		delete_check.push(worker4);
		delete_check.push(worker5);
		delete_check.push(worker6);
		while (!delete_check.empty()) {
			if (delete_check.front() == nullptr) {
				throw MyException("Спроба видалити пустий об'єкт");
			}
			delete_check.pop();
		}
		delete worker1;
		delete worker3;
		delete worker4;
		delete worker5;
		delete worker6;
	}
	catch (MyException& e) {
		cerr << "Знайдена помилка: " << e.what() << endl;
	}
	delete customer2;
	cin.get();
}