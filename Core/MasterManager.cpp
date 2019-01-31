#include "MasterManager.h"

#include <iostream>
#include <pqxx/pqxx>


MasterManager::MasterManager () {}


MasterManager::~MasterManager () {}

void MasterManager::load () {
	std::string connectionString = "user='postgres' password='admin' host='127.0.0.1' port='5432' dbname='postgres'";

	try {
		pqxx::connection con (connectionString);
		pqxx::work work (con);

		// CHECK TABLES
		// BoMeta
		pqxx::result resBoMeta = work.exec ("SELECT EXISTS ("
											"SELECT 1 "
											"FROM pg_tables "
											"WHERE schemaname = 'public' "
											"AND tablename = 'bometa'"
											");");
		if (resBoMeta.size () == 0) {
			std::cout << "BoMeta table does not exist. Creating one!\r\n";
			pqxx::result resCreateGroup_Role_Rel_Table = work.exec ("CREATE TABLE bometa ("
																	"BoMetaID serial PRIMARY KEY, "
																	"Name VARCHAR(50) UNIQUE NOT NULL"
																	");");
		}

		// BoMetaAttribute
		pqxx::result resBoMetaAttribute = work.exec ("SELECT EXISTS ("
													 "SELECT 1 "
													 "FROM pg_tables "
													 "WHERE schemaname = 'public' "
													 "AND tablename = 'bometa_attribute'"
													 ");");
		if (resBoMetaAttribute.size () == 0) {
			std::cout << "BoMetaAttribute table does not exist. Creating one!\r\n";
			pqxx::result resCreateGroup_Role_Rel_Table = work.exec ("CREATE TABLE bometa_attribute ("
																	"BoMetaAttributeID serial PRIMARY KEY, "
																	"BoMetaID_FK integer, "
																	"Name VARCHAR(50) UNIQUE NOT NULL,"
																	"CONSTRAINT bometa_constraint "
																	"FOREIGN KEY (BoMetaID_FK) "
																	"REFERENCES bometa (BoMetaID) "
																	"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
																	");");
		}

		// User
		pqxx::result resUsersExist = work.exec ("SELECT EXISTS ("
												"SELECT 1 "
												"FROM pg_tables "
												"WHERE schemaname = 'public' "
												"AND tablename = 'users'); ");
		if (resUsersExist.size () == 0) {
			std::cout << "User table does not exist. Creating one!\r\n";
			pqxx::result resCreateUserTable = work.exec ("CREATE TABLE users ("
														 "UserID serial PRIMARY KEY, "
														 "Username VARCHAR(50) UNIQUE NOT NULL, "
														 "Password VARCHAR(50) NOT NULL"
														 ");");
		}

		// Group
		pqxx::result resGroupsExist = work.exec ("SELECT EXISTS ("
												 "SELECT 1 "
												 "FROM pg_tables "
												 "WHERE schemaname = 'public' "
												 "AND tablename = 'group');");
		if (resGroupsExist.size () == 0) {
			std::cout << "Group table does not exist. Creating one!\r\n";
			pqxx::result resCreateGroupTable = work.exec ("CREATE TABLE group ("
														  "GroupID serial PRIMARY KEY, "
														  "Name VARCHAR(50) UNIQUE NOT NULL"
														  ");");
		}

		// User-Group-Relation
		pqxx::result resUser_Group_Rel = work.exec ("SELECT EXISTS ("
													"SELECT 1 "
													"FROM pg_tables "
													"WHERE schemaname = 'public' "
													"AND tablename = 'user_group_rel'"
													");");
		if (resUser_Group_Rel.size () == 0) {
			std::cout << "User-Group-Relation table does not exist. Creating one!\r\n";
			pqxx::result resCreateUser_Group_Rel_Table = work.exec ("CREATE TABLE user_group_rel ("
																	"User_Group_Rel_ID serial, "
																	"UserID_FK integer, "
																	"GroupID_FK integer, "
																	"PRIMARY KEY(User_Group_Rel_ID, UserID_FK, GroupID_FK), "
																	"CONSTRAINT user_constraint "
																	"FOREIGN KEY (UserID_FK) "
																	"REFERENCES users (UserID) "
																	"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION, "
																	"CONSTRAINT group_constraint "
																	"FOREIGN KEY (GroupID_FK) "
																	"REFERENCES group (GroupID) "
																	"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
																	");");
		}

		// Role
		pqxx::result resRole = work.exec ("SELECT EXISTS ("
										  "SELECT 1 "
										  "FROM pg_tables "
										  "WHERE schemaname = 'public' "
										  "AND tablename = 'role'"
										  ");");
		if (resRole.size () == 0) {
			std::cout << "Role table does not exist. Creating one!\r\n";
			pqxx::result resCreateRole = work.exec ("CREATE TABLE role ("
													"RoleID serial PRIMARY KEY, "
													"Name VARCHAR(50) UNIQUE NOT NULL"
													");");
		}

		// Group-Role-Relation
		pqxx::result resGroup_Role_Rel = work.exec ("SELECT EXISTS ("
													"SELECT 1 "
													"FROM pg_tables "
													"WHERE schemaname = 'public' "
													"AND tablename = 'group_role_rel'"
													");");
		if (resGroup_Role_Rel.size () == 0) {
			std::cout << "Group-Role-Relation table does not exist. Creating one!\r\n";
			pqxx::result resCreateGroup_Role_Rel_Table = work.exec ("CREATE TABLE group_role_rel ("
																	"Group_Role_Rel_ID serial, "
																	"GroupID_FK integer, "
																	"RoleID_FK integer, "
																	"PRIMARY KEY(Group_Role_Rel_ID, GroupID_FK, RoleID_FK), "
																	"CONSTRAINT group_constraint "
																	"FOREIGN KEY (GroupID_FK) "
																	"REFERENCES group (GroupID) "
																	"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION, "
																	"CONSTRAINT role_constraint "
																	"FOREIGN KEY (RoleID_FK) "
																	"REFERENCES role (RoleID) "
																	"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
																	");");
		}

		// BoPermission
		pqxx::result resBoPermission = work.exec ("SELECT EXISTS ("
												  "SELECT 1 "
												  "FROM pg_tables "
												  "WHERE schemaname = 'public' "
												  "AND tablename = 'bopermission'"
												  ");");
		if (resBoPermission.size () == 0) {
			std::cout << "BoPermission table does not exist. Creating one!\r\n";
			pqxx::result resBoPermission_Table = work.exec ("CREATE TABLE bopermission ("
															"BoPermissionID serial PRIMARY KEY, "
															"BoMetaID_FK integer, "
															"RoleID_FK integer, "
															"AllAttribsAllowed boolean, "
															"CONSTRAINT bometa_constraint "
															"FOREIGN KEY (BoMetaID_FK) "
															"REFERENCES bometa (BoMetaID) "
															"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION, "
															"CONSTRAINT role_constraint "
															"FOREIGN KEY (RoleID_FK) "
															"REFERENCES role (RoleID) "
															"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
															");");
		}

		// BoAttributePermission
		pqxx::result resBoAttributePermission = work.exec ("SELECT EXISTS ("
														   "SELECT 1 "
														   "FROM pg_tables "
														   "WHERE schemaname = 'public' "
														   "AND tablename = 'boattribute_permission'"
														   ");");
		if (resBoAttributePermission.size () == 0) {
			std::cout << "BoAttributePermission table does not exist. Creating one!\r\n";
			pqxx::result resBoAttributePermission_Table = work.exec ("CREATE TABLE boattribute_permission ("
																	 "BoAttributePermissionID serial PRIMARY KEY, "
																	 "BoMetaID_FK integer, "
																	 "BoMetaAttributeID_FK integer, "
																	 "BoPermissionID_FK integer, "
																	 "CONSTRAINT bometa_constraint "
																	 "FOREIGN KEY (BoMetaID_FK) "
																	 "REFERENCES bometa (BoMetaID) "
																	 "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION, "
																	 "CONSTRAINT bometaAttribute_constraint "
																	 "FOREIGN KEY (BoMetaAttributeID_FK) "
																	 "REFERENCES bometa_attribute (BoMetaAttributeID) "
																	 "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION, "
																	 "CONSTRAINT bopermission_constraint "
																	 "FOREIGN KEY (BoPermissionID_FK) "
																	 "REFERENCES bopermission (BoPermissionID) "
																	 "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
																	 ");");
		}

		// Layout
		pqxx::result resLayout = work.exec ("SELECT EXISTS ("
											"SELECT 1 "
											"FROM pg_tables "
											"WHERE schemaname = 'public' "
											"AND tablename = 'layout'"
											");");
		if (resLayout.size () == 0) {
			std::cout << "Layout table does not exist. Creating one!\r\n";
			pqxx::result resLayout_Table = work.exec ("CREATE TABLE layout ("
													  "LayoutID serial PRIMARY KEY,"
													  "BoMetaID_FK integer,"
													  "CONSTRAINT bometa_constraint "
													  "FOREIGN KEY (BoMetaID_FK) "
													  "REFERENCES bometa (BoMetaID) "
													  "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION, "
													  ");");
		}

		// LayoutPermission
		pqxx::result resLayoutPermission = work.exec ("SELECT EXISTS ("
													  "SELECT 1 "
													  "FROM pg_tables "
													  "WHERE schemaname = 'public' "
													  "AND tablename = 'layoutpermission'"
													  ");");
		if (resLayoutPermission.size () == 0) {
			std::cout << "LayoutPermission table does not exist. Creating one!\r\n";
			pqxx::result resLayoutPermission_Table = work.exec ("CREATE TABLE layoutpermission ("
																"LayoutPermissionID serial PRIMARY KEY, "
																"RoleID_FK integer, "
																"LayoutID_FK integer, "
																"CONSTRAINT role_constraint "
																"FOREIGN KEY (RoleID_FK) "
																"REFERENCES role (RoleID) "
																"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION, "
																"CONSTRAINT layout_constraint "
																"FOREIGN KEY (LayoutID_FK) "
																"REFERENCES layout (LayoutID) "
																"MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
																");");
		}

		// Component
		pqxx::result resComponent = work.exec ("SELECT EXISTS ("
											   "SELECT 1 "
											   "FROM pg_tables "
											   "WHERE schemaname = 'public' "
											   "AND tablename = 'component'"
											   ");");
		if (resComponent.size () == 0) {
			std::cout << "Component table does not exist. Creating one!\r\n";
			pqxx::result resComponent_Table = work.exec ("CREATE TABLE component ("
														 "ComponentID serial PRIMARY KEY,"
														 "LayoutID_FK integer, "
														 "type integer, "
														 "CONSTRAINT layout_constraint "
														 "FOREIGN KEY (LayoutID_FK) "
														 "REFERENCES layout (LayoutID) "
														 "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
														 ");");
		}

		// Container
		pqxx::result resContainer = work.exec ("SELECT EXISTS ("
											   "SELECT 1 "
											   "FROM pg_tables "
											   "WHERE schemaname = 'public' "
											   "AND tablename = 'container'"
											   ");");
		if (resContainer.size () == 0) {
			std::cout << "Container table does not exist. Creating one!\r\n";
			pqxx::result resContainer_Table = work.exec ("CREATE TABLE container ("
														 "ContainerID serial PRIMARY KEY,"
														 "LayoutID_FK integer, "
														 "type integer, "
														 "CONSTRAINT layout_constraint "
														 "FOREIGN KEY (LayoutID_FK) "
														 "REFERENCES layout (LayoutID) "
														 "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
														 ");");
		}

		// Container Component Relation
		pqxx::result resContainerComponent = work.exec ("SELECT EXISTS ("
														"SELECT 1 "
														"FROM pg_tables "
														"WHERE schemaname = 'public' "
														"AND tablename = 'container_component'"
														");");
		if (resContainerComponent.size () == 0) {
			std::cout << "Container Component Relation table does not exist. Creating one!\r\n";
			pqxx::result resContainerComponent_Table = work.exec ("CREATE TABLE container_component ("
																  "ContainerComponentID serial PRIMARY KEY,"
																  "ContainerID_FK integer,"
																  "ComponentID_FK integer,"
																  "column integer,"
																  "column_span integer,"
																  "row integer,"
																  "row_span integer,"
																  "CONSTRAINT container_constraint "
																  "FOREIGN KEY (ContainerID_FK) "
																  "REFERENCES container (ContainerID) "
																  "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION,"
																  "CONSTRAINT component_constraint "
																  "FOREIGN KEY (ComponentID_FK) "
																  "REFERENCES component (ComponentID) "
																  "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
																  ");");
		}

		// Container Container Relation
		pqxx::result resContainerContainer = work.exec ("SELECT EXISTS ("
														"SELECT 1 "
														"FROM pg_tables "
														"WHERE schemaname = 'public' "
														"AND tablename = 'container_container'"
														");");
		if (resContainerContainer.size () == 0) {
			std::cout << "Container Container Relation table does not exist. Creating one!\r\n";
			pqxx::result resContainerContainer_Table = work.exec ("CREATE TABLE container_container ("
																  "ContainerContainerID serial PRIMARY KEY,"
																  "ParentContainerID_FK integer,"
																  "ChildContainerID_FK integer,"
																  "column integer,"
																  "column_span integer,"
																  "row integer,"
																  "row_span integer,"
																  "pos integer,"
																  "CONSTRAINT parent_container_constraint "
																  "FOREIGN KEY (ParentContainerID_FK) "
																  "REFERENCES container (ContainerID) "
																  "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION,"
																  "CONSTRAINT child_container_constraint "
																  "FOREIGN KEY (ChildContainerID_FK) "
																  "REFERENCES container (ContainerID) "
																  "MATCH SIMPLE ON UPDATE NO ACTION ON DELETE NO ACTION"
																  ");");
		}

		// TODO: Layout component Permission, Component Types (Enum), Put IDs into layout classes, Create Managr constructors

		work.commit ();
		con.disconnect ();
	} catch (const std::exception &e) {
		std::cerr << e.what () << std::endl;
	}
}

RoleManager & MasterManager::getRoleManager () {
	return roleManager;
}

BoMetaManager & MasterManager::getBoMetaManager () {
	return boMetaManager;
}

LayoutManager & MasterManager::getLayoutManager () {
	return layoutManager;
}

User_UserGroup_Rel_Manager & MasterManager::getUser_UserGroup_RelationManager () {
	return user_usergroup_rel_manager;
}

UserGroupManager & MasterManager::getUserGroupManager () {
	return userGroupManager;
}

UserGroup_Role_Rel_Manager & MasterManager::getUserGroup_Role_Rel_Manager () {
	return userGroup_Role_Rel_Manager;
}

UserManager & MasterManager::getUserManager () {
	return userManager;
}