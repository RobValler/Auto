project( auto_test )

#PACKAGES
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

#INCLUDES
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/auto/src)
include_directories(${CMAKE_SOURCE_DIR}/auto/src/common)
include_directories(${CMAKE_SOURCE_DIR}/auto/src/core)
include_directories(${CMAKE_SOURCE_DIR}/auto/src/control)
include_directories(${CMAKE_SOURCE_DIR}/auto/src/decide)
include_directories(${CMAKE_SOURCE_DIR}/auto/src/sense)
include_directories(${CMAKE_SOURCE_DIR}/auto/src/situation)



#SOURCE FILES
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/auto/src/*.cpp)
file(GLOB_RECURSE HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/auto/src/*.h)

#GENERATE
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )
target_link_libraries(  ${PROJECT_NAME}
                        ${CMAKE_THREAD_LIBS_INIT}
                        ${GTEST_LIBRARIES})

