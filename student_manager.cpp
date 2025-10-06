#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students++] = Student(name,id,midterm,final);
   
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if(idx== -1) return;
    for(int i=idx;i<num_of_students-1;i++){
        students[i]=students[i+1];
    }
    --num_of_students;

}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());
    for(int i=0;i<num_of_students;i++){
        if(students[i].getID()==student.getID()){
            students[i]=student;
        }
    }

}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for(int i=0;i<num_of_students;i++){
        if(students[i].getID()==id){
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    float max =0.0f;
    int idx= 0;
    for(int i=0;i<num_of_students;i++){
        if(max < students[i].getRecord().getMidterm()){
            max = students[i].getRecord().getMidterm();
            idx= i;
        }
    }

    return students[idx].getID();
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    float max =0.0f;
    int idx=0;
    for(int i=0;i<num_of_students;i++){
        if(max<students[i].getRecord().getFinal()){
            max =students[i].getRecord().getFinal();
            idx =i;
        }
    }

    return students[idx].getID();
}

int StudentManager::findBestStudent() const {
    /* TODO */
    float max = 0.0f;
    int idx =0;
    for(int i=0;i<num_of_students;i++){
        if(max < students[i].getRecord().getMidterm()+students[i].getRecord().getFinal()){
            max = students[i].getRecord().getMidterm()+students[i].getRecord().getFinal();
            idx =i;
        }
    }
    return students[idx].getID();
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float mid_sum = 0.0f;
    for(int i=0;i<num_of_students;i++){
        mid_sum+=students[i].getRecord().getMidterm();
    }
    float average = mid_sum/num_of_students;
    return average;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float final_sum = 0.0f;
    for(int i=0;i<num_of_students;i++){
        final_sum+=students[i].getRecord().getFinal();
    }
    float average = final_sum/num_of_students;
    return average;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float total_sum = 0.0f;
    for(int i=0;i<num_of_students;i++){
        total_sum+=(students[i].getRecord().getMidterm()+students[i].getRecord().getFinal());
    }
    float average = total_sum/num_of_students;
    return average;
}

