#include "MasterLayer.h"



MasterLayer::MasterLayer () :
	authLayer (dataManager.getUserManager ()),
	groupLayer (dataManager.getUser_UserGroup_RelationManager ()),
	permissionLayer (dataManager.getUserGroup_Role_Rel_Manager (), dataManager.getRoleManager (), dataManager.getBoMetaManager ()) {

}


MasterLayer::~MasterLayer () {}

AuthResponse MasterLayer::getAuthentication (AuthRequest req) {
	return AuthResponse ();
}

LayoutResponse MasterLayer::getLayout (LayoutRequest req) {
	return LayoutResponse ();
}

BoResponse MasterLayer::getBo (BoRequest req) {
	return BoResponse ();
}

BoListResponse MasterLayer::getBoList (BoListRequest req) {
	BoListResponse resp;

	return resp;
}
