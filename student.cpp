#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) 
/* TODO: Initializer list 사용해 초기화 해보기 */
: midterm(midterm),final(final){}

float StudentRecord::getTotal() const {
    /* TODO */
    float average = (midterm+final)/2;
    return average;
}

void StudentRecord::updateScores(float midterm, float final) {
    /* TODO: this keyword 사용해 보기 */
    this -> midterm =midterm;
    this -> final = final;
}


/* Student */

Student::Student() 
/* TODO: Initializer list 사용해 초기화 해보기 */
: id(0), name(""),record(0.0f,0.0f){ }

Student::Student(const char *name, int id, float midterm, float final)
/* TODO: Initializer list 사용해 초기화 해보기 */
: id(id),name(name),record(midterm,final){  }

void Student::updateRecord(const char *name, float midterm, float final) {
    /* TODO */
    this -> name = name;
    this -> record = midterm,final;

}

