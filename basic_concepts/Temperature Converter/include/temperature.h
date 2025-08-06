#pragma once
#include <iostream>
#include <string>
#include <format>
namespace temperatures {
    enum class TemperatureUnit {
        Celsius,
        Fahrenheit,
        Kelvin,
        Rankine,
        Delisle,
        Newton,
        Reaumur,
        Romer,
        end
    };

    std::string formatD(double value) {
        return std::format("{:.2f}", value);
    }

    std::string toString(TemperatureUnit unit) {
        switch (unit) {
        case TemperatureUnit::Celsius:
            return "Celcius (øC)";
        case TemperatureUnit::Fahrenheit:
            return "Fahrenheit (øF)";
        case TemperatureUnit::Kelvin:
            return "Kelvin (K)";
        case TemperatureUnit::Rankine:
            return "Rankine (øR)";
        case TemperatureUnit::Delisle:
            return "Delisle (øDe)";
        case TemperatureUnit::Newton:
            return "Newton (øN)";
        case TemperatureUnit::Reaumur:
            return "Reaumur (øRé)";
        case TemperatureUnit::Romer:
            return "Romer (øRo)";
        default:
            std::cout << "ERROR invalid unit type";
            return "";
        }
    }

    std::string asUnit(double value, TemperatureUnit unit) {
        switch (unit) {
        case TemperatureUnit::Celsius:
            return formatD(value) + " øC";
        case TemperatureUnit::Fahrenheit:
            return formatD(value) + " øF";
        case TemperatureUnit::Kelvin:
            return formatD(value) + " K";
        case TemperatureUnit::Rankine:
            return formatD(value) + " øR";
        case TemperatureUnit::Delisle:
            return formatD(value) + " øDe";
        case TemperatureUnit::Newton:
            return formatD(value) + " øN";
        case TemperatureUnit::Reaumur:
            return formatD(value) + " øRé";
        case TemperatureUnit::Romer:
            return formatD(value) + " øRo";
        default:
            std::cout << "ERROR invalid unit type";
            return "";
        }
    }

    // Conversion to Celsius from various units
    double toCelsius(double value, TemperatureUnit unit) {
        switch (unit) {
        case TemperatureUnit::Celsius:
            return value;
        case TemperatureUnit::Fahrenheit:
            return (value - 32.0) * 5.0 / 9.0;
        case TemperatureUnit::Kelvin:
            return value - 273.15;
        case TemperatureUnit::Rankine:
            return (value - 491.67) * 5.0 / 9.0;
        case TemperatureUnit::Delisle:
            return 100.0 - (value / 1.5);
        case TemperatureUnit::Newton:
            return value * 100.0 / 33.0;
        case TemperatureUnit::Reaumur:
            return value * 5.0 / 4.0;
        case TemperatureUnit::Romer:
            return (value - 7.5) * 40.0 / 21.0;
        default:
            std::cout << "ERROR invalid unit type";
            return 0;
        }
    }

    // Conversion from Celsius to various units
    double fromCelsius(double value, TemperatureUnit unit) {
        switch (unit) {
        case TemperatureUnit::Celsius:
            return value;
        case TemperatureUnit::Fahrenheit:
            return (value * 9.0 / 5.0) + 32.0;
        case TemperatureUnit::Kelvin:
            return value + 273.15;
        case TemperatureUnit::Rankine:
            return (value + 273.15) * 9.0 / 5.0;
        case TemperatureUnit::Delisle:
            return (100.0 - value) * 1.5;
        case TemperatureUnit::Newton:
            return value * 33.0 / 100.0;
        case TemperatureUnit::Reaumur:
            return value * 4.0 / 5.0;
        case TemperatureUnit::Romer:
            return value * 21.0 / 40.0 + 7.5;
        default:
            std::cout << "ERROR invalid unit type";
            return 0;
        }
    }

    // Generic conversion function
    double convertTemperature(double value, TemperatureUnit fromUnit, TemperatureUnit toUnit) {
        // First, convert the input value to Celsius
        double celsiusValue = toCelsius(value, fromUnit);

        // Then, convert from Celsius to the desired output unit
        return fromCelsius(celsiusValue, toUnit);
    }
}