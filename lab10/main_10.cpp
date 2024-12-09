#include <iostream>
#include "GraduationDao.h"
#include "Student.h"

int main() {
    string subjects[] = {"roman", "matek", "magyar"};
    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < 3; ++i) {
        dao.saveGradesForSubject(subjects[i], subjects[i]);
    }
    dao.computeAverage();

    return 0;
}