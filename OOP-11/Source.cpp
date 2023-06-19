#include <iostream>
#include <string>
#include <vector>

//Принцип SRP - принцип единственной ответственности (каждый блок отвечает только за одну функцию)
class myClass {
public:
	explicit myClass(int a) {
		if (a >= 0) {
			data.reserve(a);
			this->init();
		}
	}

	int operator+ (const myClass obj)const {
		int result{};
		for (size_t i = 0; i < obj.data.size(); i++) {
			result += obj.data[i];
		}
		for (size_t i = 0; i < this->data.size(); i++) {
			result += this->data[i];
		}
		return result;
	}
private:
	void init() {
		for (size_t i = 0; i < data.capacity(); i++) {
			data.push_back(i + 1);
		}
	}
	std::vector<int> data;
};

class Integer {
public:
	int units;
	Integer operator ++(int) {
		Integer result;
		result.units = units;
		units += 1;
		return result;
	}
	Integer operator --() {
		units -= 1;
		return *this;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	/*myClass a(5);
	myClass b(7);
	std::cout << a + myClass(6);*/
	Integer a;
	a.units = 9;
	Integer r3(a++);
	Integer r4(--a);

	return 0;
}