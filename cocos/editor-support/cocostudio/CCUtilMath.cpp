/****************************************************************************
Copyright (c) 2013 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "cocostudio/CCUtilMath.h"

using namespace cocos2d;


namespace cocostudio {

bool isSpriteContainPoint(Sprite *sprite, Point point, Point &outPoint)
{
    outPoint = sprite->convertToNodeSpace(point);

    Size s  = sprite->getContentSize();
    Rect r(0, 0, s.width, s.height);

    return r.containsPoint(outPoint);
}

bool isSpriteContainPoint(Sprite *sprite, Point point)
{
    Point p = Point(0, 0);
    return isSpriteContainPoint(sprite, point, p);
}


Point bezierTo(float t, Point &point1, Point &point2, Point &point3)
{

    Point p;

    p.x = pow((1 - t), 2) * point1.x + 2 * t * (1 - t) * point2.x + pow(t, 2) * point3.x;
    p.y = pow((1 - t), 2) * point1.y + 2 * t * (1 - t) * point2.y + pow(t, 2) * point3.y;

    return p;
}

Point bezierTo(float t, Point &point1, Point &point2, Point &point3, Point &point4)
{
    Point p;

    p.x = point1.x * pow((1 - t), 3) + 3 * t * point2.x * pow((1 - t), 2) + 3 * point3.x * pow(t, 2) * (1 - t) + point4.x * pow(t, 3);
    p.y = point1.y * pow((1 - t), 3) + 3 * t * point2.y * pow((1 - t), 2) + 3 * point3.y * pow(t, 2) * (1 - t) + point4.y * pow(t, 3);

    return p;
}

Point circleTo(float t, Point &center, float radius, float fromRadian, float radianDif)
{
    Point p;

    p.x = center.x + radius * cos(fromRadian + radianDif * t);
    p.y = center.y + radius * sin(fromRadian + radianDif * t);

    return p;
}

}
