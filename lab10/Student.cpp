//
// Created by Csala on 2024. 11. 25..
//

#include <fstream>
#include <iostream>
#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) {
    this-> id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

int Student::getId() const {
    return this->id;
}
void Student::setId(int id) {
this->id = id;
}
const string &Student::getFirstName() const {
    return this->firstName;
}
const string &Student::getLastName() const {
    return this->lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string &subject) {
    return grades[subject];
}

const map<string, double> &Student::getGrades() const {

}

void Student::computeAverage() {
    double sum = 0;
 for(auto it:grades){
    if(it.second >= 5)
    {
        sum += it.second;
    }
    else
        break;
 }
 double avg = sum/grades.size();
 cout<< "Atlag: " << avg << endl;
}

double Student::getAverage() const {
    double sum = 0;
    for(auto it:grades){
        if(it.second >= 5)
        {
            sum += it.second;
        }
        else
            break;
    }
    double avg = sum/grades.size();
    return avg;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "Student Name: " << student.id << "\n";
    os << "Grades:\n";

    for (const auto &entry : student.grades) {
        os << entry.first << ": " << entry.second << "\n";
    }

    return os;
    }
