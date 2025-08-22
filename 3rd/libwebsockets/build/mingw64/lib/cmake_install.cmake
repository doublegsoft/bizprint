# Install script for directory: /export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/lib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/x86_64-w64-mingw32-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/plat/windows/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/core/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/misc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/system/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/core-net/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/roles/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/event-libs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/secure-streams/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/secure-streams/serialized/client/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xcorex" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/libwebsockets_static.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xcorex" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/lib/libwebsockets.dll.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xcorex" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/bin/libwebsockets.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libwebsockets.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libwebsockets.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/x86_64-w64-mingw32-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libwebsockets.dll")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/libwebsockets.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/export/local/works/doublegsoft.biz/bizprint/03.Development/bizprint/3rd/libwebsockets/build/mingw64/libwebsockets_static.pc")
endif()

