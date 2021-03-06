#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "Moudle.h"
#include "Macros.h"
#include "util.h"

#include <lua.hpp>
#include <SDL.h>

#include <math.h>

struct ColorHSLA
{
	double h;
	double s;
	double l;
	double a;
};

// 将数值限制在指定区间
// 1或3参数：被限定值（number），下限和上限（number，默认为0和1）
// 1返回值：限定后值
ETHER_API clamp(lua_State * L);

// 判断点是否位于指定矩形区域内(包含矩形边界）
// 2参数：点坐标（table），矩形区域（table）
// 1返回值：是否位于区域内（boolean）
ETHER_API ifPointInRect(lua_State* L);

// 判断点是否严格位于指定矩形区域内（不包含矩形边界）
// 2参数：点坐标（table），矩形区域（table）
// 1返回值：是否严格位于区域内（boolean）
ETHER_API ifPointInRectStrict(lua_State* L);

// 判断点是否位于指定圆形区域内(包含圆形边界）
// 3参数：点坐标（table），圆心坐标（table），圆半径（number）
// 1返回值：是否位于区域内（boolean）
ETHER_API ifPointInCircle(lua_State* L);

// 判断点是否严格位于指定圆形区域内(不包含圆形边界）
// 3参数：点坐标（table），圆心坐标（table），圆半径（number）
// 1返回值：是否严格位于区域内（boolean）
ETHER_API ifPointInCircleStrict(lua_State* L);

// 判断两矩形区域是否相交（包含矩形边界）
// 2参数：矩形1区域（table），矩形2区域（table）
// 1返回值：是否相交（boolean）
ETHER_API ifRectsOverlap(lua_State* L);

// 严格判断两矩形区域是否严格相交（不包含矩形边界）
// 2参数：矩形1区域（table），矩形2区域（table）
// 1返回值：是否严格相交（boolean）
ETHER_API ifRectsOverlapStrict(lua_State* L);

// 判断两圆是否相交（包含圆形边界）
// 2参数：圆1圆心坐标（table），圆1半径（number），圆2圆心坐标（table），圆2半径（number）
// 1返回值：是否相交（boolean）
ETHER_API ifCirclesOverlap(lua_State* L);

// 判断两圆是否严格相交（不包含圆形边界）
// 2参数：圆1圆心坐标（table），圆1半径（number），圆2圆心坐标（table），圆2半径（number）
// 1返回值：是否严格相交（boolean）
ETHER_API ifCirclesOverlapStrict(lua_State* L);

// 获取两点间直线距离
// 2参数：点1坐标（table），点2坐标（table）
// 1返回值：两点间直线距离（number）
ETHER_API getPointsDistance(lua_State* L);

// 获取两直线间距离
// 2参数：直线1起点坐标（table），直线1终点坐标（table），直线2起点坐标（table），直线2终点坐标（table）
// 1返回值：两直线间距离（number）
ETHER_API getLinesDistance(lua_State* L);

// 获取点到直线的垂直距离
// 3参数：点坐标（table），直线起点坐标（table），直线终点坐标（table）
// 1返回值：点到直线的距离（number）
ETHER_API getPointLineDistance(lua_State* L);

// RGBA颜色空间转HSLA颜色空间
// 1参数：使用RGBA描述的颜色（table）
// 1返回值：使用HSLA描述的颜色（table）
ETHER_API rgbaToHSLA(lua_State* L);

// HSLA颜色空间转RGBA颜色空间
// 1参数：使用HSLA描述的颜色（table）
// 1返回值：使用RGBA描述的颜色（table）
ETHER_API hslaToRGBA(lua_State* L);

/*
* 判断指定元素是否位于表值中
* 3参数：指定元素（number或string），表（table，值类型与被判断元素类型相同），元素类型（Macro number）
* 1参数：是否存在（boolean）
*/
ETHER_API ifElementInTable(lua_State* L);

class MoudleAlgorithm : public Moudle
{
public:
	MoudleAlgorithm(lua_State* L);
	~MoudleAlgorithm() {};

};

#endif // !_ALGORITHM_H_

