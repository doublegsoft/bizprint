### libwebsockets

#### 修改CMakeLists.txt

```
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-variable")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wno-unused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-label")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wno-unused-label")

option(LWS_WITH_MINIMAL_EXAMPLES "Also build the normally standalone minimal examples, for QA" OFF)
```

#### 编译

```
cmake -DCMAKE_TOOLCHAIN_FILE=../../cmake/mingw64.cmake \
  -DLWS_WITH_TLS=OFF \
  -DLWS_WITH_SSL=OFF \
  -DLWS_WITHOUT_BUILTIN_SHA1=OFF \
  -DLWS_WITH_GNUTLS=OFF \
  -DLWS_WITH_MBEDTLS=OFF \
  -DLWS_WITH_WOLFSSL=OFF \
  -DLWS_WITH_SYSTEMD=OFF \
  -DLWS_WITH_HTTP2=OFF \
  -DLWS_WITH_DAEMON=OFF \
  -DLWS_WITH_LIBUV=OFF \
  -DLWS_WITH_LIBEVENT=OFF \
  -DLWS_WITH_ZLIB=OFF \
  -DCMAKE_BUILD_TYPE=Release \
  ../..
```
