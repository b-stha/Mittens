cmake_minimum_required(VERSION 3.22)

project(Mittens VERSION 1.0 DESCRIPTION "Mittens: Discord bot that outputs your match result!")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/)

#OpenSSL
set(OPENSSL_ROOT_DIR /usr/lib/aarch64-linux-gnu)
set(OPENSSL_CRYPTO_LIBRARY /usr/lib/aarch64-linux-gnu/libcrypto.so)
set(OPENSSL_INCLUDE_DIR /usr/include/openssl)
find_package(OpenSSL REQUIRED)
message(STATUS "OpenSSL Include: ${OPENSSL_INCLUDE_DIR}")
message(STATUS "OpenSSL Libraries: ${OpenSSL_LIBRARIES}")

#dpp
find_package(DPP REQUIRED CONFIG)

#nlohmann-json
find_package(nlohmann_json 3.2.0 REQUIRED)

#cpr
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8)
FetchContent_MakeAvailable(cpr)

add_executable(${PROJECT_NAME}
        src/Player.cpp
        src/RiotAPI.cpp
        src/bot.cpp
        src/data.cpp
        src/helpers.cpp
        src/parsejson.cpp
        src/main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${OPENSSL_INCLUDE_DIR}
        ${cpr_SOURCE_DIR}/include
        ${nlohmann_json_INCLUDE_DIRS}
)

#Linking
target_link_libraries(${PROJECT_NAME} PRIVATE
        dpp::dpp
	OpenSSL::SSL
	OpenSSL::Crypto
        nlohmann_json::nlohmann_json
        cpr::cpr
)

add_executable(data_writer
        src/data_writer.cpp
        src/parsejson.cpp
        src/data.cpp
)

set_target_properties(data_writer PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(data_writer PRIVATE
        ${OPENSSL_INCLUDE_DIR}
        ${cpr_SOURCE_DIR}/include
        ${nlohmann_json_INCLUDE_DIRS}
)

#Linking
target_link_libraries(data_writer PRIVATE
        nlohmann_json::nlohmann_json
        cpr::cpr
)