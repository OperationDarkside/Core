#pragma once
#ifndef BOMETAREQUEST_H
#define BOMETAREQUEST_H

#include "Request.h"

#include <vector>

class BoMetaRequest : public Request {
public:
	BoMetaRequest ();
	~BoMetaRequest ();

	int getBoMetaID ();
	void setBoMetaID (int _metaId);

	std::vector<int>& getAttributeIDs();

private:
	int boMetaID = 0;
	std::vector<int> attrIDs;
};

#endif // !BOMETAREQUEST_H