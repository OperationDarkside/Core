#include "MasterManager.h"



MasterManager::MasterManager () {}


MasterManager::~MasterManager () {}

RoleManager & MasterManager::getRoleManager () {
	return roleManager;
}

BoMetaManager & MasterManager::getBoMetaManager () {
	return boMetaManager;
}

LayoutManager & MasterManager::getLayoutManager () {
	return layoutManager;
}

User_UserGroup_Rel_Manager & MasterManager::getUser_UserGroup_RelationManager () {
	return user_usergroup_rel_manager;
}

UserGroupManager & MasterManager::getUserGroupManager () {
	return userGroupManager;
}

UserGroup_Role_Rel_Manager & MasterManager::getUserGroup_Role_Rel_Manager () {
	return userGroup_Role_Rel_Manager;
}

UserManager & MasterManager::getUserManager () {
	return userManager;
}