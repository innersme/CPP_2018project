#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Student {
private:
    string name ;
    float gpa ;
public:
    void setGPA(float);
    void setName(string);
};

class School {
private:
    string schoolName ;
    vector<Student> students ;
public:
    School(string);
    void addStudent(string,float);
    void print();
    void sort();
    Student& findStudentWithName(string);
};

School::School(string name){
    schoolName = name;
}
void School::addStudent(string name, float _gpa = 0){
    schoolName = name;
}


int main() {
    School pnu("PNU") ;
    pnu.addStudent("Kim", 2.7F) ;
    pnu.addStudent("Hong", 3.5F) ;
    pnu.addStudent("Lee") ;
    pnu.addStudent("Joo", 1.5F) ;
    pnu.print() ;
    pnu.sort() ; // descending
    pnu.print() ;
    School knu("KNU") ;
    knu.addStudent("Seo", 2.5F) ;
    knu.addStudent("Lee", 3.8F) ;
    knu.print() ;
    Student& lee = pnu.findStudentWithName("Lee") ;
    lee.setGPA(3.3F) ;
    lee.setName("Yoon") ;
    pnu.print() ;
    knu.addStudent("Hong", 4.3F) ;
    Student& hong = knu.findStudentWithName("Hong") ;
    hong.setGPA(3.3F) ;
    hong.setName("Joon") ;
    knu.print() ;
}
