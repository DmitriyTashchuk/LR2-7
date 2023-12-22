#include "manager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "MyException.h"
using namespace std;
void Customer<Project>::add_cust_info(string company, string country) {		//додавання інформації замовника
	this->company = company;
	this->country = country;
}
void Customer<Project>::set_proj_param(string name, int time){		//встановлення імені і термінів проекту
	this->get_project()->set_param(name, time);
}
void Customer<Project>::set_proj_param(int price, int id) {		//встановлення вартості і id проекту
	this->get_project()->set_param(price, id);
}
void Customer<Project>::set_proj_param(int emp) {		//встановлення кількості працівників на проекті
	this->get_project()->set_param(emp);
}
void Customer<Project>::create_project() {		//створення проекту замовником
	Project *temp = new Project;
	this->new_project = *temp;
	delete temp;
}
void Customer<SoftwareProject>::add_cust_info(string company, string country) {		//додавання інформації замовника
	this->company = company;
	this->country = country;
}
void Customer<SoftwareProject>::set_proj_param(string name, int time) {		//встановлення імені і термінів проекту
	this->get_project()->set_param(name, time);
}
void Customer<SoftwareProject>::set_proj_param(int price, int id) {		//встановлення вартості і id проекту
	this->get_project()->set_param(price, id);
}
void Customer<SoftwareProject>::set_proj_param(int emp) {		//встановлення кількості працівників на проекті
	this->get_project()->set_param(emp);
}
void Customer<SoftwareProject>::create_project() {		//створення проекту замовником
	SoftwareProject* temp = new SoftwareProject;
	this->new_project = *temp;
	delete temp;
}
template<class Proj>
Proj* Customer<Proj>::get_project() {		//отримання посилання на проект
	return &new_project;
}
template<class Proj>
void Customer<Proj>::show_info() {
	cout << "Інформація по замовнику:" << endl;
	cout << "Ім'я: " << this->name << endl;
	cout << "Зарплата: " << this->salary << endl;
	cout << "ID: " << this->get_id() << endl;
	cout << "Країна замовника: " << this->country << endl;
	cout << "Компанія замовника: " << this->company << endl;
}
int Manager::get_num_of_emp(Customer<Project>& cust_name) {
	return stoi(cust_name.get_project()->get_info()[4]);
}
void Manager::set_worker_premium(Worker& worker, int prem) {
	worker.set_premium(prem);
}
//void Manager::set_id(int id, Customer<Project>& cust_name) {			//встановлення id замовника менеджером
//	cust_name.set_id(id);
//}
void Manager::add_manager_info(int exp, int id) {			//додавання інформації менеджера
	this->exp_in_job = exp;
	Human::set_id(id);
}
//void Manager::set_proj_param(int price, int id, Customer<Project>& cust_name) {		//встановлення вартості і id проекту менеджером
//	cust_name.set_proj_param(price, id);
//}
//void Manager::set_num_of_emp(int emp, Customer<Project>& cust_name) {		//встановлення кількості працівників на проекті менеджером
//	cust_name.set_proj_param(emp);
//}
//void Manager::show_project_info(Customer<Project>& cust_name){				//вивід інформації про проект, закріплений за замовником			
//	vector<string> info = cust_name.get_project()->get_info();
//	cout << "Назва проекту: " << info[0] << endl;
//	cout << "Терміни виконання(у днях): " << info[1] << endl;
//	cout << "Вартість проекту: " << info[2] << endl;
//	cout << "ID проекту: " << info[3] << endl;
//	cout << "Працівників закріплено за проектом: " << info[4] << endl;
//}
void Manager::set_tasks(vector<string> param, int num_of_proj) {		//запис завдань для вибраного проекту
	if (num_of_proj > this->tasks.size()) {
		this->tasks.push_back({});
		this->tasks[num_of_proj - 1] = param;
	}
	else {
		this->tasks[num_of_proj - 1] = param;
	}
}
void Manager::show_tasks(int num_of_proj) {						//вивід завдань, заданих для проекту
	if ((num_of_proj - 1) < this->tasks.size()) {
		cout << "Наявні завдання по проекту: " << endl;
		for (int i = 0; i < this->tasks[(num_of_proj - 1)].size(); i++) {
			cout << this->tasks[(num_of_proj - 1)][i] << endl;
		}
	}
}
void Manager::add_worker(Worker* emp, int num_of_proj, Customer<Project>& cust_name) {		//додавання працівника на вибраний проект
	if (emp->get_id() != 0) {
		int number_of_emp = this->get_num_of_emp(cust_name);
		if (num_of_proj > this->workers.size()) {
			this->workers.push_back({});
		}
		if (number_of_emp > this->workers[num_of_proj - 1].size()) {
			this->workers[num_of_proj - 1].push_back(emp);
		}
		else {
			cerr << "Максимальна кількість працівників на проекті" << endl;
		}
	}
}
void Manager::set_trainee_data(Trainee& emp, int id, int time) {
	emp.set_internship_time(time);
	emp.set_id(id);
}
void Manager::set_worker_task(int num_of_proj) {				//встановлення завдань для працівників
	for (int i = 0; i < this->tasks[num_of_proj - 1].size(); i++) {
		if (i < this->workers[num_of_proj - 1].size()) {
			string department = this->get_worker(i, num_of_proj)->get_department();
			bool busy = this->get_worker(i, num_of_proj)->get_busy();
			if (department == "measure" && busy != true) {
				this->get_worker(i, num_of_proj)->set_task(this->tasks[num_of_proj - 1][i]);
			}
			else if (department == "layout" && busy != true) {
				this->get_worker(i, num_of_proj)->set_task(this->tasks[num_of_proj - 1][i]);
			}
			else if (department == "materials" && busy != true) {
				this->get_worker(i, num_of_proj)->set_task(this->tasks[num_of_proj - 1][i]);
			}
		}
	}
}
Worker* Manager::get_worker(int index, int num_of_proj) {			//отримання вказівника на працівника з масиву
	return workers[num_of_proj - 1][index];
}
void Manager::set_id(int id, Worker& emp) {						//встановлення id працівнику менеджером
	emp.set_id(id);
}
void Manager::delete_by_id(int worker_id) {						//пошук працівника по id в масиві працівників
	for (int i = 0; i < this->workers.size(); i++) {
		for (int j = 1; j <= this->workers[i].size(); j++) {
			if (this->workers[i][j - 1]->get_id() == worker_id) {
				delete this->workers[i][j - 1];
				workers[i].erase(workers[i].begin() + j - 1);
				return;
			}
		}
	}
}
void Manager::write_proj_to_file(Customer<Project>& cust_name) {			//запис даних проекту в файл
	cust_name.get_project()->write_to_file(cust_name.get_name(), cust_name.get_id());
}
void Manager::search_by_id(int worker_id) {						//пошук працівника по id в масиві працівників
	for (int i = 0; i < this->workers.size(); i++) {
		for (int j = 1; j <= this->workers[i].size(); j++) {
			if (this->workers[i][j - 1]->get_id() == worker_id) {
				this->workers[i][j - 1]->show_info();
				return;
			}
		}
	} 
}
void Manager::add_and_sort_id() {								//метод формування масиву id працівників і сортування його
	int size = 0;
	for (int i = 0; i < this->workers.size(); i++) { //перерахунок працівників в масиві
		for (vector<Worker*>::iterator j = this->workers[i].end(); j > this->workers[i].begin(); j--) {
			size++;
		}
	}
	int countt = size;
	this->id_data = new int[countt];
	for (int i = 0; i < this->workers.size(); i++) { //додавання id в масив
		for (int j = 1; j <= this->workers[i].size(); j++) {
			countt--;
			this->id_data[countt] = this->workers[i][j - 1]->get_id();
		}
	}
	sort(this->id_data, this->id_data + size); //сортування масиву
	reverse(this->id_data, this->id_data + size);
	cout << "Відсортовані значення: " << endl;
	remove(this->id_data, this->id_data + size, 3512);
	for_each(this->id_data, this->id_data + size - 1, printElement);
	int count_number = count(this->id_data, this->id_data + size, 3142);
	cout << count_number << endl;
}
void printElement(int id) {
	cout << id << endl;
}
void Manager::show_info() {
	cout << "Інформація по менеджеру:" << endl;
	cout << "Ім'я: " << this->name << endl;
	cout << "Зарплата: " << this->salary << endl;
	cout << "ID: " << this->get_id() << endl;
	cout << "Досвід в роботі: " << this->exp_in_job << endl;
}
void Project::set_param(string name, int time) {			//метод зміни назви і термінів проекту
	this->project_name = name;
	this->time_to_complete = time;
}
void Project::set_param(int price, int id) {			//метод зміни ціни і id проекту
	this->price = price;
	this->id = id;
}
void Project::set_param(int emp) {				//метод зміни кількості працівників на проекті
	this->number_of_emp = emp;
}
vector<string> Project::get_info() {				// метод отримання інформації проекту
	Project temp = Project(*this);
	vector<string> info;
	info.push_back(temp.project_name);
	info.push_back(to_string(temp.time_to_complete));
	info.push_back(to_string(temp.price));
	info.push_back(to_string(temp.id));
	info.push_back(to_string(temp.number_of_emp));
	return info;
}
void Project::write_to_file(string cust_name, int id) {							//метод запису даних проекту в файл
	cout << "Введіть назву файлу для запису" << endl;
	string file_name;
	cin >> file_name;
	file_name = file_name + ".txt";
	try {
		ofstream write_project(file_name, ios::app);
		if (!write_project.is_open()) {
			throw MyException("Помилка при відкритті файлу");
		}
		write_project << "Проект власника " << cust_name << "  ; ID: " << id << endl;
		write_project << "Назва проекту: " << this->project_name << "\n" << "Час на виконання: " << this->time_to_complete << "\n" << "Вартість проекту: " << this->price << endl;
		write_project << "ID: " << this->id << "\n" << "Кількість працівників на проекті: " << this->number_of_emp << "\n";
		write_project.close();
	}
	catch (MyException& e) {
		cerr << "Знайдена помилка: " << e.what() << endl;
	}
}
void SoftwareProject::set_param(string name, int time) {			//метод зміни назви і термінів проекту
	this->project_name = name;
	this->time_to_complete = time;
}
void SoftwareProject::set_param(int price, int id) {			//метод зміни ціни і id проекту
	this->price = price;
	this->id = id;
}
void SoftwareProject::set_param(int emp) {				//метод зміни кількості працівників на проекті
	this->number_of_emp = emp;
}
vector<string> SoftwareProject::get_info() {				// метод отримання інформації проекту
	SoftwareProject temp = SoftwareProject(*this);
	vector<string> info;
	info.push_back(temp.project_name);
	info.push_back(to_string(temp.time_to_complete));
	info.push_back(to_string(temp.price));
	info.push_back(to_string(temp.id));
	info.push_back(to_string(temp.number_of_emp));
	return info;
}
void SoftwareProject::write_to_file(string cust_name, int id) {							//метод запису даних проекту в файл
	cout << "Введіть назву файлу для запису" << endl;
	string file_name;
	cin >> file_name;
	file_name = file_name + ".txt";
	try {
		ofstream write_project(file_name, ios::app);
		if (!write_project.is_open()) {
			throw MyException("Помилка при відкритті файлу");
		}
		write_project << "Проект власника " << cust_name << "  ; ID: " << id << endl;
		write_project << "Назва проекту: " << this->project_name << "\n" << "Час на виконання: " << this->time_to_complete << "\n" << "Вартість проекту: " << this->price << endl;
		write_project << "ID: " << this->id << "\n" << "Кількість працівників на проекті: " << this->number_of_emp << "\n";
		write_project.close();
	}
	catch (MyException& e) {
		cerr << "Знайдена помилка: " << e.what() << endl;
	}
}
void read_proj_from_file(int id) {			//метод зчитування даних проекту з файлу по ID власника
	cout << "Введіть назву файлу для зчитування" << endl;
	string file_name;
	cin >> file_name;
	file_name = file_name + ".txt";
	cout << "Зчитані дані з файлу: " << endl;
	try {
		ifstream proj_read(file_name); 
		if (!proj_read) {
			throw MyException("Помилка при відкритті файлу");
		}
		string line;
		while (getline(proj_read, line)) {
			size_t pos = line.find("ID: ");
			if (pos != string::npos) {
				string cust_id = line.substr(pos + 4);
				if (stoi(cust_id) == id) {
					string proj_line;
					cout << line << endl;
					for (int i = 0; i < 5; i++) {
						getline(proj_read, proj_line);
						cout << proj_line << endl;
					}
				}
			}
		}
		proj_read.close();
	}
	catch (MyException& e) {
		cerr << "Знайдена помилка: " << e.what() << endl;
	}
}
void Worker::set_task(string task) {					//встановлення задачі працівнику
	this->task = task;
	this->has_a_task = true;
}
void Worker::set_premium(int prem) {
	this->premium = prem;
}
void Manager::set_premium(int prem) {
	this->premium = prem;
}
void Trainee::set_salary(int salary) {
	this->salary = salary;
}
void Worker::show_task() {								//вивід завдання працівника
	cout << this->task << endl;
}
void Worker::add_worker_info(string name, string dep) {		//додавання інформації працівника
	this->name = name;
	this->department = dep;
}
bool Worker::get_busy() {								//отримання даних про наявність завдання у працівника
	return has_a_task;
}
string Worker::get_department() {						//отримання відділу, в якому працює робочий
	return department;
}
int Human::get_id() {									//отримання id об'єкту
	return id;
}
string Human::get_name() {
	return name;
}
int Human::get_salary() {
	return salary;
}
void Human::set_id(int id) {							//встановлення id об'єкту
	this->id = id;
}
void Human::show_message() {
	cout << "Клас наслідується від Human"<< endl;
	
}
void Worker::show_info() {								//вивід інформації про працівника
	cout << "Ім'я працівника: " << this->name << endl;
	cout << "Відділ: " << this->department << endl;
	cout << "Завдання: " << this->task << endl;
	cout << "Чи є завдання: " << this->has_a_task << endl;
	cout << "ID: " << this->get_id() << endl;
	cout << "Зарплата робочого: " << this->salary << endl;
	Vacancy::show_company();
	show_message();
}
Worker::Worker() : Trainee("None", 0), department("None") {}     //конструктори для класів
Worker::Worker(Trainee& trainee, string dep){
	this->name = trainee.get_name();
	this->salary = trainee.get_salary();
	this->id = trainee.get_id();
	this->department = dep;
}
Manager::Manager() : Human("None", 0) {}
Customer<Project>::Customer() : Human("None", 0) {}
Customer<SoftwareProject>::Customer() : Human("None", 0) {}
Human::Human(){}
Vacancy::Vacancy(){}
Trainee::Trainee() : Human("None", 0), Vacancy() {}
Project::Project(){}
SoftwareProject::SoftwareProject() {}
Project::Project(const Project*& pattern) {
	this->project_name = pattern->project_name;
	this->time_to_complete = pattern->time_to_complete;
	this->price = pattern->price;
	this->id = pattern->id;
	this->number_of_emp = pattern->number_of_emp;
}
Trainee::~Trainee(void){												//деструктори для класів
	cout << "Знищення об'єкту для Trainee " << name << endl;
}
template <class Proj>
Customer<Proj>::~Customer(void) {
	cout << "Знищення об'єкту для Customer " << name << endl;
}
Manager::~Manager(void) {
	cout << "Знищення об'єкту для Manager " << name << endl;
}
Human::~Human(void) {
	cout << "Знищення об'єкту для Human " << name << endl;
}
Worker::~Worker(void) {
	cout << "Знищення об'єкту для Worker " << name << endl;
}
string Vacancy::company = "IBM";										//статичні поля класу Worker
string Vacancy::job = "IT";
void Vacancy::show_company() {
	cout << "Компанія, на якій працює робочий: " << company << endl;
}
void Vacancy::show_job() {
	cout << "Напрям роботи: " << job << endl;
}
void Trainee::set_internship_time(int time) {
	this->internship_time = time;
}
void Trainee::show_info() {
	cout << "Інформація по стажеру:" << endl;
	cout << "Ім'я: " << this->name << endl;
	cout << "ID: " << this->get_id() << endl;
	cout << "Час стажування: " << this->internship_time << endl;
}
void Human::show_salary() {
	cout << "Зарплата "<< name << " : " << this->salary << endl;
}
void Worker::show_salary() {
	cout << "Зарплата працівника " << name << " з премією: " << this->salary << " + " << this->premium <<endl;
}
void Manager::show_salary() {
	cout << "Зарплата працівника " << name << " з премією: " << this->salary << " + " << this->premium << endl;
}
void count_salary_for_year(Worker emp) {						//перевантажені функції обчислення зарплати
	cout << "Зарплата вибраного робочого за рік: " << emp * 12 << endl;
}
void count_salary_for_year(Worker* emp) {
	cout << "Зарплата вибраного робочого за рік: " << (*emp) * 12 << endl;
}
Trainee& Trainee::operator++() {
	this->salary += 1000;
	return *this;
}
Trainee Trainee::operator++(int) {
	Trainee temp = *this;
	temp.salary += 1000;
	return temp;
}
Trainee& Trainee::operator--() {
	this->salary  -= 1000;
	return *this;
}
Trainee Trainee::operator--(int) {
	Trainee temp = *this;
	temp.salary -= 1000;
	return temp;
}
int Trainee::operator*(int n) {
	int year_salary = this->salary * n;
	return year_salary;
}
string Worker::operator+=(string dep) {
	string worker_job = this->name + dep;
	return worker_job;
}
vector<string>::iterator Manager::operator[](string task) {
	return find(task_arr.begin(), task_arr.end(), task);
}