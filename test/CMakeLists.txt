SET(TEST_SOURCES
	test.cc
	mime/mime.cc
	base64/base64.cc
)
ADD_EXECUTABLE(shttpd_test ${TEST_SOURCES})
INCLUDE_DIRECTORIES(../src)
TARGET_LINK_LIBRARIES(shttpd_test shttpd boost_system ssl crypto pthread)
ADD_CUSTOM_TARGET(run_test COMMAND ${CMAKE_BINARY_DIR}/test/shttpd_test DEPENDS shttpd_test WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
