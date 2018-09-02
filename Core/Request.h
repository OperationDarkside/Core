#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request {
public:
	Request ();
	~Request ();

	int getUserID ();
	void setUserID (int _userId);

	int getUserGroupID ();
	void setUserGroupID (int _userGroupId);

	std::string& getSessionID ();
	void setSessionID (std::string id);

protected:
	int userID = 0;
	int userGroupID = 0;

	std::string sessionID;
};

#endif // !REQUEST_H