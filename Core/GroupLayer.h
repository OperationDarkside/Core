#pragma once
#ifndef GROUPLAYER_H
#define GROUPLAYER_H

#include "User_UserGroup_Rel_Manager.h"

#include "Request.h"

class GroupLayer {
public:
	GroupLayer (User_UserGroup_Rel_Manager & _user_UserGroup_Rel_Manager);
	~GroupLayer ();

	bool hasGroup (Request* req);

private:
	User_UserGroup_Rel_Manager & user_UserGroup_Rel_Manager;
};

#endif // !GROUPLAYER_H