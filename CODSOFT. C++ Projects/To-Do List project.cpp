#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
	string description;
	bool completed;
};

class ToDoList {
private:
	vector<Task> tasks;

public:
	void addTask(const string& description) {
		Task newTask;
		newTask.description = description;
		newTask.completed = false;
		tasks.push_back(newTask);
		cout << "Task added: " << description << endl;
	}

	void viewTasks() {
		cout << "To-Do List:" << endl;
		for (size_t i = 0; i < tasks.size(); ++i) {
			cout << i + 1 << ". ";
			cout << (tasks[i].completed ? "[X] " : "[ ] ");
			cout << tasks[i].description << endl;
		}
		cout << endl;
	}

	void markAsCompleted(size_t index) {
		if (index >= 1 && index <= tasks.size()) {
			tasks[index - 1].completed = true;
			cout << "Task marked as completed: " << tasks[index - 1].description << endl;
		}
		else {
			cout << "Invalid task index." << endl;
		}
	}

	void removeTask(size_t index) {
		if (index >= 1 && index <= tasks.size()) {
			cout << "Task removed: " << tasks[index - 1].description << endl;
			tasks.erase(tasks.begin() + index - 1);
		}
		else {
			cout << "Invalid task index." << endl;
		}
	}
};

int main() {
	ToDoList toDoList;

	while (true) {
		cout << "Options:" << endl;
		cout << "1. Add Task" << endl;
		cout << "2. View Tasks" << endl;
		cout << "3. Mark Task as Completed" << endl;
		cout << "4. Remove Task" << endl;
		cout << "5. Quit" << endl;

		int choice;
		cout << "Enter your choice (1-5): ";
		cin >> choice;

		switch (choice) {
		case 1: {
					string taskDescription;
					cout << "Enter task description: ";
					cin.ignore(); // Clear the buffer
					getline(cin, taskDescription);
					toDoList.addTask(taskDescription);
					break;
		}
		case 2:
			toDoList.viewTasks();
			break;
		case 3: {
					size_t taskIndex;
					cout << "Enter the index of the task to mark as completed: ";
					cin >> taskIndex;
					toDoList.markAsCompleted(taskIndex);
					break;
		}
		case 4: {
					size_t taskIndex;
					cout << "Enter the index of the task to remove: ";
					cin >> taskIndex;
					toDoList.removeTask(taskIndex);
					break;
		}
		case 5:
			cout << "Exited the program successfully." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
		}
	}

	return 0;
}