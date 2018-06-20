#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum EmployeeLevel{ 사원, 대리, 과장, 차장, 부장 };
class Employee {
protected:
    string name;
    EmployeeLevel level;
    public :
    Employee(string name, EmployeeLevel level){
        this->name = name;
        this->level = level;
    }
    string getName(){return name;}
    EmployeeLevel getLevel(){return level;}
    friend ostream& operator<<(ostream& os, Employee& e);
};

ostream& operator << (ostream& os, Employee& e){
    os << e.level << "\t" << e.name << endl;
    return os;
}


class Manager : public Employee {
    vector<Employee*> group;
public:
    Manager(string _name, EmployeeLevel _level):
    Employee(_name,_level){}
    void addEmployee(Employee* a){
        Manager inp(a->getName(), a->getLevel());
        group.push_back(&inp);
    }
    friend ostream& operator<<(ostream& os, Manager& m);
};

ostream& operator << (ostream& os, Manager& m){
    os << m.level << '\t' << m.name << endl <<"List of employees managed by me" << endl;
    return os;
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
