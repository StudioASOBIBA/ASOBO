#ifndef GUARD_DIRECTORY_H
#define GUARD_DIRECTORY_H

#include <filesystem>

namespace Amuse::IO::Directory
{
	/**
	 * @brief 지정한 경로에 디렉터리가 존재하는지 확인합니다.
	 * 
	 * @param path_ 확인할 디렉터리 경로
	 * 
	 * @return bool 해당 경로에 디렉터리가 존재하는지 여부
	 */
	[[nodiscard]]
	bool Exists(const std::filesystem::path& path_) noexcept;
} // namespace Amuse::IO::Directory

#endif // !GUARD_DIRECTORY_H