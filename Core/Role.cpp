#include "Role.h"



Role::Role () {}


Role::~Role () {}

int Role::getID () {
	return id;
}

void Role::setID (int id) {
	this->id = id;
}

std::unordered_map<int, Permission>& Role::getPermissions () {
	return permissions;
}
