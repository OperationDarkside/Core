#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#include <experimental/net>
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <iostream>
#include <pqxx/pqxx>

namespace net = std::experimental::net;
//using namespace std::literals::string_literals;

class async_downloader {
public:
	async_downloader (net::io_context & io_c) : io_context_{io_c},
		socket_{io_context_},
		vdata_{"GET /plain HTTP/1.0\r\n", "Host: ipecho.net\r\n", "Accept: */*\r\n" , "Connection: close\r\n\r\n"},
		resolver_{io_context_},
		recv_data_{} {
		std::cout << "async_downloader constructor" << std::endl;
	};

	void retrieve () {
		resolver_.async_resolve ("ipecho.net", "http", [this] (auto ec, auto end_point) { this->handle_resolve (ec, end_point); });
	}

private:
	net::io_context & io_context_;
	net::ip::tcp::socket socket_;
	std::deque<std::string> vdata_;
	net::ip::tcp::resolver resolver_;
	std::string recv_data_;

	void handle_resolve (const std::error_code& ec, const net::ip::tcp::resolver::results_type& endpoints) {
		std::cout << "handle_resolve" << std::endl;
		if (ec) {
			std::cout << "resolve failed with message " << ec.message () << std::endl;
		} else {
			std::cout << "resolve successful" << std::endl;
			net::async_connect (socket_, endpoints, [this] (auto ec, auto end_point) { (this->handle_connect)(ec, end_point); });
		}
	}

	void handle_connect (const std::error_code& ec, const net::ip::tcp::endpoint& endpoint) {
		std::cout << "handle_connect" << std::endl;
		if (ec) {
			std::cout << "connect failed" << std::endl;
		} else {
			std::cout << "connect successful" << std::endl;
			write ();
		}
	}

	void write () {
		std::string str{vdata_.front ()};
		str.erase (std::remove (str.begin (), str.end (), '\r'), str.end ());
		str.erase (std::remove (str.begin (), str.end (), '\n'), str.end ());
		std::cout << "write: " << str << std::endl;

		net::async_write (socket_, net::buffer (vdata_.front ()), [this] (auto ec, auto bytes_transferred) { this->handle_write (ec, bytes_transferred); });
		//net::async_write (socket_, net::buffer ("GET /plain HTTP/1.0\r\nHost: ipecho.net\r\nAccept: */*\r\nConnection: close\r\n\r\n"), [this] (auto ec, auto bytes_transferred) { this->handle_write (ec, bytes_transferred); });


		//vdata_.clear ();
	}

	void handle_write (const std::error_code& ec, std::size_t bytes_transferred) {
		vdata_.pop_front ();
		std::cout << "handle_write" << std::endl;
		if (ec) {
			std::cout << "write failed" << std::endl;
		} else if (vdata_.empty ()) {
			std::cout << "write finished" << std::endl;
			this->read ();
		} else {

			write ();
		}
	}

	void read () {
		std::cout << "read" << std::endl;
		net::async_read (socket_,
						 net::dynamic_buffer (recv_data_),
						 net::transfer_all (),
						 [this] (auto ec, auto bytes_transferred) { this->handle_read (ec, bytes_transferred); }
		);
	}

	void handle_read (const std::error_code& ec, std::size_t bytes_transferred) {
		std::cout << "handle_read" << std::endl;
		if (ec == net::error::eof) {
			// Connection closed by peer
			// http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/tutorial/tutdaytime1/src.html
			std::cout << "read finished" << std::endl;
			std::cout << recv_data_ << std::endl;
		} else if (ec) {
			std::cout << "read error: " << ec << std::endl;
		} else {
			std::cout << "read more" << std::endl;
			read ();
		}
	}

};

struct Base {
	using type1 = char;
};

struct A : public Base {
	using type1 = int;
};

struct B : public Base {
	//using type1 = double;
};

B operator "" _flupp (const char* str, size_t size) {
	for (int i = 0; i < size; ++i) {
		char c = str[i];

		std::cout << c << "\n";
	}

	return B{};
}

B operator "" _sql (const char* str) {
	for (int i = 0; i < 5; ++i) {
		char c = str[i];

		std::cout << c << "\n";
	}

	return B{};
}

int main () {
	/*
	std::cout << "networking ts async example" << std::endl;

	net::io_context io_context;

	async_downloader hd{io_context};
	hd.retrieve ();

	std::cout << "io_context.run()" << std::endl;
	io_context.run ();
	std::cout << "end" << std::endl;
	*/
	/*
	try {
		pqxx::connection C ("user='postgres' password='admin' host='127.0.0.1' port='5432' dbname='postgres'");
		std::cout << "Connected to " << C.dbname () << std::endl;
		pqxx::work W (C);

		pqxx::result R = W.exec ("SELECT name FROM employee");

		std::cout << "Found " << R.size () << "employees:" << std::endl;
		for (auto row : R)
			std::cout << row[0].c_str () << std::endl;

		std::cout << "Doubling all employees' salaries..." << std::endl;
		W.exec ("UPDATE employee SET salary = salary*2");

		std::cout << "Making changes definite: ";
		W.commit ();
		std::cout << "OK." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what () << std::endl;
		return 1;
	}*/

	B b1 = "SELECT * FROM magenta where bla = '5';"_flupp;
	B b2 = 1234_sql;

	int bla;
	std::cin >> bla;

	return 0;
}