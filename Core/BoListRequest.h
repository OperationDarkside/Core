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

	std::vector<int> getBoAttrMetaIDs ();

private:
	int boMetaID = 0;
	std::vector<int> boAttrMetaIDs;
};

#endif // !DATAREQUEST_H