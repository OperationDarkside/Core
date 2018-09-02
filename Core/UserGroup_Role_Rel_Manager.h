#pragma once
#ifndef USERGROUP_ROLE_REL_MANAGER_H
#define USERGROUP_ROLE_REL_MANAGER_H

#include <unordered_map>

class UserGroup_Role_Rel_Manager {
public:
	UserGroup_Role_Rel_Manager ();
	~UserGroup_Role_Rel_Manager ();

	int getRoleID (int userGroupID);

private:
	std::unordered_map<int, int> rel;
};

#endif // !USERGROUP_ROLE_REL_MANAGER_H