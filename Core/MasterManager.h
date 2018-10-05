#pragma once
#ifndef MASTERMANAGER_H
#define MASTERMANAGER_H

#include "BoMeta.h"
#include "Layout.h"
#include "Status.h"
#include "Role.h"
#include "UserGroup.h"

#include "UserManager.h"
#include "User_UserGroup_Rel_Manager.h"
#include "UserGroupManager.h"
#include "UserGroup_Role_Rel_Manager.h"
#include "RoleManager.h"
#include "BoMetaManager.h"
#include "LayoutManager.h"

#include <vector>
#include <unordered_map>

class MasterManager {
public:
	MasterManager ();
	~MasterManager ();

	void load ();

	UserManager& getUserManager ();
	User_UserGroup_Rel_Manager& getUser_UserGroup_RelationManager ();
	UserGroupManager& getUserGroupManager ();
	UserGroup_Role_Rel_Manager& getUserGroup_Role_Rel_Manager ();
	RoleManager& getRoleManager ();
	BoMetaManager& getBoMetaManager ();
	LayoutManager& getLayoutManager ();

private:
	UserManager userManager;
	User_UserGroup_Rel_Manager user_usergroup_rel_manager;
	UserGroupManager userGroupManager;
	UserGroup_Role_Rel_Manager userGroup_Role_Rel_Manager;
	RoleManager roleManager;
	BoMetaManager boMetaManager;
	LayoutManager layoutManager;
};

#endif // !MASTERMANAGER_H