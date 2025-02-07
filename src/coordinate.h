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
#ifndef __COORDINATE_H__
#define __COORDINATE_H__

#include <string>
#include <iostream>
#include <sstream>
#include <ios>
#include "interface/i_coordinate.h"

namespace sosicon {

	//! Coordinate container
    /*!
        \author Espen Andersen
        \copyright GNU General Public License

        Stores a geographical position with some additional information.
     */
    class Coordinate : public ICoordinate {

        double mEast;
        double mNorth;
        double mAltitude;

    public:

        virtual ~Coordinate() {}
        Coordinate() : mEast( 0.0 ), mNorth( 0.0 ), mAltitude( 0.0 ) {}
        virtual double getE() { return mEast; }
        virtual double getN() { return mNorth; }
        virtual bool leftOf( ICoordinate* c ) { return mEast < c->getE(); }
        virtual bool rightOf( ICoordinate* c ) { return mEast > c->getE(); }
        virtual void setE( double coordEast ) { mEast = coordEast; }
        virtual void setN( double coordNorth ) { mNorth = coordNorth; }
        virtual void setH( double altitude ) { mAltitude = altitude; }
        virtual void shift( int offsetN, int offsetE ) { mNorth += offsetN; mEast += offsetE; }
        virtual void divide( int divisor ) { mNorth /= divisor; mEast /= divisor; }
        virtual bool equals( ICoordinate* c ) { return mEast == c->getE() && mNorth == c->getN(); }
        virtual std::string toString() { std::stringstream ss; ss << "POINT( " << std::fixed << mNorth << " " << std::fixed << mEast << " )"; return ss.str(); }

    }; // class Coordinate
    
} // namespece sosicon

#endif
