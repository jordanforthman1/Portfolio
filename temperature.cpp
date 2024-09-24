/* These definitions give the user options in creating temperature objects and allow functions such as conversion
to different scale or conmparison between scales. */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "temperature.h"

using namespace std;

Temperature::Temperature(double deg, char sc, char f)
{   
    format = 'D';
    sc = toupper(sc);
    //Check for valid scale
    if (sc == 'F' || sc == 'C' || sc == 'K')
        scale = sc;
    else
        scale = 'C';
    //Check vor valid temp above absolute zero per scale
    if (scale == 'C' && deg < -273.15)    
        deg = 0.0;
    
    else if (scale == 'F' && deg < -459.67)
    {
        scale = 'C';
        deg = 0.0;
    }

    else if (scale == 'K' && deg < 0)
    {
        scale = 'C';
        deg = 0.0;
    }

    degrees = deg;
    //Check for valid format
    if (f == 'D' || f == 'P' || f == 'L') 
        format = f;
    else 
        format = 'D';
}

void Temperature::Input()
{
    double newDegrees;
    char newScale;
    bool valid = true;
    
    do
    {    
        cout << "\nInput new temperature: ";
        cin >> newDegrees;
        cin >> newScale;
        newScale = toupper(newScale);

        if (newScale != 'F' && newScale != 'C' && newScale != 'K') //Valid scale input check
        {
            cout << "Invalid temperature. Try again";
            valid = false;
            continue;
        }

        if (newScale == 'F')
        {
            if (newDegrees < -459.67) //Farenheit abs zero = -459.67
            {
                cout << "Invalid temperature. Try again.";
                valid = false;
                continue;
            }
        }

        else if (newScale == 'C')
        {
            if (newDegrees < -273.15) //Celsius abs zero = -273.15
            {
                cout << "Invalid temperature. Try again.";
                valid = false;
                continue;
            }
        }

        else if (newScale == 'K')
        {
            if (newDegrees < 0) //Kelvin abs zero = 0
            {
                cout << "Invalid temperature. Try again.";
                valid = false;
                continue;
            }
        }

        valid = true;

    } while (valid == false);

    scale = newScale;
    degrees = newDegrees;
}

bool Temperature::Set(double deg, char sc)
{
    sc = toupper(sc);

    if (sc == 'F' || sc == 'C' || sc == 'K')
        scale = sc;
    else
        return false;
    
    if (scale == 'C' && deg < -273.15)    
        return false;
    
    else if (scale == 'F' && deg < -459.67)
        return false;

    else if (scale == 'K' && deg < 0)
        return false;
    
    degrees = deg;
    return true;
}

bool Temperature::SetFormat(char f)
{
    f = toupper(f);

    if (f == 'D' || f == 'P' || f == 'L')
    {
        format = f;
        return true;
    }
    else
        return false;
}

bool Temperature::Convert(char sc)
{   
    char originalScale = scale;
    sc = toupper(sc);
    //Check valid scale
    if (sc != 'F' && sc != 'C' && sc != 'K')
        return false;
    //Farenheit -> new scale
    if (originalScale == 'F')
    {
        if (sc == 'C')
            degrees = ((degrees - 32.0) * 5.0) / 9.0;
        else if (sc == 'K')
            degrees = (((degrees - 32) * 5.0) / 9.0) + 273.15;
    }
    //Celsius -> new scale
    if (originalScale == 'C')
    {
        if (sc == 'F')
            degrees = ((degrees * 9.0) / 5.0) + 32.0;
        else if (sc == 'K')
            degrees = degrees + 273.15;
    }
    //Kelvin -> new scale
    if (originalScale == 'K')
    {
        if (sc == 'F')
            degrees = (((degrees - 273.15) * 9.0) / 5.0) + 32.0;
        else if (sc == 'C')
            degrees = degrees - 273.15;
    }

    scale = sc;
    return true;
}

void Temperature::Increment(int deg, char sc)
{
    char originalScale = scale; //Store original scale for reversion at end of operation
    
    Temperature callingTemp = *this;

    if (callingTemp.Convert(sc)) //Check for successful conversion
    {
        callingTemp.degrees += deg; //Increment within same scale
        callingTemp.Convert(originalScale); //Revert back to original scale

        degrees = callingTemp.degrees; //Apply result to object
    }
}

int Temperature::Compare(const Temperature& d) const
{
    //Return 1: calling object temperature > parameter objects
    //Return 0: calling object temperature = parameter objects
    //Return -1: calling object temperature < parameter objects
    //Return 2: error

    Temperature callingTemp = *this; //Copy calling object
    Temperature paramTemp = d; //Copy parameter object

    callingTemp.Convert(paramTemp.scale); //Convert calling objects scale to parameters scale for easy compare

    if (callingTemp.degrees > paramTemp.degrees)
        return 1;
    
    else if (callingTemp.degrees < paramTemp.degrees)
        return -1;

    else if (callingTemp.degrees == paramTemp.degrees)
        return 0;

    return 2;
}

double Temperature::GetDegrees() const
{
    return degrees;
}

char Temperature::GetScale() const
{
    return scale;
}

void Temperature::Show() const
{
    if (format == 'D') //Default
        cout << degrees << " " << scale << endl;
    else if (format == 'P') //Precision-1
    {
        cout << fixed << showpoint << setprecision(1);
        cout << degrees << " " << scale << endl;
    }
    
    else if (format == 'L') //Long
    {
        cout << degrees;
        if (scale == 'F')
            cout << " Farenheit" << endl;
        else if (scale == 'C')
            cout << " Celcius" << endl;
        else if (scale == 'K')
            cout << " Kelvin" << endl;
    }
}




