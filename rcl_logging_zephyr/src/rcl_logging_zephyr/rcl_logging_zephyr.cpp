// Copyright 2018 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "rcutils/logging.h"
#include <rcl_logging_interface/rcl_logging_interface.h>
#include <rcutils/allocator.h>

#include <logging/log.h>
#include <logging/log_ctrl.h>

LOG_MODULE_REGISTER(ros);

rcl_logging_ret_t rcl_logging_external_initialize(
  const char * config_file,
  rcutils_allocator_t allocator)
{
  (void) config_file;
  (void) allocator;
  return RCL_LOGGING_RET_OK;
}

rcl_logging_ret_t rcl_logging_external_shutdown()
{
  return RCL_LOGGING_RET_OK;
}

void rcl_logging_external_log(int severity, const char * name, const char * msg)
{
  (void) severity;
  (void) name;
  (void) msg;

  log_set_tag(name);

  if (severity <= RCUTILS_LOG_SEVERITY_DEBUG) {
    LOG_DBG("%s", msg);
  } else if (severity <= RCUTILS_LOG_SEVERITY_INFO) {
    LOG_INF("%s", msg);
  } else if (severity <= RCUTILS_LOG_SEVERITY_WARN) {
    LOG_WRN("%s", msg);
  } else if (severity <= RCUTILS_LOG_SEVERITY_ERROR) {
    LOG_ERR("%s", msg);
  } else if (severity <= RCUTILS_LOG_SEVERITY_FATAL) {
    LOG_ERR("%s", msg);
  }
}

rcl_logging_ret_t rcl_logging_external_set_logger_level(const char * name, int level)
{
  (void) name;
  (void) level;
  return RCL_LOGGING_RET_OK;
}
