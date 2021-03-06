# Dependencies
find_package(BerkeleyDB REQUIRED)

# Source code to be built
set(
  SRCS
  mdbfs.c
  fuseops.c
  dbmgr.c
)

# Targets
add_library(mdbfs-berkeleydb ${SRCS})

# Link against utils
target_include_directories(mdbfs-berkeleydb PRIVATE mdbfs-utils)
target_link_libraries(mdbfs-berkeleydb PRIVATE mdbfs-utils)

# Link against Berkeley DB
target_include_directories(mdbfs-berkeleydb PRIVATE ${BERKELEY_DB_INCLUDE_DIR})
target_link_libraries(mdbfs-berkeleydb PRIVATE BerkeleyDB::BerkeleyDB)

# Include FUSE development files (headers etc.)
target_compile_definitions(mdbfs-berkeleydb PRIVATE ${FUSE_DEFINITIONS})
target_include_directories(mdbfs-berkeleydb PRIVATE ${FUSE_INCLUDE_DIRS})
