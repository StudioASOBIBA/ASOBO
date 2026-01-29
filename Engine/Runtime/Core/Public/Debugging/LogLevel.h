#ifndef AMUSE_INCLUDE_LOGLEVEL_H
#define AMUSE_INCLUDE_LOGLEVEL_H

namespace Amuse::Debug
{
	/**
	 * @enum ELogLevel
	 * 
	 * @brief 로그 레벨을 정의합니다.
	 */
	enum class LogLevel : unsigned char
	{
		Info,
		Warn,
		Error,
		Critical
	};
} // namespace Amuse::Debug

#endif // !AMUSE_INCLUDE_LOGLEVEL_H