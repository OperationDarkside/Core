#include "User.h"



User::User () {}


User::~User () {}

int User::getID () {
	return id;
}

void User::setID (int id) {
	this->id = id;
}

std::string & User::getName () {
	return name;
}

void User::setName (std::string _name) {
	name = _name;
}

std::string & User::getPassword () {
	return pw;
}

void User::setPassword (std::string _password) {
	pw = _password;
}

std::string & User::getSessionID () {
	return sessionID;
}

void User::setSessionID (std::string id) {
	sessionID = id;
}
