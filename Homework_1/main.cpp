// 1

//#include <iostream>
//using namespace std;
//
//
//struct MyCar {
//private:
//	int* number;
//	string color;
//	string model;
//public:
//	MyCar()
//	{
//		this->color = "";
//		this->model = "";
//		this->number = nullptr;
//	}
//
//	MyCar(int number) : MyCar()
//	{
//		setNumber(number);
//	}
//	MyCar(int number, string color) : MyCar(number)
//	{
//		setColor(color);
//	}
//	MyCar(int number, string color, string model) : MyCar(number, color)
//	{
//		setModel(model);
//	}
//
//
//	void setNumber(int number)
//	{
//		this->number = (this->number == nullptr) ? new int(number) : &number;
//	}
//	void setColor(string color)
//	{
//		this->color = color;
//	}
//	void setModel(string model)
//	{
//		this->model = model;
//	}
//
//	int getNumber()
//	{
//		return (this->number == nullptr) ? 0 : *this->number;
//	}
//	string getColor()
//	{
//		return (this->color.empty()) ? "No info" : this->color;
//	}
//	string getModel()
//	{
//		return (this->model.empty()) ? "No info" : this->model;
//	}
//
//	void print()
//	{
//		cout << "Number: " << getNumber() << endl;
//		cout << "Color: " << getColor() << endl;
//		cout << "Model: " << getModel() << endl;
//	}
//};
//
//void printAllCars(MyCar* arr, int size) {
//	for (int i = 0; i < size; i++) {
//		arr[i].print();
//		cout << endl;
//	}
//}
//
//void findCarByNumber(MyCar* arr, int size, int searchNumber) {
//	for (int i = 0; i < size; i++) {
//		if (arr[i].getNumber() == searchNumber) {
//			arr[i].print();
//			return; //ùîá âèéòè ç öèêëó
//		}
//	}
//	cout << "Car with number " << searchNumber << " not found" << endl;
//}
//
//
//void editCar(MyCar* arr, int size, int searchNumber, string newColor, string newModel) {
//	for (int i = 0; i < size; i++) {
//		if (arr[i].getNumber() == searchNumber) {
//			arr[i].setColor(newColor);
//			arr[i].setModel(newModel);
//			cout << "Car with number " << searchNumber << " updated" << endl;
//			return;
//		}
//	}
//	cout << "Car with number " << searchNumber << " not found" << endl;
//}
//
//int main() {
//
//	MyCar* arr = new MyCar[10]
//	{
//		MyCar(1234, "black", "bmw"),
//		MyCar(2436, "red", "audi"),
//		MyCar(3742, "green", "mercedes"),
//		MyCar(4645, "grey", "reno"),
//		MyCar(9765, "white", "volkswagen"),
//		MyCar(2656, "orange", "kia"),
//		MyCar(6627, "white", "mitsubishi"),
//		MyCar(6548, "purple", "bmw"),
//		MyCar(6349, "blue", "mercedes"),
//		MyCar(6410, "black", "bmw"),
//	};
//
//	cout << "All cars:" << endl;
//	printAllCars(arr, 10);
//	cout << endl;
//
//	cout << "Search cars by number:" << endl;
//	findCarByNumber(arr, 10, 3742);
//	cout << endl;
//
//	cout << "Editing cars:" << endl;
//	editCar(arr, 10, 3742, "red", "audi");
//	cout << endl;
//
//	cout << "Update:" << endl;
//	findCarByNumber(arr, 10, 3742);
//	cout << endl;
//
//	return 0;
//}

// 2

#include <iostream>
using namespace std;



enum EntityType {
    BIRD,
    ANIMAL,
    HUMAN
};

union Characteristic {
    double flightSpeed;
    bool isEvenToed;
    int iqLevel;
};

struct LivingEntity {
private:
    EntityType type;
    string color;
    double movementSpeed;
    Characteristic characteristic;

public:
    LivingEntity() {
        this->color = "";
        this->movementSpeed = 0;
    }

    LivingEntity(EntityType type) : LivingEntity()
    {
        setType(type);
    }

    LivingEntity(EntityType type, string color) : LivingEntity(type)
    {
        setColor(color);
    }

    LivingEntity(EntityType type, string color, double movementSpeed) : LivingEntity(type, color)
    {
        setMovementSpeed(movementSpeed);
    }

    LivingEntity(EntityType type, string color, double movementSpeed, double flightSpeed) : LivingEntity(type, color, movementSpeed)
    {
        setCharacteristic(flightSpeed);
    }

    void setType(EntityType type) {
        this->type = type;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setMovementSpeed(double speed) {
        this->movementSpeed = speed;
    }

    void setCharacteristic(double flightSpeed) {
        this->characteristic.flightSpeed = flightSpeed;
    }

    void setCharacteristic(bool isEvenToed) {
        this->characteristic.isEvenToed = isEvenToed;
    }

    void setCharacteristic(int iqLevel) {
        this->characteristic.iqLevel = iqLevel;
    }

    EntityType getType() {
        return type;
    }

    string getColor() {
        return (this->color.empty()) ? "No info" : this->color;
    }

    double getMovementSpeed() {
        return this->movementSpeed;
    }

    double getFlightSpeed() {
        return (this->type == BIRD) ? this->characteristic.flightSpeed : 0;
    }

    bool getEvenToed() {
        return (this->type == ANIMAL) ? this->characteristic.isEvenToed : false;
    }

    int getIQ() {
        return (this->type == HUMAN) ? this->characteristic.iqLevel : 0;
    }

    void print() {
        cout << "Type: " << (type == BIRD ? "Bird" : type == ANIMAL ? "Cattle" : "Human") << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Move Speed: " << getMovementSpeed() << " m/s" << endl;

        if (type == BIRD) {
            cout << "Flight Speed: " << getFlightSpeed() << " m/s" << endl;
        }
        else if (type == ANIMAL) {
            cout << "Even-toed: " << (getEvenToed() ? "Yes" : "No") << endl;
        }
        else if (type == HUMAN) {
            cout << "IQ Level: " << getIQ() << endl;
        }
    }
};

void printAllEntities(LivingEntity* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i].print();
        cout << endl;
    }
}

void editEntity(LivingEntity* arr, int size, int index, string newColor, double newSpeed, Characteristic newCharacteristic, EntityType newType) {
    if (index >= 0 && index < size) {
        arr[index].setColor(newColor);
        arr[index].setMovementSpeed(newSpeed);
        arr[index].setType(newType);

        if (newType == BIRD) {
            arr[index].setCharacteristic(newCharacteristic.flightSpeed);
        }
        else if (newType == ANIMAL) {
            arr[index].setCharacteristic(newCharacteristic.isEvenToed);
        }
        else if (newType == HUMAN) {
            arr[index].setCharacteristic(newCharacteristic.iqLevel);
        }
        cout << "Entity at index " << index << " updated." << endl;
    }
}


int main() {
    LivingEntity* arr = new LivingEntity[10]{
        LivingEntity(BIRD, "blue", 10, 20),
        LivingEntity(ANIMAL, "brown", 2, true),
        LivingEntity(HUMAN, "white", 1.5, 100 /*????*/),
    };

    cout << "All entities:" << endl;
    printAllEntities(arr, 3);
    cout << endl;

    cout << "Editing entity at index 3:" << endl;
    Characteristic newChar;
    newChar.iqLevel = 130;
    editEntity(arr, 3, 2, "black", 2.0, newChar, HUMAN);
    cout << endl;

    cout << "Update:" << endl;
    cout << "All entities:" << endl;
    printAllEntities(arr, 3);
    cout << endl;

    return 0;
}