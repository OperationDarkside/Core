#include "BoMetaRequest.h"



BoMetaRequest::BoMetaRequest () {}


BoMetaRequest::~BoMetaRequest () {}

int BoMetaRequest::getBoMetaID () {
	return boMetaID;
}

void BoMetaRequest::setBoMetaID (int _metaId) {
	boMetaID = _metaId;
}

std::vector<int>& BoMetaRequest::getAttributeIDs () {
	return attrIDs;
}
