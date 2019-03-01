#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

#include "person.h"
#include "person.cpp"

using namespace std;

void readData(Person employees[], int &size);
void writeData(Person employees[], int size);

void readData(Person employees[], int &size){
  string fname,lname;
  double workedHours,payRate;
  ifstream input;
  input.open("input.txt");

  while(input>>fname>>lname>>workedHours>>payRate){
    Person p;
    p.setFirstName(fname);
    p.setLastName(lname);
    p.setHoursWorked(workedHours);
    p.setPayRate(payRate);
    employees[size] = p;
    size++;
  }
  input.close();
}

void writeData(Person employees[], int size){
  ofstream output;
  output<<setprecision(2)<<fixed;
  output.open("output.txt");
  for(int i = 0; i < size; i++){
    output<<employees[i].fullName()<<" "<<employees[i].totalPay()<<endl;
  }
  output.close();
}
int main(){
  int size = 0;
  Person employees[20];
  readData(employees, size);
  writeData(employees, size);
  return 0;
}
