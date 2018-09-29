#include "BoRequest.h"



BoRequest::BoRequest () {}


BoRequest::~BoRequest () {}

int BoRequest::getBoID () {
	return boID;
}

void BoRequest::setBoID (int _id) {
	boID = _id;
}

int BoRequest::getBoMetaID () {
	return boMetaID;
}

void BoRequest::setBoMetaID (int _metaId) {
	boMetaID = _metaId;
}

bool BoRequest::wantsAllAttributes () {
	return this->requestsAllAttributes;
}

void BoRequest::setRequestsAllAttributes (bool wantsItAll) {
	this->requestsAllAttributes = wantsItAll;
}

bool BoRequest::wantsAllAvailableAttributes () {
	return this->requestsAllAvailableAttributes;
}

void BoRequest::setRequestsAllAvailableAttributes (bool wantsAllAvailable) {
	this->requestsAllAvailableAttributes = wantsAllAvailable;
}

std::vector<int>& BoRequest::getBoAttrMetaIDs () {
	return boAttrMetaIDs;
}

std::vector<int>& BoRequest::getAllowedStatuses () {
	return this->allowedStatuses;
}
