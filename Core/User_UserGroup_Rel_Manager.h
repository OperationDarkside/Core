#pragma once
#ifndef USER_USERGROUP_REL_MANAGER_H
#define USER_USERGROUP_REL_MANAGER_H

#include <unordered_map>

class User_UserGroup_Rel_Manager {
public:
	User_UserGroup_Rel_Manager ();
	~User_UserGroup_Rel_Manager ();

	int getGroupID (int userID);

private:
	std::unordered_map<int, int> rel;
};

#endif // !USER_USERGROUP_REL_MANAGER_H