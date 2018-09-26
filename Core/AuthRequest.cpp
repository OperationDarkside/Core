#include "AuthRequest.h"



AuthRequest::AuthRequest () {}


AuthRequest::~AuthRequest () {}

std::string & AuthRequest::getUsername () {
	return username;
}

void AuthRequest::setUsername (std::string _username) {
	username = _username;
}

std::string & AuthRequest::getHash () {
	return hash;
}

void AuthRequest::setHash (std::string _hash) {
	hash = _hash;
}
