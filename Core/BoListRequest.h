#pragma once
#ifndef BOLISTREQUEST_H
#define BOLISTREQUEST_H

#include "Request.h"

#include <vector>

class BoListRequest : public Request {
public:
	BoListRequest ();
	~BoListRequest ();

	int getBoMetaID ();
	void setBoMetaID (int _metaId);

	bool wantsAllAttributes ();
	void setRequestsAllAttributes (bool wantsItAll);

	bool wantsAllAvailableAttributes ();
	void setRequestsAllAvailableAttributes (bool wantsAllAvailable);

	std::vector<int>& getBoAttrMetaIDs ();
	std::vector<int>& getAllowedStatuses ();

private:
	int boMetaID = 0;
	bool requestsAllAttributes = false;
	bool requestsAllAvailableAttributes = false;
	std::vector<int> boAttrMetaIDs;
	std::vector<int> allowedStatuses;
};

#endif // !DATAREQUEST_H