#include "DataManager.h"



DataManager::DataManager () {}


DataManager::~DataManager () {}

RoleManager & DataManager::getRoleManager () {
	return roleManager;
}

BoMetaManager & DataManager::getBoMetaManager () {
	return boMetaManager;
}

LayoutManager & DataManager::getLayoutManager () {
	return layoutManager;
}

User_UserGroup_Rel_Manager & DataManager::getUser_UserGroup_RelationManager () {
	return user_usergroup_rel_manager;
}

UserGroupManager & DataManager::getUserGroupManager () {
	return userGroupManager;
}

UserGroup_Role_Rel_Manager & DataManager::getUserGroup_Role_Rel_Manager () {
	return userGroup_Role_Rel_Manager;
}

UserManager & DataManager::getUserManager () {
	return userManager;
}