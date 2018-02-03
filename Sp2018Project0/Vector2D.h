#ifndef Vector2D_h
#define Vector2D_h
/**
 * @class Point2D
 * @brief 2d point
 */
class Point2D
{
private:
    /**< x component */
    float x;
    /**< y component */
    float y;
public:
    /**
     * @brief constructor
     */
    Point2D() {}
    /**
     * @brief constructor
     * @param r x coordinate
     * @param s y coordinate
     */
    Point2D(float r, float s) {this->x = r; this->y=s;}
    /**
     * @brief set x
     * @param x x coordinate
     */
    void setX(float xC) {this->x = xC;}
    /**
     * @brief get x
     * @return x coordinate
     */
    int getX(){return this->x;}
    /**
     * @brief set y
     * @param y y coordinate
     */
    void setY(float yC) {this->y = yC;}
    /**
     * @brief get y
     * @return y coordinate
     */
    int getY(){return this->y;}
};
#endif
