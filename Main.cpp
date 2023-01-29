#include <iostream>
#include <vector>
class IVehicle {
public:
	virtual void printName()const = 0;
	virtual ~IVehicle() {}
};
class Car : virtual public IVehicle {
public:
	void printName()const  override {
		std::cout << "Car class" << std::endl;
	}
};
void foo(const std::vector<const IVehicle*>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		vec[i]->printName();
	}
}
int main() {
	Car car;
	IVehicle* vehicle2 = &car;
	const std::vector<const IVehicle*> vec{ vehicle2 };
	foo(vec);
}