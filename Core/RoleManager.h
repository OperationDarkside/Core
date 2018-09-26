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

	int getIndex (int roleID);

	Role& getRole (int index);

private:
	std::vector<Role> roles;
	std::unordered_map<int, int> role_index;
};

#endif // !ROLEMANAGER_H