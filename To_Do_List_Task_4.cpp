#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;
};

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
    tasks.push_back({description, false});
    std::cout << "Task added!" << std::endl;
}

void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "To-Do List:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description << " ["
                  << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << std::endl;
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    int taskIndex;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> taskIndex;
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].isCompleted = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks) {
    int taskIndex;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskIndex;
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "Task removed!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch(choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markTaskCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid option. Try again.\n"; break;
        }
    } while (choice != 5);

    return 0;
}
