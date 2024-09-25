#include <iostream>

#include <fstream>

using namespace std;

class Employee{//b1

	public:
		char emp_name [10];
		float salary;
		int age;
		void read_data(void);
		void write_data(void);

};//b1

void Employee::read_data(void){//b2
	cout<<"Enter Employee's name - ";
	cin>>emp_name;
	cout<<"Enter Employee's  salary - ";
	cin>>salary;
	cout<<"Enter Employee's age - ";
	cin>>age;

}//b2

void Employee::write_data(void){//b3

	cout<<"Employee's name is - "<<emp_name<<endl;

	cout<<"Employee's salary is - "<<salary<<endl;

	cout<<"Employee's age is - "<<age<<endl;

}//b3

int main(){//b4

	Employee emp;

	fstream file;

	file.open("Employee.txt", ios::app | ios::in | ios::out | ios::binary);
	//ifstream infile("qbits.txt");
	//ofstream outfile("qbits.txt");

	char choice;
	do{//b5

		emp.read_data();

		file.write(reinterpret_cast<char*>(&emp), sizeof(emp));
		
		cout<<"\nEnter next employee's data (y/n) - ";
		cin>>choice;

}//b5
	while(choice=='y');

	file.seekg(0);
	file.read(reinterpret_cast<char*>(&emp), sizeof(emp));
	//ofstream outfile("qbits.txt");


	while(!file.eof()){//b6
		cout<<"\nPersons - ";
		emp.write_data();
		file.read(reinterpret_cast<char*>(&emp), sizeof(emp));

}//b6
	cout<<endl;
	file.close();
	//infile.close();
	//outfile.close();

return 0;

}//b4
