#pragma once
#ifndef BOREQUEST_H
#define BOREQUEST_H

#include "Request.h"

#include <vector>

class BoRequest : public Request {
public:
	BoRequest ();
	~BoRequest ();

	int getBoID ();
	void setBoID (int _id);

	int getBoMetaID ();
	void setBoMetaID (int _metaId);

	bool wantsAllAttributes ();
	void setRequestsAllAttributes (bool wantsItAll);

	bool wantsAllAvailableAttributes ();
	void setRequestsAllAvailableAttributes (bool wantsAllAvailable);

	std::vector<int>& getBoAttrMetaIDs ();
	std::vector<int>& getAllowedStatuses ();

private:
	int boID = 0;
	int boMetaID = 0;
	bool requestsAllAttributes = false;
	bool requestsAllAvailableAttributes = false;
	std::vector<int> boAttrMetaIDs;
	std::vector<int> allowedStatuses;
};

#endif // !BOREQUEST_H