#include "RoleManager.h"



RoleManager::RoleManager () {}


RoleManager::~RoleManager () {}

bool RoleManager::exists (int roleID) {
	auto role_index_find = role_index.find (roleID);
	if (role_index_find == role_index.end ()) {
		return false;
	}
	return true;
}

Role & RoleManager::getRole (int roleID) {
	auto role_index_find = role_index.find (roleID);

	return roles[role_index_find->second];
}
