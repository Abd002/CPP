#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>

class Worker
{
    std::string name;
    int hoursWorked;

public:
    Worker(const std::string &name, int hoursWorked);

    int getHoursWorked() const;

    void setHoursWorked(int x);

    virtual double calculateSalary() const = 0;

    void displaySalary() const;

    virtual ~Worker();
};

class FullTimeWorker : public Worker
{
    double monthlySalary;

public:
    FullTimeWorker(const std::string &name, int monthlySalary);

    double calculateSalary() const override;

    ~FullTimeWorker() { std::cout << "FullTimeWorker Destructor\n"; }
};

class PartTimeWorker : public Worker
{
    double hourlyRate;

public:
    PartTimeWorker(const std::string &name, int hourlyRate);

    double calculateSalary() const override;
};
#endif