#include "MasterLayer.h"



MasterLayer::MasterLayer () :
	authLayer (masterManager.getUserManager ()),
	groupLayer (masterManager.getUser_UserGroup_RelationManager ()),
	permissionLayer (masterManager.getUserGroup_Role_Rel_Manager (), masterManager.getRoleManager (), masterManager.getBoMetaManager ()) {

}


MasterLayer::~MasterLayer () {}

AuthResponse MasterLayer::getAuthentication (AuthRequest req) {
	AuthResponse resp = authLayer.login (req);
	
	return resp;
}

LayoutResponse MasterLayer::getLayout (LayoutRequest req) {
	LayoutResponse resp;

	Request* raw_req = static_cast<Request*>(&req);

	bool isAuth = authLayer.authenticate (raw_req);
	if (!isAuth) {
		resp.setSuccess (false);
		return resp;
	}

	bool hasGroup = groupLayer.hasGroup (raw_req);
	if (!hasGroup) {
		resp.setSuccess (false);
		return resp;
	}

	bool hasLayoutPerm = permissionLayer.hasLayoutPermission (req);
	if (!hasLayoutPerm) {
		resp.setSuccess (false);
		return resp;
	}

	LayoutManager& layoutManager = masterManager.getLayoutManager ();

	int layout_index = layoutManager.getIndex (req.getLayoutID());
	if (layout_index == -1) {
		resp.setSuccess (false);
		return resp;
	}

	Layout& layout = layoutManager.getLayout (layout_index);
	resp.setLayout (&layout);

	return resp;
}

BoResponse MasterLayer::getBo (BoRequest req) {
	return BoResponse ();
}

BoListResponse MasterLayer::getBoList (BoListRequest req) {
	BoListResponse resp;

	return resp;
}
