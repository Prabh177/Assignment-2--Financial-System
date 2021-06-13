#include "Customer.hpp"
#include <string>

int Customer :: nextID = 0;

Customer::Customer(const std::string &name) {
	this -> name = name;		// customer name
	this -> ID = nextID++;

}

std::string Customer::getName() const {
	return this -> name;
}

int Customer::getID() const {
	return this -> ID;
}

Customer::~Customer() {
	// TODO implement
}

