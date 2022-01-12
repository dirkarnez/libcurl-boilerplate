cmake_minimum_required(VERSION 3.14)

project(libcurl-boilerplate)

add_compile_definitions(
    CURL_STATICLIB
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

include_directories("${libcurl_ROOT}/include")

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME}
    "${libcurl_ROOT}/lib/libcurl.a"
    ws2_32.lib
    wldap32.lib
)