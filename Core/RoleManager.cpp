#include "RoleManager.h"



RoleManager::RoleManager () {}


RoleManager::~RoleManager () {}

int RoleManager::getIndex (int roleID) {
	auto role_index_find = role_index.find (roleID);
	if (role_index_find == role_index.end ()) {
		return -1;
	}
	return role_index_find->second;
}

Role & RoleManager::getRole (int index) {
	//auto role_index_find = role_index.find (roleID);

	return roles[index/*role_index_find->second*/];
}
