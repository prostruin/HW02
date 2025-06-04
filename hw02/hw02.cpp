
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;

class Animal // 애니멀 클래스 구현
{
public:
	virtual void makeSound() = 0; // 순수 가상 함수로 선언

};

class Zoo // zoo 클래스 구현
{
private:
	Animal** animals;
public:
	Zoo()
	{
		animals = new Animal * [10]; // 동물 포인터 배열을 동적 할당
		for (int i = 0; i < 10; i++)
		{
			animals[i] = nullptr; // 배열의 모든 공간을 nullptr로 초기화
		}
	}
	~Zoo()
	{
		for (int i = 0; i < 10; i++)
		{
			if (animals[i] != nullptr)
			{
				delete animals[i]; // 메모리 누수 방지로 해제
			}
		}
		delete[] animals; // 동적 할당된 배열 해제
	}

	void addAnimal(Animal* animal) // 동물을 추가하는 함수
	{
		for (int i = 0; i < 10; i++)
		{
			if (animals[i] == nullptr) // 배열의 공간이 비어있을때만 동물을 추가
			{
				animals[i] = animal;

				return;
			}
		}
	}

	void performActions()
	{

		for (int i = 0; i < 10; i++)
		{

			animals[i]->makeSound();
		}
	}
};

class Dog : public Animal // dog 클래스 구현
{
	void makeSound() // 가상 함수 통해 소리내는 함수 구현
	{
		cout << "멍멍" << endl;
	}
};

class Cat : public Animal // cat 클래스 구현
{
	void makeSound() // 가상 함수 통해 소리내는 함수 구현
	{
		cout << "야옹" << endl;
	}

};

class Cow : public Animal // cow 클래스 구현
{
	void makeSound() // 가상 함수 통해 소리내는 함수 구현
	{
		cout << "음메" << endl;
	}
};

Animal* createRandomAnimal() // 랜덤으로 동물을 생성하는 함수
{

	int random = rand() % 3; // 0,1,2 중 하나의 랜덤 숫자를 생성해서 그에 따른 동물을 동적 으로 생성
	switch (random)
	{
	case 0:
		return new Dog();
	case 1:
		return new Cat();
	case 2:
		return new Cow();
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 초기화
	Animal* animals[10] = { nullptr }; // 동물 포인터 배열을 선언하고 빈공간으로 초기화
	Zoo zoo; // Zoo 객체 생성
		
	for (int i = 0; i < 10; i++)
	{
		animals[i] = createRandomAnimal(); // 랜덤으로 동물 생성해서 배열에 저장.
	}
	for (int i = 0; i < 10; i++)
	{
		if (animals[i] != nullptr)
		{
			zoo.addAnimal(animals[i]); // zoo에 동물을 추가하고
			//animals[i]->makeSound(); // 그 동물들의 울음소리를 출력.
		}
	}
	zoo.performActions();
   return 0;
}