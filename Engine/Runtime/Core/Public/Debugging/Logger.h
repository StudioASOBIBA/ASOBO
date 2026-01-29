#ifndef AMUSE_INCLUDE_LOGGER_H
#define AMUSE_INCLUDE_LOGGER_H

#include "LogLevel.h"

namespace Amuse::Debug::Logger
{
	void Log(LogLevel level_, const char* message_) noexcept;

	template <typename... TArgs>
	void Info(const char* message_, TArgs... args_) noexcept;

	template <typename... TArgs>
	void Warn(const char* message_, TArgs... args_) noexcept;

	template <typename... TArgs>
	void Error(const char* message_, TArgs... args_) noexcept;

	template <typename... TArgs>
	void Critical(const char* message_, TArgs... args_) noexcept;
} // namespace Logger

#endif // !AMUSE_INCLUDE_LOGGER_H