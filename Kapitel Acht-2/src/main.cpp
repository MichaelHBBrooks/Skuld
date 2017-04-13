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

#include<iostream>
#include<vector>

enum class EmployeeRank{
	respondent, manager, director
};

class Employee{
public:
	Employee(EmployeeRank new_rank_): busy_(false), rank_(new_rank_){
	}
	bool isBusy(){
		return busy_;
	}
	void assignCall(){
//		std::cout << "Employee assigned!\n";
		busy_ = true;
	}
protected:
	bool busy_;
	EmployeeRank rank_;
};

class Respondent: protected Employee{
public:
	Respondent(): Employee(EmployeeRank::respondent){
	}
};

class Manager: protected Employee{
	Manager(): Employee(EmployeeRank::manager){
	}
};

class Director: protected Employee{
	Director(): Employee(EmployeeRank::director){
	}
};

class Call{
public:
	Call(): min_rank_to_handle_(EmployeeRank::respondent){
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
		respondents_.reserve(num_respondent_);
		managers_.reserve(num_manager_);
		directors_.reserve(num_director_);
	}

	void dispatchCall(){
		unsigned int x = last_called_respondent_+1;
		while(x != last_called_respondent_){
//			if(!respondents_[x].isBusy()){
//				respondents_[x].assignCall();
//				last_called_respondent_++;
//				if(last_called_respondent_ > num_respondent_){
//					last_called_respondent_ = 0;
//				}
//				return;
//			}
			std::cout << "x = " << x << std::endl;
			x++;
			if(x > num_respondent_){
				x = 0;
				std::cout << "reset\n";
			}
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
};

int main(){
	CallCenter cc1;
	cc1.dispatchCall();
	std::cout << "done\n";
	return 0;
}
