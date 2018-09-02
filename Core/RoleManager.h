#pragma once
#ifndef ROLEMANAGER_H
#define ROLEMANAGER_H

#include "Role.h"

#include <vector>
#include <unordered_map>

class RoleManager {
public:
	RoleManager ();
	~RoleManager ();

	bool exists (int roleID);

	Role& getRole (int roleID);

private:
	std::vector<Role> roles;
	std::unordered_map<int, int> role_index;
};

#endif // !ROLEMANAGER_H