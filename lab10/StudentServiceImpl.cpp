//
// Created by Csala on 2024. 12. 02..
//

#include "StudentServiceImpl.h"
#include "Student.h"
bool StudentServiceImpl::isEnrolled(int id) const {
    Student student1 = dao->findById(id);
}
