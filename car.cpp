/*===================================================================
 * car.cpp
 * 
 * This library implements our sample car class
 */

#include <Arduino.h>
#include "car.h"

static char *dir_string_table[] =
{
  "North", // DIR_NORTH
  "East",  // DIR_EAST
  "South", // DIR_SOUTH
  "West"   // DIR_WEST
};

/*============================================
 * Function:  getDirString
 *
 * This function takes a dir_type and returns
 * a human-readable string.
 *==========================================*/
char *getDirString(dir_type dir)
{
  return(dir_string_table[dir]);
}

/*==========================================
 * Default Constructor
 * 
 * Sets default values for direction, speed, and max speed.
 ==========================================*/
Car::Car( void )
{
  _currentDir = DIR_NORTH;
  _currentSpeed = 0;
  _maxSpeed = 65;
}

/*=========================================
 * Car::Car (dir_type)
 * 
 * This constructor creates a car object pointed in the specified direciton.
 ==========================================*/
Car::Car( dir_type init_direction )
{
  _currentDir = init_direction;
  _currentSpeed = 0;
  _maxSpeed = 65;
}

/*==========================================
 * Public Method:  Car::turnLeft
 * 
 * This method sets a car's internal direction to 90 degrees 
 * left of which direction it was previously going.
 ============================================*/
void Car::turnLeft( void )
{
  switch (_currentDir )
  {
    case DIR_NORTH:
      _currentDir = DIR_WEST;
    break;

    case DIR_EAST:
      _currentDir = DIR_NORTH;
    break;

    case DIR_SOUTH:
      _currentDir = DIR_EAST;
    break;

    case DIR_WEST:
      _currentDir = DIR_SOUTH;
    break;

    default:
      Serial.print("Unknown direction in CAR: ");
      Serial.println(_currentDir);
  }
  
  Serial.print("Turned Left.  New dir = ");
  Serial.println(_currentDir);
}

/*==========================================
 * Public Method:  Car::turnRight
 * 
 * This method sets a car's internal direction to 90 degrees 
 * right of which direction it was previously going.
 ============================================*/
void Car::turnRight( void )
{
  switch (_currentDir )
  {
    case DIR_NORTH:
      _currentDir = DIR_EAST;
    break;

    case DIR_EAST:
      _currentDir = DIR_SOUTH;
    break;

    case DIR_SOUTH:
      _currentDir = DIR_WEST;
    break;

    case DIR_WEST:
      _currentDir = DIR_NORTH;
    break;

    default:
      Serial.print("Unknown direction in CAR: ");
      Serial.println(_currentDir);
  }

  Serial.print("Turned Right.  New dir = ");
  Serial.println(_currentDir);
}

/*==========================================
 * Public Method:  Car::speedUp
 * 
 * This method increases the car's internal speed by 5 until it reaches
 *  a cap.
 ============================================*/
void Car::speedUp( void )
{
  Serial.print("Speeding up --> ");

  _currentSpeed = _currentSpeed + 5;
  if (_currentSpeed >= _maxSpeed) 
  {
    _currentSpeed = _maxSpeed;
    Serial.print("Hit max speed:  ");
    Serial.println(_currentSpeed);
  }
  else
  {
    Serial.print("New Speed = ");
    Serial.println(_currentSpeed);
  }
  
}


/*==========================================
 * Public Method:  Car::slowDown
 * 
 * This method decreases the car's internal speed by 5.  
 * We only go down to zero.
 ============================================*/
void Car::slowDown( void )
{
  Serial.print("Slowing down --> ");

  _currentSpeed = _currentSpeed - 5;
  if (_currentSpeed <= 0) 
  {
    _currentSpeed = 0;
    Serial.println("Stopped.");
  }
  else
  {
    _currentSpeed = _currentSpeed - 5;
    Serial.print("New Speed = ");
    Serial.println(_currentSpeed);
  }
}

/*===========================================
 * Public Method:  Car::getSpeed
 * 
 * This method returns the current speed
 ===========================================*/
int Car::getSpeed( void )
{
  return(_currentSpeed);
}

/*==============================================
 * Public Method:  Car::getDirection
 * 
 * This method returns the current direction
 ===============================================*/
dir_type Car::getDir( void )
{
  return(_currentDir);
}
