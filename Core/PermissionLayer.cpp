#include "PermissionLayer.h"



PermissionLayer::PermissionLayer (UserGroup_Role_Rel_Manager& _group_role_rel_manager, RoleManager& _roleManager, BoMetaManager& _boMetaManager) : 
	group_role_rel_manager(_group_role_rel_manager),
	roleManager(_roleManager),
	boMetaManager(_boMetaManager)
{}


PermissionLayer::~PermissionLayer () {}

bool PermissionLayer::hasBoPermission (BoRequest & boReq) {

	auto roleId_find = group_role_rel_manager.getRoleID (boReq.getUserGroupID ());
	if (roleId_find == -1) {
		return false;
	}

	bool role_exists = roleManager.exists (roleId_find);
	if (!role_exists) {
		return false;
	}

	Role& role = roleManager.getRole (roleId_find);

	bool hasPermission = role.hasPermission (boReq.getBoMetaID ());
	if (!hasPermission) {
		// No Bo Permission
		return false;
	}

	Permission& perm = role.getPermission (boReq.getBoMetaID ());
	
	bool wantsAllAttributes = boReq.wantsAllAttributes ();
	if (wantsAllAttributes) {
		// Wants all attributes
		if (perm.areAllAttributesAllowed ()) {
			return true;
		} else {
			return false;
		}
	}

	auto& attrMetaIds = boReq.getBoAttrMetaIDs ();
	auto& attrPermissions = perm.getAttributePermissions ();

	bool wantsAvailableAttributes = boReq.wantsAllAvailableAttributes ();
	if (wantsAvailableAttributes) {
		// Wants all available attributes

		attrMetaIds.resize (attrPermissions.size());

		for (auto& attrPerm : attrPermissions) {
			attrMetaIds.push_back (attrPerm.first);
		}

		return true;
	}
	
	for (auto attrMetaId : attrMetaIds) {
		auto attrMetaId_find = attrPermissions.find(attrMetaId);
		if (attrMetaId_find == attrPermissions.end ()) {
			// permission attribute not found...
			return false;
		}
	}

	// TODO: Set allowed Statuses for data fetching

	return true;
}

bool PermissionLayer::hasBoListPermission (BoListRequest & boListReq) {

	return false;
}

bool PermissionLayer::hasStatusChangePermission (BoStatusChangeRequest& req) {
	return false;
}

bool PermissionLayer::hasLayoutPermission (LayoutRequest& req) {
	return false;
}