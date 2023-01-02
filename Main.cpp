#include <iostream> 
#include <queue> 
#include <string>
#include <Windows.h>

void printQueue(std::queue<std::string> queue)
{
	int i = 0;
	while (!queue.empty())
	{
		i++; 
		Sleep(500); 
		std::cout << " " << i << ". " << queue.front() << "\n\n";        
		queue.pop(); 
	}
}

int main()
{
	std::string firstTask;
	std::queue<std::string> DailyScheduleQueue;
	Sleep(500); 
	std::cout << "\n Please enter your tasks for the day in the order that you would like to complete them. \n\n";
	Sleep(500); 
	std::cout << " Enter a task here: ";
	std::getline(std::cin, firstTask);

	while (firstTask.empty())
	{
		std::cout << "\n Please do not press the enter key without entering a task.\n\n";
		Sleep(500); 
		std::cout << " Enter a task here: ";
		std::cin.clear();
		std::getline(std::cin, firstTask);
	}

	DailyScheduleQueue.push(firstTask); 

	std::string taskAddition;
	std::string task;
	std::string taskAdditionRepsonses[6] = { "Yes", "yes", "y", "No", "no", "n" };

	while (DailyScheduleQueue.size() >= 1)
	{
		std::cout << "\n Would you like to add another task (y or n)? "; 
		std::getline(std::cin, taskAddition);

		while (taskAddition != taskAdditionRepsonses[0] && taskAddition != taskAdditionRepsonses[1] && taskAddition != taskAdditionRepsonses[2]
			&& taskAddition != taskAdditionRepsonses[3] && taskAddition != taskAdditionRepsonses[4] && taskAddition != taskAdditionRepsonses[5])
		{
			std::cout << "\n Please do not press the enter key without entering 'y' or 'n.'\n\n";
			Sleep(500); 
			std::cout << " Would you like to add another task (y or n)? ";
			std::cin.clear();
			std::getline(std::cin, taskAddition);
		}

		if (taskAddition == taskAdditionRepsonses[0] || taskAddition == taskAdditionRepsonses[1] || taskAddition == taskAdditionRepsonses[2])
		{
			std::cout << "\n Enter another task: ";
			std::getline(std::cin, task);

			while (task.empty())
			{
				std::cout << "\n Please do not press the enter key without entering a task.\n\n";
				Sleep(500); 
				std::cout << " Enter a task here: ";
				std::cin.clear();
				std::getline(std::cin, task);
			}

			DailyScheduleQueue.push(task); 
		}

		if (taskAddition == taskAdditionRepsonses[3] || taskAddition == taskAdditionRepsonses[4] || taskAddition == taskAdditionRepsonses[5])
		{
			std::cout << "\n\n Here are your tasks for today:\n\n";
			Sleep(500); 
			printQueue(DailyScheduleQueue);

			std::string taskCompletion; 
			std::string taskCompletionResponses[6] = { "Yes", "yes", "y", "No", "no", "n" };
			Sleep(500); 
			std::cout << "\n Have you completed a task yet (y or n)? "; 
			std::getline(std::cin, taskCompletion); 

			while (!DailyScheduleQueue.empty())
			{
				while (taskCompletion != taskCompletionResponses[0] && taskCompletion != taskCompletionResponses[1] && taskCompletion != taskCompletionResponses[2]
					&& taskCompletion != taskCompletionResponses[3] && taskCompletion != taskCompletionResponses[4] && taskCompletion != taskCompletionResponses[5])
				{
					std::cout << "\n Please do not press the enter key without entering 'y' or 'n.'\n\n";
					Sleep(500); 
					std::cout << " Have you completed a task yet (y or n)? ";
					std::cin.clear();
					std::getline(std::cin, taskCompletion);
				}

				while (taskCompletion == taskCompletionResponses[3] || taskCompletion == taskCompletionResponses[4] || taskCompletion == taskCompletionResponses[5])
				{
					std::cout << "\n Well, get on with it then.\n\n";
					Sleep(500); 
					std::cout << " Have you completed a task yet (y or n)? ";
					std::cin.clear();
					std::getline(std::cin, taskCompletion);
				}

				if (taskCompletion == taskCompletionResponses[0] || taskCompletion == taskCompletionResponses[1] || taskCompletion == taskCompletionResponses[2])
				{
					DailyScheduleQueue.pop();
					if (!DailyScheduleQueue.empty())
					{
						std::cout << "\n\n Here are your remaining tasks:\n\n";
						Sleep(500); 
						printQueue(DailyScheduleQueue);
						Sleep(500); 
						std::cout << " Have you completed another task (y or n)? ";
						std::cin.clear();
						std::getline(std::cin, taskCompletion);
					}
				}
			}
		}
	}

	if (DailyScheduleQueue.empty())
	{
		Sleep(500); 
		std::cout << "\n\n Congratulations!! You have completed your tasks for the day.\n\n";
	}

	return 0; 
}