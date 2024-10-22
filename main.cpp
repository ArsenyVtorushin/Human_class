#include <iostream>
#include <string>

class Human
{
public:
	Human(std::string name, int age) 
		:name(name), 
		age(age)
	{}

	void PrintInfo();
	
	// Каждый человек (и управдом, и житель) может это делать:
	void Walk();
	void Run();
	
	void setName(std::string name);
	void setAge(int age);

	auto getName()const->std::string;
	auto getAge()const->int;

protected:
	std::string name;
	int age;
	std::string role;
};

class Resident : public Human
{
public:
	Resident(std::string name, int age)
		:Human(name, age)
	{
		this->role = "Resident";
	}
	
	// Эти методы отличают обычного жителя дома от управляющего домом
	void Vote();
	void Complain();
	void AskForHeating();
};

class HouseManager : public Human
{
public:
	HouseManager(std::string name, int age)
		:Human(name, age)
	{
		this->role = "House manager";
	}

	// Эти методы отличают управляющего домом от обычного жителя дома
	void TurnOnHeating();
	void OrderToCleanHouse();
	void WriteReceipt();
};



int main()
{
	Resident resident("Bob", 35);
	HouseManager manager("Fred", 57);

	resident.PrintInfo();
	std::cout << '\n';
	manager.PrintInfo();
	std::cout << '\n';

	std::cout << resident.getName() << ": ";
	resident.Walk();

	std::cout << manager.getName() << ": ";
	manager.Walk();

	std::cout << resident.getName() << ": ";
	resident.AskForHeating();

	std::cout << manager.getName() << ": ";
	manager.TurnOnHeating();
	manager.WriteReceipt();
	
	std::cout << resident.getName() << ": ";
	resident.Run();


	return 0;
}




// Human

void Human::PrintInfo()
{
	std::cout << this->name << '\n' << this->age << '\n' << this->role << '\n';
}

void Human::Walk()
{
	std::cout << "Walkin'\n";
}
void Human::Run()
{
	std::cout << "Run away\n";
}

void Human::setName(std::string name)
{
	this->name = name;
}
void Human::setAge(int age)
{
	this->age = age;
}

auto Human::getName()const -> std::string
{
	return this->name;
}
auto Human::getAge()const -> int
{
	return this->age;
}


// Resident

void Resident::Vote()
{
	std::cout << "I vote!\n";
}
void Resident::Complain()
{
	std::cout << "There is a rat in my flat!\n";
}
void Resident::AskForHeating()
{
	std::cout << "Please, turn on the heating!\n";
}


// House manager

void HouseManager::TurnOnHeating()
{
	std::cout << "Within a week we'll turn the heating on\n";
}
void HouseManager::OrderToCleanHouse()
{
	std::cout << "Clean the house, please!";
}
void HouseManager::WriteReceipt()
{
	std::cout << "Here's your receipt\n";
}
