#include "AuthResponse.h"



AuthResponse::AuthResponse () {}


AuthResponse::~AuthResponse () {}

bool AuthResponse::getSuccess () {
	return success;
}

void AuthResponse::setSuccess (bool _success) {
	success = _success;
}

std::string & AuthResponse::getSessionID () {
	return sessionId;
}

void AuthResponse::setSessionID (std::string _sessionID) {
	sessionId = _sessionID;
}
