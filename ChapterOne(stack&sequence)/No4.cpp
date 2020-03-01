/*
�����ơ�è������
����Ŀ��ʵ��һ��è�����еĽṹ��Ҫ������£�
1.�û����Ե���add������cat��dog��ʵ����������У�
2.�û����Ե���pollAll�����������������е�ʵ�����ս����е��Ⱥ�˳�����ε�����
3.�û����Ե���pollDog��������������dog���ʵ�����ս����е��Ⱥ�˳�����ε�����
4.�û����Ե���pollCat��������������cat���ʵ�����ս����е��Ⱥ�˳�����ε�����
5.�û����Ե���isEmpty���������������Ƿ���dog��cat��ʵ����
6.�û����Ե���isDogEmpty���������������Ƿ���dog���ʵ����
7.�û����Ե���isCatEmpty���������������Ƿ���cat���ʵ����
���Ѷȡ�ʿ
*/

#include <iostream>
#include <queue>
#include <stdexcept>

class Pet{
public:
	Pet(){}
	Pet(std::string type) {
		type_ = type;
	}
	std::string getPetType() {
		return type_;
	}
	void setPetType(std::string type) {
		type_ = type;
	}
private:
	std::string type_;
};

class Dog: public Pet {
public:
	Dog():Pet("dog"){

	}
};

class Cat : public Pet {
public:
	Cat() :Pet("cat") {

	}
};

class PetEnterQueue {
public:
	PetEnterQueue(Pet pet, int count) {
		pet_ = pet;
		count_ = count;
	}

	Pet getPet() {
		return pet_;
	}
	
	long getCount() {
		return count_;
	}

	std::string getEnterPetType() {
		return pet_.getPetType();
	}

private:
	Pet pet_;
	int count_;
};



class DogCatQueue{
public:
	DogCatQueue() {
		count_ = 0;
	}

	void add(Pet pet) {
		if (pet.getPetType() == "dog") {
			DogQ_.push(PetEnterQueue(pet, count_++));
		}
		else if (pet.getPetType() == "cat") {
			CatQ_.push(PetEnterQueue(pet, count_++));
		}
	}

	Pet pollAll() {
		Pet pet;

		if (!DogQ_.empty() && !CatQ_.empty()) {
			if (DogQ_.front().getCount() < CatQ_.front().getCount()) {
				pet = DogQ_.front().getPet();
				DogQ_.pop();
			}
			else {
				pet = CatQ_.front().getPet();
				CatQ_.pop();
			}
		}
		else if (!DogQ_.empty()) {
			pet = DogQ_.front().getPet();
			DogQ_.pop();
		}
		else if (!CatQ_.empty()) {
			pet = CatQ_.front().getPet();
			CatQ_.pop();
		}
		else {
			throw std::runtime_error("Error empty all stack");
		}

		return pet;
	}

	Dog pollDog() {
		if (!isDogQueueEmpty()) {
			Dog dog;
			Pet pet = DogQ_.front().getPet();
			Pet* p = &dog;
			*p = pet;
			DogQ_.pop();
			return dog;
		}
		throw std::runtime_error("Error,empty dog queue!");
	}

	Cat pollCat() {
		if (!isCatQueueEmpty()) {
			Cat cat;
			Pet pet = CatQ_.front().getPet();
			Pet* p = &cat;
			*p = pet;
			CatQ_.pop();
			return cat;
		}
		throw std::runtime_error("Error,empty cat queue!");
	}

	bool isEmpty() {
		return DogQ_.empty() && CatQ_.empty();
	}

	bool isDogQueueEmpty() {
		return DogQ_.empty();
	}

	bool isCatQueueEmpty() {
		return CatQ_.empty();
	}
private:
	std::queue<PetEnterQueue> DogQ_;
	std::queue<PetEnterQueue> CatQ_;
	int count_;
};

int main(){

	DogCatQueue cdq;
	if (cdq.isEmpty())
		std::cout << "All queue is empty!" << std::endl;
	cdq.add(Dog());
	//cdq.add(Cat());
	if (!cdq.isDogQueueEmpty())
		std::cout << "Dog queue is not empty!" << std::endl;
	if (!cdq.isCatQueueEmpty())
		std::cout << "Cat queue is not empty!" << std::endl;

	for (int i = 0; i<2; i++)
	{
		cdq.add(Cat());
		cdq.add(Dog());
	}
	std::cout << "popAll:" << cdq.pollAll().getPetType().c_str() << std::endl;
	std::cout << "popDog:" << cdq.pollDog().getPetType().c_str() << std::endl;
	std::cout << "popCat:" << cdq.pollCat().getPetType().c_str() << std::endl;
	std::cout << "popAll:" << cdq.pollAll().getPetType().c_str() << std::endl;
	std::cout << "popAll:" << cdq.pollAll().getPetType().c_str() << std::endl;

	if (cdq.isEmpty())
		std::cout << "All queue is empty!" << std::endl;

	return 0;
}