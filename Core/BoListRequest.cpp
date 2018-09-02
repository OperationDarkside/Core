#include "BoListRequest.h"



BoListRequest::BoListRequest () {}


BoListRequest::~BoListRequest () {}

int BoListRequest::getBoMetaID () {
	return boMetaID;
}

void BoListRequest::setBoMetaID (int _metaId) {
	boMetaID = _metaId;
}

std::vector<int> BoListRequest::getBoAttrMetaIDs () {
	return boAttrMetaIDs;
}
