#pragma once
#ifndef AUTHLAYER_H
#define AUTHLAYER_H

#include "UserManager.h"

#include "Request.h"

#include <unordered_map>

class AuthLayer {
public:
	AuthLayer (UserManager& _manager);
	~AuthLayer ();

	bool authenticate (Request* req);

private:
	UserManager & manager;
};

#endif // !AUTHLAYER_H