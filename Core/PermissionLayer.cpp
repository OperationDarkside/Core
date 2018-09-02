#include "PermissionLayer.h"



PermissionLayer::PermissionLayer (UserGroup_Role_Rel_Manager& _group_role_rel_manager, RoleManager& _roleManager, BoMetaManager& _boMetaManager) : 
	group_role_rel_manager(_group_role_rel_manager),
	roleManager(_roleManager),
	boMetaManager(_boMetaManager)
{}


PermissionLayer::~PermissionLayer () {}

bool PermissionLayer::hasBoPermission (BoRequest & boReq) {
	Request* req = static_cast<Request*>(&boReq);

	auto roleId_find = usergroup_role_rel->find (boReq.getUserGroupID());
	if (roleId_find == usergroup_role_rel->end()) {
		// usergroup-role-relation not found
		return false;
	}

	int roleID = roleId_find->second;
	for (auto& role : *roles) {

	}

	auto role_find = roles->find (roleId_find->second);
	if (role_find == roles->end ()) {
		// role not found...
		return false;
	}

	Role& role = role_find->second;
	auto& permissions = role.getPermissions ();

	auto perm_find = permissions.find (boReq.getBoMetaID());
	if (perm_find == permissions.end ()) {
		// permission not found...
		return false;
	}

	Permission& perm = perm_find->second;
	auto& attrPermissions = perm.getAttributePermissions ();

	auto& attrMetaIds = boReq.getBoAttrMetaIDs ();
	for (auto attrMetaId : attrMetaIds) {
		auto attrMetaId_find = attrPermissions.find(attrMetaId);
		if (attrMetaId_find == attrPermissions.end ()) {
			// permission attribute not found...
			return false;
		}
	}

	return true;
}

bool PermissionLayer::hasBoListPermission (BoListRequest & boListReq) {
	Request* req = static_cast<Request*>(&boListReq);

	

	return false;
}

void PermissionLayer::setRoles (std::vector<Role>* _roles) {
	roles = _roles;
}

void PermissionLayer::setBoMetas (std::vector<BoMeta>* _boMetas) {
	boMetas = _boMetas;
}

void PermissionLayer::setGroupRoleRel (std::unordered_map<int, int>* _usergroup_role_rel) {
	usergroup_role_rel = _usergroup_role_rel;
}
