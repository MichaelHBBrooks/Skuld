/**
 * An animal shelter holds only dogs and cats, and operates on a strictly "first in, first out"
 * basis. People must adopt either the "oldest" (based on arrival time) of all animals at the
 * shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest
 * animal of that type). They cannot select which specific animal they would like. Create the data
 * structures to maintain this system and implement operations such as enqueue, dequeueAny,
 * dequeueDog, and dequeueCat. You must use the built-in LinkedList data structure.
 *
 * Programmer response:
 * What would the C++11 equivalent to LinkedList be? List? Forward_list?
 * This is a queue. I know I have access to the head and tail for pushing and popping purposes.
 * I'm just going to go with a queue. That's exactly what this question is describing and they
 * clearly want me to use the built in structure for the language. I suspect their implementation is
 * using Java.
 *
 * Pretty straightforward once I decided to stop making a Pet class followed by a PetQueue class
 * that used an extended Pet. Then complicated stuff happened... I simplified it. This works. It's
 * not the most secure system, but it fits their criteria in hopefully the time I'm allotted.
 */

#include<iostream>
#include<queue>
#include<string>

using namespace std;

enum class PetType{
	dog, cat
};

typedef unsigned int pet_id_t;

class Pet{
public:
	const PetType type_;
	const string name_;
	pet_id_t id_;
	Pet(const PetType new_type_, const string new_name_) : type_(new_type_), name_(new_name_){
		id_ = 0;
	}
};

class PetQueue{
	queue<Pet> cats_;  //  Cats rule.
	queue<Pet> dogs_;  //  Dogs drool.
	unsigned int record_number_;
public:
	PetQueue(){
		record_number_ = 0;
	}
	void enqueue(Pet pet_){
		pet_.id_ = ++record_number_;
		if(pet_.type_ == PetType::cat){
			cats_.push(pet_);
		}else{
			dogs_.push(pet_);
		}
	}

	Pet dequeueAny(){
		if(cats_.front().id_ < dogs_.front().id_){
			Pet some_pet = cats_.front();
			cats_.pop();
			return some_pet;
		}else{
			Pet some_pet = dogs_.front();
			dogs_.pop();
			return some_pet;
		}
	}

	Pet dequeueDog(){
		Pet some_dog = dogs_.front();
		dogs_.pop();
		return some_dog;
	}

	Pet dequeueCat(){
		Pet some_cat = cats_.front();
		cats_.pop();
		return some_cat;
	}
};

int main(){
	Pet dog1(PetType::dog, "Fido");
	Pet dog2(PetType::dog, "Sam");
	Pet cat1(PetType::cat, "Queen Fluffy");
	Pet dog3(PetType::dog, "Fred, Destroyer of Shoes");
	Pet cat2(PetType::cat, "Hunter");

	PetQueue queue;
	queue.enqueue(dog1);
	queue.enqueue(dog2);
	queue.enqueue(cat1);
	queue.enqueue(dog3);
	queue.enqueue(cat2);

	Pet adopted1 = queue.dequeueCat();
	cout << "Name: " << adopted1.name_ << endl;
	Pet adopted2 = queue.dequeueDog();
	cout << "Name: " << adopted2.name_ << endl;
	Pet adopted3 = queue.dequeueAny();
	cout << "Name: " << adopted3.name_ << endl;

	return 0;
}
