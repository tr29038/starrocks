// This file is made available under Elastic License 2.0.
// This file is based on code available under the Apache license here:
//   https://github.com/apache/incubator-doris/blob/master/be/src/udf/udf_debug.h

// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <sstream>
#include <string>

#include "udf/udf.h"

namespace starrocks_udf {

template <typename T>
std::string debug_string(const T& val) {
    if (val.is_null) {
        return "NULL";
    }

    std::stringstream ss;
    ss << val.val;
    return ss.str();
}

template <>
std::string debug_string(const StringVal& val) {
    if (val.is_null) {
        return "NULL";
    }

    return std::string(reinterpret_cast<const char*>(val.ptr), val.len);
}

} // namespace starrocks_udf
