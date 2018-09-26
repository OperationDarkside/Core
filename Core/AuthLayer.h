#pragma once
#ifndef AUTHLAYER_H
#define AUTHLAYER_H

#include "UserManager.h"

#include "Request.h"
#include "AuthRequest.h"

#include "AuthResponse.h"

#include <unordered_map>
#include <random>

class AuthLayer {
public:
	AuthLayer (UserManager& _manager);
	~AuthLayer ();

	AuthResponse login (AuthRequest& req);

	bool authenticate (Request* req);

private:
	UserManager & manager;
	std::mt19937 randomiz0r;

	std::string generateSessionID ();
};

#endif // !AUTHLAYER_H