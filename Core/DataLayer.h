#pragma once
#ifndef DATALAYER_H
#define DATALAYER_H

#include "BoRequest.h"
#include "BoListRequest.h"
#include "BoMetaRequest.h"

#include "Bo.h"
#include "BoMeta.h"

#include <vector>

class DataLayer {
public:
	DataLayer ();
	~DataLayer ();

	Bo getBo (BoRequest& req);

	std::vector<Bo> getBoList (BoListRequest& req);

private:

};

#endif // !DATALAYER_H