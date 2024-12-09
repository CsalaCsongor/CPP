//
// Created by Csala on 2024. 12. 02..
//

#ifndef LAB10_STUDENTSERVICE_H
#define LAB10_STUDENTSERVICE_H
#include <string>
#include <vector>

using namespace std;
class StudentService {
public:
    virtual bool isEnrolled(int id) const = 0;
    virtual double getResultBySubject(int id, const string& subject) const = 0;
    virtual vector<string> getSubjects(int id) const = 0;
    virtual double getAverage(int id) const = 0;
    virtual bool isPassed(int id) const = 0;
};



#endif //LAB10_STUDENTSERVICE_H
