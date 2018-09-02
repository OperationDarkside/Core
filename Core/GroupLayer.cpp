#include "GroupLayer.h"



GroupLayer::GroupLayer (User_UserGroup_Rel_Manager & _user_UserGroup_Rel_Manager) : user_UserGroup_Rel_Manager(_user_UserGroup_Rel_Manager) {

}


GroupLayer::~GroupLayer () {}

bool GroupLayer::hasGroup (Request * req) {
	int userID = req->getUserID ();

	int groupID = user_UserGroup_Rel_Manager.getGroupID (userID);
	if (groupID == -1) {
		return false;
	}

	req->setUserGroupID (groupID);

	return true;
}
