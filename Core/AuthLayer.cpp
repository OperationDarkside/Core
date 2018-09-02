#include "AuthLayer.h"



AuthLayer::AuthLayer (UserManager& _manager) : manager(_manager) {

}

AuthLayer::~AuthLayer () {}

bool AuthLayer::authenticate (Request * req) {
	int user_id = req->getUserID ();
	std::string& sessionId = req->getSessionID ();

	bool user_exists = manager.exists (user_id);
	if (!user_exists) {
		return false;
	}

	User& user = manager.getUser (user_id);
	if (user.getSessionID () != sessionId) {
		return false;
	}

	return true;
}