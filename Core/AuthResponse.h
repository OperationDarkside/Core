#pragma once
#ifndef AUTHRESPONSE_H
#define AUTHRESPONSE_H

#include "Response.h"

#include <string>

class AuthResponse : public Response {
public:
	AuthResponse ();
	~AuthResponse ();

	bool getSuccess ();
	void setSuccess (bool _success);

	std::string& getSessionID ();
	void setSessionID (std::string _sessionID);

private:
	bool success = false;
	std::string sessionId;
};

#endif // !AUTHRESPONSE_H