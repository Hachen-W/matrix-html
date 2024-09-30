find_package(Catch2 3 REQUIRED)


add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)


add_library(libhtml STATIC html.cpp)
target_link_libraries(tests PRIVATE libhtml)