find_package(Catch2 3 REQUIRED)

add_compile_options(-fprofile-arcs -ftest-coverage)
link_libraries(gcov)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_library(libhtml STATIC html.cpp)
target_link_libraries(tests PRIVATE libhtml)