find_package(Boost.Hana QUIET)
if (NOT Boost.Hana_FOUND)
    find_package(Boost 1.61.0 REQUIRED)
endif()
find_package(jegp 3.0.0 REQUIRED)
find_package(RapidXml 5.0.0 REQUIRED)

include(${CMAKE_CURRENT_LIST_DIR}/tmxppTargets.cmake)
