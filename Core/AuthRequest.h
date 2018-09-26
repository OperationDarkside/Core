#pragma once
#ifndef AUTHREQUEST_H
#define AUTHREQUEST_H

#include "Request.h"

#include <string>

class AuthRequest : public Request {
public:
	AuthRequest ();
	~AuthRequest ();

	std::string& getUsername ();
	void setUsername (std::string _username);

	std::string& getHash ();
	void setHash (std::string _hash);

private:
	std::string username;
	std::string hash;
};

#endif // !AUTHREQUEST_H