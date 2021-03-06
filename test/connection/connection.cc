#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>
#include "TcpConnection.hh"
#include "SslConnection.hh"

BOOST_AUTO_TEST_CASE(tcp_connect)
{
	boost::asio::io_service service;
	TcpConnectionPtr conn = std::make_shared<TcpConnection>(service);
	conn->async_connect("www.example.com", "80",
		[](ConnectionPtr conn, bool good) {
			BOOST_CHECK(good);
		}
	);
	service.run();
}
