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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "StarShape.h"
#include <cmath>

namespace sf
{
////////////////////////////////////////////////////////////
StarShape::StarShape(float radius, size_t points, size_t connectDistance)
{
    m_radius = radius;
    m_points = points;
    m_connectDistance = connectDistance % (m_points / 2);
    update();
}

////////////////////////////////////////////////////////////
void StarShape::setRadius(float radius)
{
    m_radius = radius;
    update();
}

////////////////////////////////////////////////////////////
float StarShape::getRadius() const
{
    return m_radius;
}

////////////////////////////////////////////////////////////
void StarShape::setPoints(size_t points)
{
    m_points = points;
    update();
}

////////////////////////////////////////////////////////////
void StarShape::setConnectDistance(size_t connectDistance) {
    m_connectDistance = connectDistance % (m_points / 2);
    update();
}

////////////////////////////////////////////////////////////
size_t StarShape::getConnectDistance() const {
    return m_connectDistance;
}

////////////////////////////////////////////////////////////
size_t StarShape::getPoints() const
{
    return m_points;
}

////////////////////////////////////////////////////////////
std::size_t StarShape::getPointCount() const
{
    return 2 * m_points;
}

////////////////////////////////////////////////////////////
sf::Vector2f StarShape::getPoint(std::size_t index) const
{
    if(index % 2 == 0)
        return getEdgePoint(index / 2);

    sf::Vector2f p1 = getEdgePoint((index - 1) / 2);
    sf::Vector2f p2 = getEdgePoint((index - 1) / 2 + m_connectDistance);
    sf::Vector2f p3 = getEdgePoint((index + 1) / 2);
    sf::Vector2f p4 = getEdgePoint((index + 1) / 2 - m_connectDistance);
    float m1, m2, b1, b2;

    if(p1.x == p2.x) {
        m2 = (p3.y - p4.y) / (p3.x - p4.x);
        b2 = -m2 * p3.x + p3.y;
        return {p1.x, m2 * p1.x + b2};
    }

    if(p3.x == p4.x) {
        m1 = (p1.y - p2.y) / (p1.x - p2.x);
        b1 = -m1 * p1.x + p1.y;
        return {p3.x, m1 * p3.x + b1};
    }

    m1 = (p1.y - p2.y) / (p1.x - p2.x);
    b1 = -m1 * p1.x + p1.y;
    m2 = (p3.y - p4.y) / (p3.x - p4.x);
    b2 = -m2 * p3.x + p3.y;
    return {(b2 - b1) / (m1 - m2), m1 * (b2 - b1) / (m1 - m2) + b1};
}

////////////////////////////////////////////////////////////
sf::Vector2f StarShape::getEdgePoint(long long edgeIndex) const
{
    float angle = (90 - edgeIndex * float(360 / m_points)) * float(M_PI / 180);
    return {m_radius * (1 + cos(angle)), m_radius * (1 - sin(angle))};
}
}
