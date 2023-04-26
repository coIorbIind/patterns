#include <iostream>

#include "Observer.h"

int main() {
    Teacher* teacher1 = new Teacher("Ivanov Ivan Ivanovich");
    Teacher* teacher2 = new Teacher("Petrov Petr Petrovich");

    Date *date1;

    Statement* statement = new Statement();
    statement->addTeacher(teacher1);
    statement->addTeacher(teacher2);

    date1 = new Date(15, 1, 2023);

    Deanery* deanery = new Deanery();
    deanery->setVerificationDate(date1);

    teacher1->addMark(date1, statement);

    University* university = new University(statement);
    university->registerObserver(deanery);

    university->verify();
}
