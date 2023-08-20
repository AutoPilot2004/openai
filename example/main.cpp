#include <iostream>

#include <gpt/gpt.h>
#include <gpt/exception.h>

int main()
{
	OpenAI::GPT gpt("1k-uMkg3nQndBtv63ginTEaT3BlbkFJGaFZrLe71sDZRw9pQzk8");

	try {
		while (true) {
			printf("You: ");
			std::string prompt;
			std::getline(std::cin, prompt);
			OpenAI::GPTResponse response = gpt.prompt(prompt);
			printf("ChatGPT: ");
			for (const auto& choice : response.choices) {
				printf("%s", choice.getContent().c_str());
			}
			printf("\n");
		}
	}
	catch (OpenAI::GPTException e) {
		printf("%s\n", e.what());
		std::cin.get();
	}

	return 0;
}