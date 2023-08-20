#pragma once
#include <string>
#include <vector>

namespace OpenAI
{
	struct GPTResponse
	{
		std::string id;
		std::string object;
		int created;
		std::string model;
		struct Choice
		{
			const std::string& getContent() const
			{
				return message.content;
			}

			int index;
			std::string finishReason;
			struct Message
			{
				std::string role;
				std::string content;
			} message;
		};
		std::vector<Choice> choices;
		struct Usage
		{
			int promptTokens;
			int completionTokens;
			int totalTokens;
		} usage;
	};

	class GPT
	{
	public:
		GPT(const std::string& apiKey) : m_apiKey(apiKey) {}
		~GPT() = default;

		GPTResponse prompt(const std::string& message);

	private:
		std::string m_apiKey;
	};
}