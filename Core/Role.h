#pragma once
#ifndef ROLE_H
#define ROLE_H

#include "Permission.h"

#include <unordered_map>

class Role {
public:
	Role ();
	~Role ();

	int getID ();
	void setID (int id);

	std::unordered_map<int, Permission>& getPermissions ();

private:
	int id = 0;
	std::unordered_map<int, Permission> permissions;
};

#endif // !ROLE_H