#include "UserGroup.h"



UserGroup::UserGroup () {}


UserGroup::~UserGroup () {}

int UserGroup::getID () {
	return id;
}

void UserGroup::setID (int id) {
	this->id = id;
}

std::vector<User>& UserGroup::getUsers () {
	return users;
}
