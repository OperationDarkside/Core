#include "Component.h"



Component::Component () {}


Component::~Component () {}

int Component::getID () {
	return id;
}

void Component::setID (int _id) {
	id = _id;
}
