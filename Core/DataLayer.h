#pragma once
#ifndef DATALAYER_H
#define DATALAYER_H

#include "BoRequest.h"
#include "BoListRequest.h"
#include "BoMetaRequest.h"

#include "BoMetaManager.h"

#include "Bo.h"
#include "BoMeta.h"

#include "QueryBuilder.h"

#include <vector>
#include <iostream>

class DataLayer {
public:
	DataLayer (BoMetaManager& _boMetaManager);
	~DataLayer ();

	Bo getBo (BoRequest& req);

	std::vector<Bo> getBoList (BoListRequest& req);

private:
	std::string connectionString = "user='postgres' password='admin' host='127.0.0.1' port='5432' dbname='postgres'";
	BoMetaManager& boMetaManager;
};

#endif // !DATALAYER_H