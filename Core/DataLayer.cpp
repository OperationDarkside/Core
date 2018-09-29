#include "DataLayer.h"

#include "BoAttributeType.h"

#include <variant>
#include <iostream>
#include <pqxx/pqxx>


DataLayer::DataLayer (BoMetaManager& _boMetaManager) : boMetaManager (_boMetaManager) {

}


DataLayer::~DataLayer () {}

Bo DataLayer::getBo (BoRequest & req) {
	Bo bo;

	int boMetaIndex = boMetaManager.getIndex (req.getBoMetaID ());
	if (boMetaIndex == -1) {
		// ??? should have been caught
		return bo;
	}
	BoMeta& boMeta = boMetaManager.getBoMeta (boMetaIndex);

	// Create Query
	std::string query = QueryBuilder::getBoQuery (req, boMeta);
	std::cout << query << "\r\n"; // DEBUG

	// Setup Attributes
	auto& attrIDs = req.getBoAttrMetaIDs ();
	std::vector<BoAttribute> attributes;
	attributes.resize (attrIDs.size ());

	auto& metaAttrIndex = boMeta.getAttributeIndex ();
	auto& metaAttribs = boMeta.getAttributes ();

	for (int i = 0; i < attrIDs.size (); ++i) {
		int attrID = attrIDs[i];
		BoAttribute& attr = attributes[i];
		attr.setBoAttributeMetaID (attrID);

		int metaAttrInd = metaAttrIndex[attrID];
		if (metaAttrInd == -1) {
			// error
			return bo;
		}
		BoAttributeMeta& metaAttr = metaAttribs[metaAttrInd];
		attr.setType (metaAttr.getType ());
	}

	// Database
	try {
		pqxx::connection con (connectionString);
		pqxx::work work (con);
		pqxx::result res = work.exec (query);

		if (res.columns () != attrIDs.size ()) {
			// Error attribute-size mismatch
			return bo;
		}

		for (auto row : res) {
			for (int i = 0; i < attributes.size (); ++i) {
				BoAttribute& attr = attributes[i];

				switch (attr.getType ()) {
				case INTEGER:
					attr.setValue (row[i].as<long>());
					break;
				case FLOATING:
					attr.setValue (row[i].as<double> ());
					break;
				case DATE:
					attr.setValue (row[i].as<long> ());
					break;
				case STRING:
					attr.setValue (row[i].as<std::string> ());
					break;
				case REFERENCE:
					attr.setValue (row[i].as<long> ());
					break;
				}
			}
			//std::cout << row[0].c_str () << std::endl;
		}

		work.commit ();
		con.disconnect ();
	} catch (const std::exception &e) {
		std::cerr << e.what () << std::endl;
		return bo;
	}

	// TODO: Check status

	bo.setAttributes (attributes);

	return bo;
}

std::vector<Bo> DataLayer::getBoList (BoListRequest & req) {
	std::vector<Bo> bos;

	int boMetaIndex = boMetaManager.getIndex (req.getBoMetaID ());
	if (boMetaIndex == -1) {
		// ??? should have been caught
		return bos;
	}
	BoMeta& boMeta = boMetaManager.getBoMeta (boMetaIndex);

	std::string query = QueryBuilder::getBoListQuery (req, boMeta);

	std::cout << query << "\r\n"; // DEBUG

	// Setup Attributes
	auto& attrIDs = req.getBoAttrMetaIDs ();
	std::vector<BoAttribute> attributes;
	attributes.resize (attrIDs.size ());

	auto& metaAttrIndex = boMeta.getAttributeIndex ();
	auto& metaAttribs = boMeta.getAttributes ();

	for (int i = 0; i < attrIDs.size (); ++i) {
		int attrID = attrIDs[i];
		BoAttribute& attr = attributes[i];
		attr.setBoAttributeMetaID (attrID);

		int metaAttrInd = metaAttrIndex[attrID];
		if (metaAttrInd == -1) {
			// error
			return bos;
		}
		BoAttributeMeta& metaAttr = metaAttribs[metaAttrInd];
		attr.setType (metaAttr.getType ());
	}

	// Database
	try {
		pqxx::connection con (connectionString);
		pqxx::work work (con);
		pqxx::result res = work.exec (query);

		if (res.columns () != attrIDs.size ()) {
			// Error attribute-size mismatch
			return bos;
		}

		for (auto row : res) {
			for (int i = 0; i < attributes.size (); ++i) {
				BoAttribute& attr = attributes[i];

				switch (attr.getType ()) {
				case INTEGER:
					attr.setValue (row[i].as<long> ());
					break;
				case FLOATING:
					attr.setValue (row[i].as<double> ());
					break;
				case DATE:
					attr.setValue (row[i].as<long> ());
					break;
				case STRING:
					attr.setValue (row[i].as<std::string> ());
					break;
				case REFERENCE:
					attr.setValue (row[i].as<long> ());
					break;
				}
			}
			//std::cout << row[0].c_str () << std::endl;
		}

		work.commit ();
		con.disconnect ();
	} catch (const std::exception &e) {
		std::cerr << e.what () << std::endl;
		return bos;
	}

	return bos;
}