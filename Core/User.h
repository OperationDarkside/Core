#pragma once
#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
	User ();
	~User ();

	int getID ();
	void setID (int id);

	std::string& getName ();
	void setName (std::string _name);

	std::string& getPassword ();
	void setPassword (std::string _password);

	std::string& getSessionID ();
	void setSessionID (std::string id);

private:
	int id = 0;

	std::string name;
	std::string pw;

	std::string sessionID;
};

#endif // !USER_H