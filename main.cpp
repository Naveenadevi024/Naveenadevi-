/*
Weather  App
Name : Naveenadevi.M
College name : Vivekanandha College of Engineering for Woman
Location

1. Today 2. Yesterday

3. Tomorrow

4. Week report

5. month weather

cloudy

dry

rain

thunderstrom

heatwaves

temperature rain possibility

humidity

functions

class and objects oops concepts

*/
#include <iostream>
#include <string>
#include <vector>

// Weather class represents the weather conditions
class Weather {
private:
    std::string condition;
    double temperature;
    int humidity;

public:
    Weather(std::string condition, double temperature, int humidity) : condition(condition), temperature(temperature), humidity(humidity) {}

    // Getters
    std::string getCondition() const { return condition; }
    double getTemperature() const { return temperature; }
    int getHumidity() const { return humidity; }
};

// WeatherReport class represents a report for a specific day
class WeatherReport {
private:
    std::string date;
    Weather weather;

public:
    WeatherReport(std::string date, Weather weather) : date(date), weather(weather) {}

    // Getters
    std::string getDate() const { return date; }
    Weather getWeather() const { return weather; }
};

// WeatherApp class manages the weather reports
class WeatherApp {
private:
    std::vector<WeatherReport> reports;

public:
    void addReport(WeatherReport report) {
        reports.push_back(report);
    }

    void printReport(std::string date) {
        for (const auto& report : reports) {
            if (report.getDate() == date) {
                std::cout << "Weather Report for " << report.getDate() << std::endl;
                std::cout << "Condition: " << report.getWeather().getCondition() << std::endl;
                std::cout << "Temperature: " << report.getWeather().getTemperature() << " C" << std::endl;
                std::cout << "Humidity: " << report.getWeather().getHumidity() << "%" << std::endl;
                return;
            }
        }
        std::cout << "No report found for the specified date." << std::endl;
    }
};

int main() {
    WeatherApp weatherApp;

    // Add example weather reports
    Weather weather1("cloudy", 25.0, 60);
    Weather weather2("rain", 20.0, 70);
    Weather weather3("sunny", 30.0, 50);

    WeatherReport report1("2023-07-12", weather1);
    WeatherReport report2("2023-07-13", weather2);
    WeatherReport report3("2023-07-14", weather3);

    weatherApp.addReport(report1);
    weatherApp.addReport(report2);
    weatherApp.addReport(report3);

    // Print report for a specific date
    std::string date = "2023-07-13";
    weatherApp.printReport(date);

    return 0;
}