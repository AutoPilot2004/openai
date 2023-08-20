#include "gpt.h"
#include "exception.h"

#include <iostream>
#include <cpr/cpr.h>

namespace OpenAI
{
	namespace
	{
		void convertJsonToGPTR(const json& j, GPTResponse& response)
		{
			j.at("id").get_to(response.id);
			j.at("object").get_to(response.object);
			j.at("created").get_to(response.created);
			j.at("model").get_to(response.model);

			for (auto i = j.at("choices").begin(); i != j.at("choices").end(); i++) {
				GPTResponse::Choice choice;
				i->at("index").get_to(choice.index);
				i->at("finish_reason").get_to(choice.finishReason);
				i->at("message").at("role").get_to(choice.message.role);
				i->at("message").at("content").get_to(choice.message.content);
				response.choices.push_back(choice);
			}

			j.at("usage").at("prompt_tokens").get_to(response.usage.promptTokens);
			j.at("usage").at("completion_tokens").get_to(response.usage.completionTokens);
			j.at("usage").at("total_tokens").get_to(response.usage.totalTokens);
		}
	}

	GPTResponse GPT::prompt(const std::string& message)
	{
		std::string msgRequest = R"({"model": "gpt-3.5-turbo","messages": [{"role": "user", "content": ")" + message + "\"}]}";

		std::string msgResponse = cpr::Post(cpr::Url{"https://api.openai.com/v1/chat/completions"},
			cpr::Bearer{ {m_apiKey} },
			cpr::Header{ {"Content-Type", "application/json"} },
			cpr::Body{msgRequest}).text;

		json parsedResponse = json::parse(msgResponse);
		GPTResponse fullResponse;

		if (parsedResponse.contains("error")) {
			throw GPTException(static_cast<std::string>(parsedResponse["error"]["message"]).c_str());
		}
		else {
			convertJsonToGPTR(parsedResponse, fullResponse);
		}

		return fullResponse;
	}
}