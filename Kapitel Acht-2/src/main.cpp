/**
 * Imagine you have a call center with three levels of employees: respondent, manager, and director.
 * An incoming telephone call must be first allocated to a respondent who is free. If the respondent
 * can't handle the call, he or she must escalate the call to a manager. If the manager is not free
 * or not able to handle it, then the call should be escalated to a director. Design the classes and
 * data structures for this problem. Implement a method dispatchCall() which assigns a call to the
 * first available employee.
 *
 * Programmer response:
 * This is looking like 3 concrete classes, one abstract/pure virtual class to handle everyone.
 */

class Employee{
public:
	virtual ~Employee(){}
	virtual void dispatchCall() = 0;
};

class Respondent: public Employee{
	virtual void dispatchCall() override{

	}
};

class Manager: public Employee{
	virtual void dispatchCall() override{

	}
};

class Director: public Employee{
	virtual void dispatchCall() override{

	}
};

int main(){
	return 0;
}
