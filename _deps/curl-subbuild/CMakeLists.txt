# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.25.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(curl-populate NONE)



include(ExternalProject)
ExternalProject_Add(curl-populate
                     "UPDATE_DISCONNECTED" "False" "DOWNLOAD_EXTRACT_TIMESTAMP" "FALSE" "URL" "https://github.com/curl/curl/releases/download/curl-8_4_0/curl-8.4.0.tar.xz" "URL_HASH" "SHA256=16c62a9c4af0f703d28bda6d7bbf37ba47055ad3414d70dec63e2e6336f2a82d"
                    SOURCE_DIR          "//home/MK/Documents/git/_deps/curl-src"
                    BINARY_DIR          "//home/MK/Documents/git/_deps/curl-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


