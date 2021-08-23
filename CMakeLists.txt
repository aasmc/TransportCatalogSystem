cmake_minimum_required(VERSION 3.20)
project(TransportCatalogSystem)
find_package(Protobuf REQUIRED)
set(CMAKE_CXX_STANDARD 17)

set(APP_DOMAIN ./)
include_directories(${APP_DOMAIN})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Protobuf_INCLUDE_DIRS})


protobuf_generate_cpp(
        PROTO_SRCS PROTO_HDRS protos/directed_graph.proto protos/router.proto protos/transport_router.proto protos/transport_catalog.proto
        protos/svg.proto protos/transport_renderer.proto protos/address.proto protos/company.proto protos/database.proto
        protos/name.proto protos/phone.proto protos/rubric.proto protos/sphere.proto protos/url.proto protos/working_time.proto)

add_executable(TransportCatalog ${PROTO_SRCS} ${PROTO_HDRS} main.cpp compression.cpp compression.h descriptions.cpp descriptions.h graph.h json.cpp
        json.h requests.cpp requests.h router.h sphere.cpp sphere.h svg.cpp svg.h transport_catalog.cpp
        transport_catalog.h transport_renderer.cpp transport_renderer.h transport_router.cpp transport_router.h
        utils.cpp utils.h companies_database.h companies_database.cpp companies_components.h companies_components.cpp)

target_link_libraries(TransportCatalog ${Protobuf_LIBRARIES})

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_LIBCPP_DEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -fno-omit-frame-pointer -fno-optimize-sibling-calls")
add_definitions(-fsanitize=address -g -fno-omit-frame-pointer -fno-optimize-sibling-calls)
set(ENV{ASAN_OPTIONS=detect_leaks=1})
set(ENV{ASAN_OPTIONS=symbolize=1})
set(ENV{ASAN_SYMBOLIZER_PATH=/usr/local/Cellar/llvm/12.0.1/bin/llvm-symbolizer})