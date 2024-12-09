//
// Created by Csala on 2024. 12. 02..
//

#ifndef LAB10_STUDENTSERVICEIMPL_H
#define LAB10_STUDENTSERVICEIMPL_H
#include <string>
#include <vector>
#include "StudentService.h"
#include "GraduationDao.h"
using namespace std;

class StudentServiceImpl : public StudentService{
    GraduationDao *dao;
public:
    StudentServiceImpl(GraduationDao *dao) : dao(dao) {}
    virtual bool isEnrolled(int id) const override;
    virtual vector<string> getSubjects(int id) const override;
    virtual double getResultBySubject(int id, const string& subject) const override;
    virtual double getAverage(int id) const override;
    virtual bool isPassed(int id) const override;
};



#endif //LAB10_STUDENTSERVICEIMPL_H
