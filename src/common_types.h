/*
 *  This file is part of the command-line tool sosicon.
 *  Copyright (C) 2014  Espen Andersen, Norwegian Broadcast Corporation (NRK)
 *
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __COMMON_TYPES_H__
#define __COMMON_TYPES_H__

#include <vector>
#include "interface/i_coordinate.h"

namespace sosicon {

    //! List of coordinate pairs
    /*!
        Used throughout the application.
    */
    typedef std::vector<ICoordinate*> CoordinateList;
    
    //! List of applied, well-known text geometries
    enum Wkt {
        wkt_unknown = 0,           //!< Unknown geometry
        wkt_point,                 //!< Point geometry
        wkt_linestring,            //!< Linestring geometry
        wkt_polygon                //!< Polygon geometry
    }; // Wkt
}; // namespece sosicon

#endif
