#pragma once
#include <exception>
#include <string>

namespace OpenAI
{
	class GPTException : public std::exception
	{
	public:
		GPTException(const std::string& msg) noexcept : m_message(msg) {}

		const char* what() const noexcept override
		{
			return m_message.c_str();
		}

	private:
		std::string m_message;
	};
}