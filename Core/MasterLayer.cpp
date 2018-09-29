#include "MasterLayer.h"



MasterLayer::MasterLayer () :
	authLayer (masterManager.getUserManager ()),
	groupLayer (masterManager.getUser_UserGroup_RelationManager ()),
	permissionLayer (masterManager.getUserGroup_Role_Rel_Manager (), masterManager.getRoleManager ()) {

}


MasterLayer::~MasterLayer () {}

AuthResponse MasterLayer::getAuthentication (AuthRequest req) {
	AuthResponse resp = authLayer.login (req);
	resp.setSuccess (true);
	return resp;
}

AddLayoutResponse MasterLayer::addLayout (AddLayoutRequest req) {
	return AddLayoutResponse ();
}

LayoutResponse MasterLayer::getLayout (LayoutRequest req) {
	LayoutResponse resp;

	Request* raw_req = static_cast<Request*>(&req);

	// Auth
	bool isAuth = authLayer.authenticate (raw_req);
	if (!isAuth) {
		resp.setSuccess (false);
		return resp;
	}
	// Group
	bool hasGroup = groupLayer.hasGroup (raw_req);
	if (!hasGroup) {
		resp.setSuccess (false);
		return resp;
	}
	// Permission
	bool hasLayoutPerm = permissionLayer.hasLayoutPermission (req);
	if (!hasLayoutPerm) {
		resp.setSuccess (false);
		return resp;
	}

	LayoutManager& layoutManager = masterManager.getLayoutManager ();

	int layout_index = layoutManager.getIndex (req.getLayoutID ());
	if (layout_index == -1) {
		resp.setSuccess (false);
		return resp;
	}

	// TODO don't set pointer, but already serialize/cache
	Layout& layout = layoutManager.getLayout (layout_index);
	resp.setLayout (&layout);
	resp.setSuccess (true);
	return resp;
}

SetLayoutResponse MasterLayer::setLayout (SetLayoutRequest req) {
	return SetLayoutResponse (); // TODO
}

AddBoResponse MasterLayer::addBo (AddBoRequest req) {
	return AddBoResponse (); // TODO
}

BoResponse MasterLayer::getBo (BoRequest req) {
	BoResponse resp;

	Request* raw_req = static_cast<Request*>(&req);
	// Auth
	bool isAuth = authLayer.authenticate (raw_req);
	if (!isAuth) {
		resp.setSuccess (false);
		return resp;
	}
	// Group
	bool hasGroup = groupLayer.hasGroup (raw_req);
	if (!hasGroup) {
		resp.setSuccess (false);
		return resp;
	}
	// Permission
	bool hasBoPerm = permissionLayer.hasBoPermission (req);
	if (!hasBoPerm) {
		resp.setSuccess (false);
		return resp;
	}

	Bo bo = dataLayer.getBo (req);
	resp.setSuccess (true);
	// TODO serialze/cache to response

	return resp;
}

SetBoResponse MasterLayer::setBo (SetBoRequest req) {
	return SetBoResponse (); // TODO
}

BoListResponse MasterLayer::getBoList (BoListRequest req) {
	BoListResponse resp;

	Request* raw_req = static_cast<Request*>(&req);
	// Auth
	bool isAuth = authLayer.authenticate (raw_req);
	if (!isAuth) {
		resp.setSuccess (false);
		return resp;
	}
	// Group
	bool hasGroup = groupLayer.hasGroup (raw_req);
	if (!hasGroup) {
		resp.setSuccess (false);
		return resp;
	}
	// Permission
	bool hasBoPerm = permissionLayer.hasBoListPermission (req);
	if (!hasBoPerm) {
		resp.setSuccess (false);
		return resp;
	}

	std::vector<Bo> bos = dataLayer.getBoList (req);
	// TODO set bos to resp
	resp.setSuccess (true);

	return resp;
}

AddBoMetaResponse MasterLayer::addBoMeta (AddBoMetaRequest req) {
	return AddBoMetaResponse (); // TODO
}

BoMetaResponse MasterLayer::getBoMeta (BoMetaRequest req) {
	BoMetaResponse resp;

	Request* raw_req = static_cast<Request*>(&req);
	// Auth
	bool isAuth = authLayer.authenticate (raw_req);
	if (!isAuth) {
		resp.setSuccess (false);
		return resp;
	}
	// Group
	bool hasGroup = groupLayer.hasGroup (raw_req);
	if (!hasGroup) {
		resp.setSuccess (false);
		return resp;
	}
	// Permission
	bool hasBoMetaPerm = permissionLayer.hasBoMetaPermission (req);
	if (!hasBoMetaPerm) {
		resp.setSuccess (false);
		return resp;
	}

	BoMetaManager& boMetaManager = masterManager.getBoMetaManager ();
	int boMetaIndex = boMetaManager.getIndex (req.getBoMetaID ());
	if (boMetaIndex == -1) {
		resp.setSuccess (false);
		return resp;
	}

	BoMeta& boMeta = boMetaManager.getBoMeta (boMetaIndex);

	BoMeta newBoMeta;
	newBoMeta.setID (boMeta.getID ());
	newBoMeta.setName (boMeta.getName ());

	auto& oldAttribs = boMeta.getAttributes ();
	auto& newAttribs = newBoMeta.getAttributes ();

	for (auto attribId : req.getAttributeIDs()) {
		// Dirty, TODO use index
		for (auto& oldAttrib : oldAttribs) {
			if (attribId == oldAttrib.getID()) {
				newAttribs.push_back (oldAttrib);
				break;
			}
		}
	}

	// TODO
	// Serialize newBoMeta
	// Set result to resp

	resp.setSuccess (true);

	return resp;
}

SetBoMetaResponse MasterLayer::setBoMeta (SetBoMetaRequest req) {
	return SetBoMetaResponse (); // TODO
}
