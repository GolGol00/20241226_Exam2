

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Animal
{
public:
	virtual void makeSound() = 0;

	virtual ~Animal()
	{
		cout << "동물(은)이 떠나갔다.. FareWell 동물" << endl;
	};
protected:

};

class Dog : public Animal
{
public:
	Dog()
	{
		cout << "개(은)가 태어났다.. Welcome 멍멍아!" << endl;
	}
	void makeSound()
	{
		cout << "멍멍!" << endl;
	}
	~Dog()
	{
		cout << "개(은)이 떠나갔다.. FareWell 멍멍" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat()
	{
		cout << "고양이(은)가 태어났다.. Welcome 야옹아!" << endl;
	}
	void makeSound()
	{
		cout << "야옹!!" << endl;
	}
	~Cat()
	{
		cout << "고양이(은)이 떠나갔다.. FareWell 야옹" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow()
	{
		cout << "소(은)가 태어났다.. Welcome 탱탱!" << endl;
	}
	void makeSound()
	{
		cout << "음머어~!" << endl;
	}
	~Cow()
	{
		cout << "소(은)이 떠나갔다.. FareWell 탱탱" << endl;
	}
};


class Zoo {
private:
	int animalCount = 0;
	Animal* animals[5];
public:
	void addAnimal(Animal* animal)
	{
		if (animalCount < 5)
		{
			animals[animalCount] = animal;
			animalCount++;
		}
	}

	void performActions()
	{
		cout << "외쳐라 모든 동물들아" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (animals[i] != NULL) {
				animals[i]->makeSound();
			}
		}
	}

	~Zoo()
	{
		for (int i = 0; i < animalCount; i++)
		{
			delete animals[i];
		}
		cout << "없어져라.." << endl;
	}
};

Animal* createRandomAnimal()
{
	int randomInt = rand() % 3;

	if (randomInt == 0)
	{
		Animal* myAnimal;
		myAnimal = new Dog();
		return myAnimal;
	}

	if (randomInt == 1)
	{
		Animal* myAnimal;
		myAnimal = new Cat();
		return myAnimal;
	}

	if (randomInt == 2)
	{
		Animal* myAnimal;
		myAnimal = new Cow();
		return myAnimal;
	}
}

int main()
{
	Zoo* zoo = new Zoo();
	for (int i = 0; i < 5; i++)
	{
		Animal* randomAnimal = createRandomAnimal();
		zoo->addAnimal(randomAnimal);
	}

	zoo->performActions();
	zoo->~Zoo();

	return 0;
}