#include "AppMenu.h"
#include "CustomerForm.h"
#include "ManagerForm.h"
#include "WorkerForm.h"
#include "TraineeForm.h"

using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab8::AppMenu form; //назва створеного проекту
	Application::Run(% form); //запуск форми 
}
System::Void Lab8::AppMenu::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	CustomerForm^ CustForm = gcnew CustomerForm();
	CustForm->Show();
}
System::Void Lab8::AppMenu::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	ManagerForm^ MngForm = gcnew ManagerForm();
	MngForm->Show();
}
System::Void Lab8::AppMenu::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	WorkerForm^ WorkForm = gcnew WorkerForm();
	WorkForm->Show();
}
System::Void Lab8::AppMenu::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	TraineeForm^ TrnForm = gcnew TraineeForm();
	TrnForm->Show();
}