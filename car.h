#ifndef _CAR_H
#define _CAR_H
/*===================================================================
 * car.h 
 ===================================================================*/

/* dir_type:  used by the car class to show which direction we're going. */
typedef enum
{
  DIR_NORTH,
  DIR_EAST,
  DIR_SOUTH,
  DIR_WEST
} dir_type;

/*============================================
 * Function:  getDirString
 *
 * This function takes a dir_type and returns
 * a human-readable string.
 *==========================================*/
extern char *getDirString(dir_type dir);

/*==========================================
 * Class:  Car
 * 
 * A car has two intrinsic attributes:
 *   - direction
 *   - speed
 *   
 * Construtors:
 *   A car can either be instantiated with: 
 *     direction specified (speed will be zero)
 *     default (no parameters, speed zero, direction DIR_NORTH.
 *     
 * Public Methods:
 *   Since direction can only be north, south, east, or west, turning left or right turns 
 *   90 degrees to the new direction.
 *   
 *   We can also speed up or slow down.  
 *   On speed up, the car will increase speed by 5 until it hits it's max.  
 *   On slow down, the car will decrease it's speed by 5 until it hits zero.
 *   There is no provision for negative speed (eg, going backwards)
 *   
 *   We also provide access methods for getting current direction and speed.
 ============================================*/
class Car
{
  public:
    Car( void );
    Car( dir_type );
    void turnLeft( void );
    void turnRight( void );
    void speedUp( void );
    void slowDown( void );
    int getSpeed( void );
    dir_type getDir( void );

  private:
    dir_type _currentDir;
    int      _currentSpeed;
    int      _maxSpeed;
};

#endif /* _CAR_H */
