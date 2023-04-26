#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Teacher;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int newDay, int newMonth, int newYear) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (newYear > 0) {
            this->year = newYear;
        } else {
            this->year = 2023;
        }

        if (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0) {
            days[1] += 1;
        }

        if (newMonth > 0 && newMonth < 12) {
            this->month = newMonth;
        } else {
            this->month = 1;
        }

        if (newDay > 0 && newDay < days[this->month - 1]) {
            this->day = newDay;
        } else {
            this->day = 1;
        }
    }

    int getDay() const {
        return this->day;
    };

    int getMonth() const {
        return this->month;
    };

    int getYear() const {
        return this->year;
    };
};

bool operator>(const Date &left, const Date &right) {
    return left.getYear() > right.getYear() ||
           left.getYear() == right.getYear() && left.getMonth() > right.getMonth() ||
           left.getYear() == right.getYear() && left.getMonth() == right.getMonth() && left.getDay() > right.getDay();
}


class Info {
public:
    virtual ~Info() { };
};


class Statement : public Info {
private:
    map <Teacher*, Date*> LastMarksByTeacherMap;
public:
    void addTeacher(Teacher* teacher) {
        this->LastMarksByTeacherMap[teacher] = new Date(1, 1, 1);
    }
    void addMark(Teacher* teacher, Date* date) {
        this->LastMarksByTeacherMap[teacher] = date;
    }
    map <Teacher*, Date*> getStatement() {
        return this->LastMarksByTeacherMap;
    }
};

class IObserver {
public:
    virtual void update(Info *info) = 0;

    virtual ~IObserver() = default;
};

class IObservable {
private:
    Info *info;
protected:
    vector<IObserver *> observers;

public:
    virtual void registerObserver(IObserver *o) {
        this->observers.push_back(o);
    };

    virtual void removeObserver(IObserver *o) {
        this->observers.erase(std::remove(this->observers.begin(), this->observers.end(), o), this->observers.end());
    };

    virtual void notifyObservers() {
        for (auto &observer: this->observers) {
            observer->update(this->info);
        }
    };

    ~IObservable() {
        delete this->info;
        for (auto &observer: this->observers) {
            delete observer;
        }
    }
};


class Teacher {
private:
    string fio;
public:
    string getFio() {
        return this->fio;
    }

    Teacher(string fio) {
        this->fio = fio;
    }

    void addMark(Date* date, Statement* statement) {
        statement->addMark(this, date);
    }
};


class University : public IObservable {
private:
    Statement *statement;

public:
    University(Statement* statement) {
        this->statement = statement;
    }

    ~University() {
        delete this->statement;
    }

    void notifyObservers() override {
        for (auto &observer: this->observers) {
            observer->update(this->statement);
        }
    };

    void verify() {
        notifyObservers();
    }
};


class Deanery : public IObserver {
private:
    Date* verificationDate;
public:
    Date getVerificationDate() {
        return *this->verificationDate;
    }
    void setVerificationDate(Date* date) {
        this->verificationDate = date;
    }

    void update(Info *info) override {
        Statement* statement = dynamic_cast<Statement*>(info);
        map<Teacher*, Date*> data = statement->getStatement();
        for (auto it = data.begin(); it != data.end(); it++) {
            if (it->second < this->verificationDate) {
                cout << "Teacher " << it->first->getFio() << " hasn't given the grades yet." << endl;
            }
        }
    }
};
