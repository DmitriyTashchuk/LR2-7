#include "manager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "MyException.h"
using namespace std;
void Customer<Project>::add_cust_info(string company, string country) {		//��������� ���������� ���������
	this->company = company;
	this->country = country;
}
void Customer<Project>::set_proj_param(string name, int time){		//������������ ���� � ������ �������
	this->get_project()->set_param(name, time);
}
void Customer<Project>::set_proj_param(int price, int id) {		//������������ ������� � id �������
	this->get_project()->set_param(price, id);
}
void Customer<Project>::set_proj_param(int emp) {		//������������ ������� ���������� �� ������
	this->get_project()->set_param(emp);
}
void Customer<Project>::create_project() {		//��������� ������� ����������
	Project *temp = new Project;
	this->new_project = *temp;
	delete temp;
}
void Customer<SoftwareProject>::add_cust_info(string company, string country) {		//��������� ���������� ���������
	this->company = company;
	this->country = country;
}
void Customer<SoftwareProject>::set_proj_param(string name, int time) {		//������������ ���� � ������ �������
	this->get_project()->set_param(name, time);
}
void Customer<SoftwareProject>::set_proj_param(int price, int id) {		//������������ ������� � id �������
	this->get_project()->set_param(price, id);
}
void Customer<SoftwareProject>::set_proj_param(int emp) {		//������������ ������� ���������� �� ������
	this->get_project()->set_param(emp);
}
void Customer<SoftwareProject>::create_project() {		//��������� ������� ����������
	SoftwareProject* temp = new SoftwareProject;
	this->new_project = *temp;
	delete temp;
}
template<class Proj>
Proj* Customer<Proj>::get_project() {		//��������� ��������� �� ������
	return &new_project;
}
template<class Proj>
void Customer<Proj>::show_info() {
	cout << "���������� �� ���������:" << endl;
	cout << "��'�: " << this->name << endl;
	cout << "��������: " << this->salary << endl;
	cout << "ID: " << this->get_id() << endl;
	cout << "����� ���������: " << this->country << endl;
	cout << "������� ���������: " << this->company << endl;
}
int Manager::get_num_of_emp(Customer<Project>& cust_name) {
	return stoi(cust_name.get_project()->get_info()[4]);
}
void Manager::set_worker_premium(Worker& worker, int prem) {
	worker.set_premium(prem);
}
//void Manager::set_id(int id, Customer<Project>& cust_name) {			//������������ id ��������� ����������
//	cust_name.set_id(id);
//}
void Manager::add_manager_info(int exp, int id) {			//��������� ���������� ���������
	this->exp_in_job = exp;
	Human::set_id(id);
}
//void Manager::set_proj_param(int price, int id, Customer<Project>& cust_name) {		//������������ ������� � id ������� ����������
//	cust_name.set_proj_param(price, id);
//}
//void Manager::set_num_of_emp(int emp, Customer<Project>& cust_name) {		//������������ ������� ���������� �� ������ ����������
//	cust_name.set_proj_param(emp);
//}
//void Manager::show_project_info(Customer<Project>& cust_name){				//���� ���������� ��� ������, ���������� �� ����������			
//	vector<string> info = cust_name.get_project()->get_info();
//	cout << "����� �������: " << info[0] << endl;
//	cout << "������ ���������(� ����): " << info[1] << endl;
//	cout << "������� �������: " << info[2] << endl;
//	cout << "ID �������: " << info[3] << endl;
//	cout << "���������� ��������� �� ��������: " << info[4] << endl;
//}
void Manager::set_tasks(vector<string> param, int num_of_proj) {		//����� ������� ��� ��������� �������
	if (num_of_proj > this->tasks.size()) {
		this->tasks.push_back({});
		this->tasks[num_of_proj - 1] = param;
	}
	else {
		this->tasks[num_of_proj - 1] = param;
	}
}
void Manager::show_tasks(int num_of_proj) {						//���� �������, ������� ��� �������
	if ((num_of_proj - 1) < this->tasks.size()) {
		cout << "����� �������� �� �������: " << endl;
		for (int i = 0; i < this->tasks[(num_of_proj - 1)].size(); i++) {
			cout << this->tasks[(num_of_proj - 1)][i] << endl;
		}
	}
}
void Manager::add_worker(Worker* emp, int num_of_proj, Customer<Project>& cust_name) {		//��������� ���������� �� �������� ������
	if (emp->get_id() != 0) {
		int number_of_emp = this->get_num_of_emp(cust_name);
		if (num_of_proj > this->workers.size()) {
			this->workers.push_back({});
		}
		if (number_of_emp > this->workers[num_of_proj - 1].size()) {
			this->workers[num_of_proj - 1].push_back(emp);
		}
		else {
			cerr << "����������� ������� ���������� �� ������" << endl;
		}
	}
}
void Manager::set_trainee_data(Trainee& emp, int id, int time) {
	emp.set_internship_time(time);
	emp.set_id(id);
}
void Manager::set_worker_task(int num_of_proj) {				//������������ ������� ��� ����������
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
Worker* Manager::get_worker(int index, int num_of_proj) {			//��������� ��������� �� ���������� � ������
	return workers[num_of_proj - 1][index];
}
void Manager::set_id(int id, Worker& emp) {						//������������ id ���������� ����������
	emp.set_id(id);
}
void Manager::delete_by_id(int worker_id) {						//����� ���������� �� id � ����� ����������
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
void Manager::write_proj_to_file(Customer<Project>& cust_name) {			//����� ����� ������� � ����
	cust_name.get_project()->write_to_file(cust_name.get_name(), cust_name.get_id());
}
void Manager::search_by_id(int worker_id) {						//����� ���������� �� id � ����� ����������
	for (int i = 0; i < this->workers.size(); i++) {
		for (int j = 1; j <= this->workers[i].size(); j++) {
			if (this->workers[i][j - 1]->get_id() == worker_id) {
				this->workers[i][j - 1]->show_info();
				return;
			}
		}
	} 
}
void Manager::add_and_sort_id() {								//����� ���������� ������ id ���������� � ���������� ����
	int size = 0;
	for (int i = 0; i < this->workers.size(); i++) { //����������� ���������� � �����
		for (vector<Worker*>::iterator j = this->workers[i].end(); j > this->workers[i].begin(); j--) {
			size++;
		}
	}
	int countt = size;
	this->id_data = new int[countt];
	for (int i = 0; i < this->workers.size(); i++) { //��������� id � �����
		for (int j = 1; j <= this->workers[i].size(); j++) {
			countt--;
			this->id_data[countt] = this->workers[i][j - 1]->get_id();
		}
	}
	sort(this->id_data, this->id_data + size); //���������� ������
	reverse(this->id_data, this->id_data + size);
	cout << "³��������� ��������: " << endl;
	remove(this->id_data, this->id_data + size, 3512);
	for_each(this->id_data, this->id_data + size - 1, printElement);
	int count_number = count(this->id_data, this->id_data + size, 3142);
	cout << count_number << endl;
}
void printElement(int id) {
	cout << id << endl;
}
void Manager::show_info() {
	cout << "���������� �� ���������:" << endl;
	cout << "��'�: " << this->name << endl;
	cout << "��������: " << this->salary << endl;
	cout << "ID: " << this->get_id() << endl;
	cout << "����� � �����: " << this->exp_in_job << endl;
}
void Project::set_param(string name, int time) {			//����� ���� ����� � ������ �������
	this->project_name = name;
	this->time_to_complete = time;
}
void Project::set_param(int price, int id) {			//����� ���� ���� � id �������
	this->price = price;
	this->id = id;
}
void Project::set_param(int emp) {				//����� ���� ������� ���������� �� ������
	this->number_of_emp = emp;
}
vector<string> Project::get_info() {				// ����� ��������� ���������� �������
	Project temp = Project(*this);
	vector<string> info;
	info.push_back(temp.project_name);
	info.push_back(to_string(temp.time_to_complete));
	info.push_back(to_string(temp.price));
	info.push_back(to_string(temp.id));
	info.push_back(to_string(temp.number_of_emp));
	return info;
}
void Project::write_to_file(string cust_name, int id) {							//����� ������ ����� ������� � ����
	cout << "������ ����� ����� ��� ������" << endl;
	string file_name;
	cin >> file_name;
	file_name = file_name + ".txt";
	try {
		ofstream write_project(file_name, ios::app);
		if (!write_project.is_open()) {
			throw MyException("������� ��� ������� �����");
		}
		write_project << "������ �������� " << cust_name << "  ; ID: " << id << endl;
		write_project << "����� �������: " << this->project_name << "\n" << "��� �� ���������: " << this->time_to_complete << "\n" << "������� �������: " << this->price << endl;
		write_project << "ID: " << this->id << "\n" << "ʳ������ ���������� �� ������: " << this->number_of_emp << "\n";
		write_project.close();
	}
	catch (MyException& e) {
		cerr << "�������� �������: " << e.what() << endl;
	}
}
void SoftwareProject::set_param(string name, int time) {			//����� ���� ����� � ������ �������
	this->project_name = name;
	this->time_to_complete = time;
}
void SoftwareProject::set_param(int price, int id) {			//����� ���� ���� � id �������
	this->price = price;
	this->id = id;
}
void SoftwareProject::set_param(int emp) {				//����� ���� ������� ���������� �� ������
	this->number_of_emp = emp;
}
vector<string> SoftwareProject::get_info() {				// ����� ��������� ���������� �������
	SoftwareProject temp = SoftwareProject(*this);
	vector<string> info;
	info.push_back(temp.project_name);
	info.push_back(to_string(temp.time_to_complete));
	info.push_back(to_string(temp.price));
	info.push_back(to_string(temp.id));
	info.push_back(to_string(temp.number_of_emp));
	return info;
}
void SoftwareProject::write_to_file(string cust_name, int id) {							//����� ������ ����� ������� � ����
	cout << "������ ����� ����� ��� ������" << endl;
	string file_name;
	cin >> file_name;
	file_name = file_name + ".txt";
	try {
		ofstream write_project(file_name, ios::app);
		if (!write_project.is_open()) {
			throw MyException("������� ��� ������� �����");
		}
		write_project << "������ �������� " << cust_name << "  ; ID: " << id << endl;
		write_project << "����� �������: " << this->project_name << "\n" << "��� �� ���������: " << this->time_to_complete << "\n" << "������� �������: " << this->price << endl;
		write_project << "ID: " << this->id << "\n" << "ʳ������ ���������� �� ������: " << this->number_of_emp << "\n";
		write_project.close();
	}
	catch (MyException& e) {
		cerr << "�������� �������: " << e.what() << endl;
	}
}
void read_proj_from_file(int id) {			//����� ���������� ����� ������� � ����� �� ID ��������
	cout << "������ ����� ����� ��� ����������" << endl;
	string file_name;
	cin >> file_name;
	file_name = file_name + ".txt";
	cout << "������ ��� � �����: " << endl;
	try {
		ifstream proj_read(file_name); 
		if (!proj_read) {
			throw MyException("������� ��� ������� �����");
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
		cerr << "�������� �������: " << e.what() << endl;
	}
}
void Worker::set_task(string task) {					//������������ ������ ����������
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
void Worker::show_task() {								//���� �������� ����������
	cout << this->task << endl;
}
void Worker::add_worker_info(string name, string dep) {		//��������� ���������� ����������
	this->name = name;
	this->department = dep;
}
bool Worker::get_busy() {								//��������� ����� ��� �������� �������� � ����������
	return has_a_task;
}
string Worker::get_department() {						//��������� �����, � ����� ������ �������
	return department;
}
int Human::get_id() {									//��������� id ��'����
	return id;
}
string Human::get_name() {
	return name;
}
int Human::get_salary() {
	return salary;
}
void Human::set_id(int id) {							//������������ id ��'����
	this->id = id;
}
void Human::show_message() {
	cout << "���� ���������� �� Human"<< endl;
	
}
void Worker::show_info() {								//���� ���������� ��� ����������
	cout << "��'� ����������: " << this->name << endl;
	cout << "³���: " << this->department << endl;
	cout << "��������: " << this->task << endl;
	cout << "�� � ��������: " << this->has_a_task << endl;
	cout << "ID: " << this->get_id() << endl;
	cout << "�������� ��������: " << this->salary << endl;
	Vacancy::show_company();
	show_message();
}
Worker::Worker() : Trainee("None", 0), department("None") {}     //������������ ��� �����
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
Trainee::~Trainee(void){												//����������� ��� �����
	cout << "�������� ��'���� ��� Trainee " << name << endl;
}
template <class Proj>
Customer<Proj>::~Customer(void) {
	cout << "�������� ��'���� ��� Customer " << name << endl;
}
Manager::~Manager(void) {
	cout << "�������� ��'���� ��� Manager " << name << endl;
}
Human::~Human(void) {
	cout << "�������� ��'���� ��� Human " << name << endl;
}
Worker::~Worker(void) {
	cout << "�������� ��'���� ��� Worker " << name << endl;
}
string Vacancy::company = "IBM";										//������� ���� ����� Worker
string Vacancy::job = "IT";
void Vacancy::show_company() {
	cout << "�������, �� ��� ������ �������: " << company << endl;
}
void Vacancy::show_job() {
	cout << "������ ������: " << job << endl;
}
void Trainee::set_internship_time(int time) {
	this->internship_time = time;
}
void Trainee::show_info() {
	cout << "���������� �� �������:" << endl;
	cout << "��'�: " << this->name << endl;
	cout << "ID: " << this->get_id() << endl;
	cout << "��� ����������: " << this->internship_time << endl;
}
void Human::show_salary() {
	cout << "�������� "<< name << " : " << this->salary << endl;
}
void Worker::show_salary() {
	cout << "�������� ���������� " << name << " � ���쳺�: " << this->salary << " + " << this->premium <<endl;
}
void Manager::show_salary() {
	cout << "�������� ���������� " << name << " � ���쳺�: " << this->salary << " + " << this->premium << endl;
}
void count_salary_for_year(Worker emp) {						//������������ ������� ���������� ��������
	cout << "�������� ��������� �������� �� ��: " << emp * 12 << endl;
}
void count_salary_for_year(Worker* emp) {
	cout << "�������� ��������� �������� �� ��: " << (*emp) * 12 << endl;
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