cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(app VERSION ${PROJECT_VESRION})

option(WITH_GOOGLE_TEST "Whether to build Google test" ON)

add_executable(
    ${PROJECT_NAME}_cli
    ${CMAKE_SOURCE_DIR}/main.cpp
)

add_library(${PROJECT_NAME} ip_filter.cpp)

set_target_properties(${PROJECT_NAME}_cli ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set(${CMAKE_CXX_FLAGS} "-Wall -Wextra -Werror -pedantic -lpthread -Wignored-qualifiers -Wcpp")

target_include_directories(${PROJECT_NAME}
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(${PROJECT_NAME}_cli PRIVATE
    ${PROJECT_NAME}
)

if(WITH_GOOGLE_TEST)
    find_package(GTest REQUIRED)
    find_package(Threads REQUIRED)
    add_executable(test_version test_version.cpp)

    set_target_properties(test_version PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    set_target_properties(test_version PROPERTIES
        include_directories(${GTEST_INCLUDE_DIRS})
    )

    target_link_libraries(test_version
        ${GTEST_BOTH_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        ${PROJECT_NAME}
    )
endif()

if (MSVC)
    target_compile_options(${PROJECT_NAME}_cli PRIVATE
        /W4
    )
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
    )
    if(WITH_GOOGLE_TEST)
        target_compile_options(test_version PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(${PROJECT_NAME}_cli PRIVATE
        ${CMAKE_CXX_FLAGS}
    )
    target_compile_options(${PROJECT_NAME} PRIVATE
        ${CMAKE_CXX_FLAGS}
    )
    if(WITH_GOOGLE_TEST)
        target_compile_options(test_version PRIVATE
            ${CMAKE_CXX_FLAGS}
        )
    endif()
endif()

install(TARGETS ${PROJECT_NAME}_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_GOOGLE_TEST)
    enable_testing()
    add_test(test_version test_version)
endif()