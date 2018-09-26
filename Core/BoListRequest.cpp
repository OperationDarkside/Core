#include "BoListRequest.h"



BoListRequest::BoListRequest () {}


BoListRequest::~BoListRequest () {}

int BoListRequest::getBoMetaID () {
	return boMetaID;
}

void BoListRequest::setBoMetaID (int _metaId) {
	boMetaID = _metaId;
}

bool BoListRequest::wantsAllAttributes () {
	return requestsAllAttributes;
}

void BoListRequest::setRequestsAllAttributes (bool wantsItAll) {
	requestsAllAttributes = wantsItAll;
}

bool BoListRequest::wantsAllAvailableAttributes () {
	return requestsAllAvailableAttributes;
}

void BoListRequest::setRequestsAllAvailableAttributes (bool wantsAllAvailable) {
	requestsAllAvailableAttributes = wantsAllAvailable;
}

std::vector<int>& BoListRequest::getBoAttrMetaIDs () {
	return boAttrMetaIDs;
}

std::vector<int>& BoListRequest::getAllowedStatuses () {
	return allowedStatuses;
}
