#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum EmployeeLevel{ 사원, 대리, 과장, 차장, 부장 };
class Employee {
    string name;
    EmployeeLevel level;
    public :
    Employee(string name, EmployeeLevel level){
        this->name = name;
        this->level = level;
    }
    friend ostream& operator<<(ostream& os, Employee& e);
};

ostream& operator << (ostream& os, Employee& e){
    os << e.level << "\t" << e.name << endl;
}


class Manager : public Employee {
    vector<Employee*> group;
public:
    void addEmployee(string name, EmployeeLevel level){
        Manager inp
        this.name = name;
        this.level = level;
        group.push_back(levle, name);
    }
    friend ostream& operator<<(ostream& os, Manager& m1);
};

ostream& operator << (ostream& os, Manager& m){
    os << m.level << \t\ << m.name << endl <<"List of employees managed by me" << endl << Manager.group;
}

int main()
{
    Employee e1("홍", 사원), e2("김", 대리), e3("차", 사원);
    cout<< e1 << e2 << e3;
    
    Manager m1("Tom", 차장);
    m1.addEmployee(&e1);
    m1.addEmployee(&e2);
    m1.addEmployee(&e3);
    cout << endl << "Information for Manager" << endl;
    cout << m1;
}
