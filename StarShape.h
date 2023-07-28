////////////////////////////////////////////////////////////
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef ROUNDEDRECTANGLESHAPE_HPP
#define ROUNDEDRECTANGLESHAPE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Shape.hpp>
#include <cmath>
#include <iostream>

namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Specialized shape representing a star
////////////////////////////////////////////////////////////
class StarShape : public sf::Shape
{
    public:
        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param radius Radius of the star
        /// \param points Number of edge points in the star
        /// \param connectDistance Distance to connect points, 
        /// should be >= 2 and < half number of edge points
        ///
        ////////////////////////////////////////////////////////////
        StarShape(float radius, size_t points, size_t connectDistance);
        
        ////////////////////////////////////////////////////////////
        /// \brief Set the radius of the star
        ///
        /// \param radius Radius of the star
        ///
        /// \see getRadius
        ///
        ////////////////////////////////////////////////////////////
        void setRadius(float radius);

        ////////////////////////////////////////////////////////////
        /// \brief Get the radius of the star
        ///
        /// \see setRadius
        ///
        ////////////////////////////////////////////////////////////
        float getRadius() const;

        ////////////////////////////////////////////////////////////
        /// \brief Set the number of edge points in the star
        ///
        /// \param points number of edge points in the star
        ///
        /// \see getPoints
        ///
        ////////////////////////////////////////////////////////////
        void setPoints(size_t points);

        ////////////////////////////////////////////////////////////
        /// \brief Get the number of edge points in the star
        ///
        /// \see setPoints
        ///
        ////////////////////////////////////////////////////////////
        size_t getPoints() const;

        ////////////////////////////////////////////////////////////
        /// \brief Set the distance to connect points
        ///
        /// \param connectDistance distance to connect points
        ///
        /// \see getConnectDistance
        ///
        ////////////////////////////////////////////////////////////
        void setConnectDistance(size_t connectDistance);

        ////////////////////////////////////////////////////////////
        /// \brief the distance to connect points
        ///
        /// \see setConnectDistance
        ///
        ////////////////////////////////////////////////////////////
        size_t getConnectDistance() const;

        ////////////////////////////////////////////////////////////
        /// \brief Get point count 
        ///
        ////////////////////////////////////////////////////////////
        virtual std::size_t getPointCount() const;

        ////////////////////////////////////////////////////////////
        /// \brief Get point by index 
        ///
        /// \param index Index of point to get from 0 to getPointCount() - 1
        ///
        ////////////////////////////////////////////////////////////
        virtual sf::Vector2f getPoint(std::size_t index) const;
    private:
        ////////////////////////////////////////////////////////////
        // Member data and private method
        ////////////////////////////////////////////////////////////
        sf::Vector2f getEdgePoint(long long index) const;
        float m_radius;
        size_t m_points;
        size_t m_connectDistance;
};
}
#endif // ROUNDEDRECTANGLESHAPE_HPP

////////////////////////////////////////////////////////////
/// \class sf::StarShape
/// \ingroup graphics
///
/// This class inherits all the functions of sf::Transformable
/// (position, rotation, scale, bounds, ...) as well as the
/// functions of sf::Shape (outline, color, texture, ...).
///
/// Usage example:
/// \code
/// sf::StarleShape star(100, 10, 4);
/// ...
/// window.draw(star);
/// \endcode
///
/// \see sf::Shape, sf::CircleShape, sf::ConvexShape
///
////////////////////////////////////////////////////////////