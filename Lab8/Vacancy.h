#pragma once
#include <string>
#include <vector>
using namespace std;
//клас Вакансії
class Vacancy {
public:
	Vacancy();
	static void show_company();
	static void show_job();
private:
	static string job;
	static string company;
};
