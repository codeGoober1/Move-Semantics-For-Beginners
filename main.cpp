#include <iostream>
#include <chrono>
#include <thread>

class Data
{
public:
	Data() = default;

	Data(int value) : value(value)
	{
		std::cout << "Created\n";
	}

        /*
	Data(Data&& other) noexcept : value(other.value) 
	{
		std::cout << "Moved\n";
	}
        */

	Data& operator=(Data&& other) noexcept
	{
		std::cout << "Moved\n";

		if (this != &other)
		{
			value = other.value;
			other.value = 0;
		}
		return *this;
	}

	~Data()
	{
		std::cout << "Destroyed\n";
	}

	void print()
	{
		std::cout << value << "\n";
	}

	void assign(int e)
	{
		value = e;
	}

private:
	int value = 0;
};

/*
class Entity
{
public:
	Entity(Data&& d) : d(std::move(d)) {}

	void print()
	{
		d.print();
	}
private:
	Data d;
};
*/

int main()
{
	using namespace std::literals::chrono_literals;

	Data d1;
	Data d2;

	int in1;
	int in2;

	std::string decision;

	std::cout << "First number: \n";
	std::cout << "\n";

	std::this_thread::sleep_for(1s);

	std::cin >> in1;
	d1.assign(in1);

	std::this_thread::sleep_for(1s);

	std::cout << "\n";

	std::cout << "Second number: \n";
	std::cout << "\n";

	std::cin >> in2;
	d2.assign(in2);

	std::cout << "\n";

	std::this_thread::sleep_for(1s);

	std::cout << "Do you want to move Data1 into Data2 or Data2 into Data1?\n";
	std::cout << "\n";

	std::cin >> decision;

	std::cout << "\n";

	std::this_thread::sleep_for(1s);

	std::cout << "Data before move:\n";
	std::cout << "----------------------------------------\n";
	std::cout << "\n";

	d1.print();
	d2.print();

	std::cout << "\n";

	std::this_thread::sleep_for(1s);

	std::cout << "Data after move:\n";
	std::cout << "----------------------------------------\n";
	std::cout << "\n";

	if (decision == "Data1")
		d1 = std::move(d2);

	else if (decision == "Data2")
		d2 = std::move(d1);

	d1.print();
	d2.print();
}
