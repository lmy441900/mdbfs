/**
 * @file list.h
 *
 * A list of supported MDBFS database backends.
 */

#ifndef MDBFS_BACKENDS_LIST_H
#define MDBFS_BACKENDS_LIST_H

#include "sqlite/mdbfs-backend.h"
#include "berkeleydb/mdbfs-backend.h"

/**
 * Private structure representing a backend and its related metadata.
 */
struct mdbfs_backend_map {
  /**
   * Name of the backend.
   */
  const char const *name;

  /**
   * Function to retrieve the `struct mdbfs_backend` representing the backend.
   */
  struct mdbfs_backend *(*get_mdbfs_backend)(void);
};

/**
 * A list of supported backends.
 *
 * It is okay to have multiple names pairing with one same registration
 * function; this creates alias for the backend.
 */
static const struct mdbfs_backend_map mdbfs_backends[] = {
  {"sqlite", mdbfs_backend_sqlite_get_mdbfs_backend},
  {"berkeleydb", mdbfs_backend_berkeleydb_get_mdbfs_backend},
  {NULL, NULL},
};

#endif
