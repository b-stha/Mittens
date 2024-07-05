# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "//home/MK/Documents/mittens/build/_deps/curl-src"
  "//home/MK/Documents/mittens/build/_deps/curl-build"
  "/home/MK/Documents/mittens/build/_deps/curl-subbuild/curl-populate-prefix"
  "/home/MK/Documents/mittens/build/_deps/curl-subbuild/curl-populate-prefix/tmp"
  "/home/MK/Documents/mittens/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
  "/home/MK/Documents/mittens/build/_deps/curl-subbuild/curl-populate-prefix/src"
  "/home/MK/Documents/mittens/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/MK/Documents/mittens/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/MK/Documents/mittens/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
