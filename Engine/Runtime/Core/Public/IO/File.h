#ifndef AMUSE_INCLUDE_FILE_H
#define AMUSE_INCLUDE_FILE_H

#include <filesystem>

namespace Amuse::IO::File
{
	/**
	 * @brief 지정한 경로에 파일이 존재하는지 확인합니다.
	 * 
	 * @param path_ 지정할 파일 경로
	 * 
	 * @return bool 해당 경로에 파일이 존재하는지 여부
	 */
	bool Exists(const std::filesystem::path& path_) noexcept;
} // namespace Amuse::IO::File

#endif // !GUARD_FILE_H