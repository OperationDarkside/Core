#include "BoRequest.h"



BoRequest::BoRequest () {}


BoRequest::~BoRequest () {}

int BoRequest::getBoMetaID () {
	return boMetaID;
}

void BoRequest::setBoMetaID (int _metaId) {
	boMetaID = _metaId;
}

std::vector<int>& BoRequest::getBoAttrMetaIDs () {
	return boAttrMetaIDs;
}
