// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "element/RoadSegment.h"
#include "carla/NonCopyable.h"

#include <boost/graph/adjacency_list.hpp>

#include <map>

namespace carla {
namespace road {

  using namespace carla::road::element;

  class Map {
  public:

    Map(const Map &) = delete;
    Map &operator=(const Map &) = delete;

    Map(Map &&) = default;
    Map &operator=(Map &&) = default;

    bool ExistId(id_type id) const;

    const RoadElement *GetRoad(id_type id);

    const RoadElement &NearestRoad(const geom::Location &loc);

  private:

    friend class MapBuilder;
    Map() {}
    std::map<id_type, std::unique_ptr<RoadElement>> _elements;
  };

} // namespace road
} // namespace carla