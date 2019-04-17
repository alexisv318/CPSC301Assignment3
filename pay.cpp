#include "person.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

void readData(vector <Person> &employees){
ifstream input_file;
string fName;
string lName;
string coName;
int id;
float rate;
float hours;
input_file.open("input.txt");
Person P;
if (input_file.is_open()) {

while (input_file >> fName >> lName >> id >> coName >> rate >> hours){

	 cout << fName << " " << lName << " " << id << " " << coName << " " << rate
<< " " << hours << endl;
P.setFirstName(fName);
P.setLastName(lName);
P.setCompanyName(coName);
P.setEmployeeId(id);
P.setPayRate(rate);
P.setHoursWorked(hours);
employees.push_back(P);

}
input_file.close();
}
}
void getCompanies(vector <Person> &employees, vector<string> &companyNames){
string name;
name = employees.at(0).getCompanyName();


companyNames.push_back(name);	
for (unsigned int i = 0; i < employees.size(); i++) 
{ 
	bool found = false;
	for (unsigned int j = 0; j < companyNames.size(); j++)
	{
		if(employees.at(i).getCompanyName() == companyNames.at(j)){
			found = true;
	 }
	}
	if (!found) {
		companyNames.push_back(employees.at(i).getCompanyName());
	}
	
}
for (unsigned int j = 0; j < companyNames.size(); j++){

}
}
void printHighestPaid(vector <Person> &employees){
int highest = 0;
int index = 0;

for (unsigned int i = 0; i < employees.size(); i++) {
	if (highest < employees.at(i).totalPay()){
	highest = employees.at(i).totalPay();
	index = i;
	
	
	    }
	}
cout << " Highest Paid: " << employees.at(index).fullName() << endl; 
cout << " Employee ID: " << employees.at(index).getEmployeeId() << endl;
cout << " Employer: "  << employees.at(index).getCompanyName() << endl;
cout << " Total Pay: "  << employees.at(index).totalPay() << endl;

}



void separateAndSave(vector<Person> &employees, vector<string> &companyNames){

float totalText = 0;
fstream myfile;
for (unsigned int j = 0; j < companyNames.size(); j++)
{
	myfile.open(companyNames.at(j) + ".txt", fstream::out);
	for (unsigned int i = 0; i < employees.size(); i++){
		
		if (employees.at(i).getCompanyName() == companyNames.at(j)){
			
		totalText += employees.at(i).totalPay();
		
		myfile << employees.at(i).getFirstName() << " " << employees.at(i).getLastName() << " " << employees.at(i).getEmployeeId() << " " << employees.at(i).getCompanyName() << " " << "$" << employees.at(i).totalPay() << endl;

}






}
	myfile << "Total $" << totalText << endl;
    totalText = 0;
	myfile.close();
}		










}

int main(){
	vector<Person> employees;
	vector<string> companyNames;
	

	readData(employees);
	getCompanies(employees, companyNames);
	printHighestPaid(employees);
	separateAndSave(employees, companyNames);	
}
