#include "Worker.hpp"

Worker::Worker(const std::string &name, int hoursWorked) : name(name), hoursWorked(hoursWorked) {}

int Worker::getHoursWorked() const
{
    return hoursWorked;
}

void Worker::setHoursWorked(int x)
{
    hoursWorked = x;
}

void Worker::displaySalary() const
{
    std::cout << name << ' ' << hoursWorked << ' ' << calculateSalary() << std::endl;
}

Worker::~Worker()
{
    std::cout << "Worker Destractor called\n";
}

FullTimeWorker::FullTimeWorker(const std::string &name, int monthlySalary) : Worker(name, 0), monthlySalary(monthlySalary) {}

double FullTimeWorker::calculateSalary() const
{
    return monthlySalary;
}

PartTimeWorker::PartTimeWorker(const std::string &name, int hourlyRate) : Worker(name, 0), hourlyRate(hourlyRate) {}

double PartTimeWorker::calculateSalary() const
{
    return hourlyRate;
}