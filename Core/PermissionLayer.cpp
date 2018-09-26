#include "PermissionLayer.h"



PermissionLayer::PermissionLayer (UserGroup_Role_Rel_Manager& _group_role_rel_manager, RoleManager& _roleManager) :
	group_role_rel_manager (_group_role_rel_manager),
	roleManager (_roleManager)
{}


PermissionLayer::~PermissionLayer () {}

bool PermissionLayer::hasBoPermission (BoRequest & boReq) {

	auto roleId_find = group_role_rel_manager.getRoleID (boReq.getUserGroupID ());
	if (roleId_find == -1) {
		return false;
	}

	int role_index = roleManager.getIndex (roleId_find);
	if (role_index == -1) {
		return false;
	}

	Role& role = roleManager.getRole (role_index);

	int boPermIndex = role.getBoPermissionIndex (boReq.getBoMetaID ());
	if (boPermIndex == -1) {
		// No Bo Permission
		return false;
	}

	BoPermission& perm = role.getBoPermission (boPermIndex);

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

		attrMetaIds.resize (attrPermissions.size ());

		for (auto& attrPerm : attrPermissions) {
			attrMetaIds.push_back (attrPerm.first);
		}

		return true;
	}

	for (auto attrMetaId : attrMetaIds) {
		auto attrMetaId_find = attrPermissions.find (attrMetaId);
		if (attrMetaId_find == attrPermissions.end ()) {
			// permission attribute not found...
			return false;
		}
	}

	// Set allowed Permissions
	auto& allowedStatuses = boReq.getAllowedStatuses ();
	auto& statuses = perm.getStatusPermissions ();

	allowedStatuses.resize (statuses.size ());

	for (auto& status : statuses) {
		allowedStatuses.push_back (status.first);
	}

	return true;
}

bool PermissionLayer::hasBoListPermission (BoListRequest & boListReq) {

	auto roleId_find = group_role_rel_manager.getRoleID (boListReq.getUserGroupID ());
	if (roleId_find == -1) {
		return false;
	}

	int role_index = roleManager.getIndex (roleId_find);
	if (role_index == -1) {
		return false;
	}

	Role& role = roleManager.getRole (role_index);

	int boPermIndex = role.getBoPermissionIndex (boListReq.getBoMetaID ());
	if (boPermIndex == -1) {
		// No Bo Permission
		return false;
	}

	BoPermission& perm = role.getBoPermission (boPermIndex);

	bool wantsAllAttributes = boListReq.wantsAllAttributes ();
	if (wantsAllAttributes) {
		// Wants all attributes
		if (perm.areAllAttributesAllowed ()) {
			return true;
		} else {
			return false;
		}
	}

	auto& attrMetaIds = boListReq.getBoAttrMetaIDs ();
	auto& attrPermissions = perm.getAttributePermissions ();

	bool wantsAvailableAttributes = boListReq.wantsAllAvailableAttributes ();
	if (wantsAvailableAttributes) {
		// Wants all available attributes

		attrMetaIds.resize (attrPermissions.size ());

		for (auto& attrPerm : attrPermissions) {
			attrMetaIds.push_back (attrPerm.first);
		}

		return true;
	}

	for (auto attrMetaId : attrMetaIds) {
		auto attrMetaId_find = attrPermissions.find (attrMetaId);
		if (attrMetaId_find == attrPermissions.end ()) {
			// permission attribute not found...
			return false;
		}
	}

	// Set allowed Permissions
	auto& allowedStatuses = boListReq.getAllowedStatuses ();
	auto& statuses = perm.getStatusPermissions ();

	allowedStatuses.resize (statuses.size ());

	for (auto& status : statuses) {
		allowedStatuses.push_back (status.first);
	}

	return true;
}

bool PermissionLayer::hasStatusChangePermission (BoStatusChangeRequest& req) {
	return false;
}

bool PermissionLayer::hasLayoutPermission (LayoutRequest& req) {
	auto roleId_find = group_role_rel_manager.getRoleID (req.getUserGroupID ());
	if (roleId_find == -1) {
		return false;
	}

	int role_index = roleManager.getIndex (roleId_find);
	if (role_index == -1) {
		return false;
	}

	Role& role = roleManager.getRole (role_index);

	int layoutPermIndex = role.getLayoutPermissionIndex (req.getLayoutID ());
	if (layoutPermIndex == -1) {
		return false;
	}

	LayoutPermission& layoutPerm = role.getLayoutPermission (layoutPermIndex);

	return true;
}

bool PermissionLayer::hasBoMetaPermission (BoMetaRequest & req) {

	auto roleId_find = group_role_rel_manager.getRoleID (req.getUserGroupID ());
	if (roleId_find == -1) {
		return false;
	}

	int role_index = roleManager.getIndex (roleId_find);
	if (role_index == -1) {
		return false;
	}

	Role& role = roleManager.getRole (role_index);

	int boPermIndex = role.getBoPermissionIndex (req.getBoMetaID ());
	if (boPermIndex == -1) {
		return false;
	}

	BoPermission& perm = role.getBoPermission (boPermIndex);

	auto& attrPerms = perm.getAttributePermissions ();
	auto& reqAttrIDs = req.getAttributeIDs ();

	reqAttrIDs.resize (attrPerms.size());
	for (auto& attrPerm : attrPerms) {
		reqAttrIDs.push_back (attrPerm.first);
	}

	return true;
}
