#include "Request.h"



Request::Request () {}


Request::~Request () {}

int Request::getUserID () {
	return userID;
}

void Request::setUserID (int _userId) {
	userID = _userId;
}

int Request::getUserGroupID () {
	return userGroupID;
}

void Request::setUserGroupID (int _userGroupId) {
	userGroupID = _userGroupId;
}

std::string & Request::getSessionID () {
	return sessionID;
}

void Request::setSessionID (std::string id) {
	sessionID = id;
}
