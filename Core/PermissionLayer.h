#pragma once
#ifndef PERMISSIONLAYER_H
#define PERMISSIONLAYER_H

#include "UserGroup_Role_Rel_Manager.h"
#include "RoleManager.h"
#include "BoMetaManager.h"

#include "BoMeta.h"
#include "Role.h"
#include "UserGroup.h"

#include "BoRequest.h"
#include "BoListRequest.h"
#include "BoStatusChangeRequest.h"
#include "LayoutRequest.h"

#include "AuthLayer.h"

class PermissionLayer {
public:
	PermissionLayer (UserGroup_Role_Rel_Manager& _group_role_rel_manager, RoleManager& _roleManager, BoMetaManager& _boMetaManager);
	~PermissionLayer ();

	bool hasBoPermission (BoRequest& req);
	bool hasBoListPermission (BoListRequest& req);
	bool hasStatusChangePermission (BoStatusChangeRequest& req);
	bool hasLayoutPermission (LayoutRequest& req);
	
private:
	UserGroup_Role_Rel_Manager& group_role_rel_manager;
	RoleManager& roleManager;
	BoMetaManager& boMetaManager;
};

#endif // !PERMISSIONLAYER_H