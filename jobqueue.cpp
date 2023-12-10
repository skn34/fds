#include <iostream>
#include <queue>

class JobQueue {
private:
    std::queue<std::string> jobs;

public:
    void insertJob(const std::string& job) {
        jobs.push(job);
        std::cout << "Job \"" << job << "\" added to the queue.\n";
    }

    void displayJobs() {
        if (jobs.empty()) {
            std::cout << "Queue is empty. No jobs to display.\n";
        } else {
            std::cout << "Jobs in the queue:\n";
            std::queue<std::string> tempQueue = jobs; // Create a temporary queue for display
            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << "\n";
                tempQueue.pop();
            }
        }
    }

    void removeJob() {
        if (jobs.empty()) {
            std::cout << "Queue is empty. No job to remove.\n";
        } else {
            std::cout << "Removing job: " << jobs.front() << "\n";
            jobs.pop();
        }
    }
};

int main() {
    JobQueue jobQueue;
    int choice;
    std::string job;

    do {
        std::cout << "\n******** JOB QUEUE SIMULATION ********\n";
        std::cout << "1. Insert Job\n2. Display Jobs\n3. Remove Job\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter job name: ";
                std::cin >> job;
                jobQueue.insertJob(job);
                break;
            case 2:
                jobQueue.displayJobs();
                break;
            case 3:
                jobQueue.removeJob();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

