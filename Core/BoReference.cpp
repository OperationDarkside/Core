#include "BoReference.h"



BoReference::BoReference () {}


BoReference::~BoReference () {}

int BoReference::getID () {
	return id;
}

void BoReference::setID (int _id) {
	id = _id;
}

std::string & BoReference::getName () {
	return name;
}

void BoReference::setName (std::string _name) {
	name = _name;
}
