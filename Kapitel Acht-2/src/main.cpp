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
 *
 * After writing out the three loops in the dispatchCall function, I could've saved some time by
 * condensing things into a single multi-dimensional vector. This has pros and cons though. In the
 * future, this setup does make dealing with respondents, managers, and directors differently
 * easier.
 */

#include<iostream>
#include<vector>

enum class EmployeeRank{
	respondent, manager, director
};

class Employee{
public:
	Employee() :
			busy_(false), rank_(EmployeeRank::respondent){
	}

	Employee(EmployeeRank new_rank_) :
			busy_(false), rank_(new_rank_){
	}
	virtual ~Employee(){
	}

	virtual bool isBusy() = 0;
	virtual void assignCall() = 0;
protected:
	bool busy_;
	EmployeeRank rank_;
};

class Respondent: public Employee{
public:
	Respondent() :
			Employee(EmployeeRank::respondent){
	}
	bool isBusy() override{
		return busy_;
	}
	void assignCall(){
		busy_ = true;
	}
};

class Manager: public Employee{
public:
	Manager() :
			Employee(EmployeeRank::manager){
	}
	bool isBusy() override{
		return busy_;
	}
	void assignCall(){
		busy_ = true;
	}
};

class Director: public Employee{
public:
	Director() :
			Employee(EmployeeRank::director){
	}
	bool isBusy() override{
		return busy_;
	}
	void assignCall(){
		busy_ = true;
	}
};

class Call{
public:
	Call() :
			min_rank_to_handle_(EmployeeRank::respondent){
	}
	void incrementRank(){
		if(min_rank_to_handle_ == EmployeeRank::respondent){
			min_rank_to_handle_ = EmployeeRank::manager;
		}else if(min_rank_to_handle_ == EmployeeRank::manager){
			min_rank_to_handle_ = EmployeeRank::director;
		}
	}
private:
	EmployeeRank min_rank_to_handle_;
};

class CallCenter{
public:
	CallCenter() :
			last_called_respondent_(5), last_called_manager_(0), last_called_director_(0){
		num_respondent_ = 10;
		num_manager_ = 5;
		num_director_ = 2;

		respondents_.resize(num_respondent_);
		managers_.resize(num_manager_);
		directors_.resize(num_director_);
	}

	void dispatchCall(){
		unsigned int x = last_called_respondent_ + 1;
		while(true){
			if(x >= num_respondent_){
				x = 0;
			}
			std::cout << "Respondent x = " << x << std::endl;
			if(!respondents_[x].isBusy()){
				respondents_[x].assignCall();
				std::cout << "Assigned Respondent " << x << std::endl;
				last_called_respondent_++;
				if(last_called_respondent_ >= num_respondent_){
					last_called_respondent_ = 0;
				}
				return;
			}
			if(x == last_called_respondent_){
				break;
			}
			x++;
		}
		//  I admit this is pretty messy and could be done differently.
		x = last_called_manager_ + 1;
		while(true){
			if(x >= num_manager_){
				x = 0;
			}
			std::cout << "Manager x = " << x << std::endl;
			if(!managers_[x].isBusy()){
				managers_[x].assignCall();
				std::cout << "Assigned Manager " << x << std::endl;
				last_called_manager_++;
				if(last_called_manager_ >= num_manager_){
					last_called_manager_ = 0;
				}
				return;
			}
			if(x == last_called_manager_){
				break;
			}
			x++;
		}
		x = last_called_director_ + 1;
		while(true){
			if(x >= num_director_){
				x = 0;
			}
			std::cout << "Director x = " << x << std::endl;
			if(!directors_[x].isBusy()){
				directors_[x].assignCall();
				std::cout << "Assigned Director " << x << std::endl;
				last_called_director_++;
				if(last_called_director_ >= num_director_){
					last_called_director_ = 0;
				}
				return;
			}
			if(x == last_called_director_){
				break;
			}
			x++;
		}
	}

private:
	unsigned int num_respondent_;
	unsigned int num_manager_;
	unsigned int num_director_;
	unsigned int last_called_respondent_;
	unsigned int last_called_manager_;
	unsigned int last_called_director_;
	std::vector<Respondent> respondents_;
	std::vector<Manager> managers_;
	std::vector<Director> directors_;
	//  I could do this, but I don't want to delve into smart pointers yet. While I know vaguely how
	//  they work, I would prefer not to implement them until I know how many companies plan on
	//  using them.
	//std::vector<std::vector<Employee*>> employees_;
};

int main(){
	CallCenter cc1;
	for(int x = 0; x < 13; x++){
		cc1.dispatchCall();
	}
	std::cout << "done\n";
	return 0;
}
