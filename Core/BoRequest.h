#pragma once
#ifndef BOREQUEST_H
#define BOREQUEST_H

#include "Request.h"

#include <vector>

class BoRequest : public Request {
public:
	BoRequest ();
	~BoRequest ();

	int getBoMetaID ();
	void setBoMetaID (int _metaId);

	std::vector<int>& getBoAttrMetaIDs ();

private:
	int boMetaID = 0;
	std::vector<int> boAttrMetaIDs;
};

#endif // !BOREQUEST_H