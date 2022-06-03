/****************************************************************
 *
 * Description:  It's a good practice to include a source header.
 *               It gives other developers an idea of what the 
 *               file/class implements.
 *
 * Author(s):  T. Buono, ...
 *
 ***************************************************************/


#ifndef CAR_HPP
#define CAR_HPP
// include guards help to avoid double declaration when multiple
// other source files include this header file.

#include<string>

/**
 * Simple example Car class that provides car functionality.
 * Comments made above declarations, so Doxygen can generate
 * documentation.
 */
class Car {
public:
    /**
     * Constructor
     *
     * @param manufacturerName The manufacturer name of the car
     * @param modelName The model name of the car
     */
    Car(std::string manufacturerName, std::string modelName);

    /**
     * Gets the manufacturer name of the car
     *
     * @return A std::string of the manufacturer name
     */
    std::string getManufacturerName();

    /**
     * Gets the model name of the car
     *
     * @return A std::string of the model name
     */
    std::string getModelName();
    
private:
    Car(); /**< default constructor not allowed for this class */

    std::string manufacturerName;
    std::string modelName;
};


#endif
