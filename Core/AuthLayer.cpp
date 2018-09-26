#include "AuthLayer.h"
#include <chrono>


AuthLayer::AuthLayer (UserManager& _manager) : manager(_manager) {

}

AuthLayer::~AuthLayer () {}

AuthResponse AuthLayer::login (AuthRequest & req) {
	AuthResponse resp;

	std::string& username = req.getUsername ();
	std::string& hash = req.getHash ();

	int user_index = manager.getIndex (username);

	if (user_index == -1) {
		resp.setSuccess (false);
		return resp;
	}

	User& user = manager.getUser (user_index);
	if (user.getPassword () != hash) {
		resp.setSuccess (false);
		return resp;
	}

	std::string sessionID = generateSessionID ();

	user.setSessionID (sessionID);
	resp.setSessionID (sessionID);

	return resp;
}

bool AuthLayer::authenticate (Request * req) {
	int user_id = req->getUserID ();
	std::string& sessionId = req->getSessionID ();

	int user_index = manager.getIndex (user_id);
	if (user_index == -1) {
		return false;
	}

	User& user = manager.getUser (user_index);
	if (user.getSessionID () != sessionId) {
		return false;
	}

	return true;
}

std::string AuthLayer::generateSessionID () {
	long long seed = std::chrono::high_resolution_clock::now ().time_since_epoch ().count();
	randomiz0r.seed (seed);

	std::string sessionID = std::to_string (randomiz0r());

	return sessionID;
}
