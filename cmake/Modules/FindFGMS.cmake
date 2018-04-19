set(FGMS_ROOT_SEARCH "" CACHE STRING "The path to fgms's source code.")
if ("${FGMS_ROOT_SEARCH}" STREQUAL "")
    set(FGMS_FOUND FALSE)
        return()
endif()

find_path(FGMS_SOURCE_ROOT
        NAMES "./fgms/src/server/fg_server.hxx"
        PATHS ${FGMS_ROOT_SEARCH}
        DOC "Base directory of the fmgs git repository"
        NO_DEFAULT_PATH
        )

if ("${FGMS_SOURCE_ROOT}" STREQUAL "FGMS_SOURCE_ROOT-NOTFOUND" OR
        "${FGMS_SOURCE_ROOT}" STREQUAL "")
    set(FGMS_FOUND FALSE)
    set(FGMS_INCLUDE_DIRS "FGMS_INCLUDE_DIRS-NOTFOUND")
    set(FGMS_LIBRARIES "FGMS_LIBRARIES-NOTFOUND")
else()
    set(FGMS_FOUND TRUE)
    set(FGMS_INCLUDE_DIRS ${FGMS_SOURCE_ROOT}/fgms/src)
    set(FGMS_LIBRARIES "${FGMS_SOURCE_ROOT}/build/libfg_server.so"
            "${FGMS_SOURCE_ROOT}/build/libSGUtils.so"
            "${FGMS_SOURCE_ROOT}/build/libMultiplayer.so"
            "${FGMS_SOURCE_ROOT}/build/libPlib.so"
            "${FGMS_SOURCE_ROOT}/build/libLibCLI.so")
endif()
