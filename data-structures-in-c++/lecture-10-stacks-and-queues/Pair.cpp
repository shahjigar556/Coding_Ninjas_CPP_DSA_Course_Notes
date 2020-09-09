// CREATE ALL CLASSES WITH TEMPLATES
// Each class has their own template

/**********************************************************************************************************************
 * Single Template
 */
/*
template <typename T>
// Here we are using a template of name T, whose datatype is defined at the time of object creation

class Pair
{
    T x;
    T y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(T y)
    {
        this->y = y;
    }
    T getY()
    {
        return y;
    }
};
*/

/***********************************************************************************************************************
 * Multiple Templates
 */

template <typename T, typename V>
// Here we are using two templates of name T and V, whose datatypes are defined at the time of object creation

class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(V y)
    {
        this->y = y;
    }
    V getY()
    {
        return y;
    }
};